#include "Node.h"
class AFD {
	public:
	AFD(void); //makes empty FSA to then add to with update
	char sep; //what character to split input at
	/* turns input into a vector key using sep as separator */
	bool accept(string input); //test if input is accepted
	void update(string input); //add to FSA to make input be accepted
	private:
	vector<NodePtr> initial_states;
	vector<string> key;
	void set_key_from_string(string in); //set key by spliting string at the sep character
	bool accept(void); //checks if key is accepted
};

/*sets accept and final to 0 */
Node::Node() {
	accept = false; /* final status */
	initial = false; /* start status */
}
 /* adds a pair (label,n) to the arcs of the node
* where n is newly allocated Node object */
NodePtr Node::update(string label) {
	NodePtr n2;
	n2 = new Node;
	Arc p;
	p.label = label;
	p.next = n2;
	arcs.push_back(p);
	return n2;
}

AFD::AFD() {
	NodePtr n;
	n = new Node;
	n->initial = true;
	initial_states.push_back(n);
}

bool AFD::accept(string input) {
	set_key_from_string(input);
	return accept();
}
 bool AFD::accept() {
	int k = 0;
	bool accept = false;
	NodePtr n1, n2;
	for(int count = 0; count < initial_states.size(); count++){
		n1 = initial_states[count];
		/* k records how much of the key has been seen so far */
		for (k = 0; k < key.size(); k++) {
			if ((n2 = n1->match(key[k])) != NULL) {
			n1 = n2;
			} else {
			break; /* jump out of main loop */
			}
		}
		 if (k == key.size() && n1->accept) {
			accept = true;
			break;
		}
	}
	return accept;
} 

int main() {
	AFD f1;
	return 0;
}
