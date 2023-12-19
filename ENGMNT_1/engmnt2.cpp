#include <iostream>
using namespace std;

int factorial(int n){
    int result;
    result = 1;
    for (int i=n; i > 1; --i)
        result = result*i;
    
    return result;
}

int main(){
    int a, b;

    do {
        cout << "Enter two integer a b (with a <= b):";
        cin >> a >> b;
    } while (a > b);

    for (int i=a; i <=b; i++){
       cout << "factorial(" << i << ") returns " << factorial(i) << endl;
    }
}