#include <iostream>
#include <cstring>

typedef unsigned char * byte_type;

int a_set_least(int a);
int b_complement(int a);
int c_unchange(int a);

int main() {
    long int x = 0x87654321;

    long int result = a_set_least(x);
    printf("%#010X\n", result);
    result = b_complement(x);
    printf("%#010X\n", result);
    result = c_unchange(x);
    printf("%#010X\n", result);
    return 0;
}

int a_set_least(int a) {
    return a & 0xff;
}

int b_complement(int a) {
    int all_complement = ~a;
    int zero_least_complement = a & 0xff;
    int complement_zero_least = all_complement & (~0xff);
    int result = zero_least_complement | complement_zero_least;
    return result; // better results is x ^ ~0xff
}

int c_unchange(int a) {
    int unchange_zero = a & (~0xff); // unecessary
    return unchange_zero | 0xff;
}