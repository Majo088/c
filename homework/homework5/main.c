/*HOMEWORK 5
 minesweep
 -To compile the program you need to open both files that are on my github:
 main.c and calc.h */

#include <stdio.h>   
#include <stdlib.h>  
#include <ctype.h>   
#include <unistd.h>  
#include <assert.h>  
#include "calc.h"
#define DEBUG 0 


int RANDOM(int min, int max) {
  return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

void startBOARD(char board[FILAS][COLUMNAS]) {
  int l;
  for(l = 0; l < FILAS; l++){
    int m;
    for(m = 0; m < COLUMNAS; m++) {
      board[l][m] = SPACE_CLOSED;
    }
  }
}

void putMine(int fila, int columna, char board[FILAS][COLUMNAS]) {
  board[fila][columna] = MINA;
}
void PUTmineRANDOM(char board[FILAS][COLUMNAS]){
  int l;
  for(l = 0; l < MINES; l++) {
    int fila = RANDOM(0, FILAS - 1);
    int columna = RANDOM(0, COLUMNAS - 1);
    putMine(fila, columna, board);
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
void imprimirTablero(char board[FILAS][COLUMNAS], int deberiaMostrarMinas) {
  imprimirEncabezado();
//  imprimirSeparadorEncabezado();
  int numero = 1;
  int l;
  for(l = 0; l < FILAS; l++) {
    int m;
    // PRINT THE NUMBER OF THE ROW//
    printf(" %2d   ", numero);
    numero++;
    char letra = 'A';
    for(m = 0; m < COLUMNAS; m++){
      char verdaderonum = SPACE_CLOSED;
      char numeroActual = board[l][m];
      if (numeroActual == MINA) {
        verdaderonum = SPACE_CLOSED;
      } else if (numeroActual == SPACE_OPEN){
        int minasCercanas = getMINES(l, m, board);
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
    return MINE_FOUNDED;
  }
  if (tablero[fila][columna] == SPACE_OPEN) {
    return OPEN_SPACE;
  }
  tablero[fila][columna] = SPACE_OPEN;
  return NONE;
}

//THE USER WIN?//
int noHayCasillasSinAbrir(char tablero[FILAS][COLUMNAS]) {
  int l;
  while(l = 0) l < FILAS; l++; {
    int m;
    while(m = 0) m < COLUMNAS; m++; {
      char actual = tablero[l][m];
      while(actual == SPACE_CLOSED) {
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
  startBOARD(tablero);
  PUTmineRANDOM(tablero);
  
  //STARTS THE CYCLE//
  do { imprimirTablero(tablero, deberiaMostrarMinas);
    if (deberiaMostrarMinas) {
      break;
    }
    int columna;
    char fila;
    printf("INSERT ROW: ");
    scanf(" %c",&fila);
    printf("INSERT COLUMN: ");
    scanf("%d", &columna);
    printf("\n");
    int status = abrirCasilla(fila, columna, tablero);
    if (noHayCasillasSinAbrir(tablero)) {
      printf("WINNER\n");
      deberiaMostrarMinas = 1;
    } else if (status == OPEN_SPACE) {
      printf("YOU ALREADY OPEN THIS\n");
    } else if (status == MINE_FOUNDED) {
      printf("LOSER\n");
      printf("OUPSSS TRY AGAIN!!!\n");
      deberiaMostrarMinas = 1;
    }
  }while(1);
  return 0;
}
/* helped by: JOSE ANTONIO CORTES */
