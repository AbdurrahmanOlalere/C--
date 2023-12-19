#include <iostream>
#include <stdexcept>

using namespace std;

int Largest(int a, int b, int c) {
  int largest = a;
  if ((b > largest)) {
    largest = b;
  }
  if (c > largest) {
    largest = c;
  }
  return largest;
}

bool SumIsEven(int a, int b) {
  if (((a+b)%2) == 0) {// if modulo equal to zero return true for sum is even
    return true;
  }
  else 
  {
    return false;
  }
}

int BoxesNeeded(int apples) {
  
  if ((apples <= 0))
  {
    return 0;
  }
  int box = apples/20;

  if (apples%20 == 0)
  {
    return box;
  }
  
  return 1+box;
}

bool SmarterSection(int A_correct, int A_total, int B_correct, int B_total) {

    if (A_correct < 0 || A_total < 0 || B_correct < 0 || B_total < 0)
    {
      throw std::invalid_argument("Invalid Argument");
    }
    if ((A_correct > A_total) || (B_correct > B_total))
    {
      throw std::invalid_argument("Invalid Argument");
    }
    if (((static_cast<double>(A_correct))/A_total) > ((static_cast<double>(B_correct))/B_total))
    {
      return true;
    }
    else 
    {
      return false;
    }
  
  
} 


bool GoodDinner(int pizzas, bool is_weekend) {
  if ((pizzas >= 10 && pizzas <= 20) || (is_weekend && pizzas >= 10)) 
  {
    return true;
  }
  return false;
}

int SumBetween(int low, int high) {
  int value = 0;
  if (low > high)
  {
    throw std::invalid_argument("Invalid Argument");
  }
  // cout << low << endl;
  // cout << high << endl;

  if (((low < 0) && (high > 0)) && (low*-1) < high)
  {
    low = -low+1;
  }

  if (((low < 0) && (high > 0)) && (high*-1) > low)
  {
    high = -high-1;
  }
  if (low == high)
  {
    return low;
  }
  
  
  for (int n = low; n <= high; n++) 
  {
    value += n;
    if (n > 0 && value > 0)
    {
      if (n > INT32_MAX - value)
      {
      throw std::overflow_error("Overflow");
      }
    }
    
    if (n < 0 && value < 0)
    {
      if (n < INT32_MIN - value)
      {
      throw std::overflow_error("Overflow");
      } 
    }
    
  }
  return value;
}

int Product(int a, int b) {
  if (a == 0 || b == 0 )
  {
    return 0;
  }
  else if (a > (INT32_MAX/b) && (b > 0) && (a > 0))
  {
    throw std::overflow_error("Overflow");// not sure if i need to 
  }
  else if ( a < (INT32_MAX/b) && (b < 0) && (a < 0))
  {
    throw std::overflow_error("Overflow");
  }
  else if (b > (INT32_MIN/a)&& (b > 0) && (a < 0))
  {
    throw std::overflow_error("Overflow");
  }
  else if (b < (INT32_MIN/a)&& (b < 0) && (a > 0))
  {
    throw std::overflow_error("Overflow");
  }
  else {
    return a * b;
  }
}