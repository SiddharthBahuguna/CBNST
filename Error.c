#include <stdio.h>
#include <math.h>
double round1(double num) {
 double value = (int)(num * 10000 + 0.5);
 return (double)value / 10000;
}
double truncate1(double num) {
 double value = (int)(num * 10000);
 return (double)value / 10000;
}
int main() {
 double x;
 printf("\nEnter the value of x: ");
 scanf("%lf", &x);
 double r = round1(x);
 double t = truncate1(x);
 printf("%lf %lf\n", r, t);
 printf("\nThe Absolute Error of Round-off value is: %lf\n", fabs(x - r));
 printf("\nThe Relative Error of Round-off value is: %lf\n", fabs((x - r) / x));
 printf("\nThe Percentage Error of Round-off value is: %lf %%\n", fabs((x - r) / x) * 
100);
 printf("\nThe Absolute Error of Truncate value is: %lf\n", fabs(x - t));
 printf("\nThe Relative Error of Truncate value is: %lf\n", fabs((x - t) / x));
 printf("\nThe Percentage Error of Truncate value is: %lf %%\n", fabs((x - t) / x) * 100);
return 0;
}