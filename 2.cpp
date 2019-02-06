#include <iostream>
using namespace std;

int main() {

    int listOfNumbers[] = {1, 2, 3 ,4, 5};
    int n = sizeof(listOfNumbers) / sizeof(listOfNumbers[0]);

    int waiter = 1;

    int finalListOfNumbers[n];

    // constructing the product of the elements to the left of it
    for (int i = 0; i < n; i++) {
        finalListOfNumbers[i] = waiter;
        waiter *= listOfNumbers[i];
    }

    waiter = 1;

    // multiply with the others on right (of course not oneself)
    for (int i = n - 1; i >= 0; i--) {
        finalListOfNumbers[i] *= waiter;
        waiter *= listOfNumbers[i];
    }

    for (size_t i = 0; i < n; i++) {
        cout << finalListOfNumbers[i] << endl;
    }

    return 0;
}

/*
Would like to write a few words about some conclusions and learnings from this problem
size_t is wonderful, and definitely a swissknife, however be very careful as it might bleed in cases you'd sweat to find out
size_t rotates back to 1 after [reaching zero and --i] and you'd therefore not be able to catch the case of >= 0
the same follows for uint[8-256]
*/