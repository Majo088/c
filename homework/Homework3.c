#include <stdio.h>
#include <ctype.h>

#define IN 1
#define OUT 0

int main() { //variables that we will use
  int c;
  int number = OUT;
  int signs = OUT; // signs like , // () .
  int quotes = OUT; // " " , ' '

  do{ // start of the do-while loop
      switch(c){ // using switch loop to get a better view on the cases

      case '[':
          signs = IN;
          putchar(c);
          break;

      case ']':
          signs = OUT; // out of the ']'
          putchar(c);
          break;

      case '(':
          signs = IN;
          putchar(c);
          break;

      case ')':
          signs = OUT;
          putchar(c);
          break;

      case '{':
          signs = IN;
          putchar(c);
          break;

      case '}':
          signs = OUT;
          putchar(c);
          break;

      case '<':
          signs = IN;
          putchar(c);
          break;

      case '>':
          signs = OUT;
          putchar(c);
          break;

      case '\"':
          putchar(c);
          quotes++;
          break;

       case '\'':
          putchar(c);
          quotes++;
          break;

      default:
        if(c!='.'&&c!=','){ // if it appears any of these signs

            if (signs == IN||quotes==IN) // if there are signs and quotes
            {
            putchar(c);
            }
            else{
                if (quotes == 2){
                    quotes = 0;
                }
                if (isdigit(c)) // if we enter any of these numbers
                    {
                    number++;
                }else {
                  number=0;
                }
                if(number==1){
                    putchar('X');
                }
                if (number==0){
                    putchar(c);
                }
            }
        }
      }
    }while((c = getchar()) != EOF); // end of the  do-while loop
    return 0; //end of the program
  }
  /* references: Angel Raul program, youtube videos and Hector Mtz*/

