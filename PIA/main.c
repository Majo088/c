/*INSTRUCTIONS TO COMPILE THE PROGRAM:
-Put on the GDB online compiler the files that are on my repository:
    -main.c 
    -file.h 
    -info.txt
    -clientinfo.txt
    -available.txt
-click "run" to start the program and insert the number of the function that you want to do (select a number 
between 1-5*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "file.h"
 
//hour
void horario(){
time_t tiempoahora;
time(&tiempoahora);
struct tm*mitiempo= localtime(&tiempoahora);
int actualdia=mitiempo->tm_mday;
printf("Registered at: %s\n\n", ctime(&tiempoahora));
}
  int main(){
      
do{   
  printf("--START MENU--\n");
  printf("---WELCOME TO SUNCITY MALL RENTS---\n");
  printf("[1] Information\n");
  printf("[2] Registration of a new client\n");
  printf("[3] available establishments\n");
  printf("[4] My information\n");
  printf("[5] close the program\n");
  
  printf("Insert the number: ");
  scanf("%d",&op);
  if(op>5){
      printf("Insert a number between 1-5!!\n");
  }
  if(op==1){
info();
  }
  
  if(op==2){
newclient();      
  }
  
  if(op==3){
available();  
  }
  
  if(op==4){
      myin();
  }
  if(op==5){
      printf("Have a nice day!");
  }
  }while(op !=5);
  
 }
  
void newclient(){
time_t tiempoahora;
time(&tiempoahora);
    int establishment;
    char gender;
    int age;
    int day;
    int month;
    int year;
    
printf("Introduce your name: ");
scanf("%s",name);
printf("Introduce your age: ");
scanf("%d",&age);
printf("Gender M or F: ");
scanf("%s",&gender);

do
    {
      printf ("Which establishment you are going to be renting: ");
      scanf ("%d", &establishment);

      if (establishment %2== 0)
	{
	  printf ("its available\n");
	}
      if (establishment %3== 0)
	{
	  printf ("its not available try again\n");
	}
    }
  while (establishment %3== 0);
 horario();

  printf ("YOU HAVE BEEN REGISTER\n");
  FILE *client = fopen ("clientinfo.txt", "a+");
  fprintf (client, "NAME: %s\nAGE: %d\nGENDER: %c\nESTABLISMENT: %d\nREGISTERED AT: %s", name,
	   age, gender, establishment,ctime(&tiempoahora));
  fclose (client);
}
  
void info(){
       char line[MAX];
      printf("REMAINDER: The contracts last for 2 moths\n");
       FILE*fpointer =fopen("info.txt","r");
//This part was taken from a youtube tutorial (link in my github)
    while(!feof(fpointer)){
    fgets(line, MAX, fpointer);
    printf("%s",line);
    }
      fclose(fpointer);
//untill here
  }
  
void available(){
  char line[MAX];
       
    FILE*months =fopen("available.txt","r");
//This part was taken from a youtube tutorial (link in my github)
    while(!feof(months)){
    fgets(line, MAX, months);
    printf("%s",line);
    }
      fclose(months);
//untill here
  }
  
 void myin(){
int d;
int m;
int a;
int cantmax(int m, int a);

printf("Insert your name: ");
scanf("%s",name);
printf("Insert your establishment: ");
scanf("%d",&establishment);

printf("Day of your register: ");
scanf("%d",&d);
printf("Month: ");
scanf("%d",&m);
printf("year: ");
scanf("%d",&a);

d=1;
m++;
if(m++){
//The day that it will appear will be 1st of each 2 months 
    printf("The day that expires your contract is in: %d/%d/%d\n",d,m,a);
}
}
  