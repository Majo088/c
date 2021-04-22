#define MINA_ENCONTRADA 1
#define ESPACIO_YA_DESCUBIERTO 2
#define NINGUNO 3

#define COLUMNAS 10
#define FILAS 10
#define ESPACIO_SIN_DESCUBRIR '#'
#define ESPACIO_DESCUBIERTO '*'
#define MINA 'X'
#define CANTIDAD_MINAS \
  6  
  void colocarMinasAleatoriamente(char tablero[FILAS][COLUMNAS]);
