#include <cmplx.h>
#include <stdio.h>

int main(void) {
	cmplx_t a = {3, 4};
	
	double mag = cmplx_mag(a);
	printf("mag = %f\n", mag);
	
	return 0;
}
