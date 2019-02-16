#include <iostream>
using namespace std;

int countPossibleWays(int *myset, int combos, int n) {
    if (n == 0) {
        return 1;
    }

    int ways = 0;
    for (int i = 0; i < combos; i++) {
        if (n >= myset[i]) {
            ways += countPossibleWays(myset, combos, (n - myset[i]));
        }
    }
    return ways;
}

int main() {

    int x[] = {1, 3, 5};
    int combos = sizeof(x) / sizeof(x[0]);
    int n = 4;
    int ways = countPossibleWays(x, combos, n);
    cout << ways << endl;

    return 0;

}