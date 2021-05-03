#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *archivo;
    char caracter;
    
    archivo= fopen("datos.txt","r");
    if(archivo==NULL){
        printf("ERROR\n");
    }else{
        printf("data: \n");
        while(feof(archivo)==0){
            
            caracter=fgetc(archivo);
            printf("%c",caracter);
        }
    }
}