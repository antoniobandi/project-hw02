#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int read_word(int fd) {
	char buffer[16];
	read(fd, buffer, 4);
	int word = atoi(buffer);
	return word;
}
short read_half(int fd) {
	char buffer[4];
	read(fd, buffer, 2);
	short half_word = atoi(buffer);
	return half_word;
}
void write_word(int fd, int word) {
	char buffer[16];
	sprintf(buffer, "%d", word);
	write(fd, buffer, 4);
}
void write_half(int fd, short word) {
	char buffer[4];
	sprintf(buffer, "%d", word);
	write(fd, buffer, 2);
}
