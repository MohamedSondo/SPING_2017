#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	
	int x=2;
	int y=2;
	int myArr[10][4];
	FILE *fp;
	fp = fopen("grades.txt", "r"); 
	int i=0;
	int j=0;
	int grade=0;
	for(i=0; i<10; i++)
	{
		for(j=0; j<4; j++)
		{
			fscanf(fp, "%d", &myArr[i][j]);
			
		}
	}
	
	/* for (i = 0; i < 10; i++) {      // code to see if the values were actuallyu 												saved
        for (j = 0; j < 4; j++) {
            printf("%i ", myArr[i][j]);
        }
        printf("\n");
    }*/
    i=0;
    double avg;
    for(i=0; i<2; i++) //each manegerial process will create x numbers of process
    {
    	//printf("I am in here");
    	int child1=fork();
    	if(child1==0)
    	{
    		for(j=0; j<2; j++)
    		{
    			int child2 = fork();
    			int col;
    			int row;
    			//printf("I am in here \n");	
    			if(child2==0)
    			{
    				//printf("I am in child2 \n");
    				for(row=0; row<4;row++)
    				{
    					//printf("I am in row \n");
    					for(col=0; col<10; col++)
    					{
    						//printf("I am in col \n");
    						avg=avg+myArr[col][row];
    						//printf("%f" , avg);
    					}
    					avg=avg/10;
    					printf("%f",avg);
    					printf("\n");
    					avg =0;	
    				}
    				return 0;
    			}	
    			return 0;
    		}
    		
    		return 0;
    	}
    	
    	return 0;
    }
    return 0;

}







