#include <iostream>
using namespace std;

int main() {
    int array[] = {9, 11, 8, 5, 7, 10};
    int n = sizeof(array) / sizeof(array[0]);

    int currMin = INT32_MAX;
    int currMax = INT32_MIN;
    int currDiff = 0;

    for (int i = 0; i < n; i++) {
        int currElement = array[i];
        if (currElement < currMin) {
            currMin = currElement;
            currMax = INT32_MIN;
        } else if (currElement > currMax) {
            currMax = currElement;
            currDiff = max(currDiff, (currMax - currMin));
        }
    }

    cout << currDiff;
}