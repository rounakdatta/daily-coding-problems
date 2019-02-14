#include <iostream>
using namespace std;

int main() {
    
    int setOfNumbers[] = {2, 4, 6, 9, 18, 14};
    int n = sizeof(setOfNumbers) / sizeof(setOfNumbers[0]);

    int sum0 = setOfNumbers[0];
    int sum1 = 0;

    for (int i = 1; i < n; i++) {
        int temp = (sum0 > sum1)? sum0: sum1;

        sum0 = sum1 + setOfNumbers[i];
        sum1 = temp;
    }

    cout << max(sum0, sum1);

    return 0;

}