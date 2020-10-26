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
	int fd = open("dft.txt",O_CREAT | O_RDWR);
	cmplx_t signal[N] = {0};
	cmplx_t dft[N] = {0};
	cmplx_t* ps = &signal[0];
	cmplx_t* pd = &dft[0];

	int i;
	
	for(i = 0; i < N; i++) {
		*(ps + i)[0] = sin(2*PI*50*i/FREQ);
	}
	
	cmplx_dft(ps, pd, N);
	
	for(i = 0; i < N; i++) {
		//upis amplitude
		float vrijednost = cmplx_mag(dft[i]);
		void *a = (void *) &vrijednost;
		int vrijednost_ieee = *((int *) a);
		int vrijednost_cijeli_broj = (int) vrijednost;
		write_word(fd, vrijednost_ieee);
		//upis faze
		vrijednost = cmplx_phs(dft[i]);
		a = (void *) &vrijednost;
		vrijednost_ieee = *((int *) a);
		vrijednost_cijeli_broj = (int) vrijednost;
		write_word(fd, vrijednost_ieee);
	}
	
	close(fd);
	
	return 0;
}
