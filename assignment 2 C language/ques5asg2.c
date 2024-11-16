//WAP to find sum of all scores in Marks array.
#include <stdio.h>
int main() {
 int marks[] = {69, 79, 85, 98, 49};
 int n = 5, sum = 0;
 for (int i = 0; i < n; i++) {
 sum += marks[i];
 }
 printf("Sum of all scores: %d", sum);
 return 0;
}