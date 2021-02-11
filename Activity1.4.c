#include <stdio.h>

 int main ()
{
 double fahr, celsius;
 double lower, upper, step;

 lower= 0;
 upper= 300;
 step= 20;

 celsius = lower;
 while(celsius<=upper){
        fahr = ((9 * celsius) / 5) + 32;
        printf("%.2lf\t%.2lf\n", celsius,fahr);
        celsius = celsius + step;
        }

  return 0;
}

