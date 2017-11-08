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

int main(){

FILE * fd;
int status;
int dir_proc =0, mang_proc =0, work_proc=0;
int row=10, coln, pointer=0, x, y;
int adder;

printf("Enter values for x and y with a space in between: ");
scanf("%d %d" ,&x, &y);  //ASk the user to input values for x and y
coln = x*y; 
int grades[row][coln]; //2d array to hold grades in text file
int grade_avg[coln]; //Holds avreg grade



dir_proc= fork(); //Director process
if (work_proc< 0){printf("fork failed1"); }

if (dir_proc == 0){
    fd = fopen("source.txt", "r"); //Open source file with read permission
    for(int i=0; i<row; i++){ //this reads the source file grades into the grade array
	    
	    for(int j=0; j<coln; j++){
	        
	        fscanf(fd, "%d", &grades[i][j]);
	    }
    }  
    
    for(int k=0; k<x; k++){ //loop to create x number of manager processes
        mang_proc = fork(); //Manager process
        if (work_proc< 0){printf("fork failed2"); }
        if (mang_proc == 0){
            
            for(int l=0; l<y; l++){ //loop to create y number of worker processes
                work_proc = fork(); //worker process
                if (work_proc< 0){printf("fork failed3"); }
                if (work_proc == 0){
                    
                    adder=0; //Set adder to zero whenever a new process is created
                    for (int m =0; m<row; m++ ){
                        
                        //if (pointer >=coln){printf("\nprint progress coln:%d \n", pointer); exit(0);}
                        adder+=grades[m][pointer]; //add all the grades for a chapter
 
                    }
                    grade_avg[pointer] = adder/row; //divide the added grades by number of students
                     
                   
                }
                else{//Worker parent
                    waitpid(work_proc, &status, 0);
                    pointer++; //more to the next chapter for the next worker process    
                }
                
            }   
        }
        else{//Manager parent
            waitpid(mang_proc, &status, 0);
            printf("\nprint progress coln:%d \n", pointer);
       
        
        }
    }
    

}
else{ //Director parent
    waitpid(dir_proc, &status, 0);
    fclose(fd);
    for (int o=0; o<coln; o++){
        printf ("The average of chapter %d: %d \n", o+1, grade_avg[o]);
    }
}



return 0;
}
