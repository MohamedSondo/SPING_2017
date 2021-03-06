//Mohamed Sondo
//CSC332  OS
//DAD-SON problem

#include <stdio.h>
#include "sem.h"

#define CHILD      			0  			/* Return value of child proc from fork call */
#define TRUE       			0
#define FALSE      			1

FILE *fp1, *fp2, *fp3, *fp4;			/* File Pointers */

//#define N 3
#define BUFSIZE 1
#define PERMS 0666 //0666 - To grant read and write permissions

int *buffer;

int balance, attempts;

main()
{
	int pid;						// Process ID after fork call
	int i;							// Loop index
	int N;							// Number of times dad does update
	int N_Att;						// Number of time sons allowed to do update
	int status;						// Exit status of child process
	int bal1, bal2;					// Balance read by processes
	int flag, flag1;				// End of loop variables

	int balance = seminit (4096, 1);// semaphore for the balance
	int attempts = seminit (4097, 1);//semaphore for the attempts


	//Initialize the file balance to be $100
	fp1 = fopen("balance","w");
	bal1 = 100;
	fprintf(fp1, "%d\n", bal1);
	fclose(fp1);

	//Initialize the number of attempts to be 20
	fp4 = fopen("attempt", "w");
	N_Att = 10;
	fprintf(fp4, "%d\n", N_Att);
	fclose(fp4);

	//Create child processes that will do the updates
		if ((pid = fork()) == -1)
	{
		//fork failed!
		perror("fork");
		exit(1);
	}

	if (pid == CHILD){
	//First Child Process. Dear old dad tries to do some updates.

		N=5;
		for(i=1;i<=N; i++)
		{
			printf("Dear old dad is trying to do update.\n");
			P(balance);//---------------controlling Dad Balance
			fp1 = fopen("balance", "r+");
			fscanf(fp1, "%d", &bal2);
			printf("Dear old dad reads balance = %d \n", bal2);

			//Dad has to think (0-14 sec) if his son is really worth it
			sleep(rand()%15);
			fseek(fp1,0L,0);
			bal2 += 60;
			printf("Dear old dad writes new balance = %d \n", bal2);
			fprintf(fp1, "%d \n", bal2);
			fclose(fp1);

			printf("Dear old dad is done doing update. \n");
			sleep(rand()%5);	/* Go have coffee for 0-4 sec. */
			V(balance);//---------increase balance to future and others process access
		}
	}

	else
	{
		//Parent Process. Fork off another child process.
		if ((pid = fork()) == -1)
		{
			//Fork failed!
			perror("fork");
			exit(1);
		}
		if (pid == CHILD)
		{
			printf("First Son's Pid: %d\n",getpid());
			//Second child process. First poor son tries to do updates.
			flag = FALSE;
			while(flag == FALSE)
			{
				P(attempts);//--------------controlling Son 1 attempts
				fp3 = fopen("attempt" , "r+");
				fscanf(fp3, "%d", &N_Att);
				if(N_Att == 0)
				{
					fclose(fp3);
					flag = TRUE;
					V(attempts);//---------increase attempts to future and others process access
				}
				else
				{
					printf("Poor SON_1 wants to withdraw money.\n");
					P(balance);//-------------------controlling Son 1 Balance
					fp2 = fopen("balance", "r+");
					fscanf(fp2,"%d", &bal2);
					printf("Poor SON_1 reads balance. Available Balance: %d \n", bal2);
					if (bal2 == 0)
					{
						fclose(fp2);
						V(balance);//--------increase balance to future and others process access

						fclose(fp3);
						V(attempts);//-------increase attempts to future and others process access
					}
					else
					{
						sleep(rand()%5);
						fseek(fp2,0L, 0);
						bal2 -=20;
						printf("Poor SON_1 write new balance: %d \n", bal2);
						fprintf(fp2,"%d\n", bal2);
						fclose(fp2);
						V(balance);//--------increase balance to future and others process access

						printf("poor SON_1 done doing update.\n");
						fseek(fp3,0L, 0);
						N_Att -=1;
						fprintf(fp3, "%d\n", N_Att);
						fclose(fp3);
						V(attempts);//-------increase attempts to future and others process access
					}
				}
			}
		}
		else
		{
		//Parent Process. Fork off one more child process.
			if ((pid = fork()) == -1)
			{
				//fork failed!
				perror("fork");
				exit(1);
			}
			if (pid == CHILD)
			{
				printf("Second Son's Pid: %d\n",getpid());
				//Third child process. Second poor student tries to do updates.
				flag1 = FALSE;
				while(flag1 == FALSE)
				{
					P(attempts);//------------------controlling Son 2 attempts
					fp3 = fopen("attempt" , "r+");
					fscanf(fp3, "%d", &N_Att);
					if(N_Att == 0)
					{
						fclose(fp3);
						flag1 = TRUE;
						V(attempts);//---------increase attempts to future and others process access
					}
					else
					{
						printf("Poor SON_2 wants to withdraw money.\n");

						P(balance);//------------controlling Son 1 Balance
						fp2 = fopen("balance", "r+");
						fscanf(fp2,"%d", &bal2);
						printf("Poor SON_2 reads balance. Available Balance: %d \n", bal2);
						if (bal2 == 0)
						{
							fclose(fp2);
							V(balance);//-------increase balance to future and others process access

							fclose(fp3);
							V(attempts);//------increase attempts to future and others process access
						}
						else
						{
							sleep(rand()%5);
							fseek(fp2,0L, 0);
							bal2 -=20;
							printf("Poor SON_2 write new balance: %d \n", bal2);
							fprintf(fp2,"%d\n", bal2);
							fclose(fp2);
							V(balance);//-------increase balance to future and others process access

							printf("poor SON_2 done doing update.\n");
							fseek(fp3,0L, 0);
							N_Att -=1;
							fprintf(fp3, "%d\n", N_Att);
							fclose(fp3);
							V(attempts);//-------increase attempts to future and others process access
						}
					}
				}
			}
			else
			{
				//Now parent process waits for the child processes to finish
				pid = wait(&status);
				printf("Process(pid = %d) exited with the status %d. \n", pid, status);

				pid = wait(&status);
				printf("Process(pid = %d) exited with the status %d. \n", pid, status);

				pid = wait(&status);
				printf("Process(pid = %d) exited with the status %d. \n", pid, status);

				semkill (attempts); //kill semaphore for attempts
				semkill (balance); //kill semaphore for balance
			}
			exit(0);
		}
		exit(0);
	}
	exit(0);
}
