#include <stdio.h>

int main() {
    int n;


    printf("Enter the number of students: ");
    scanf("%d", &n);

    
    int marks[n];
    int sum = 0;

   
    printf("Enter the marks of %d students:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Student %d: ", i + 1);
        scanf("%d", &marks[i]);
        sum += marks[i];  
    }

    float average = (float)sum / n;

    
    printf("\nThe average score of the students is: %.2f\n", average);

    return 0;
}
