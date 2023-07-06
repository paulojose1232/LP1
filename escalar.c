#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

float escalar(float vet1[], float vet2[], int i) 
{
  if (i >= 0) 
  {
      return (vet1[i] * vet2[i] + escalar(vet1, vet2, i-1));
  }

  return 0;
}