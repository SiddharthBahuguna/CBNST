#include <stdio.h>
#include <math.h>
double f(double x, double y)
{
  return x;
}
main()
{
  int i;
  double x, y, x0, y0, h, k1, k2, k3, k4;
  printf("Enter the initial condition for y: ");
  scanf("%lf", &y0);
  printf("Enter the initial condition for x: ");
  scanf("%lf", &x0);
  printf("Enter the value of x for which y is required: ");
  scanf("%lf", &x);
  printf("Enter the step-width h: ");
  scanf("%lf", &h);
  printf("x\t\ty\t\n");

  while ((x - x0) > 0.0000000001)
  {
    k1 = h * f(x0, y0);
    k2 = h * f(x0 + h / 2.0, y0 + k1 / 2.0);
    k3 = h * f(x0 + h / 2.0, y0 + k2 / 2.0);
    k4 = h * f(x0 + h, y0 + k3);
    printf("%lf\t%lf\n", x0, y0);
    y = y0 + 1 / 6.0 * (k1 + 2 * k2 + 2 * k3 + k4);
    y0 = y;
    x0 = x0 + h;
  }
  printf("%lf\t%lf\n", x0, y0);

  printf("The value of y is %lf\n\n", y);
}
