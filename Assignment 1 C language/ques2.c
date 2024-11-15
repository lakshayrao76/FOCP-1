//WAP to read two integers and print their HCF (Highest Common
//Factor).
#include <stdio.h>
int main() {
 int a , b , temp;
 printf("enter number 1 :");
 scanf("%d",&a);
 printf("enter number 2 :");
 scanf("%d", &b);
 while (b != 0) {
 temp = b;
 b = a % b;
 a = temp;
 }
 printf("HCF: %d\n", a);
 return 0;
}