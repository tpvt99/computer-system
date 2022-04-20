#include <iostream>
#include <cstring>

void inplace_swap(int *x, int *y);
void reverse_array(int a[], int cnt);


int main() {
    int a[5] = {1,2,3,4,5};
    reverse_array(a, 5);
    for (int i = 0; i < 5; i++) {
        std::cout << a[i] << " ";
    }
    return 0;
}

void inplace_swap(int *x, int *y) {
    *y = *x ^ *y; /* Step 1 */
    *x = *x ^ *y; /* Step 2 */
    *y = *x ^ *y; /* Step 3 */
}

void reverse_array(int a[], int cnt) {
    int first, last;
    for (first = 0, last = cnt-1;
    first < last;
    first++,last--)
        inplace_swap(&a[first], &a[last]);
}