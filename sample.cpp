#include <iostream>
using namespace std;

void findAllPossibleCombinations(int n, int howMany, int *x, int *count) {

    if (n == 0) {
        *count += 1;
        return;
    }

    if (n < 0) {
        return;
    }

    for (int i = 0; i < howMany; i++) {
        findAllPossibleCombinations(n - x[i], howMany, x, count);
    }
}

int main() {

    int x[] = {1, 3, 5};
    int n = 4;

    int count = 0;
    findAllPossibleCombinations(n, sizeof(x) / sizeof(x[0]), x, &count);
    cout << count;
    
    return 0;

}