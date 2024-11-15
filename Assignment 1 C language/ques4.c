//WAP to accept two integer numbers and swap them using 4 different method in c language 
#include <stdio.h>
int main() {
//Using a third variable
int c = 7, d = 8, temp;
temp = c;
c = d;
d = temp;
printf("c = %d, d = %d\n", c, d);
//Without using a third variable (Arithmetic addition and subtraction)
int e = 76, f = 88;
e = e + f;
f = e - f;
e = e - f;
printf("\ne = %d, f = %d\n", e, f);
//Without using a third variable (Arithmetic multiplication and
//division)
int g = 88, h = 76;
g = g * h;
h = g / h;
g = g / h;
printf("g = %d, h = %d\n", g, h);
//Using bitwise XOR operator
int a = 10, b = 20;
a = a ^ b;
b = a ^ b;
a = a ^ b;
printf("a = %d, b = %d\n", a, b);
return 0;
}