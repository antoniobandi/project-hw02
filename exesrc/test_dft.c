#include <cmplx.h>
#include <io.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define FREQ 200
#define PI 3.14159265359

int main(void) {
	int fd = open("dft.txt",O_CREAT | O_WRONLY);
	cmplx_t signal[100];
	cmplx_t dft[100];
	cmplx_t* ps = &signal[0];
	cmplx_t* pd = &dft[0];
	int i;
	
	for(i = 0; i < 100; i++) {
		*(ps + i*sizeof(cmplx_t))[0] = sin(2*PI*50*i/FREQ);
	}
	
	cmplx_dft(ps, pd, 100);
	
	for(i = 0; i < 100; i++) {
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
