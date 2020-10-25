#include <cmplx.h>
#include <io.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define FREQ 200
#define PI 3.14159265359

int main(void) {
	int fd = open("dft.txt",O_RDONLY);
	cmplx_t dft_signal[100];
	cmplx_t idft[100];
	cmplx_t* ps = &dft_signal[0];
	cmplx_t* pi = &idft[0];
	int i;
	float phs, mag;
	
	for(i = 0; i < 100; i++) {
		//čitanje amplitude
		int vrijednost_ieee = read_word(fd);
		void *a = (void *) &vrijednost_ieee;
		float vrijednost = *((float *) a);
		mag = vrijednost;
		//čitanje faze
		vrijednost_ieee = read_word(fd);
		a = (void *) &vrijednost_ieee;
		vrijednost = *((float *) a);
		phs = vrijednost;
		
		*(ps + i*sizeof(cmplx_t))[0] = mag;
		*(ps + i*sizeof(cmplx_t))[1] = phs;
	}
	close(fd);
	
	cmplx_idft(ps, pi, 100);
	
	for(i = 0; i < 100; i++) {
		float real = *(ps + i*sizeof(cmplx_t))[0];
		float imag = *(ps + i*sizeof(cmplx_t))[1]; 
		printf("%f + i%f\n", real, imag);
	}

	return 0;
}
