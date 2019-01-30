/*
	Dima Ivanov's C Programs:
	
	John Conway's Game of Life
	
	JCGoL is a mathematical toy invented by John Conway where you set up circumstances and see how they progress.
	
	--- --- --- Rules --- --- ---
	
	The game happens on a square grid where every tile can either be alive (white) or dead (black).
	The game progresses in discrete steps where something happens each step based on the grid's configuration.
	A tile's status may change depending on the number of living neighbors it has in the 3x3 area around it.
	
	If a living tile has 4+ living neighbors, it will die (presumably by lack of resources / overcrowding).
	  1 2 3 X
	1 #   #
	2 # X  <-- Will Die
	3   #
	Y
	
	If a living tile has 1- living neighbors, it will also die (presumably by isolation).
	  1 2 3 X
	1
	2   X  <-- Will Die
	3     #
	Y
	
	A tile will continue to be alive if neither of the above conditions are met.
	  1 2 3 4 X
	1
	2   # #    (Stable configuration)
	3   # #
	4
	Y
	
	A dead tile may only become alive if it has 3 living neighbors (optimal population for birth).
	  1 2 3 4 X
	1     #
	2 # O  <-- Will be born
	3 #
	Y
	
	The game progresses according to these rules with many configurations leading to surprisingly complex outcomes.
	The math behind the game has been investigated with surprising results though it is also fun to just play around with.
	
	--- --- --- Controls --- --- ---
	
		  ^        Ww
		<   >   Aa    Dd  - Move Cursor
		  v        Ss
	  
			Space - Toggle Tile Status
			   Ee - Toggle Edit Mode (Deactivate Cursor)
			   Enter - Progress Board Once
			   1-9 - Progress Board 10^Key Times (WARNING : MAY TAKE AGES)
			   Rr - Randomize Board
			   Cc - Clear Board
			   Tt - Toggle Cinematic Mode, Plays automatically until next key hit
	
	--- --- --- Configurable Constants --- --- ---
	
	Change these at your own risk.
*/
	const xSize=50; // Board Size, the only issue with large sizes is that it prints slowly
	const ySize=50; // I've been looking for an alternative to printf() and have not found one.
/*
	
	--- --- --- Examples --- --- ---
	
	Here are some simple configurations which appear often:
	
	"Square"
	Type: Stable
	Highly resistant to loss of units but unstable if it gains units.
	  1 2 3 4 X          1 2 3 4 X
	1            --->  1
	2   # #      --->  2   # #
	3   #        --->  3   # #
	4            --->  4
	Y                  Y
	
	"Blinker"
	Type: Alternating
	3-tile configuration which alternates between a vertical and horizontal position.
	  1 2 3 X            1 2 3 X
	1   #        --->  1    
	2   #        --->  2 # # #
	3   #        --->  3    
	Y                  Y
	
	"Flower"
	Type: Stable
	Also stable, just like the square.
	  1 2 3 X 
	1   # #  
	2 #   #  
	3 # #     
	Y        
	
	"Glider"
	Type: Moving
	An alternating configuration that moves itself diagonally.
	A "Glider Gun" configuration also exists which periodically emits gliders.
	  1 2 3 4 X          1 2 3 4 X          1 2 3 4 X          1 2 3 4 X
	1            --->  1   #        --->  1   # #      --->  1   # #
	2 # # #      --->  2   # #      --->  2 #   #      --->  2     # #
	3     #      --->  3 #   #      --->  3     #      --->  3   #
	4   #        --->  4            --->  4            --->  4      
	Y 
*/



#include<stdio.h>
#include<math.h>

int board[200][200]={0};
int cursor[2]={0};
int editMode;
//function declarations
void displayBoard();
void progressBoard();
void clearAll();

main()
{
	int i,j;
	char input;
	do
	{
		editMode=1;
		system("cls");
		printf("John Conway's Game of Life\n\nP - Play\nESC - Exit");
		input=getch();
		switch(input)
		{
			case 'p':
				clearAll();
				do
				{
					displayBoard();
					input=getch();
					switch(input)
					{
						case 72:case 'w':case 'W':
							if(editMode==1&&cursor[1]>0) cursor[1]--;
							break;
						case 75:case 'a':case 'A':
							if(editMode==1&&cursor[0]>0) cursor[0]--;
							break;
						case 77:case 'd':case 'D':
							if(editMode==1&&cursor[0]<xSize-1) cursor[0]++;
							break;
						case 80:case 's':case 'S':
							if(editMode==1&&cursor[1]<ySize-1) cursor[1]++;
							break;
						case ' ':
							board[cursor[0]][cursor[1]]=(board[cursor[0]][cursor[1]]+1)%2;
							break;
						case 'e':case 'E':
							editMode=(editMode+1)%2;
							break;
						case 13:case '1':
							progressBoard();
							break;
						case 'r':case 'R':
							srand((unsigned int) time(NULL));
							for(j=0;j<ySize;j++)
							{
								for(i=0;i<xSize;i++)
								{
									board[i][j]=rand()%2;
								}
							}
							break;
						case 'c':case 'C':
							for(j=0;j<ySize;j++)
							{
								for(i=0;i<xSize;i++)
								{
									board[i][j]=0;
								}
							}
							break;
						case 't':case 'T':
							while(!kbhit())
							{
								progressBoard();
								displayBoard();
							}
							getch();
							break;
					}
					if(input>=50&&input<=57)
					{
						for(i=0;i<(int)ceil(pow(10,input-48));i++)
						{
							progressBoard();
						}
					}
				}
				while(input!=27);
				input=0;
				break;
		}
	}
	while(input!=27);
	displayBoard();
}
//function definitions
void displayBoard()
{
	system("cls");
	int i,j;
	for(j=0;j<ySize;j++)
	{
		for(i=0;i<xSize;i++)
		{
			if(editMode==1&&cursor[0]==i&&cursor[1]==j)
			{
				if(board[i][j]==1)
				{
					printf("%c",178);
				}
				else
				{
					printf("%c",176);
				}
			}
			else
			{
				if(board[i][j]==1)
				{
					printf("%c",219);
				}
				else
				{
					printf(" ");
				}
			}
		}
		printf("|\n");
	}
	for(i=0;i<=xSize;i++)
	{
		printf("-");
	}
}

void progressBoard()
{
	int nBoard[200][200]={0};
	int i,j,k,l;
	int cNeighbors;
	for(j=0;j<ySize;j++)
	{
		for(i=0;i<xSize;i++)
		{
			cNeighbors=0;
			for(l=-1;l<=1;l++)
			{
				for(k=-1;k<=1;k++)
				{
					if(i+k>=0&&i+k<xSize&&j+l>=0&&j+l<ySize)
					{
						if(board[i+k][j+l]==1&&(l!=0||k!=0))
						{
							cNeighbors++;
						}
					}
				}
			}
			if((cNeighbors==2&&board[i][j]==1)||cNeighbors==3)
			{
				nBoard[i][j]=1;
			}
		}
	}
	for(j=0;j<ySize;j++)
	{
		for(i=0;i<xSize;i++)
		{
			board[i][j]=nBoard[i][j];
		}
	}
}

void clearAll()
{
	int i,j;
	for(j=0;j<ySize;j++)
	{
		for(i=0;i<xSize;i++)
		{
			board[i][j]=0;
		}
	}
	cursor[0]=0;
	cursor[1]=0;
}
