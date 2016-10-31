#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char whichLetter(int i) {
    if (i % 3 == 0) {
        return 'x';
    }
    else if (i % 3 == 1) {
        return 'r';
    }
    else return 'w';
}

char * chmodThat(mode_t permissions) {
    int i = permissions, t = 10;
    char *ret = malloc(10);
    ret[0] = '-';
    while(t-- > 1) {
        ret[t] = permissions % 2 ? whichLetter(t) : '-';
        permissions /= 2;
    }
    return ret;
}

char * fileSize(off_t size) {
    char *list[5];
    list[0] = "";
    list[1] = "K";
    list[2] = "M";
    list[3] = "G";
    list[4] = "T";
    unsigned long num = size;
    int i = 0;
    if (num / 1024 > 0) {
        num /= 1024;
        i++;
    }
    char *ret = malloc(10);
    sprintf(ret, "%lu%s%s",num,list[i],"B");
    return ret;
}

int main() {
    struct stat buffer;
    stat("HelloWorld.c", &buffer);
    printf("File Size: %s\n", fileSize(buffer.st_size));
    printf("mode(permissions): %s\n", chmodThat(buffer.st_mode));
    printf("Time of last access: %s\n", ctime((time_t*)&buffer.st_atime));
    return 0;
}

