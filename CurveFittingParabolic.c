#include <stdio.h>
#include <math.h>

void parabolicCurveFit(int n, double x[], double y[])
{
  double sum_x = 0.0, sum_x2 = 0.0, sum_x3 = 0.0, sum_x4 = 0.0, sum_y = 0.0, sum_xy = 0.0, sum_x2y = 0.0;

  for (int i = 0; i < n; ++i)
  {
    double xi = x[i];
    double yi = y[i];

    sum_x += xi;
    sum_x2 += xi * xi;
    sum_x3 += xi * xi * xi;
    sum_x4 += xi * xi * xi * xi;
    sum_y += yi;
    sum_xy += xi * yi;
    sum_x2y += xi * xi * yi;
  }

  double denominator = (n * sum_x2 - sum_x * sum_x);
  if (denominator == 0)
  {
    printf("Error: Division by zero!\n");
    return;
  }

  double a = (sum_x2y - sum_x * sum_xy) / denominator;
  double b = (n * sum_xy - sum_x * sum_y) / denominator;
  double c = (sum_y - b * sum_x - a * sum_x2) / n;

  printf("Parabolic curve equation: y = %.4f*x^2 + %.4f*x + %.4f\n", a, b, c);
}

int main()
{
  int n;

  printf("Enter the number of data points: ");
  scanf("%d", &n);

  double x[n], y[n];

  printf("Enter the data points (x y):\n");
  for (int i = 0; i < n; ++i)
  {
    scanf("%lf %lf", &x[i], &y[i]);
  }

  parabolicCurveFit(n, x, y);

  return 0;
}
