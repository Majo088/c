#include <stdio.h>
#include <conio.h>

struct registro{
    char nombre [20];
    int matricula;
}est;

void main(){
    printf("nombre: ");
    gets(est.nombre);
    
printf("matricula: ");
scanf("%d", &est.matricula);

FILE*ptr;
ptr=fopen("work.txt", "a+");

if(ptr==NULL){
    printf("no se pudo crear");
    
    return;
}
fwrite(&est, sizeof(est),1,ptr);
printf("los datos se guardaron");
fclose(ptr);

getch();

}