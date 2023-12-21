#include <stdio.h>
int main()
{
  int n, i, j;
  printf("Enter the number of data points: ");
  scanf("%d", &n);
  double x[n], y[n][n];
  printf("Enter the data points:\n");
  for (i = 0; i < n; i++)
  {
    printf("X%d = ", i + 1);
    scanf("%lf", &x[i]);
    printf("Y%d = ", i + 1);
    scanf("%lf", &y[i][0]);
  }
  for (j = 1; j < n; j++)
  {
    for (i = 0; i < n - j; i++)
    {
      y[i][j] = y[i + 1][j - 1] - y[i][j - 1];
    }
  }
  printf("\nForward Difference Table:\n");
  for (i = 0; i < n; i++)
  {
    printf("%.2lf\t", x[i]);
    for (j = 0; j < n - i; j++)
    {
      printf("%.2lf\t", y[i][j]);
    }
    printf("\n");
  }
  double target_x;
  printf("\nEnter the value of x for interpolation: ");
  scanf("%lf", &target_x);
  double result = y[0][0];
  double u = (target_x - x[0]) / (x[1] - x[0]);
  double term = 1.0;
  for (i = 1; i < n; i++)
  {
    term = term * (u - i + 1) / i;
    result = result + term * y[0][i];
  }
  printf("Interpolated value at x = %.1lf is %.4lf\n", target_x, result);
  return 0;
}
int factorial(int n)
{
  if (n == 0)
  {
    return 1;
  }
  else
  {
    return n * factorial(n - 1);
  }
}
