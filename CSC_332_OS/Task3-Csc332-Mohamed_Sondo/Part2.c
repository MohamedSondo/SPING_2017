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


int main(int *argc, char *argv[]){

char* input[] = {"ls", "-l", NULL};

//Verify process was forked successfuly
printf ("My pid is: %d. \n" , getpid());

int err = execvp ("/bin/ls", input);

printf ("Process %d failed to fork(). Returned with value %d. \n" , getpid(), err);

return 0;
}

