#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int main() {
    struct stat buffer;
    stat("HelloWorld.c", &buffer);
    printf("File Size: %lu\n", buffer.st_size);
    printf("mode(permissions): %o\n", buffer.st_mode);
    printf("Time of last access: %s\n", ctime((time_t*)&buffer.st_atime));
    return 0;
}