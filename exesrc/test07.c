#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <io.h>
       
int main(void) {
	short word = 1100;
	int fd = open("test07.txt", O_RDWR | O_CREAT);
	
	write_half(fd, word);
	short num = read_half(fd);
	
	printf("%d\n", num);
	
	close(fd);
	
	return 0;
}
