#include <stdio.h>
    /*printf("Hello World\n");
    return 0;*/
 int main ()
{
 double fahr, celsius;
 double lower, upper, step;

 lower= 0;
 upper= 300;
 step= 20;

 fahr= lower;
 while(fahr<=upper){
        celsius = 5 * (fahr-32) / 9;
        printf("%.2lf\t%.2lf\n", fahr,celsius);
        fahr= fahr + step;
        }

  return 0;
}

