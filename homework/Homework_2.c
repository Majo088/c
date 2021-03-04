#include<stdio.h>
#include<math.h>

#define M 15
char*prime(int n);
char*binary(int j);

int main(void)
{
   prime(M);
}


char*binary(int j)
{
    int i=0;

    int a[6]={0};

    while(j>0)
    {
a[i]= j % 2;
j /= 2;
++i;
    }

for(int x=5; x >= 0 ; -- x)
    {
printf("%1d",a[x]);
    }
printf("\n");
}

//start of the prime numbers//
char*prime(k)
{
  int count, i, is, sr;
  int n=1;
  count = 1;

  do{
    sr = sqrt(n);
    is = 0;
    for(i=2; i<= sr; i++){
      if(n % i == 0){
        is = 1;
        break;
      }

    }

    if(is == 0){

      binary(n);
      count++;
    }

    n++;

  } while(count <= M);

  return 0;

}
//references: Youtube videos
//inspired by Angel Raul on the array form
