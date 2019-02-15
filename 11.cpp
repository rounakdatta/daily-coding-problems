#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

struct trieNode {
    char letter;
    vector <trieNode*> connections;
};

void insertIntoTrie(string *bagOfWords, int count, trieNode *head) {
    trieNode *ref = head;

    for (int i = 0; i < count; i++) {
        // a word starts
        for (int x = 0; x < bagOfWords[i].length(); x++) {

            bool isLetterPresent = false;
            for (vector <trieNode*>::iterator p = ref->connections.begin(); p != ref->connections.end(); p++) {
                trieNode *temp = *p;
                if (temp->letter == bagOfWords[i][x]) {
                    ref = temp;
                    isLetterPresent = true;
                    break;
                }
            }

            if (!isLetterPresent) {
                trieNode *newn = new trieNode;
                newn->letter = bagOfWords[i][x];
                ref->connections.push_back(newn);
                ref = newn;
            }
        }
        ref = head;
    }
}

void getAllWordsDownThere(trieNode *ref, string *results, int pos) {
    // perform some DFS
    int i = 0;

    for (vector <trieNode*>::iterator p = ref->connections.begin(); p != ref->connections.end(); p++) {
        trieNode *temp = *p;
        results[pos] += temp->letter;
        getAllWordsDownThere(temp, results, pos);
        pos += 1;
    }
}

void autocomplete(trieNode *head, string query, string *results) {
    trieNode *ref = head;
    for (int i = 0; i < query.length(); i++) {
        bool validQuery = false;
        for (vector <trieNode*>::iterator p = ref->connections.begin(); p != ref->connections.end(); p++) {
            trieNode *temp = *p;
            if (temp->letter == query[i]) {
                ref = temp;
                validQuery = true;
                break;
            }
        }

        if (!validQuery) {
            cout << "No results found\n";
            return;
        }
    }
    // now can extract all the autocompletions from the vector
    getAllWordsDownThere(ref, results, 0);
}

int main() {
    
    string bagOfWords[] = {"dog", "deer", "deal", "duck"};
    int n = sizeof(bagOfWords) / sizeof(bagOfWords[0]);
    trieNode *head = new trieNode;
    head->letter = '\0';

    insertIntoTrie(bagOfWords, n, head);

    string query = "de";
    string results[INT32_WIDTH] = {};
    autocomplete(head, query, results);

    for (int i = 0; !results[i].empty(); i++) {
        cout << query + results[i] << endl;
    }

    return 0;

}