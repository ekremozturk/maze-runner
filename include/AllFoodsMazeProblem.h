#ifndef ALLFOODSMAZEPROBLEM_H
#define ALLFOODSMAZEPROBLEM_H
#include"MazeProblem.h"
// Q6
class AllFoodsMazeState : public MazeState{
		public:
				/********************* FILL-IN FROM HERE *********************/
				/********************* FILL-IN UNTIL HERE *********************/

				AllFoodsMazeState (int agentPos, std::vector<int> foodPosList, std::vector<int> wallPosList);
				virtual bool isSameState (State *state);
};


#define MAX_FOODS 1000
class AllFoodsMazeProblem : public MazeProblem{
		/********************* FILL-IN FROM HERE *********************/
		/********************* FILL-IN UNTIL HERE *********************/
		public:
				virtual void   readFromFile (char fileName[]);
				virtual State* setInitState ();
				virtual bool   isGoalState (State *curState);
				virtual State* getNextState (State *curState, int action);
				virtual double heuristicFunc (State *state);
				virtual void   printState(State* s);
};

#endif
