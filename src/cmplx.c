#include <math.h>
#define PI 3.14159265358979323846264338327950288419716939937510582097494459230781640628

typedef float cmplx_t[2];

// c = a / b;
void cmplx_div(cmplx_t a, cmplx_t b, cmplx_t c) {
	c[0] = (a[0]*b[0] + a[1]*b[1]) / (b[0]*b[0] + b[1]*b[1]);
	c[1] = (a[1]*b[0] - a[0]*b[1]) / (b[0]*b[0] + b[1]*b[1]);
}
// c = a * b;
void cmplx_mul(cmplx_t a, cmplx_t b, cmplx_t c) {
	c[0] = (a[0]*b[0] - a[1]*b[1]);
	c[1] = (a[0]*b[1] + a[1]*b[0]);
}
// returns |a|
double cmplx_mag(cmplx_t a) {
	return sqrt(a[0]*a[0] + a[1]*a[1]);
}
// returns phase in radians of a 
double cmplx_phs(cmplx_t a) {
	return atan(a[1]/a[0]);
}
// returns real part of mag/_phs
double cmplx_real(double mag, double phs) {
	return mag*cos(phs);
}
// returns imaginary part of mag/_phs
double cmplx_imag(double mag, double phs) {
	return mag*sin(phs);
}
// returns dft transformation of complex input signal
void cmplx_dft(cmplx_t *input, cmplx_t *output, int N) {
	int n, k;
	float* out = output[0];
	
	for(k = 0; k < N; k++) {
		*(out + 2*k) = 0;
		*(out + 2*k + 1) = 0;
		cmplx_t pom = {0, 0};
		for(n = 0; n < N; n++) {
			cmplx_t faktor = {cos(n*k*2*PI/N), -1*sin(n*k*2*PI/N)};
			cmplx_mul(*(input + n), faktor, pom);
			*(out + 2*k) += pom[0];
			*(out + 2*k + 1) += pom[1];
		}
	}
}
// returns inverse dft transformation of complex input signal
void cmplx_idft(cmplx_t *input, cmplx_t *output, int N) {
	int n, k;
	float* out = output[0];
	
	for(n = 0; n < N; n++) {
		*(out + 2*n) = 0;
		*(out + 2*n + 1) = 0;
		cmplx_t pom = {0, 0};
		for(k = 0; k < N; k++) {
			cmplx_t faktor = {cos(n*k*2*PI/N)/N, sin(n*k*2*PI/N)/N};
			cmplx_mul(*(input + k), faktor, pom);
			*(out + 2*n) += pom[0];
			*(out + 2*n + 1) += pom[1];
		}
	}
}
