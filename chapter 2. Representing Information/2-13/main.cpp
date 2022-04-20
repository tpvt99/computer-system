#include <iostream>

/* Declarations of functions implementing operations bis and bic */
int bis(int x, int m);
int bic(int x, int m);
int bool_or(int x, int y);
int bool_xor(int x, int y);

void print_binary(unsigned int number)
{
    if (number >> 1) {
        print_binary(number >> 1);
    }
    putc((number & 1) ? '1' : '0', stdout);
}

int main() {
    int a = 0b1100110;
    int b = 0b0101101;
    print_binary(bool_or(a,b));
    printf("\n");
    print_binary(bool_xor(b,a));

    return 0;
}

int bis(int x, int m) {
    return x | m;
}

int bic(int x, int m) {
    return x & (~m);
}

/* Compute x|y using only calls to functions bis and bic */
int bool_or(int x, int y) {
    int result = bis(x,y);
    return result;
}


/* Compute x^y using only calls to functions bis and bic */
int bool_xor(int x, int y) {
    int result = bis(bic(x,y), bic(y,x));
    return result;
}