#include <iostream>
#include <string>
#include "./string_calculator.h"
#include <sstream>

using std::cout, std::endl, std::ostringstream, std::istringstream;
using std::string;

unsigned int digit_to_decimal(char digit) {
    // TODO(student): implement
    if (digit < '0' || digit > '9')
    {
        throw std::invalid_argument("Invalid Argument,The input is not a valid digit, e.g. '0' -- '9'");
    }

    int digitInt = digit - '0';

    
    return digitInt;
}

char decimal_to_digit(unsigned int decimal) {
    // TODO(student): implement

    if (decimal > 9)
    {
        throw std::invalid_argument("Invalid Argument,The input is not a valid digit, e.g. 0 -- 9");
    }

    char digit = decimal + 48;
    return digit;
}

string trim_leading_zeros(string num) {
    // TODO(student): implement
    // the stuff below ddoesn't support numbers larger than INT32 MAX
    // istringstream ss(num);
    // int n;
    // ss >> n;// this shoudl work but the parseing is being weird.
    // ostringstream tss;
    // tss << n;
    // return tss.str();

    size_t trimPos = num.find_first_not_of('0');

    if (trimPos == std::string::npos)
    {
        return "0";
    }
    else
    {
        return num.substr(trimPos);
    }
    
}
string add_leading_zeros(string a, int width){
    
    for (int i = 0; i < width; i++)
    {
        a.insert(0,"0");

    }
    
    return a;

}

string add(string lhs, string rhs) {
    int llen = lhs.length();
    int rlen = rhs.length();
    //cout << rhs << endl;
    // Find the maximum length and add leading zeros if needed
    int maxLngth = std::max(llen, rlen);
    lhs = add_leading_zeros(lhs, maxLngth - llen);
    rhs = add_leading_zeros(rhs, maxLngth - rlen);

    //cout << rhs << endl;

    int carry = 0;
    string result;

    for (int i = maxLngth - 1; i >= 0; i--) 
    {
        //cout << "Here" << endl;
        //cout << lhs[i] << " " << rhs[i] << endl;
        int dgtSm = digit_to_decimal(lhs[i]) + digit_to_decimal(rhs[i]) +carry;
        //cout << dgtSm << endl;
        if (dgtSm >= 10) 
        {
            carry =1;
            dgtSm -=10;
        } 
        else
        {
            carry =0;
        }

        result = decimal_to_digit(dgtSm) + result;
    }

    if (carry > 0) {
        result = decimal_to_digit(carry) + result;
    }
    result = trim_leading_zeros(result);
    return result;
}


string multiply(string lhs, string rhs) {
    // TODO(student): implement
    string result = "0";

    if (lhs == "0" || rhs == "0")
    {
        return "0";
    }

    bool isNgtve = (lhs.at(0) == '-' && rhs.at(0) != '-') || (lhs.at(0) != '-' && rhs.at(0) == '-');

    if (lhs.at(0) == '-')
    {
        lhs = lhs.substr(1);
    }
    if (rhs.at(0) == '-')
    {
        rhs = rhs.substr(1);
    }
    
    for (size_t i = 0; i < rhs.length(); i++)
    {
        int mltplierDgt = digit_to_decimal(rhs.at(i));
        string tempResult = "0";

        for (int j = 0; j < mltplierDgt; j++)
        {
            tempResult = add(tempResult, lhs);
            //cout << tempResult<< endl;
        }

        // append zeros)
        tempResult += string(rhs.length() - 1 - i, '0');

        // Add tempResult to the result
        result = add(result, tempResult);
    }

    if (isNgtve && result != "0")
    {
        result = "-" + result;
    }

    return result;
}
