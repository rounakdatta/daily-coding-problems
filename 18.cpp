#include <iostream>
using namespace std;

void findWindowGreatest(int array[], int n, int k) {

    int j, max;  
  
    for (int i = 0; i <= n - k; i++)  
    {  
        max = array[i];  
  
        for (j = 1; j < k; j++)  
        {  
            if (array[i + j] > max)  
                max = array[i + j];  
        }  
        cout << max << " ";  
    }

}

int main() {

    int array[] = {10, 5, 2, 7, 8, 7};
    int n = sizeof(array) / sizeof(array[0]);
    int k = 3;
    
    findWindowGreatest(array, n, k);
    return 0;

}
