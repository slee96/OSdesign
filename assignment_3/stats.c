#include <stdio.h>
#include <stdlib.h> 
#include <ctype.h>
#include <pthread.h>


//init global vars
int minimum,maximum,average;

//func prototypes 
void* getAvg(void* ca); //calculate and set global var average
void* getMin(void* ca); //find and set global var minimum
void* getMax(void* ca); //find and set global var maximum
int isNum(char num[]);  //verify validity of cl input 


//Command Line Argument Struct 
//created in order to pass data to each thread
//contains argc and argv 
struct CLA{
	int argc;
	char **argv;
    };


int main (int argc, char *argv[]){
 //Loops through each CL arg 
    for(int i = 0; i < (argc-1); i++){
        //Verifies the input is numbers
        if(isNum(argv[i+1]) == 0){
            //If invalid print usage & exit
            fprintf(stderr,"usage ./stats int int int...\n");
            exit(EXIT_FAILURE);}
    }
    //Init CLA Struct
    struct CLA ca;
    //Set argc & argv
    ca.argc = argc; 
    ca.argv = argv;  

    //Init 3 Threads 
    pthread_t T[3];
    //Create 3 Threads 
    //Takes Thread-ID ,Default Thread Attributes, Function Names, A Single Function Parameter ( The CL Args ) 
    pthread_create(&T[0],NULL,getMax,(void *)&ca); 
    pthread_create(&T[1],NULL,getMin,(void *)&ca); 
    pthread_create(&T[2],NULL,getAvg,(void *)&ca); 
    //Wait for each thread to terminate
    pthread_join(T[0],NULL); 
    pthread_join(T[1],NULL);
    pthread_join(T[2],NULL);

    //Prints Results within requested format 
    printf("Average value is\n\r%d\n",average);
    printf("Minimum value is\n\r%d\n",minimum);
    printf("Maximum value is\n\r%d\n",maximum);	

    //Exit sucessfully 
    return 0;
}

//Gets Maximum Value 
void* getMax(void* ca){
    //Typecast void* back to type CLA 
    struct CLA *a = (struct CLA*)ca; 	
    //Place holder var
    int max = 0; 
    //Loop through args and keep highest value in variable max 
    for (int i = 0; i < (a->argc-1); i++){	
        if( max < atoi(a->argv[i+1]))
                max = atoi(a->argv[i+1]);}	
    //Set global variable maximum
    maximum = max;
}

//Gets Maximum Value 
void* getMin(void* ca){
    //Typecast void* back to type CLA 
    struct CLA *a = (struct CLA*)ca; 	
    //Put first value in place holder min
    int min = atoi(a->argv[2]);
    //Loop through args and keep highest value in variable min 
    for (int i = 0; i < (a->argc-1) ; i++){
        if( min > atoi(a->argv[i+1]))
            min = atoi(a->argv[i+1]);}	
    //Set global variable minimum
    minimum = min;	
}

//Calculate Average Value
void* getAvg(void* ca){
    //Typecast void* back to type CLA 
    struct CLA *a = (struct CLA*)ca; 
    //Init and set avg to 0 
    int avg = 0;
    //Loop through args and add them to avg 
    for (int i = 0; i < (a->argc-1) ; i++){
        avg += atoi(a->argv[i+1]);}	
    //Divide avg by amount of args 
    avg /= (a->argc-1); 
    //Set global variable average
    average = avg;
}

//Checks an arg for non numerical values
int isNum(char num[]){
    //Set i to first char 
    int i = 0;
    //Check if char is a negative sign  
    if (num[0] == '-')
    //Set i to second char     
        i = 1;
    //Loop through string 
    for (; num[i] != 0; i++){
        //Verify is number
        if (!isdigit(num[i]))
            //If not return 0
            return 0;
    }
    //If input is all numbers return 1 
    return 1;
}

