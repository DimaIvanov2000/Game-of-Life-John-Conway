#include<stdio.h>

int board[200][200]={0};
int sizeX=10;
int sizeY=10;

progressBoard();
displayBoard();

main()
{
	displayBoard();
}

progressBoard()
{
	int i,j,k,l;
	for(j=0;j<sizeY;j++)
	{
		for(i=0;i<sizeX;i++)
		{
			
		}
	}
}

displayBoard()
{
	system("cls");
	int i,j;
	for(j=0;j<sizeY;j++)
	{
		for(i=0;i<sizeX;i++)
		{
			printf("%i",board[i][j]);
		}
		printf("|\n");
	}
	for(i=0;i<sizeX;i++)
	{
		printf("-");
	}
}
