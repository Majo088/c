#include <stdio.h>
#include <ctype.h> // library for "isspace"

int main(){

    char BOLD[13]={"strong/strong"};
    char change[13]={"script/script"};

int c; //where the info will be save
int space = 0;

   do{ //starts the loop
        if(c == '<')
        {
            while((c = getchar()) == BOLD[space]){
                space++;
            }
            if(c == change[1]){
                c = getchar();
            if(c == change[2]){
                    c = getchar();
            if (c == change[3]){
                        while ((c = getchar()) != '>'){
                            ;
                        }
    while((c = getchar()) != '>'){;
    }
    }
    }
    }
    if(space == 13)
 {
    space = 0;
 }
    while(c != EOF && c != '>')
 {
    c = getchar();
 }
 }
        else if (space == 6 && space < 13)
 {
    if(isspace(c)) //example of the book
 {
    putchar('_'); //if theres the space put the '_'
    c = getchar();
 }
            putchar(c);
 }
if ((space != 6 && c != '<' && c != '>') || c == '\0')
    {
    putchar(c);

            space = 0;
 }
 }while((c = getchar()) != EOF);

 return 0;
 }

 //helped by Angel David and example of the class of the spaces
