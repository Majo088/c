#include <stdio.h>
#define IN 1
#define OUT 0

int main() {
  int i, w = 0, o = 0;
  int d[10];
  char c;

  for (i = 0; i < 10; i++) {//condicion
    d[i] = 0; // inicia en 0 porque es un array
  }
  while ((c = getchar()) != EOF) {
    if (c >= '0' && c <= '9') {
      i =  c - '0'; // indice
      d[i] += 1; // "+" es incremento
    } else if (c == ' ' || c == '\t' || c == '\n') {
      w++;//incremento de W 
    } else {
      ++o;
    }
  }
  for (i = 0; i < 10; i++) {
    printf("%d of %d\n", d[i], i);
  }
  printf("%d spaces and %d other characters\n", w, o); // como se va a ver al momento de imprimir
  return 1;
}

