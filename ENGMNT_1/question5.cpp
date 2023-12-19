#include <iostream>
using namespace std;

int sum(int numbers[], int num_elements){
    int sum = 0;
    for (int i=0; i < num_elements; i++){
        sum+=numbers[i];
    }
    return sum;
}

double avg(int numbers[], int num_elements){
    double avg =0.0;
    int num_element=0;
    
    avg = sum(numbers, num_elements)/num_element;

    return avg;
}


int main(){
    const int NUM_ELEMENTS = 3;
    int in_numbers[NUM_ELEMENTS];

    for (int i=0; i < NUM_ELEMENTS; i++) {
        cin >> in_numbers[i];
    }

    cout << "Sum of elements is " << sum(in_numbers, NUM_ELEMENTS) << endl;
    cout << "Avg of elements is " << avg(in_numbers, NUM_ELEMENTS) << endl;

    return 0;
}
