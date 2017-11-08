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

int main(){

int status;
int child1 = 0, child2 = 0;
char *para[] = {"./Prcs_P2" , NULL};
char *para2[] = {"./Prcs_P1" , NULL};

child1 = fork(); //fork child one 
if (child1== 0){
	
	child2= fork();  //fork child two
	if (child2 ==0){
		execv("./Prcs_P1", para2);  // creates a process to exccute program 1 on
		printf("\n Child two evecv failed \n"); //this prints if evecv fails	
	}
	else{
		waitpid (child2, &status, 0); //waits for child1 process
		printf("\n Child two finished \n");
	}

	//process of child one
	execv("./Prcs_P2", para);  //creates a process to exccute program 1 on
	printf("\n Child one evecv failed \n"); //this prints if evecv fails

}
else{
	waitpid (child1, &status, 0); //waits for child2 process
	printf("\n Child one finished \n");

}




return 0;
}
