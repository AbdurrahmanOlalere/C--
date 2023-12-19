# include <iostream>
# include <string>
# include <vector>
# include "LinkedList.h"
# include "Node.h"

using std::string, std::ostream;

LinkedList::LinkedList() : head{nullptr}, tail{nullptr} {
	// TODO: implement this function
}

LinkedList::~LinkedList() {
	// TODO: implement this function
	Node* curr = head;
	while (curr != nullptr)
    {
        Node* nxtNode = curr->next;
        delete curr;
        curr = nxtNode;
    }
}

LinkedList::LinkedList(const LinkedList& source) : head{nullptr}, tail{nullptr} {
	// TODO: implement this function
	Node* currSource = source.head;

    while (currSource != nullptr) {
        Node* nwNode = new Node(currSource->data.id,currSource->data.year,currSource->data.month,currSource->data.temperature);
        
        if (tail == nullptr) {
            head = tail = nwNode;
        } else {
            tail->next = nwNode;
            tail = nwNode;
        }

        currSource = currSource->next;
    }
}

LinkedList& LinkedList::operator=(const LinkedList& source) {
	// TODO: implement this function
	if (this != &source){
    clear();
    Node* current = source.head;
    while (current != nullptr){
      insert(current->data.id,current->data.year,current->data.month, current->data.temperature);
      current = current->next;
    }
  }
  return *this;
}

void LinkedList::insert(string location, int year, int month, double temperature) {
	// TODO: implement this function
    Node* nwNode = new Node(location, year, month, temperature);
	Node* current = head;
	Node* prev = head;

    if (head == nullptr) {
        head = nwNode;
        tail = nwNode; 
    } else {
		if (nwNode->data < head->data)
		{
			nwNode->next = head;
			head = nwNode;
            return;
		}
		
		while (current != nullptr && current->data < nwNode->data)
		{
			prev = current;
			current = current->next;
		}

		if (current == nullptr)
		{
			tail->next = nwNode;
			tail = nwNode;
		} else {
			prev->next = nwNode;
			nwNode->next = current;
		}
		
	}

    
}



void LinkedList::clear() {
	// TODO: implement this function
	Node* current = head;
	while (current != nullptr){
		Node* nextNode = current->next;
		delete current;
		current = nextNode;
	}
	head = nullptr;
	tail = nullptr;
	
}

Node* LinkedList::getHead() const {
	// TODO: implement this function, it will be used to help grade other functions
	return head;
}

string LinkedList::trimTrailingZeros(const std::string& str) const{
    size_t dotPos = str.find('.');
    if (dotPos != std::string::npos) {
        size_t lastNonZero = str.find_last_not_of('0');
        if (lastNonZero == dotPos) {
            return str.substr(0, dotPos);
        } else {
            return str.substr(0, lastNonZero + 1);
        }
    }
    return str;
}


string LinkedList::print() const {
	string outputString;

    // TODO: implement this function
    if (head == nullptr) {
        outputString = "Empty list!";
    } else {
        Node* current = head;
        while (current != nullptr) {
            string month = std::to_string(current->data.month);
            string year = std::to_string(current->data.year);
            string temp = std::to_string(current->data.temperature);
            outputString += current->data.id + " " + year + " " + month + " " + trimTrailingZeros(temp) + "\n";
            current = current->next;
        }
    }

    return outputString;
}

double LinkedList::calculateAverage(const string& location, int startYear, int endYear) const {
	std::vector<double> temperatures = getTemperatures(location, startYear, endYear);
	if (temperatures.empty()) {
		return 0.0;
	}

	double sum = 0.0;
	for (double tmp : temperatures)
	{
		sum+=tmp;
	}

	double avg = sum/temperatures.size();

	return avg;
	
}

int LinkedList::calculateMode(const string& location, int startYear, int endYear) const {
	std::vector<double> temperatures = getTemperatures(location, startYear, endYear);

	std::vector<double> uniqueTemps;
    std::vector<int> freq;

	if (temperatures.empty()) {
		return 0;
	}
 	for (size_t i = 0; i < temperatures.size(); i++) {
        double temp = temperatures[i];
        bool found = false;

        for (size_t j = 0; j < uniqueTemps.size(); j++) {
            if (temp == uniqueTemps[j]) {
                // Temp already in uniqueTemps
                freq[j]++;
                found = true;
                break;
            }
        }

        if (!found) {
            // New unique temp
            uniqueTemps.push_back(temp);
            freq.push_back(1);
        }
    }

	//find mode
	double mode = -99.99;
	int maxFreq = 0;

 	for (size_t i = 0; i < freq.size(); i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
            mode = uniqueTemps[i];
        } else if (freq[i] == maxFreq && uniqueTemps[i] < mode) {
            // There is a tie so i guess the smaller value in correct.
            mode = uniqueTemps[i];
        }
    }

	return mode;

}
std::vector<double> LinkedList::getTemperatures(const string& location, int startYear, int endYear) const {
    std::vector<double> temperatures;

    Node* curr = head;
    while (curr != nullptr) 
	{
        if (curr->data.id == location &&
            curr->data.year >= startYear &&
            curr->data.year <= endYear &&
            curr->data.temperature != -99.99 && 
            (curr->data.temperature >= -50.0 && curr->data.temperature <= 50.0)) {
            temperatures.push_back(curr->data.temperature);
        }
        curr = curr->next;
    }
    return temperatures;
}

ostream& operator<<(ostream& os, const LinkedList& ll) {
	os << ll.print();
	return os;
}
