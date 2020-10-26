#include <cmplx.h>
#include <io.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define N 4
#define FREQ 200
#define PI 3.14159265358979323846264338327950288419716939937510582097494459230781640628

int main(void) {
	int fd = open("dft.txt",O_RDONLY);
	cmplx_t dft_signal[N];
	cmplx_t idft[N];
	cmplx_t* ps = &dft_signal[0];
	cmplx_t* pi = &idft[0];
	int i;
	float phs, mag;
	
	for(i = 0; i < N; i++) {
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
		
		*(ps + i)[0] = mag;
		*(ps + i)[1] = phs;
	}
	close(fd);
	
	cmplx_idft(ps, pi, N);
	
	for(i = 0; i < N; i++) {
		printf("%f + i%f\n", dft_signal[i][0], dft_signal[i][1]);
	}
	
	return 0;
}
