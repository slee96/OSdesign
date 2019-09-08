#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// GCD-Function
int gcd(int x, int y){
	
	if (x == 0 ){
		return y;	
	}
	return gcd(y % x, x);
}

<<<<<<< HEAD
	//for loop to itterate through command line arguments
	for (int i = 1; i < argc; i++ ){
		
		//printf("%d\n", atoi(argv[i])); -- testing
=======
// PHI-Function
int phi(int a){

	int output = 1;	     
	for ( int i = 2; i < a; i++){	
		if(gcd(i,a) == 1 ){
				output++;
			} } 
	return output;
}

int main(int argc, char *argv[]){
	//itterate through commandline arguments
	for (int i = 1; i < argc; i++ ){
	// print output of phi 
	printf("%s%d%s%d\n", "phi(" ,atoi(argv[i]),"):",phi(atoi(argv[i])));
>>>>>>> refs/remotes/origin/master
	}
}