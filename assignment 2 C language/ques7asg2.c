//WAP to check whether score is even or odd in an array.
#include <stdio.h>

int main() {
    int n;

    
    printf("Enter the number of students: ");
    scanf("%d", &n);

    
    int marks[n];

    
    printf("Enter the marks of %d students:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Student %d: ", i + 1);
        scanf("%d", &marks[i]);
    }

    
    printf("\nResult of checking even or odd marks:\n");
    for (int i = 0; i < n; i++) {
        if (marks[i] % 2 == 0) {
            printf("Student %d's score %d is Even.\n", i + 1, marks[i]);
        } else {
            printf("Student %d's score %d is Odd.\n", i + 1, marks[i]);
        }
    }

    return 0;
}
