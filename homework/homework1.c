#include <stdio.h>
#include <ctype.h>

int main(){

    char BOLD[13]={"strong/strong"};
    char change[13]={"script/script"};

int c;
int space = 0;

   do{
        if(c == '<')
        {
            while((c = getchar()) == BOLD[space]){// from here :inspired in Angel David's program
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
    while((c = getchar()) != '>')
    {;
    // to here : inspired in Angel David's program
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
    if(isspace(c))
 {
    putchar('_');
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
