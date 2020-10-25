#include <cmplx.h>
#include <stdio.h>

int main(void) {
	cmplx_t a = {3, 4};
	
	double imag = cmplx_imag(cmplx_mag(a), cmplx_phs(a));
	printf("imag = %f\n", imag);
	
	return 0;
}
