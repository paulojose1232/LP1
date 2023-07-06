#define swap(t,x,y) {t z; z=x; x=y; y=z; }

#include <stdio.h>

int main(void)
{
	int z,x,y;
	x = 1;
	y = 2;
	
	printf("x=%d y=%d", x,y);
	
	swap(int,x,y);
	
	printf("x=%d y=%d", x,y);
	
	//printf(OS "\n");
}
