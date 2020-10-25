#include <cmplx.h>
#include <stdio.h>

int main(void) {
	cmplx_t a = {3, 4};
	cmplx_t b = {4, 2};
	cmplx_t c;
	
	cmplx_div(a, b, c);
	printf("c = %f + i%f\n", c[0], c[1]);
	
	return 0;
}
