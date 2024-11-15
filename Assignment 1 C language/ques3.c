// WAP to subtract two integers without using Minus (-) operator. (Hint
// Bitwise operator)
#include <stdio.h>
int main() {
 int a , b ;
 printf("enter number 1 :");
 scanf("%d",&a);
 printf("enter number 2 :");
 scanf("%d", &b);
 while (b != 0) {
 int borrow = (~a) & b;
 a = a ^ b;
 b = borrow << 1;
 }
 printf("Result: %d\n", a);
 return 0;
}