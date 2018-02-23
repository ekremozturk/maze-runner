#include"Util.h"
#include"AllFoodsMazeProblem.h"
#include <iostream>
using namespace std;

AllFoodsMazeState::AllFoodsMazeState (int agentPos, std::vector<int> foodPosList, std::vector<int> wallPosList) 
						: MazeState (agentPos, foodPosList, wallPosList)
{
		/********************* FILL-IN FROM HERE *********************/
		/********************* FILL-IN UNTIL HERE *********************/
}

bool AllFoodsMazeState::isSameState (State *state){
		/********************* FILL-IN FROM HERE *********************/
		/********************* FILL-IN UNTIL HERE *********************/
}


/******************************* ALL-FOODS-MAZE-PROBLEM ******************************/
// feel free to change
void AllFoodsMazeProblem::readFromFile (char fileName[]){
		MazeProblem::readFromFile (fileName);
}

// feel free to change
State *AllFoodsMazeProblem::setInitState (){
		State *state = new AllFoodsMazeState(initAgentPos, foodPosList, wallPosList);
		return state;
}


// feel free to change
State *AllFoodsMazeProblem::getNextState (State *curState, int action){
		int curPos = ((AllFoodsMazeState *)curState)->agentPos;
		int dC, dR, curC, curR, nextC, nextR;
		getRowColFromPos (curR, curC, curPos);
		getActionEffectRC (dR, dC, action);
		nextR = curR+dR;
		nextC = curC+dC;
		// if the next state is a wall or outside the maze, stay where you are
		if (maze[nextR][nextC] == WALL || nextR<0 || nextR>=nRows || nextC<0 || nextC>=nCols)
				return curState;
		int nextPos = getPosFromRowCol (nextR, nextC);

		State *nextState = new AllFoodsMazeState (nextPos, foodPosList, wallPosList);
		/********************* FILL-IN FROM HERE *********************/
		/********************* FILL-IN UNTIL HERE *********************/
		return nextState;
}

bool AllFoodsMazeProblem::isGoalState (State *curState){
		/********************* FILL-IN FROM HERE *********************/
		/********************* FILL-IN UNTIL HERE *********************/
}


void AllFoodsMazeProblem::printState (State* state){
		/********************* FILL-IN FROM HERE *********************/
		/********************* FILL-IN UNTIL HERE *********************/
}



/********************* FILL-IN FROM HERE *********************/
/********************* FILL-IN UNTIL HERE *********************/

double AllFoodsMazeProblem::heuristicFunc (State *state){
		double dist=0;
		/********************* FILL-IN FROM HERE *********************/
		/********************* FILL-IN UNTIL HERE *********************/
		return dist;
}


