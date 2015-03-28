//Keith Monaghan
//main.cpp

#include <iostream>
#include <string>
#include <stdexcept>
#include <fstream>

#include "MazeReader.h"
#include "MazeWalker.h"
#include "Position.h"
#include "MazeCreationException.h"

int main(int argc, char** argv)
{
	if(argc != 3){
		std::cout<< "Must provide three arguments, please try again." << std::endl;
	}
	else{	
		std::string file = argv[1];
		
		try{
			MazeReader reader(file);

			std::cout << "test";
			int startingRow, startingCol,numRows, numCols;
				
			char** mazeStructure = reader.getMaze();
			startingRow = reader.getStartRow();
			startingCol = reader.getStartCol();
			numRows = reader.getRows();
			numCols = reader.getCols();

			if(argv[2] == "dfs"){
				MazeWalker walker(mazeStructure, startingRow, startingCol, numRows, numCols, 1);					
			}
			else{
				MazeWalker awlker(mazeStructure, startingRow, startingCol, numRows, numCols, 0);
			}	
		}
		catch(std::runtime_error& e){
			std::cout << e.what() << std::endl;
		}
	}
}