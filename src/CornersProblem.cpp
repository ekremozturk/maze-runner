#include"CornersProblem.h"
#include"Util.h"
#include <iostream>
using namespace std;

// extend for Q4 and use it for Q5
CornersState::CornersState (int agentPos, vector<int> foodPosList, vector<int> wallPosList) 
		: MazeState(agentPos, foodPosList, wallPosList)
{
		/********************* FILL-IN FROM HERE *********************/

		/********************* FILL-IN UNTIL HERE *********************/
}

// extend for Q4 and use it for Q5
bool CornersState::isSameState (State *state){
		/********************* FILL-IN FROM HERE *********************/
                CornersState *otherState = (CornersState *) state;
                if (this->agentPos==otherState->agentPos){
                        for (int i=0; i<4; i++){
                             if(this->corner_visited[i] != otherState->corner_visited[i]){
                                           return 0;
                             }
                        }
                        return 1;
                }
		/********************* FILL-IN UNTIL HERE *********************/
}


// Feel free to change, but not required
void CornersProblem::readFromFile (char fileName[]){
		MazeProblem::readFromFile (fileName);
}

// extend for Q4 and use it for Q5
State *CornersProblem::getNextState (State *curState, int action){
		int curAgentPos = ((CornersState *)curState)->agentPos;
		int dC, dR, curC, curR, nextC, nextR;
		getRowColFromPos (curR, curC, curAgentPos);
		getActionEffectRC (dR, dC, action);
		nextR = curR+dR;
		nextC = curC+dC;
		// if the next state is a wall or outside the maze, stay where you are
		if (maze[nextR][nextC] == WALL || nextR<0 || nextR>=nRows || nextC<0 || nextC>=nCols)
				return curState;
		int nextAgentPos = getPosFromRowCol (nextR, nextC);
		State *nextState = new CornersState (nextAgentPos, foodPosList, wallPosList);
		/********************* FILL-IN FROM HERE *********************/
        
                for (int i=0; i<4; i++){
                        ((CornersState *)nextState)->corner_visited[i] = ((CornersState *)curState)->corner_visited[i];
                        //printf ("%d \n", ((CornersState *)curState)->food_loc_list[i]);
                        printf ("%d \n", ((CornersState *)nextState)->corner_visited[i]);
                }
        
        
		/********************* FILL-IN UNTIL HERE *********************/
		return nextState;
}




// extend for Q4 and use it for Q5
State *CornersProblem::setInitState (){
		State *state = new CornersState(initAgentPos, foodPosList, wallPosList);
		CornersState *cornersState = (CornersState *) state;

		/********************* FILL-IN FROM HERE *********************/
                cornersState->corner_visited[0]= 0;
                cornersState->corner_visited[1]= 0;
                cornersState->corner_visited[2]= 0;
                cornersState->corner_visited[3]= 0;
                state = cornersState;
		/********************* FILL-IN UNTIL HERE *********************/

		return state;
}

// extend for Q4 and use it for Q5
bool CornersProblem::isGoalState (State *curState){
		/********************* FILL-IN FROM HERE *********************/
        
                for (int i = 0; i < foodPosList.size(); i++) {
                        if (foodPosList[i] == ((CornersState *)curState)->agentPos){
                                ((CornersState *)curState)->corner_visited[i] = 1;
                                nFoods--;
                        }
                }
                int sum =((CornersState *)curState)->corner_visited[0]+
                         ((CornersState *)curState)->corner_visited[1]+
                         ((CornersState *)curState)->corner_visited[2]+
                         ((CornersState *)curState)->corner_visited[3];
        
                //printf ("%d \n", sum);
                return (nFoods == 0);
		/********************* FILL-IN UNTIL HERE *********************/
}



// Q5
double CornersProblem::heuristicFunc (State *state){
		/********************* FILL-IN FROM HERE *********************/

		/********************* FILL-IN UNTIL HERE *********************/
}




