#include"Agent.h"
#include"Util.h"
using namespace std;

// creates the agent, sets the search algorithm of the agent
// do not change
Agent::Agent (char searchStr[]){
		if (!strcmp(searchStr,"BFS"))
				searchType = BFS;
		else if (!strcmp(searchStr,"DFS"))
				searchType = DFS;
		else if (!strcmp(searchStr,"UCS"))
				searchType = UCS;
		else if (!strcmp(searchStr,"A_STAR"))
				searchType = A_STAR;
		else if (!strcmp(searchStr,"RAND"))
				searchType = RAND;
		else 
				Util::Exit("Wrong search type/string in command line");
}

// sets the problem type
// do not change
void Agent::setProblemType (char problemType[]){
		if (!strcmp(problemType, "eat-food"))
				problem = new MazeProblem();
		else if (!strcmp(problemType, "visit-corners"))
				problem = new CornersProblem();
		else if (!strcmp(problemType, "eat-all-foods"))
				problem = new AllFoodsMazeProblem();
		else 
				Util::Exit("Wrong problem type in command line");
}

// reads layout file, sets the weather (costs), sets the initial state
// do not change
void Agent::perceive (char envFile[], char weatherType[]){
		problem->readFromFile (envFile);
		problem->setCosts (weatherType);
		initState = problem->setInitState();
}

// calls the corresponding search functions
// do not change
void Agent::search(){
		if (searchType==RAND)
				randomSearch();
		else
				graphSearch();
}

// fake/no search for now, random actions
// do not change
void Agent::randomSearch(){
		Node  *initNode = new Node(initState);
		Node  *curNode = initNode;
		for (int i=0;i<100;i++){
				State *curState = curNode->getState();
				vector<int> nextActions;
				vector<State *> nextStates;
				problem->getSuccessorStateActionPairs (nextStates, nextActions, curState);
				int randActIndex = rand()%nextActions.size();
				if (nextStates[randActIndex]->isSameState(curState)){
						i--; continue;
				}

				Node *newNode     = new Node(nextStates[randActIndex]);
				newNode->setParentNode (curNode);
				newNode->action   = nextActions[randActIndex];
				newNode->depth    = curNode->depth++;
				newNode->pathCost = curNode->pathCost + 
						problem->getStateActionCost (curNode->getState(), newNode->action);
				
				curNode->childNodes.push_back(newNode);
				curNode = newNode;
				if (problem->isGoalState(curNode->getState())){
						break;
				}
		}
		solnNode = curNode;
}

// Prints the path (if msec>0) and prints out #
// do not change
void Agent::printSolution(int msec){
		if (solnNode==0)
				cout << "NO SOLUTION FOUND" << endl;
		else{
				printPath(solnNode,msec);
		}
		cout << "# of expanded nodes: " << problem->getExpandedCount() << endl;
		cout << "path cost:" << solnNode->pathCost << endl;
}


// A recursive function that prints the path starting from the final node
// do not change
void Agent::printPath(Node *curNode, int msec){
		if (msec==-1)
				return;
		if (curNode->getParentNode()==0){
				usleep(msec*400); system("clear");
				cout << "Weather: " << problem->getCostType() << endl << endl;
				problem->printState (initState);
				return;
		}
		printPath (curNode->getParentNode(),msec);
		usleep(msec*400); system("clear");
		cout << "Weather: " << problem->getCostType() << endl;
		cout << "ACTION:" << FSTARTBLU << problem->getActionName (curNode->action) << FEND << endl;
		problem->printState (curNode->getState());
}

// Implement for Q1-Q3 and use in the rest
void Agent::add2Fringe (Node *node){
		/********************* FILL-IN FROM HERE *********************/
		/********************* FILL-IN UNTIL HERE *********************/
}

// Implement for Q1-Q3 and use in the rest
Node *Agent::removeFromFringe (){
		Node *node = 0;
		if (searchType == BFS){
		/********************* FILL-IN FROM HERE *********************/
		/********************* FILL-IN UNTIL HERE *********************/
		}else if (searchType == DFS){
		/********************* FILL-IN FROM HERE *********************/
		/********************* FILL-IN UNTIL HERE *********************/
		}else if (searchType == UCS){
		/********************* FILL-IN FROM HERE *********************/
		/********************* FILL-IN UNTIL HERE *********************/
		}else if (searchType == A_STAR){
		/********************* FILL-IN FROM HERE *********************/
		/********************* FILL-IN UNTIL HERE *********************/
		}
		return node;
}



// Implement for Q1 and use in the rest
Node *Agent::graphSearch(){
		Node *initNode = new Node(initState);
		initClosedList();
		add2Fringe (initNode);

		/********************* FILL-IN FROM HERE *********************/
		/********************* FILL-IN UNTIL HERE *********************/
}

void Agent::add2ClosedList(Node *node){
		/********************* FILL-IN FROM HERE *********************/
		/********************* FILL-IN UNTIL HERE *********************/
}

void Agent::initClosedList(){
		/********************* FILL-IN FROM HERE *********************/
		/********************* FILL-IN UNTIL HERE *********************/
}

bool Agent::isInClosedList(Node *node){
		/********************* FILL-IN FROM HERE *********************/
		/********************* FILL-IN UNTIL HERE *********************/
}

/******************* SEARCH TREE NODES **********************/

Node::Node(State* state){
						this->state = state;
						parentNode = 0;
						depth = 0;
						pathCost = 0;
						action = -1;
						f_n = g_n = h_n = 0;
}


void Node::expand(Problem *problem){
		// DO NOT REMOVE THIS CODE FROM HERE!
		if (parentNode){
				if (f_n < parentNode->f_n){
						problem->printState (parentNode->getState());
						problem->printState (state);
						Util::Exit("Inconsistent heuristics!");
				}
		}
		// DO NOT REMOVE THIS CODE UNTIL HERE!
		
		/********************* FILL-IN FROM HERE *********************/
		/********************* FILL-IN UNTIL HERE *********************/
}


