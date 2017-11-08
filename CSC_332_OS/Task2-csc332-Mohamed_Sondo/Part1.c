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

//Verify process was forked successfuly
printf ("My pid is: %d. \n" , getpid());

execl ("/bin/date", "date" , NULL);

printf ("Process %d failed to fork() . \n" , getpid());

return 0;
}


