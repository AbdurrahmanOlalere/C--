# ifndef LINKEDLIST
# define LINKEDLIST

# include <iostream>
# include <string>
# include <vector>
# include "Node.h"

using std::string;

class LinkedList {
	private:
		Node* head;
		Node* tail;

		std::vector<double> getTemperatures(const string& location, int startYear, int endYear) const;

	public:
		LinkedList(); // default constructor
		~LinkedList(); // destructor
		LinkedList(const LinkedList& other); // copy constructor
		LinkedList& operator=(const LinkedList& other); // copy assignment
		void insert(std::string location, int year, int month, double temperature); // insert a record to the linked list
		void clear(); // clear the content of this linked list
		string trimTrailingZeros(const std::string& str) const;
		std::string print() const;
		Node* getHead() const;

		double calculateAverage(const string& location, int startYear, int endYear) const;
		int calculateMode(const string& location, int startYear, int endYear) const;

};

std::ostream& operator<<(std::ostream& os, const LinkedList& ll);

# endif
