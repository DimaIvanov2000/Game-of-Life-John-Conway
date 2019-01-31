# John Conway's "Game Of Life"

JCGoL is a mathematical toy invented by John Conway where you set up circumstances and see how they progress.

## How to Run

Download the file and / or run the code on your IDE of choice (Codeblocks or DevC++ should both work). A title screen should appear with some basic options.

## How to Use

### Rules of The Game

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

### Controls

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
	 
### Examples

Further examples may be found in the C file header.
