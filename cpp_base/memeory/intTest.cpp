#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include<cstdlib>

bool isLittleEndian() {
    int x = 1;
    return *((char*) (&x)) == 1;
}

template<class T>
void printBinary(T d) {
    char* p = (char*)&d;
    int sz = sizeof(T); // bytes

    char* buff = new char[sz * 8 + 1];
    buff[sz * 8] = '\0';
    int used = 0;

    for (int n = 0; n < sz; n++) {
        for (int m = 0; m < 8; m++) {
            if ((p[n] >> m) & 1)
                used += sprintf(buff + used, "1");
            else
                used += sprintf(buff + used, "0");
        }
    }

    if (isLittleEndian()) {
        int a = 0;
        int b = sz * 8 - 1;
        while (a < b) {
            buff[a] ^= buff[b];
            buff[b] ^= buff[a];
            buff[a] ^= buff[b];
            a++;
            b--;
        }
    }

    printf("%s\n", buff);
    delete [] buff;
}

int main() {
    int i = 121;
    int i2 = -4;
    float f = 98.1;
    double d = 98.1;

    printBinary(i);     // 00000000000000000000000001111001
    printBinary(i2);    // 11111111111111111111111111111100
    printBinary(f);     // 01000010110001000011001100110011
    printBinary(d);     // 0100000001011000100001100110011001100110011001100110011001100110
}