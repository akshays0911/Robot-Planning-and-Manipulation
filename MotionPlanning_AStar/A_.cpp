/*
 Author: Akshay Swaminathan
 Date: 04-04-2018
 Course : Robot Planning and Manipulation
 Purpose : Implementing A* Algorithm
 */
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <list>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct route
{
	void *Destination;                   //Pointer to the Destination state
	unsigned int Cost;                   //Cost on the route 
};
struct state
{
	string Name;                         //Name of the states 
	list<route *> route;                 //List of routes
	unsigned int time;                   //Time take by this algorithm
};
class AstarSearch
{
private:
struct node {
        state *State;                   //Pointer to current state
        unsigned int PathCost;          //Path cost till current state
        unsigned int EstimatedPathCost; //Estimated Cost = PathCost + Heuristic
        node *Parent;                   //Pointer to parent node
        bool Closed;                    //Indicates whether the node is closed
    }; 
}
int main()
{    
     }

