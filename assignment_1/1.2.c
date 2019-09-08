#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]){

	//itterate through commandline arguments
	for (int i = 1; i < argc; i++ ){

	//	printf("%d\n","", atoi(argv[i])); -- testing

	}	
	return 0



}


// Recursive GCD-Function 
int gcd(int x, int y){
	
	if (x == 0 ){
		return y;
	}
	return gcd(y % x, x);
}

// Phi-Function
  int phi(int a){

         int output = 1;
         for ( int i = 2; i < a; i++){			
             
		 if(gcd(i,a) == 1){                            
			 outcome++;
                         
		 }}
       	 return outcome;      
  }










		
} 

