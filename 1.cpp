#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include <iterator>
using namespace std;

int main() {

	int listOfNumbers[] = {10, 15, 3 ,7};
	size_t n = sizeof(listOfNumbers) / sizeof(listOfNumbers[0]);
	int k = 17;

	map <int, bool> numIfPresent;

	// insert the elements into map
	for (int i = 0; i < n; i++) {
		numIfPresent[listOfNumbers[i]] = true;
	}

	vector <int> foundElements;
	int count = 0;

	// check out each element in O(n) time
	for (int i = 0; i < n; i++) {
		int toFindNum = k - listOfNumbers[i];
		if (numIfPresent[toFindNum]) {
			count += 1;
			numIfPresent[listOfNumbers[i]] = false;
			foundElements.push_back(listOfNumbers[i]);
		}
	}

	cout << count << endl;
	for (vector <int>::iterator p = foundElements.begin(); p != foundElements.end(); p++) {
		printf("(%d, %d)\n", *p, (k - *p));
	}

	return 0;
}