// programa em c para testar programação paralelizada usando placa de vídeo

#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <stdio.h>

__global__ void vectorAdd(int* a, int* b, int* c)
{
    int i = threadIdx.x;
    c[i] = a[i] + b[i];

    return;
}

int main()
{
    int a[] = {1, 2, 3};
    int b[] = {4, 5, 6};
    int c[sizeof(a) / sizeof(int)] = { 0 };

    //Exemplo normal usando CPU
    /*
    for (int i = 0; i < sizeof(c) / sizeof(int); i++)
    {
        c[i] = a[i] + b[i];
    }
    */

    // cria ponteiros na GPU
    int* cudaA = 0;
    int* cudaB = 0;
    int* cudaC = 0;

    // aloca memória na GPU
    cudaMalloc(&cudaA, a, sizeof(a), cudaMemcpyHostToDevice);
    cudaMalloc(&cudaB, b, sizeof(b), cudaMemcpyHostToDevice);
    cudaMalloc(&cudaC, c, sizeof(c), cudaMemcpyHostToDevice);

    vectorAdd <<< 1, sizeof(a) / sizeof(int) >>> (cudaA, cudaB, cudaC);

    cudaMemcpy(c, cudaC, sizeof(c), cudaMemcpyHostToDevice);

    return;
}