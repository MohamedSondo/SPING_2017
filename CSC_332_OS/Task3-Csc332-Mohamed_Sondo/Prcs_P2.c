#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h> 
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){

int readcount , writecount;
char buffer[100];
char buffer2[50];
char *filename[] = {"source.txt" , "destination.txt", "destination2.txt"};

int fd1 , fd2 , fd3;
//open files
fd1 = open (filename[0] , O_RDONLY);
fd2 = open (filename[1] , O_WRONLY);
fd3 = open (filename[2] , O_WRONLY);

if (fd1 == -1){
	printf("\n source file failed with error [%s]\n",strerror(errno)); return 1;
}else if (fd2 == -1) {
	printf("\n destination file failed with error [%s]\n",strerror(errno)); return 1;
}else if (fd3 == -1){
	printf("\n destination2 file failed with error [%s]\n",strerror(errno)); return 1;
}
else {
	printf("\n source , destination 1 & 2 file opened Successfully\n");
}	

readcount = read(fd1 ,buffer, 100); //Read 100 characters from source

for (int i = 0; i<readcount; i++){	    //Change 1 to A's
	if (buffer[i] == '1')
		buffer[i] = 'A';
}

writecount = write (fd2, buffer, 100);

//Keep reading until end of file (readcount == 0)
while (readcount > 0){
	
	readcount = read(fd1 ,buffer2, 50);   //Read 50 characters from source
	for (int i = 0; i<readcount; i++){	    //Change 2 to B's
		if (buffer2[i] == '2')
			buffer2[i] = 'B';
	}
	writecount = write(fd3, buffer2, readcount); //Write to destination2.txt
	
	readcount = read(fd1 ,buffer, 100); //Read 100 characters from source
	for (int i = 0; i<readcount; i++){	    //Change 1 to A's
		if (buffer[i] == '1')
			buffer[i] = 'A';
	}
	writecount = write (fd2, buffer, readcount);  //Write to destination.txt
}

//close open files
close(fd1);
close(fd2);
close(fd3);

return 0;
}
