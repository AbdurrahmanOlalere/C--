#include <iostream>
using std::cin, std::cout, std::endl;

int main() {
	int i = 42;
	int *p = &i;
	int *pp = p;

	cout << "Value of i: " << i << endl;
	cout << "Address of i: " << &i << endl;
	cout << "Value of p: " << p << endl;
	cout << "Address of p: " << &p << endl;
	cout << "Value of pp: " << pp << endl;
	cout << "Address of pp: " << &pp << endl;
	return 0;
}