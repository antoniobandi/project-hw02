#include <cmplx.h>
#include <stdio.h>

int main(void) {
	cmplx_t a = {3, 4};
	
	double real = cmplx_real(cmplx_mag(a), cmplx_phs(a));
	printf("real = %f\n", real);
	
	return 0;
}
