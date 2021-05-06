/*Para compilar el programa meter todos los archivos que estan en mi repo:
-info.h
-new.txt
-worker.txt
-asistencia.txt
-registro.txt
-report.txt
ya compilado saldra la consola con el menu principal donde eligiras un numero. Cada que agregues a una persona 
saldra su reporte en report.txt y su informacion en new.txt, para tomar asistencia (opcion numero 2) mete uno de los numeros que estan
en worker.txt y saldra su asistencia en asistencia.txt, en registro.txt y en report.txt*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "info.h"

int count(){
FILE* syste = fopen("new.txt", "r");
char c;
int count=0;
    while ((c = fgetc(syste)) != EOF) {
    if (c == '\n') {
count++; 
    }
    }
    
return count;
}
//HOUR//
void horario(){
    time_t tiempoahora;
    time(&tiempoahora);
    printf("Ingreso: %s\n\n", ctime(&tiempoahora));
}
//START OF THE PROGRAM//
int main(int x, char** y) 
{
  int k, i = 0;
  char pin[NAME + 1]; 
  char pin2[NAME + 1]; 
  char trabajador[Work + 1];
time_t tiempoahora;
time(&tiempoahora);
 FILE* entrada= fopen("worker.txt","r");

  printf("--START MENU--\n");
  printf("[1] New worker\n");
  printf("[2] Register your entry\n");
  printf("[3] Close\n");
  printf("Insert the number: ");
  scanf("%d",&op);
  
 if(op==1){
      new();
  }
  if(op==2){
      
  printf ("Put yuour ID number:");
  scanf("%s",pin2);
 
  fscanf(entrada, "%s %s \n", pin,trabajador);
   if (pin, pin2 !=0){
    printf("%s arrived\n",trabajador);
    
FILE* registro = fopen("registro.txt", "a\n");
    fprintf(registro, "check: %s",trabajador);
    //horario();
    asistence();
FILE* reportes = fopen("report.txt","a");
fprintf(reportes,"The report of %s entered at: %s\n\n", trabajador,ctime(&tiempoahora));
  }
  }
   fclose(entrada);
    return 0; 
 }

//NEW USER//
void new(){
    
time_t tiempoahora;
time(&tiempoahora);
    int pin;
    pin=count()+1;
    char user[MAX];
    int domingo,lunes,martes, miercoles, jueves, viernes, sabado;
    int hora, min;
    int trabajo;
    
    printf("The users pin will be (%d)\n", pin);
    registrados++;
    printf("Entry the workers name: \n");
    scanf("%s", user);
    
    printf("succesful register, welcome\n\n");
    do{
        printf("\nWrite 1 (work) y 0 (free) the days that the employee will work\nthere must be min a 1\n");
        printf("Sun Mon Tue Wed Thu Fri Sat\n");
        scanf("%d %d %d %d %d %d %d", &domingo, &lunes, &martes, &miercoles, &jueves, &viernes, &sabado);
    } while(domingo+lunes+martes+miercoles+jueves+viernes+sabado==0);
    
    do {
        printf("\nWrite the hour and minute that it will work:\n");
        scanf("%d:%d", &hora, &min);
    } while(hora<0||hora>23||min<0||min>60);
        
    printf("Register complete\n\n");
    
    
    FILE* nuevous = fopen("new.txt", "a");
    fprintf(nuevous," id and name: %d %s \n",pin, user);
    fprintf(nuevous, "days of the week: %d %d %d %d %d %d %d\n",domingo, lunes,martes,miercoles,jueves,viernes,sabado);
    fprintf(nuevous, "hour: %d %d %d\n", hora, min, trabajo);
    fclose(nuevous);
    
FILE* reportes = fopen("report.txt","a");
fprintf(reportes,"The report of %s entered at: %s\n\n", user,ctime(&tiempoahora));
}
//Asistance list//
void asistence(int pin, int t){///estado es es 0 es entrada 1 salida
    printf("Your asistence is complete\n");
    int diferencia=0; ///El trabajador con el pin <X> trabajo diferencia segundos
    time_t tiempoahora;
    time(&tiempoahora);
    
struct tm *mitiempo = localtime(&tiempoahora);
int actualsec=mitiempo->tm_sec;
int actualmin=mitiempo->tm_min;
int actualhora=mitiempo->tm_hour;
int actualyear=mitiempo->tm_year+1900;
int actualmes=mitiempo->tm_mon+1;
int actualdia=mitiempo->tm_mday;
int actualwdia=mitiempo->tm_wday;
    
 
    FILE* registro = fopen("asistencia.txt", "a");
    fprintf(registro, "%d %d/%d/%d %d:%d:%d\n",pin,actualwdia, actualdia, actualmes, actualyear, actualhora, actualmin, actualsec);
    fclose(registro);
}


//en colaboracion con Angel Raul y Daniela Rodriguez
