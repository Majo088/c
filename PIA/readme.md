PIA-Description of the proyect

# SUNCITY MALL 



##PROYECT DESCRIPTION 
The program will try to provide information to rent the premises that are in the shopping center, where this same program will provide information on prices, space of the premises, available months.
If you as a client who wants to rent this space, your data will be saved and you will be able to see what premises are available.


###INFORMATION STORAGE
                
----
The information that will be storage on the different files will be:
- the prices of the stablishment 
-the information of the person who is renting it 
-available months 
-the measurements of the stablishment 

###FILES ON THE PROGRAM

- stablisment information
-information.txt  (will include price)
-clientsinfo.txt  (storage and you can add people)
-months.txt
-info.h


###Programming (files)
information.txt
```c
											suncity mall information: 
		Stablishment on the 1st floor
		measures: 248m2
		price: $9,000 per month 
		antiquity: 3 years 
	
		Stablishment on the 2nd floor
		measures: 50m2
		price: $5,000 per month
		antiquity:5 year
```

clientsinfo.txt
 ```c
clients information:
		NAME:
		AGE:
		GENDER:
		STABLISHMENT IS USING:
		PAYS BY MONTH: 
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
###programming in C 
This will be the menu where the user will select what he or she wants to do, by just selecting a number that is showing (the menu).

    #include <stdio.h>
	#include <stdlib.h>
    #define NAME 10
    #define Work 16
	#define MAX 30
	
	int op;
	
	int main(){
	printf("--START MENU--\n");
	printf("---WELCOME TO SUNCITY MALL RENTS---);
	printf("[1] Information\n");
	printf("[2] Registration of a new client\n");
	printf("[3] available stablishments\n");
	printf("[4] Close\n");
 	printf("Insert the number: ");
	scanf("%d",&op);
	}
    
    
(How it will appear):

    													--START MENU--
    | -------------------------WELCOME TO SUNCITY MALL RENTS--------------|
    [1] Information
    [2] Registration of a new client 
	[3] available stablishment
	[4] close 
	Insert the number: 

####C 　
registration of the client that is renting
```c
void newclient(){
    int pin;
    char user[MAX];
    int stablishment;
    
    printf("Introduce your name:\n", pin);
	scanf("%s,user");
    printf("Entry the stablishment you will like to rent: \n");
    scanf("%d", stablishment);
    
    printf("succesful register, welcome\n\n");
   
    FILE* client = fopen("clientinfo.txt", "a");
    fprintf(client," stablishment to rent: %d name of the person: %d %s \n",stablishment, user);
    fclose(nuevous);
```
references:
[info de renta de locales](https://inmuebles.mercadolibre.com.mx/locales-comerciales/renta-local-paseo-la-fe-san-nicolas-de-los-garzahttp:// "references")

###End
