#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char * argv[]){
    //Argument Error Handling
    if(sizeof(argc) != 2){
           fprintf(stderr,"usage ./filecopy arg1 arg2\n");
            exit(EXIT_FAILURE);
    }	 
    // pd = Pipe Direction fd = File Description
    int pd[2],fd;
    //Storage for File Data
    struct stat fs; 
    //File Pointer
    FILE *fptr;	
    //Get Filesize
    stat(argv[1],&fs);  
    //Gets File Size in Bytes
    int filesize = fs.st_size; 
    //Child PID
    pid_t childpid;
    //buffer for file
    char buffer[filesize];

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
	    //Create Copy 
	    fptr = fopen(argv[2], "w"); 
	    //Verify Creation
	    if(fptr == NULL){
		    exit(0);
	    }
	    //Read buffer from input
	    read(pd[0],buffer,sizeof(buffer)); 
	    //Write buffer to Copy     
	    fwrite(buffer,sizeof(char),sizeof(buffer),fptr); 
	    //Close File I/O Stream
	    fclose(fptr); 
    }//Child End
    else
    {//Parent Start
	    //Closes Input (only output needed)
      	    close(pd[0]);
	    //Open Original File
	    fptr = fopen(argv[1], "r");
	    //Checks Existance 
	    if (fptr == NULL){
		     exit(0);
            } 
	    //Read File to Buffer
	    fread(&buffer,sizeof(char),sizeof(buffer),fptr); 
	    //Writes File to Pipe
            write(pd[1],buffer,sizeof(buffer)); 	    
	    //Closes File I/O Stream
    }//Parent End

    return 0;
}

