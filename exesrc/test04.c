#include <cmplx.h>
#include <stdio.h>

int main(void) {
	cmplx_t a = {3, 4};
	
	double phs = cmplx_phs(a);
	printf("phs = %f\n", phs);
	
	return 0;
}
