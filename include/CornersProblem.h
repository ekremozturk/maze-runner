#ifndef CORNERPROBLEM_H
#define CORNERPROBLEM_H
#include"MazeProblem.h"

// extend for Q4 and use it for Q5
class CornersState : public MazeState{
		public:
			// Q4-5
		/********************* FILL-IN FROM HERE *********************/
                int corner_visited [4];
		/********************* FILL-IN UNTIL HERE *********************/
				CornersState (int agentPos, std::vector<int> foodPosList, std::vector<int> wallPosList);
				virtual bool isSameState (State *state);
};

class CornersProblem : public MazeProblem{
		public:
				void   readFromFile (char fileName[]);
				State* setInitState ();
				bool   isGoalState (State *curState);
				State* getNextState (State *curState, int action);
				double heuristicFunc (State *state);
};
#endif
