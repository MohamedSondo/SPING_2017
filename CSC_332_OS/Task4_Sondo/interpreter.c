#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h> 
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc , char *argv[]){

printf("\nargc:%i\n", argc);

char args[128];
char *cmp[128];
cmp[0]='q';
cmp[1]='u';
cmp[2]='i';
cmp[3]='t';
//cmp[4]=(char)0;



int status;
int child = 0, child2 = 0;
char *para[] = {"./interpreter" , "quit", NULL};
int p = 1;

//This quits the program when the user inputs quit
if (argc == 0) {return 0; } 

//Create child process
child = fork();

if (child < 0) { printf("error\n"); return 0; } //checks if there was an error in opening the file

if (child == 0){
	
	//This quits the program when the user inputs quit
	while ( (strcmp( argv[p], para[1]) != 0) || (strcmp( argv[2], cmp) != 0) ) {  

	
		child2 = fork(); //Second child to handle the exec process
		if (child2 == 0)
		{
			printf("Child forked: %d\n", getpid());
			execvp(argv[p], argv); //this executes the command the user inputs
			printf("\n Child evecv failed \n"); //this prints if evecv fails
	
		}else {
			
			waitpid(child2, &status, 0); //wait for child 2 to finish
                        p=0;
			argv[0] = "sh";
			argv[1] = "-c"; //Empties the array 
		}

		printf("\nInput quit to Exit \n");
		printf("Enter new command: ");
		fgets(args, 128, stdin);
		argv[2] = args;
		argv[3] = NULL; //Set the end of the array to null
		
		
		
 	 }	 
		
}
else{
	
	waitpid(child, &status, 0); //waits for child 1 to finish
	printf("\nProgram Exited \n");
}

return 0;
}
