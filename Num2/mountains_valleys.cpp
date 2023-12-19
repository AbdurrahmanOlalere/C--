#include <iostream>
#include "functions.h"

using std::cout, std::cin, std::endl;

int main() {
	int a =0;
	int b = 0;
	// TODO(student): print prompt for input

	cout <<"Enter numbers 10 <= a <= b < 10000: ";
	
	// TODO(student): read the numbers from standard input
	
	cin >> a >> b;
	//cout << a <<endl << b <<endl;
	// TODO(student): validate input (and reprompt on invalid input)

	while (!is_valid_range(a,b))	
	{
		cout << "Invalid Input" << endl;
		cout <<"Enter numbers 10 <= a <= b < 10000: ";
        cin >> a >> b;
		//cout << is_valid_range(a,b) <<endl;
	}
	

	// TODO(student): compute and display solution
	count_valid_mv_numbers(a, b);
	//cout << classify_mv_range_type(895) << endl;
	
	return 0;
}