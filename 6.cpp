#include <iostream>
using namespace std;

struct XORNode {
    int data;
    XORNode *both;
};

void insertIntoList(XORNode *ref, int data, XORNode *lastNode) {
    
    XORNode *newn = new XORNode;
    newn->data = data;

    XORNode *temp = ref;

    if (temp->both == lastNode) {
        newn->both = (XORNode*)((uintptr_t)temp ^ (uintptr_t)temp->both);
        temp->both = newn;
        lastNode->both = temp;
        return;
    }

    XORNode *curr = temp;
    XORNode *prev = temp;
    curr = prev->both;

    while ((XORNode*)((uintptr_t)curr->both ^ (uintptr_t)prev) != lastNode) {
        XORNode *tempKeep = curr;
        curr = (XORNode*)((uintptr_t)curr->both ^ (uintptr_t)prev);
        prev = tempKeep;
    }

    curr->both = (XORNode*)(((uintptr_t)curr->both ^ (uintptr_t)lastNode) ^ (uintptr_t)newn);
    newn->both = (XORNode*)((uintptr_t)curr ^ (uintptr_t)lastNode);

    return;

}

XORNode* getFromList(XORNode *ref, int index, XORNode *lastNode) {
    XORNode *prev = ref;
    XORNode *curr = prev->both;

    int count = 0;

    while (curr != lastNode) {
        
        if (count == index) {
            return curr;
        }
        
        XORNode *tempKeep = curr;
        curr = (XORNode*)((uintptr_t)curr->both ^ (uintptr_t)prev);
        prev = tempKeep;

        count += 1;
    }

    return curr;

}

int main() {

    XORNode *head = new XORNode;
    XORNode *end = new XORNode;
    
    head->both = end;
    end->both = head;

    insertIntoList(head, 1, end);
    insertIntoList(head, 2, end);
    insertIntoList(head, 3, end);
    insertIntoList(head, 4, end);
    insertIntoList(head, 5, end);

    XORNode *gettingNode = getFromList(head, 3, end);
    cout << gettingNode->data;

    return 0;

}