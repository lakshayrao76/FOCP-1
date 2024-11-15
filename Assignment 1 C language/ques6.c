//WAP to accept a coordinate point in an XY coordinate system and determine in which quadrant the coordinate point lies.
#include <stdio.h>

int main() {
    int x, y;
    printf("Enter the x coordinate: ");
    scanf("%d", &x);
    printf("Enter the y coordinate: ");
    scanf("%d", &y);
    
    if (x > 0 && y > 0) {
        printf("The coordinate point (%d, %d) lies in the First quadrant.\n", x, y);
    } else if (x < 0 && y > 0) {
        printf("The coordinate point (%d, %d) lies in the Second quadrant.\n", x, y);
    } else if (x < 0 && y < 0) {
        printf("The coordinate point (%d, %d) lies in the Third quadrant.\n", x, y);
    } else if (x > 0 && y < 0) {
        printf("The coordinate point (%d, %d) lies in the Fourth quadrant.\n", x, y);
    } else if (x == 0 && y == 0) {
        printf("The coordinate point (%d, %d) lies at the origin.\n", x, y);
    } else if (x == 0) {
        printf("The coordinate point (%d, %d) lies on the Y-axis.\n", x, y);
    } else if (y == 0) {
        printf("The coordinate point (%d, %d) lies on the X-axis.\n", x, y);
    }
    
    return 0;
}
