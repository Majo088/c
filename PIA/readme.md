PIA-Description of the proyect

# SUNCITY MALL 

youtube link: 

GDB online compiler program: https://onlinegdb.com/fprZ7idIK

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

#COMPILE THE PROGRAM 
To compile the program you need to include all the files that are on my repository on the folder that says "PIA" there you will find the following files:

-pia.c

-information.txt  (will include price)

-clientsinfo.txt  (storage and you can add people)

-available.txt

-file.h


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
NAME: majo
AGE: 28
GENDER: F
ESTABLISMENT: 2
REGISTERED AT: Wed May 19 16:12:59 2021	
```

months.txt
```c
MONTHS WITH SPACE:

january (available)
february (available)
march (available)
april (available)
may (2 places to rent)
june (available)
july  (1 place to rent)
agust (NOT AVAILABLE)
september(1 place to rent)

MONTHS NOT AVAILABLE: 

november(NOT AVAILABLE)
december(NOT AVAILABLE)

ESTABLISHMENTS AVAILABLE THE WHOLE YEAR:

establishment #3
establishment #4
establishment #8
establishment #1


```
This will be the menu where the user will select what he or she wants to do, by just selecting a number that is showing (the menu):
 [1] Information: it will appear the information of the establishments that are on the mall
 [2] registration of a new client: here you will make the registration of the person who wants to rent by introduccing they that like; the age,gender, name, and the stablish it wants to rent. Also here they will enter the establishment that he/she wants to rent and it will appear if its available or not.
 [3] available establishment: it will appear the ones that are available
 [4] it will show the information of the person 
 [5] close the program
    
(How it will appear):

    				    --START MENU--
    | -------------------------WELCOME TO SUNCITY MALL RENTS--------------|
    [1] Information
    [2] Registration of a new client 
    [3] available establishment
    [4] my information
    [5] close the program
	Insert the number: 
During the creation of the program I reread the book as well as I saw tutorials to have a better image of the things I wanted to do.
For the void of info and for the one of available I base on the program of this video:[How to read files](https://www.youtube.com/watch?v=8nIilb2kiSU&ab_channel=thenewboston:// "references"), because I wanted to read each line of the program and I was having troubles, but at the end I got it.
```c
void info(){
 char line[MAX];
 FILE*fpointer =fopen("info.txt","r");
 //part taken from the video
 while(!feof(fpointer)){
 fgets(line, MAX, fpointer);
 printf("%s",line);
 }
 fclose(fpointer);
 }
  
void available(){
char line[MAX];
FILE*months =fopen("available.txt","r");
//part taken from the video
while(!feof(months)){
fgets(line, MAX, months);
printf("%s",line);
}
fclose(months);
  
  }
```

For the information of the establishments I decided to base myself in real places and give me an idea of the cost ($) of each establishment that people rent in real life: [info de renta de locales](https://inmuebles.mercadolibre.com.mx/locales-comerciales/renta-local-paseo-la-fe-san-nicolas-de-los-garzahttp:// "references")


