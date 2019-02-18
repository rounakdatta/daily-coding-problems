#include <iostream>
#include <map>
#include <tuple>
#include <iterator>
using namespace std;

map <int, tuple <int, int>> distance2tuple;
int maxLengthReached = 0;

void findLongestSubstring(string payload, int k, int *start, int *end) {

    map <char, bool> char2present;
    if (*start == payload.length() - 1) {
        return;
    }

    int distinctCount = 0;
    while (*end < payload.length()) {
        bool isDistinct = false;
        if (!char2present[payload[*end]]) {
            // found a distinct character
            distinctCount += 1;
            char2present[payload[*end]] = true;

            isDistinct = true;
        }
        if (isDistinct && distinctCount > k) {
            break;
        }
        *end = *end + 1;
    }
    *end = *end - 1;
    distance2tuple[*end - *start + 1] = make_tuple(*start, *end);
    maxLengthReached = max(maxLengthReached, *end - *start + 1);
    *start = *start + 1;
    *end = *start;
    findLongestSubstring(payload, k, start, end);
}

int main() {

    string payload = "abcba";
    int k = 2;
    int start = 0, end = 0;
    findLongestSubstring(payload, k, &start, &end);

    cout << maxLengthReached << endl;
    tuple <int, int> longestSubstring = distance2tuple[maxLengthReached];
    for (int i = get<0>(longestSubstring); i <= get<1>(longestSubstring); i++) {
        cout << payload[i];
    }

    return 0;

}