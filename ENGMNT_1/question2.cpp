#include <iostream>
using namespace std;

int main(){
    const int n=10;
    int array[n];

    for (int i=0; i < 10; ++i){
       array[i] = i*i;
       cout << array[i] << endl;
    }

    cout << array[9] << endl;
    return 0;
}