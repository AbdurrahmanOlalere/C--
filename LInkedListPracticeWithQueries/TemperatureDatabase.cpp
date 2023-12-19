# include "TemperatureDatabase.h"
# include <fstream>

using std::cout, std::endl, std::string, std::ofstream;

TemperatureDatabase::TemperatureDatabase() {}
TemperatureDatabase::~TemperatureDatabase() {}

void TemperatureDatabase::loadData(const string& filename) {
	// TODO: implement this function
	std::fstream myFile;
	myFile.open(filename);
	if (myFile.fail())
    {
        throw std::invalid_argument("Error: Unable to open " + filename);
    }
	string location;
	int year, month;
	double temp;
	while (myFile >> location >> year >> month >> temp) {
		if (myFile.fail())
		{
			cout << "Error: Other invalid input" << endl;
			continue;
		}
		
		if (year >= 1800 && year <= CurrentYear) {
			if (month > 0 && month < 13)
			{				
				if (temp != -99.99 && (temp >= -50.0 && temp <= 50.0)) {
				records.insert(location, year, month, temp);
				}
				else if (temp > 100)
				{
					cout << "Error: Other invalid input" << endl;
				}
				else {
				cout << "Error: Invalid temperature " << temp << endl;
				}
			}
			else {
			cout << "Error: Invalid month " << month << endl;
			}
		}
		else if (year < 100)
		{
			cout << "Error: Other invalid input" << endl;
		}
		else {
			cout << "Error: Invalid year " << year << endl;
		}
	}
}

void TemperatureDatabase::outputData(const string& filename) {
	ofstream dataout("sorted." + filename);
	
	if (!dataout.is_open()) {
		cout << "Error: Unable to open " << filename << endl;
		exit(1);
	}

	dataout << records.print();
}

void TemperatureDatabase::performQuery(const string& filename) {
	// TODO: implement this function
	std::fstream queryFile(filename);
	if (queryFile.fail())
	{
		throw std::invalid_argument("Failed to open " + filename);
	}
	string location, operation;
    int startYear, endYear;

	while (queryFile >> location >> operation >> startYear >> endYear) {
		if (operation == "AVG")
		{
			cout << records.calculateAverage(location,startYear,endYear) << endl;
			
		}
		if (operation == "MODE")
		{
			cout << records.calculateMode(location,startYear,endYear) << endl;
		}
		
		
	}
	

}

void TemperatureDatabase::myTest(){
	TemperatureDatabase myDB;

	//test load
	myDB.loadData("");

	//test queries
	myDB.performQuery("");

	//test outputting data
	myDB.outputData("");

	// Test rule of three 
    TemperatureDatabase copyDatabase(myDB); // Copy constructor
    TemperatureDatabase anotherDatabase;
    anotherDatabase = myDB; // Copy assignment
}
