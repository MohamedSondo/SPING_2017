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

//printf("\n The global parent is: %d", getpid());
int status;

int a = 10 , b = 25 , fq = 0 , fr = 0;

fq = fork(); //process Q is forked
if (fq == 0){
	a = a+b;
	printf("\n a = %d", a);
	printf("\n b = %d", b);
	printf("\n fq id: %d\n", getpid()); //prints Q's id
	
	fr = fork(); //process R is forked
	if (fr != 0){
		waitpid(fr, &status, 0); //waits for child process to finish
		b = b+20;
		printf("\n a = %d", a);
		printf("\n b = %d", b);
		printf("\n fr parent id: %d\n", getppid()); //prints R's id
		
	}
	else{
		a = (a+b)+30;
		printf("\n a = %d", a);
		printf("\n b = %d", b);
		printf("\n fr id: %d\n", getpid()); //prints R's parent
		
	}
	
}else {
	waitpid(fq, &status, 0); //waits for child process to finish
	b = a+b-5;
	printf("\n a = %d", a);
	printf("\n b = %d", b);
	printf("\n fq parent id: %d\n", getppid()); //print Q's parent
	
}

return 0;
}
