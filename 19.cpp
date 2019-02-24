#include <iostream>
#include <vector>
using namespace std;

typedef vector <vector <int>> costy;

int findMinimumCost(costy& costs, int n, int k){

    int cache[n][k];
    for (int i = 0; i < k; i++) {
        cache[0][k] = costs[0][k];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cache[i][j] = INT32_MAX;
            for (int u = 0; u < k; u++) {
                if (u != j) {
                    cache[i][j] = min(cache[i - 1][j] + costs[i][j], cache[i][j]);
                }
            }
        }
    }

    int temp = INT32_MAX;
    for (int i = 0; i < k; i++) {
        temp = min(temp, cache[n - 1][i]);
    }

    return temp;
}

int main() {

    int n = 6;
    int k = 3;
    costy costs = {
        {7, 3, 8, 6, 1, 3},
        {5, 6, 7, 2, 4, 3},
        {10, 1, 4, 9, 7, 6}
        };
    
    int minCost = findMinimumCost(costs, n, k);
    cout << minCost;

    return 0;

}