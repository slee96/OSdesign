#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char * argv[]){
    // pd = Pipe Direction
    int pd[2];
    //Child PID
    pid_t childpid;
    //buffer for file
    char buffer[filesize]

    //Create Pipe
    pipe(pd);

    //Fork & Error Handling
    if((childpid = fork()) == -1){
	    perror("fork");
            exit(1);
    
    }//Child Start
    if(childpid == 0){
	    
	    //Closes Output (only input needed) 
	    close(pd[1]);
	    //Read buffer from input 
	    read(pd[0],buffer,sizeof(buffer)); 

    }//Child End
    else
    {//Parent Start
	    
	    //Closes Input (only output needed)
      	    close(pd[0]);
	    //Writes String to Pipe
            write(pd[1],buffer,sizeof(buffer)); 	    

    }//Parent End

    return 0;
}

