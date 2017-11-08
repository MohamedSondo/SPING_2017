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

//int waitpid(int , int*, int);

int main(){
//Child one 
int child1 = fork(); // forks a child1

if (child1 < 0) {perror ("\n fork() error on child1"); return 0; } // prints error if fork() fails

if (child1 == 0) //Child successfully forked
{
        printf ( "\nI am child one, my pid is: %i\n" , getpid() ); //Prints Child1's ID
	int child2 = fork();
	if (child2 < 0) {perror ("\n fork() error on child1"); return 0; } // prints error

	if (child2 == 0){
		printf ( "I am child two, my pid is: %i\n" , getpid() ); //Prints Child2's ID
	} 
	else { waitpid (child2 , NULL , 0); //parent will wait for child two
	
	}
}
else {
        waitpid (child1 , NULL , 0); //parent will wait for child one
}




return 0;
}
