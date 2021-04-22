/*HOMEWORK 5
 minesweep*/

#include <stdio.h>   
#include <stdlib.h>  
#include <ctype.h>   
#include <unistd.h>  
#include <assert.h>  
#include "calc.h"
  
#define DEBUG 0  // if you want to know where the mines are change the 0 to a 1//

int obtenerMinasCercanas(int fila, int columna, char tablero[FILAS][COLUMNAS]) {
  int conteo = 0, filaInicio, filaFin, columnaInicio, columnaFin;
  if (fila <= 0) {
    filaInicio = 0;
  } else {
    filaInicio = fila - 1;
  }

  if (fila + 1 >= FILAS) {
    filaFin = FILAS - 1;
  } else {
    filaFin = fila + 1;
  }

  if (columna <= 0) {
    columnaInicio = 0;
  } else {
    columnaInicio = columna - 1;
  }
  if (columna + 1 >= COLUMNAS) {
    columnaFin = COLUMNAS - 1;
  } else {
    columnaFin = columna + 1;
  }
  int m;
  for (m = filaInicio; m <= filaFin; m++) {
    int l;
    for (l = columnaInicio; l <= columnaFin; l++) {
      if (tablero[m][l] == MINA) {
        conteo++;
      }
    }
  }
  return conteo;
}

int aleatorioEnRango(int minimo, int maximo) {
  return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}

void iniciarTablero(char tablero[FILAS][COLUMNAS]) {
  int l;
  for (l = 0; l < FILAS; l++) {
    int m;
    for (m = 0; m < COLUMNAS; m++) {
      tablero[l][m] = ESPACIO_SIN_DESCUBRIR;
    }
  }
}

void colocarMina(int fila, int columna, char tablero[FILAS][COLUMNAS]) {
  tablero[fila][columna] = MINA;
}
void colocarMinasAleatoriamente(char tablero[FILAS][COLUMNAS]){
  int l;
  for (l = 0; l < CANTIDAD_MINAS; l++) {
    int fila = aleatorioEnRango(0, FILAS - 1);
    int columna = aleatorioEnRango(0, COLUMNAS - 1);
    colocarMina(fila, columna, tablero);
  }
}
//LETTERS AT THE TOP//
void imprimirEncabezado() {
  printf("      ");
  char letra = 'A';
  int l;
  for (l = 0; l < COLUMNAS; l++) {
    printf(" %c ", letra);
    letra++;
  }
  printf("\n");
}
int imprimirEncabezadoSeparado(){
printf("|   ");
  int l;
  for (l = 0; l < COLUMNAS; l++) {
    printf("| %c ", l + 1);
    if (l + 1 == COLUMNAS) {
      printf("|");
    }
  }
  return 0;
}

char enteroACaracter(int numero) {
  return numero + '0';
}
//INCLUDE NUMBERS ON THE COLUMN//
void imprimirTablero(char tablero[FILAS][COLUMNAS], int deberiaMostrarMinas) {
  imprimirEncabezado();
//  imprimirSeparadorEncabezado();
  int numero = 1;
  int l;
  for (l = 0; l < FILAS; l++) {
    int m;
    // PRINT THE NUMBER OF THE ROW//
    printf(" %2d   ", numero);
    numero++;
    char letra = 'A';
    for (m = 0; m < COLUMNAS; m++) {
      char verdaderonum = ESPACIO_SIN_DESCUBRIR;
      char numeroActual = tablero[l][m];
      if (numeroActual == MINA) {
        verdaderonum = ESPACIO_SIN_DESCUBRIR;
      } else if (numeroActual == ESPACIO_DESCUBIERTO) {
        int minasCercanas = obtenerMinasCercanas(l, m, tablero);
        verdaderonum = enteroACaracter(minasCercanas);
      }
      if (numeroActual == MINA && (DEBUG || deberiaMostrarMinas)) {
        verdaderonum = MINA;
      }   
        printf(" %c ", verdaderonum);
    }
    printf("\n");
//    imprimirSeparadorFilas();
  }
}


int abrirCasilla(char filaLetra, int columna, char tablero[FILAS][COLUMNAS]) {
  filaLetra = toupper(filaLetra);// TOUPPER- UPPER CASE LETTER//
  
  columna--;

  int fila = filaLetra - 'A';
  assert(columna < COLUMNAS && columna >= 0);
  assert(fila < FILAS && fila >= 0);
  if (tablero[fila][columna] == MINA) {
    return MINA_ENCONTRADA;
  }
  if (tablero[fila][columna] == ESPACIO_DESCUBIERTO) {
    return ESPACIO_YA_DESCUBIERTO;
  }
  tablero[fila][columna] = ESPACIO_DESCUBIERTO;
  return NINGUNO;
}

//THE USER WIN?//
int noHayCasillasSinAbrir(char tablero[FILAS][COLUMNAS]) {
  int l;
  for (l = 0; l < FILAS; l++) {
    int m;
    for (m = 0; m < COLUMNAS; m++) {
      char actual = tablero[l][m];
      if (actual == ESPACIO_SIN_DESCUBRIR) {
        return 0;
      }
    }
  }
  return 1;
}

int main() {
    printf("WELCOME TO MINESWEEPER GAME, LETS GET STARTED\n RULES OF THE GAME:\n YOU CANNOT FIND THE MINES OR YOU LOOSE \n BE VERY CAREFULL \n HAVE FUN \n ");
  char tablero[FILAS][COLUMNAS];
  int deberiaMostrarMinas = 0;
  // feed rand
  srand(getpid());
  iniciarTablero(tablero);
  colocarMinasAleatoriamente(tablero);
  
  //STARTS THE CYCLE//
  while (1) {
        imprimirTablero(tablero, deberiaMostrarMinas);
    if (deberiaMostrarMinas) {
      break;
    }
    int columna;
    char fila;
    printf("INSERT ROW: ");
    scanf(" %c", &fila);
    printf("INSERT COLUMN: ");
    scanf("%d", &columna);
    printf("\n");
    int status = abrirCasilla(fila, columna, tablero);
    if (noHayCasillasSinAbrir(tablero)) {
      printf("WINNER\n");
      deberiaMostrarMinas = 1;
    } else if (status == ESPACIO_YA_DESCUBIERTO) {
      printf("YOU ALREADY OPEN THIS\n");
    } else if (status == MINA_ENCONTRADA) {
      printf("LOSER\n");
      printf("OUPSSS TRY AGAIN!!!\n");
      deberiaMostrarMinas = 1;
    }
  }
  return 0;
}
/* references: JOSE ANTONIO CORTES and https://parzibyte.me/blog/2020/06/08/buscaminas-c-juego/ */
