#include <iostream>
using namespace std;

void swap(int *a, int *b) {
    int temp;
   temp=*a;
   *a=*b;
   *b=temp;
}

int separatePosNeg(int array[], int mySize) {
    int k = 0;
    for (int i = 0; i < mySize; i++) {
        if (array[i] <= 0) {
            swap(&array[i], &array[k++]);
        }
    }

    return k; // starting index of positive numbers
}

int findMinimumPositive(int array[], int mySize) {
    int startOfPositiveNumbers = separatePosNeg(array, mySize);

    // mark the traversed as negative
    for (int i = startOfPositiveNumbers; i < mySize; i++) {
        if (array[i] - 1 < mySize) {
            array[ array[i] - 1 ] = -array[ array[i] - 1 ];
        }
    }

    // catch the first positive number
    for (int i = startOfPositiveNumbers; i < mySize; i++) {
        if (array[i] > 0) {
            return i + 1;
        }
    }

    return 0;
}

int main() {

    int inputArray[] = {5, 3, 4, 2, 1, -3, 4, 6, 8};
    int lengthOfArray = sizeof(inputArray) / sizeof(inputArray[0]);

    cout << findMinimumPositive(inputArray, lengthOfArray);

    return 0;

}
