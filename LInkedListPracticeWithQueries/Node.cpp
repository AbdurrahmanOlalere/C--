# include <string>
# include "Node.h"

using std::string;

Node::Node() : data("",0,0,0.0) , next(nullptr) {
	// TODO: implement this function
}

Node::Node(string id, int year, int month, double temperature) : data(id, year, month, temperature), next(nullptr) {
	// TODO: implement this function
}

bool Node::operator<(const Node& b) {
	//compare location id
	if (data.id != b.data.id) 	  {return this->data.id < b.data.id;}
	// compare by date
	if (data.year == b.data.year) {return this->data.month < b.data.month;}
	else 						  {return this->data.year < b.data.year;}
}
