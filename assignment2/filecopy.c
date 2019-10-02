#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char * argv[]){

    //Child PID
    pid_t childpid;

    //Fork & Error Handling
    if((childpid = fork()) == -1){
	    perror("fork");
            exit(1);
    
    }//Child Start
    if(childpid == 0){
   	  
	    // test
	    //printf("im son");

    }//Child End
    else
    {//Parent Start
            //test
   	    // printf("im dad");
    
    }//Parent End

    return 0;
}

