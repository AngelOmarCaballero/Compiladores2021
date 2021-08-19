#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Node;
//! NodePtr used as typedef in Node
typedef Node * NodePtr;
//a helper class for Node representing a single arc out of a node
class Arc {
	public:
	string label;
	NodePtr next;
};
//represents a state in an AFD
class Node{
	public:
	Node(void);
	NodePtr match(string label); //returns node target for given label
	NodePtr update(string label); //makes new node target for given label
	bool accept; //is this an accept node
	bool initial; //is this an initial node
	private:
	vector<Arc> arcs; //the arcs going out of a node
};
