#include<bits/stdc++.h>			//header file that includes every standard library.
#include<conio.h>				//includes console input output library.
#include<iostream>
#include<windows.h>				//to access windows library
using namespace std;

int score = 0;					//initializing the score as zero
int highest = 0;				//initializing the highest score as zero

void pattern(int a[4][4]){
	int i,j;
	cout << "\n\n\n\n\t\t--[ THE 2048 PUZZLE ]--\t\t\t\t\t";
	printf("Score: %d",score);
	printf("\n\t\t\t\t\t\t\t\t\tHighest Score: %d",highest);
	cout << "\n\n\n";
	for (i=0;i<4;i++){			//loop for rows
		cout << "\t\t\t-------------------------\n\t\t\t";
		for (j=0;j<4;j++){		//loop for columns
			if (a[i][j]==0){
				cout << "|     ";
			}
			else{
				cout<<"| "<<a[i][j]<<"   ";
			}
		
		}
		cout<<"|"<<endl;
	}
	cout<<"\t\t\t-------------------------\n";
	cout << "\n  Controls: \t\t\t\t\t\t\tPress 'esc' to quit.";
	cout << "\n\t\t\t\t^";
	cout << "\n\n\t\t\t<\tv\t>";
}



void down(int a[4][4])		//non returning value down move function.3
{
		int i , j , l;		//i and l for column counter,j for row counter.
		for (j=0;j<4;j++){
			l=3;				//l is on last row
			for(i=2;i>=0;i--){			//reverse loop for downward move
				if(a[i][j]!=0){
					if(a[i+1][j]==0 || a[i+1][j]==a[i][j]){      //if two numbers are equal in vertical line or equal to zero
						if (a[l][j]==a[i][j]){				//if any number in last row is equal to any number in column
							a[l][j] *= 2;					//adding same numbers or multiplying by 2 are same things.
							a[i][j] = 0;					//replacing the space with zero.
							score = score + a[l][j];
						}
						
						else{
							if (a[l][j]==0){			
								a[l][j] = a[i][j];
								a[i][j] = 0;
						}
							else{
								a[--l][j] = a[i][j];		//decrementing l to go upwards
								a[i][j] = 0;
						}
					}
				}
				else {
					l--;
				}
			}
		}
	}
}

void up(int a[4][4])				//non returning value up move function.
{
	int i , j , l;				//i and l for column counter,r for row counter.
	for (j=0;j<4;j++){
		l=0;			//l is on first row
		for (i=1;i<4;i++){				//forward loop for moving upwards
			if (a[i][j]!=0){
				if (a[i-1][j]==0 || a[i-1][j]==a[i][j]){
					if (a[l][j]==a[i][j]){			//if any number in first row is equal to any number in column
						a[l][j] *= 2;
						a[i][j] = 0;
						score = score + a[l][j];
					}
					else{
						if (a[l][j]==0){
							a[l][j] = a[i][j];
							a[i][j] = 0;
						}
						else{
							a[++l][j] = a[i][j];		//incrementing l to go down
							a[i][j] = 0;
						}
					}
				}
				else{
					l++;
				}
			}
		}
	}
}

void right(int a[4][4])
{
	int i , j , r;		//i for column counter,r and j for rown counter.
	for (i=0;i<4;i++){				//forward i loop.
		r=3;					//l incrementing a i. r is initialized as last element row wise.
		for (j=2;j>=0;j--){		//backward j loop which will run 3 times
			if (a[i][j]!=0){
				if (a[i][j+1]==0 || a[i][j+1]==a[i][j]){
					if (a[i][r]==a[i][j]){
						a[i][r] *= 2;		//adding same numbers or multiplying by 2 are same things.
						a[i][j] = 0;
						score = score + a[i][r];
					}
					else{
						if (a[i][r]==0){		
							a[i][r] = a[i][j];
							a[i][j] = 0;
						}
						else{
							a[i][--r]=a[i][j];
							a[i][j] = 0;
						}
					}
				}
				else{
					r--;
				}
			}
		}
	}
}

void left(int a[4][4]){
	int i,j,r;
	for(i=0;i<4;i++){
		r=0;
		for(j=1;j<4;j++){
			if (a[i][j]!=0){
				if(a[i][j-1]==0 || a[i][j-1]==a[i][j]){
					if (a[i][r]==a[i][j]){
						a[i][r] *= 2;
						a[i][j] =0;
						score = score + a[i][r];
					}
					else{
						if (a[i][r]==0){
							a[i][r] = a[i][j];
							a[i][j] = 0;
						}
						else{
							a[i][++r] = a[i][j];
							a[i][j] =0;
						}
					}
				}
				else{
					r++;
				}
			}
		}
	}
}

void rn(int a[4][4]){
	int m,n; //initializing variables for 2D array.
	srand(time(0));		//generating random number.
	while (1){
		m = rand()%4;		//random number b/w 0 and 4.
		n = rand()%4;		//random number b/w 0 and 4.
		if (a[m][n]==0){
			a[m][n] = pow(2,m%2+1);		//displaying 2 or 4 on random two positions.
			break;
		}
	}
}

int check(int b[4][4],int a[4][4])
{
	int f=1,i,j;
	for(i=0;i<4;i++)
    	for(j=0;j<4;j++)
    		if(b[i][j]!=a[i][j])
    		{
    			f=0;
    			break;
			}
	return f;
}

int checkover(int a[4][4])
{
	int m=0,n=0,k=0,i,j;
	for(i=0;i<4;i++)
    	for(j=0;j<4;j++)
    		if(a[i][j]==0)			//if there's space left
    		{
    			m=1;
				break;	
			}
			
	for(i=0;i<3;i++)
    	for(j=0;j<3;j++)
    		if(a[i+1][j]==a[i][j] || a[i][j+1]==a[i][j]) //checking if any two numbers equal horizontally and vertically
    		{
    			n=1;
    			break;
			}
    			
	if(m || n) return 1;	//if any of m or n true, return 1
	else return 0;
}
int checkwon(int a[4][4])
{
	int k=0,i,j;
	for(i=0;i<3;i++)
    	for(j=0;j<3;j++)
    		if(a[i][j] == 2048 || a[i+1][j] == 2048 || a[i][j+1] == 2048 || a[i+1][j+1] == 2048)
			{
				k=1;
    			break;
			}
	if (k) return 1;
	else return 0;
}
int main()
{
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h,14);
	cout<<"\n\n\n\n\t\t\t\t--[ THE 2048 PUZZLE ]--";
	cout<<"\n\n\n\n\t\tInstructions: Use Arrow keys to play the game.\n\n\n\t\tPress 'Enter' to start the game!";
	cout<<"\n\n\n\t\tPress 'Backspace' to quit!";
	int c;
	c=getch();
	system("cls");
	if (c == 13) {				//if user presses 'enter' button
	
	int l1,l2,l3,l4,i,j;
	int a[4][4]={0},b[4][4]={0};		//initializing both arrays as zero. b array is for storing the data
	srand(time(0));
	l1=rand()%4;				//generating random number b/t 0 and 4
	l2=rand()%4;				//generating random number b/t 0 and 4
	while(true)
	{
		l3=rand()%4;			//generating random number b/t 0 and 4
		l4=rand()%4;			//generating random number b/t 0 and 4
		if(l3!=l1 && l4!=l2){   //this loop will run until l1=l3 and l2=l4
		break;
	}
	}
	a[l1][l2]=2;		//placing 2 at random position
	a[l3][l4]=4;		//placing 4 at random position
	SetConsoleTextAttribute(h,14);
	pattern(a);						//calling the function of pattern to display the pattern
	
	int ch;
	while (true)					//infinite loop
    {
    	for(i=0;i<4;i++)
    		for(j=0;j<4;j++)
    			b[i][j]=a[i][j];			//storing the values in array b
    	ch=getch();							//syntax to get asciiz value
    	system("cls");						//clearing console
    	if(ch==72) up(a);					//asciiz value for up key is 72, up function will run
    	if(ch==80) down(a);					//asciiz value for up key is 88, down function will run
    	if(ch==75) left(a);					//asciiz value for up key is 75, left function will run
    	if(ch==77) right(a);				//asciiz value for up key is 77, right function will run
		if(ch==27) break;
		
		if(!check(b,a))					//checking if both arrays are not equal
			rn(a);						//then generate a random number
		pattern(a);						//then display in the pattern
			
		if(!checkover(a))				//if checkover function gives 0
		{
			SetConsoleTextAttribute(h,14);
			cout<<"\n\n\t\t\tGAME OVER!!";
			cout<<"\n\t\t\tPress 'Enter' to play again!!";
			cout<<"\n\t\t\tPress 'esc' to end game!!\n\n\n";
			ch = getch();
			if (ch==13) {
			score =0;
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
			main();
		}
			if (ch==27) break;
		}	
		if (checkwon(a))				//if user wins the game
		{
			SetConsoleTextAttribute(h,14);
			cout << "\n\n\t\t\tYOU WON!!";
			cout<<"\n\t\t\tPress 'Enter' to play again!!";
			cout<<"\n\t\t\tPress 'esc' to end game!!\n\n\n";
			ch = getch();
			if (ch==13) main();
			else break;
			
		}
		if (highest < score){
			highest = score;
		}
	}
	}
	return 0;
}



