
#include <iostream>
#include <string>
#include <stdexcept>

#include "Position.h"
#include "MazeReader.h"
#include "MazeWalker.h"

MazeWalker::MazeWalker(char** mazePtr, int startRow, int startCol, int rows, int cols, bool dfs): m_startPos(startRow,startCol) , m_curPos(startRow,startCol){

	m_maze = mazePtr; 
	m_rows = rows; 
	m_cols = cols; 
	m_isDFS = dfs;
	m_noExit = false;
	
	m_visited = new bool *[m_rows];
	
	for(int i = 0; i < m_rows; i++){	
		m_visited[i] = new bool[m_cols];
		for(int j = 0; j<m_cols; j++){
			m_visited[i][j] = false;
		}
	}

	Position firstMove = Position(startRow,startCol);

	move(firstMove);

	walkMaze();

}

MazeWalker::~MazeWalker(){
	for(int i = 0; i < m_cols; i ++){
		delete[] m_visited[i];	
	}

	delete[] m_visited;
}

void MazeWalker::walkMaze(){

	if(m_isDFS){
		while(!isGoalReached()){
			storeValidMoves();

			if(m_moveStack.empty()){
				m_noExit = true;
				std::cout << "\nNo exit\n\n";
			}
			else{
				move(m_moveStack.top());
				m_moveStack.pop();
			}
		}
	}

	else{
		while(!isGoalReached()){
			storeValidMoves();

			if(m_moveQueue.empty()){
				m_noExit = true;
				std::cout << "\nNo exit\n\n";
			}
			else{
				move(m_moveQueue.front());
				m_moveQueue.pop();
			}
		}
	}

	if(!m_noExit)
		std::cout << "\nExit Found!\n\n";
}

void MazeWalker::storeValidMoves(){
	if(m_isDFS){
		if(isValidMove(m_curPos.getRow()+1, m_curPos.getCol()))
			m_moveStack.push(Position(m_curPos.getRow()+1,m_curPos.getCol()));
		if(isValidMove(m_curPos.getRow()-1, m_curPos.getCol()))
			m_moveStack.push(Position(m_curPos.getRow()-1,m_curPos.getCol()));
		if(isValidMove(m_curPos.getRow(), m_curPos.getCol()+1))
			m_moveStack.push(Position(m_curPos.getRow(),m_curPos.getCol()+1));
		if(isValidMove(m_curPos.getRow(), m_curPos.getCol()-1))
			m_moveStack.push(Position(m_curPos.getRow(),m_curPos.getCol()-1));
	}
	else{
		if(isValidMove(m_curPos.getRow()+1, m_curPos.getCol()))
			m_moveQueue.push(Position(m_curPos.getRow()+1,m_curPos.getCol()));
		if(isValidMove(m_curPos.getRow()-1, m_curPos.getCol()))
			m_moveQueue.push(Position(m_curPos.getRow()-1,m_curPos.getCol()));
		if(isValidMove(m_curPos.getRow(), m_curPos.getCol()+1))
			m_moveQueue.push(Position(m_curPos.getRow(),m_curPos.getCol()+1));
		if(isValidMove(m_curPos.getRow(), m_curPos.getCol()-1))
			m_moveQueue.push(Position(m_curPos.getRow(),m_curPos.getCol()-1));
	}
}

void MazeWalker::move(Position& p){

	m_curPos = p;
	m_visited[p.getRow()][p.getCol()] = true;

	printVisited();
	
	std::cout << "Visiting position: " << p.getRow() << ", " << p.getCol() 
			  << "\n--------------------------\n";

}

bool MazeWalker::isGoalReached() const{
	if(m_maze[m_curPos.getRow()][m_curPos.getCol()] == 'E' || m_noExit)
		return true;

	return false;
}

bool MazeWalker::isValidMove(int row, int col){
	if(row < 0 || row >= m_rows)
		return false;
	if(col < 0 || col >= m_cols)
		return false;

	if(m_visited[row][col])
		return false;

	if(m_maze[row][col] == 'W')
		return false;

	return true;
}

void MazeWalker::printVisited(){

	for(int i = 0; i < m_rows; i++){
		for(int j = 0; j<m_cols; j++)
			std::cout << m_visited[i][j];
		std::cout << "\n";
	}
}

void MazeWalker::printMaze(){

	for(int i = 0; i < m_rows; i++){
		for(int j = 0; j<m_cols; j++)
			std::cout << m_maze[i][j];
		std::cout << "\n";
	}
}