PIA-Description of the proyect

# SUNCITY MALL 



##PROYECT DESCRIPTION 
The program will try to provide information to rent the stablishments that are in the shopping center, where this same program will provide information on prices, space of the stablishment,available months,etc.
If you as a client who wants to rent this space, your data will be saved and you will be able to see what locals are available.


###INFORMATION STORAGE
                
----
The information that will be storage on the different files will be:
-the prices of the establishment 
-the information of the person who is renting it 
-available months 
-the measurements of the stablishment 

###FILES ON THE PROGRAM

-establisment information
-information.txt  (will include price)
-clientsinfo.txt  (storage and you can add people)
-months.txt
-info.h


#Programming (files)
information.txt
```c
					    suncity mall information: 
		Establishment on the 1st floor
		measures: 248m2
		price: $9,000 per month 
		antiquity: 3 years 
	
		Establishment on the 2nd floor
		measures: 50m2
		price: $5,000 per month
		antiquity:5 year
```

clientsinfo.txt
 ```c
clients information:
ESTABLISHMENT IS RENTING:
GENDER:
NAME:
AGE:		
```

months.txt
```c
MONTHS THAT ARE AVAILABLE TO RENT:

january (available)
february (available)
march (available)
april (available)
may (2 places to rent)
june (available)
july  (1 place to rent)
agust (NOT AVAILABLE)
september(1 place to rent)
october
november(NOT AVAILABLE)
december(NOT AVAILABLE)

```
This will be the menu where the user will select what he or she wants to do, by just selecting a number that is showing (the menu).

  ```c
#include <stdio.h>
#include <stdlib.h>
#define NAME 10
#define MAX 30
	
	int op;
	
	int main(){
	printf("--START MENU--\n");
	printf("---WELCOME TO SUNCITY MALL RENTS---);
	printf("[1] Information\n");
	printf("[2] Registration of a new client\n");
	printf("[3] available establishments\n");
	printf("[4] Close\n");
 	printf("Insert the number: ");
	scanf("%d",&op);
	}
    
```
 [1] Information: it will appear the information of the establishments that are on the mall
 [2] registration of a new client: here you will make the registration of the person who wants to rent by introduccing they that like; the age,gender, name, and the stablish it wants to rent. Also here they will enter the establishment that he/she wants to rent and it will appear if its available or not.
 [3] available establishment: it will appear the ones that are available
    
(How it will appear):

    				    --START MENU--
    | -------------------------WELCOME TO SUNCITY MALL RENTS--------------|
    [1] Information
    [2] Registration of a new client 
    [3] available establishment
    [4] close 
	Insert the number: 

　
Registration of the client that is renting
```c
void newclient(){
    char user[MAX];
    int establishment;
    char gender;
    int age;
    
    printf("Introduce your name: %s \n", user);
    printf("age: %d",age);
    printf("gender: %s", gender);
    printf("Entry the establishment you will like to rent: \n");
    scanf("%d", stablishment);
    /*include an "if" condition to know if the stablishment is available or not*/
    
    printf("succesful register, welcome\n\n");
   
    FILE* client = fopen("clientinfo.txt", "a");
    fprintf(client," stablishment is renting: %d\n GENDER: %s\n NAME:%s\n AGE: %s\n",establishment,gender,user,age);
    fclose(client);
```
Here what the new client is doing is adding its information to the file clientinfo.txt

references:
[info de renta de locales](https://inmuebles.mercadolibre.com.mx/locales-comerciales/renta-local-paseo-la-fe-san-nicolas-de-los-garzahttp:// "references")


