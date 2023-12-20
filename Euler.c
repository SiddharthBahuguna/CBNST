#include <stdio.h>
#include <math.h>

double f(double x, double y)
{
  return (y - x) / (y + x);
}
main()
{
  int i;
  double y, xi, yi, xf, h;
  printf("Enter the initial condition for y: ");
  scanf("%lf", &yi);
  printf("Enter the initial condition for x: ");
  scanf("%lf", &xi);
  printf("Enter the value of x for which y is required: ");
  scanf("%lf", &xf);
  printf("Enter the step-width h: ");
  scanf("%lf", &h);
  printf("x\t\ty\n");

  while (xi < xf)
  {
    y = yi + h * f(xi, yi);
    printf("%lf\t%lf\n", xi, yi);
    yi = y;
    xi = xi + h;
  }
  printf("%lf\t%lf\n", xi, yi);

  printf("The value of y is %lf\n\n", y);
}
