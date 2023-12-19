#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include "./string_calculator.h"

using std::cout, std::endl, std::cin,std::ostringstream, std::istringstream;
using std::string;

bool isOperand(char c){
    return c == '+' || c == '*';
}

/* string calculateExpression( const string input) { 
    istringstream iss;
    string tempV;

    iss >> tempV;
    string result = tempV;

    while (iss >> tempV)
    {
        if (isOperand(tempV[0]))
        {
            char oprTR = tempV[0];

            iss >> tempV;

            if (oprTR == '+')
            {
                result = add(result,tempV);
            }
            else if (oprTR == '*')
            {
                result = multiply(result,tempV);
            }
        } 
        else
        {
            throw std::invalid_argument("Invalid Operator: " + tempV);
        }
    }

    return result;
    

}*/

int main() {
    string input;
    // TODO(student): implement the UI
    cout << "String Calculator" << endl;
    cout << "\"q\" or \"quit\" or ctrl+d to exit" << endl;
    while (true)
    {
        cout << ">> ";
        getline(cin, input);
        if (input == "q" || input == "quit" || input.empty() )
        {
            cout << "\nfarvel!\n\n" << endl;
            break;
        }

        try
        {
            istringstream iss(input);
            string lhs;
            string rhs;
            string oprTR;
            iss >> lhs >> oprTR >> rhs;
            //string result = calculateExpression(input); din't work like in giving an actual result
            if (oprTR == "+")
            {
                string result = add(lhs, rhs);
                cout << "\nans = \n\n    " << result <<"\n\n";
            }
            else if (oprTR == "*")
            {
                string result = multiply(lhs, rhs);
                cout << "\nans = \n\n    " << result <<"\n\n";
            }
            else {
                cout << "Invalid operator. Please use \"+\" or \"*\" " << endl;
            }
            
        }
        catch(const std::exception& e)
        {
            cout << "Error:" << e.what() << endl;
        }
        
    }
    return 0;
    
}

