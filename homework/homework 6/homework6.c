/*TO COMPILE THE PROGRAM PUT BOTH FILES THAT ARE ON MY GITHUB
-majo.h and binary.c
then to start the program start by adding a user:
add ....
to delete a user:
delete user + password
to show the data:
show...*/

#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

#include"majo.h"

#define LIM 100


int main() {
	
	node* n = NULL;
	node* tree = NULL; 
	
int a = 0, b = 0, count = 0;
char c;
char username[LIM];
char password[LIM];
char line[LIM];
char type[LIM];
	
 while(1) {
	a = 0, b = 0;
	do{
	line[a++] = c;
	if(isspace(c))
		count++;
	}while((c = getchar()) != EOF && c != '\n');
		
    line[a] = '\0';
	
	if(count >= 2) {
	a = getdata(type, line);
	a += getdata(username, line+a);
	a += getdata(password, line+a);
		}

    if(strstr(type, "add") && username && password) {
    n = insert(username, password, tree);
    if (tree == NULL)
    tree = n;
    show(tree);
    }
    else if (strstr(type, "delete"))
        printf("the user has been deleted\n");
    /*for (i=0; i<strlen(user);i++){
          j[i]=user[i];
      }*/
    else
        printf("Invalid user, try again\n\n");
        
    if(strstr(line, "show") != NULL){
    alpha(tree);
    printf("\n\n");
    }
	}
}

void show(node* position) {
if (position != NULL) {
    printf("The user is %s and the password is %s\n", position->name, position->password);
    printf("\n");
return;
}
}

node *insert(char *name, char *password, node* pos) {
	
node* temp;
if (pos == NULL) {
    pos = (node*)malloc(sizeof(node));
    pos->name = name;
    pos->password = password;
} else if(pos->right == NULL) {
    pos->right = (node*)malloc(sizeof(node));
    pos->name = name;
    pos->password = password;
	} else if(pos->left == NULL) {
pos->left = (node*)malloc(sizeof(node));
pos->name = name;
pos->password = password;
}
printf("User succesfully added\n");
return pos;
}

int getdata(char *user, char *line) {

int i = 0, j = 0;
	if(isspace(line[0]))
while(isspace(line[++i]));
	while(!isspace(line[i]))
user[j++] = line[i++];
	user[i] = '\0';
return i;
}
//References: Antonio Cortes, Daniela Rodriguez, Rogelio Salinas and Dr Satu Elisa//
