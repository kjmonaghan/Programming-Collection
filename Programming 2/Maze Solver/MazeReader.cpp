#include <iostream>
#include <string>
#include <stdexcept>

#include "MazeReader.h"



MazeReader::MazeReader(std::string file) throw (MazeCreationException){


	inFile.exceptions ( std::ifstream::failbit | std::ifstream::badbit );

		
	inFile.open(file);

	inFile >> m_rowSize;
	inFile >> m_colSize;

	if(m_rowSize < 1 || m_colSize < 1)
		throw MazeCreationException("Invalid array dimensions");

	inFile >> m_startRow;
	inFile >> m_startCol;

	if(m_startRow > m_rowSize || m_startCol > m_colSize)
		throw MazeCreationException("Starting Position is outside array bounds");


	readMaze();

	if(m_maze[m_startRow][m_startCol] != 'S')
		throw MazeCreationException("Invalid Starting Location");

}

MazeReader::~MazeReader(){
	for(int i = 0; i < m_colSize; i ++){
		delete[] m_maze[i];	
	}

	delete[] m_maze;
}

char** MazeReader::getMaze() const{
	return m_maze;
}

int MazeReader::getCols() const{
	return m_colSize;
}

int MazeReader::getRows() const{
	return m_rowSize;
}

int MazeReader::getStartCol() const{
	return m_startCol;
}


int MazeReader::getStartRow() const{
	return m_startRow;
}

void MazeReader::readMaze() throw (MazeCreationException){

	std::cout << "test";
	
	m_maze = new char *[m_rowSize];
	
	for(int i = 0; i < m_rowSize; i++){	
		m_maze[i] = new char[m_colSize];
	}	
	
	for(int i = 0; i < m_rowSize; i++){		
		for(int j = 0; j < m_colSize; j++){
			inFile >> m_maze[i][j];
										
			if (m_maze[i][j] == 0){
				throw MazeCreationException("Cannot create maze");
			}
		}
	}
}