#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include <string>
using namespace std;

string mainNumber = "";
map <int, char> index2alphabet;
map <string, bool> dynamicArray;

int findPossibleDecodings(int extracted, int payload, vector <int> foo) {

    string calcNumber = "";
    string calcString = "";

    for (int i = foo.size() - 1; i >= 0; i--) {
        calcNumber += to_string(foo[i]);
        calcString += index2alphabet[foo[i]];
    }

    if(payload == 0) {
        if (mainNumber.compare(calcNumber) || dynamicArray[calcString] == 1) {
            return 0;
        }
        cout << calcString << endl;
        dynamicArray[calcString] = true;
        return 1;
    }

    int first = payload % 10;
    int firstRemains = payload / 10;

    int second = payload % 100;
    int secondRemains = 0;

    if (second > 9 && second <= 26) {
        secondRemains = payload / 100;
    }

    vector <int> firstExtracts, secondExtracts;
    firstExtracts = foo;
    firstExtracts.push_back(first);

    secondExtracts = foo;
    secondExtracts.push_back(second);

    return findPossibleDecodings(first, firstRemains, firstExtracts) + findPossibleDecodings(second, secondRemains, secondExtracts);

}

int main() {

    char currentChar = 'a';
    for (int i = 1; i <= 26; i++) {
        index2alphabet[i] = currentChar;
        currentChar += 1;
    }

    int payload = 1234;
    mainNumber = to_string(payload);
    map <string, bool> isElementThere;

    vector <int> nothing;
    int totalCount = findPossibleDecodings(0, payload, nothing);
    cout << totalCount;


    return 0;

}