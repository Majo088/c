#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

#include"help.h"

#define LIM 100


int main() {
	
	node* n = NULL;
	node* tree = NULL; 
	
	int i = 0, j = 0, count = 0;
	char c;
	char username[LIM];
	char password[LIM];
	char line[LIM];
	char type[LIM];
	
	while(1) {
	i = 0, j = 0;
	do{
	line[i++] = c;
	if(isspace(c))
		count++;
	}while((c = getchar()) != EOF && c != '\n');
		
		line[i] = '\0';
	
	if(count >= 2) {
	i = getdata(type, line);
	i += getdata(username, line+i);
	i += getdata(password, line+i);
		}

    if(strstr(type, "add") && username && password) {
    n = insert(username, password, tree);
    if (tree == NULL)
    tree = n;
    show(tree);
    }
		else if (strstr(type, "delete"))
			printf("the user has been deleted\n");
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
