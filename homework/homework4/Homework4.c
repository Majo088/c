/*Homework 4 references: book; ANSCI and Raul Chavez*/

#include <stdio.h>
#include <stdlib.h> //for atof()//
#include <ctype.h> //tolower//
#include "archivo.h"

#define MAXOP 100 //max size of operand or operator //

/* reverse Polish calculator */
int main()
{
    int type;
    int c_letters=0; // cantidad de letras//
    int c_numbers=0; // cantidad de numeros//
    int c_mistakes=0; //cantidad de errores//

    double op2;
    char s[MAXOP];
    int letter_founded=0;
    int question=0;
    int asignacion=0;
    int n_found =0;
    int move=0;
    int answer_yes=0;
    int answer_no=0;
    int error=0;

    int abc[27]={0}; //abc letters//
    int contador[27]={0}; //los espacios a utilizar//

      printf("insert your variable and the number (ej: a = number): ");

     while ((type = getop(s)) != EOF) {
        if (move==0) {
        switch (tolower(type)) {
            case NUMBER:
            push(atof(s));
            n_found = atof(s);
            c_numbers++;
            break;
            case '+':
            push(pop() + pop());
            break;
            case '*':
            push(pop() * pop());
            break;
            case '-':
            op2 = pop();
            push(pop() - op2);
            break;
            case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");

            break;
            case '\n':
            if (!asignacion&&!question){ 
            printf("\t%.2f\n", pop());
            // Volvemos a valores iniciales
            asignacion=0;
            letter_founded=0;
            question=0;
            n_found =0;
            c_numbers=0;
            c_letters=0;
            c_mistakes=0;
            }
    else if (asignacion==1&&!question&&c_numbers==1&&c_letters==1){ 
            if (contador[letter_founded]==0){
                abc[letter_founded]=n_found;
                printf("Asign done\n");
                contador[letter_founded]++;
            
                asignacion=0;
                letter_founded=0;
                question=0;
                pop();
                pop();
                n_found=0;
                c_numbers=0;
                c_letters=0;
                c_mistakes=0;

            }

    else{

                move=1;
                printf("Do you want to rewrite the letter? YES-> y NO-->n\n");
                pop();
                pop();
            }
            }// Hay signo de = pero no de :

    else if (asignacion==1&&question==1&&c_numbers==1&&c_letters==1){
                abc[letter_founded]=n_found;
                pop();
                pop();
                printf("Asign done\n");
                contador[letter_founded]++; //AUMENTA EL CONTADOR AL HACER UNA ASIGNACION
                // Volvemos a valores iniciales
                asignacion=0;
                letter_founded=0;
                question=0;
                n_found=0;
                c_numbers=0;
                c_letters=0;
                c_mistakes=0;
            }
    else{
                printf("error: check your input\n");
                asignacion=0;
                letter_founded=0;
                question=0;
                n_found=0;
                c_numbers=0;
                c_letters=0;
                pop();
                pop();
                c_mistakes=0;
            }

            break;
            case '=':
            asignacion=1;
            break;
            case ':':
            question=1;
            break;
            default:
            if (type>=97&&type<=122){
                push(abc[type-97]);
                letter_founded=type-97;
                c_letters++;

            }
            else {
            c_mistakes++;
            printf("error: unknown command %s\n", s);
            }
            break;
        }

     }

     else {

     switch (tolower(type)) {
     case 'y':
     answer_yes++;
     push(0); 
     break;
     case 'n':
     answer_no++;
     push(0); 
     break;
     case '\n':

     if (answer_yes==1&&answer_no==0&&error==0){
        abc[letter_founded]=n_found;
        pop();
        printf("Asign done\n");

        contador[letter_founded]++;
       
        asignacion=0;
        letter_founded=0;
        question=0;
        n_found=0;
        answer_no=0;
        answer_yes=0;
        error=0;
        move=0;
        c_numbers=0;
        c_letters=0;
        c_mistakes=0;

     }
     else if (answer_yes==0&&answer_no==1&&error==0){
        pop();
        printf("You didnt make an asignation\n");
       
        asignacion=0;
        letter_founded=0;
        question=0;
        n_found=0;
        answer_no=0;
        answer_yes=0;
        move=0;
        error=0;
        c_numbers=0;
        c_letters=0;
        c_mistakes=0;

     }
     else{
        pop();
        printf("error: Check your input\n\n");
        printf("Do you want to rewrite the variable? y -> YES n->NO");
        answer_no=0;
        answer_yes=0;
        error=0;
        c_numbers=0;
        c_letters=0;
        c_mistakes=0;
     }
     break;
     default:
     error++;
     break;
     }
     }
    }
    return 0;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f)
{
    if(sp < MAXVAL)
        val[sp++]=f;
    else
        printf("error:stack full, cant push %g\n",f);
}

double pop(void)
{
    if(sp>0)
        return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

#include<ctype.h>


int getop(char s[])
{
    int i,c;

    while((s[0] = c = getch()) == ' ' || c =='\t')
        ;
    s[1] = '\0';

    i = 0;
    if(!isdigit(c) && c!='.' && c!='-'){
        if (!isalpha(c))
        return c;
        if (isalpha(c)){
        return tolower(c);
        }

    }

    if(c=='-')
        if(isdigit(c=getch()) || c == '.')
            s[++i]=c;
        else
        {
            if(c!=EOF)
                ungetch(c);
            return '-';
        }

    if(isdigit(c))
        while(isdigit(s[++i] =c =getch()))
            ;

    if(c=='.')
        while(isdigit(s[++i] = c=getch()))
            ;

    s[i] = '\0';
    if(c!=EOF)
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if(bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
