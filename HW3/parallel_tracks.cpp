#include <iostream>
#include <iomanip>
#include <cstring>
#include "parallel_tracks.h"

using std::cin, std::cout, std::endl;

//-------------------------------------------------------
// Name: prep_double_array
// PreCondition:  an array of doubles is passed in
// PostCondition: data in the array is 'zeroed' out
//---------------------------------------------------------
void prep_double_array(double ary[])
// making sure all values within the array are set to 0.0;
{
  //TODO
  int i;
  for (i = 0; i < 9; i++)
  {

	ary[i] = 0.0;
	
  }
  
}

//-------------------------------------------------------
// Name: prep_unsigned_int_array
// PreCondition:  an array of unsigned ints is passed in
// PostCondition: data in the array is 'zeroed' out
//---------------------------------------------------------
void prep_unsigned_int_array(unsigned int ary[])
// making sure all values within the array are set to 0;
{
  //TODO
  int i;
  for (i = 0; i < 9; i++)
  {

	ary[i] = 0;
	
  }
}

//-------------------------------------------------------
// Name: prep_string_array
// PreCondition:  an array of strings is passed in
// PostCondition: each element in the array is set to "N/A"
//---------------------------------------------------------
void prep_string_array(char ary[][STRING_SIZE])
// making sure all values within the array are set to "N/A";
{
	//TODO
  int i;
  for (i = 0; i < 9; i++)
  {

	ary[i][0] ='N';
	ary[i][1] ='/';
	ary[i][2] ='A';
	ary[i][3] ='\0';
	
  }
}

//-------------------------------------------------------
// Name: trim
// PreCondition:  the cstring
// PostCondition: whitespace has been removed from beginning and end of string
//---------------------------------------------------------
void trim(char str[STRING_SIZE]) {
	// TODO
	int startIndex = 0;
	int endIndex = strlen(str)-1;
	// finds when the leading whitespace starts
	while (str[startIndex] != '\0' && isspace(str[startIndex]))
	{
		startIndex++;
	}
	// finds when the trailing whitespace ends
	while ((endIndex >= 0) && isspace(str[endIndex]))
	{
		endIndex--;
	}
	
	//create new string without the leading and trailing whitespaces
	char trimStr[STRING_SIZE];

	strncpy(trimStr, str + startIndex, endIndex - startIndex + 1);
	trimStr[endIndex - startIndex + 1] = '\0';
	// can void function return values?? also is this function meant to juct modify the inputed string.
	// then ill use the string erase function also am i allowed to use the strcnpy and strcpy function?

	strcpy(str, trimStr);

}

//-------------------------------------------------------
// Name: get_runner_data
// PreCondition:  the prepped parallel arrays
// PostCondition: all arrays contain data from standard in
//---------------------------------------------------------
bool get_runner_data(double timeArray[], char countryArray[][STRING_SIZE], 
		unsigned int numberArray[], char lastnameArray[][STRING_SIZE]) 
{
  //TODO
  int runnerCount = 0;

  //
  while (runnerCount < 9)
  {
	cin >> timeArray[runnerCount];
	if (timeArray[runnerCount] < 0)
	{
		//cout << "Time Input Error" << endl;
		return false;
	}
	cin >> countryArray[runnerCount];
	if (strlen(countryArray[runnerCount]) != 3)
	{
		//cout << "Country size Input Error" << endl;
		return false;
	}

	for (size_t i = 0; i < 3; i++)
	{
		char c = countryArray[runnerCount][i];//????
		if (c < 'A' || c > 'Z')
		{
			//cout << "Country Char Input Error" << endl;
			return false;
		}
		
	}
	cin >> numberArray[runnerCount];
	int number = numberArray[runnerCount];
	if ((number > 99) || (number < 0 ))
	{
		//cout << "Number Input Error" << endl;
		return false;
	}

	cin >> lastnameArray[runnerCount];
	trim(lastnameArray[runnerCount]);
	//cout << lastnameArray[runnerCount] << endl;
	for (size_t i = 0; i < strlen(lastnameArray[runnerCount]) ; i++)
	{
		char c = lastnameArray[runnerCount][i];
		if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')))// the reverse of my logic worked????
		{
			//cout << "Last Name char Input Error" << endl;
			return false;
		}

	}
	
	if (strlen(lastnameArray[runnerCount]) < 2)
	{
		//cout << "Last Name size Input Error" << endl;
		return false;
	}
		
		
	
	runnerCount++;
  }
  
  return true; // set so it will compile
}

//-------------------------------------------------------
// Name: get_ranking
// PreCondition:  just the time array is passed in, and has valid data
// PostCondition: after a very inefficient nested loop to determine the placements 
// and places the ranks in a new array. That new array is returned
//---------------------------------------------------------
void get_ranking(const double timeArray[], unsigned int rankArray[])
{
	//TODO
	//ill use bubble sort since that's the easiest
	// 
	// //double timeArrCopy[9];
	// for (unsigned int i = 0; i < 9; i++)
	// {
	// 	timeArrCopy[i] = timeArray[i];
	// }
	
	// assign the rank Array
	for (unsigned int i = 0; i < (9); i++)
	{
		rankArray[i] = i+1;
	}
	
	for (size_t i = 0; i < 9; i++)
	{
		int tempRank = 1;
		for (size_t j = 0; j < 9; j++)
		{
			if (timeArray[i] > timeArray[j])
			{
				tempRank++;
			}
			
		}
		rankArray[i] = tempRank;
		

	}
	

	// //buble sort algo
	// for (unsigned int i = 1; i < (9); i++)
	// {
	// 	for (unsigned int j = 0; j < 9-i; j++)
	// 	{
	// 		if (timeArrCopy[j] > timeArrCopy[j+1])
	// 		{
	// 			//swap array elements
	// 			double tempTime = timeArrCopy[j];
	// 			timeArrCopy[j] = timeArrCopy[j+1];
	// 			timeArrCopy[j+1] = tempTime;


	// 			unsigned int tempRank = rankArray[j];
	// 			rankArray[j] = rankArray[j+1];
	// 			rankArray[j+1] = tempRank;

	// 			// i should print out what's happening here
	// 			//cout << "Time Element " << i << ", before: " << tempTime << " After: " << timeArrCopy[j] << endl;
	// 			//cout << "Ranking Element " << i << ", before: " << tempRank << " After: " << rankArray[j] << endl;
	// 			//cout<< rankArray<<endl; 
	// 		}
			
	// 	}
		
		
	// }
	// for (size_t i = 0; i < 9; i++)
	// {
	// 	cout << timeArrCopy[i] << endl;
	// }

	
	
}


//-------------------------------------------------------
// Name: print_results
// PreCondition:  all parallel arrays are passed in and have valid data
// PostCondition: after a very inefficient nested loop to determine the ranks
// it then displays them along with a delta in time from the start
//---------------------------------------------------------
void print_results(const double timeArray[], const char countryArray[][STRING_SIZE],
		const char lastnameArray[][STRING_SIZE], const unsigned int rankArray[])
{

	std::cout << "Final results!!";
	std::cout << std::setprecision(2) << std::showpoint << std::fixed << std::endl;
	double best_time = 0.0;
		
	// print the results, based on rank, but measure the time difference_type
	for(unsigned int j = 1; j <= SIZE; j++)
	{
		
		// go thru each array, find who places in "i" spot
		for(unsigned int i = 0; i < SIZE; i++)
		{
			if(rankArray[i] == 1) // has to be a better way, but need the starting time
			{
				best_time = timeArray[i];
			}
			
			
			if(rankArray[i] == j) // then display this person's data
			{
				// this needs precision display
				std::cout << "[" << j << "]  " << timeArray[i] << " " << std::setw(15) << std::left << lastnameArray[i] << "\t" << "(" << countryArray[i] << ")  +" << (timeArray[i] - best_time) << std::endl; 
			}
			
		}
	}	
}