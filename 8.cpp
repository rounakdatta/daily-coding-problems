#include <iostream>
using namespace std;

struct univTree {
    int data;
    univTree *left;
    univTree *right;
};

void insertIntoTree(univTree *location, int leftOrRight, int data) {
    univTree *newn = new univTree;
    newn->data = data;
    newn->left = NULL;
    newn->right = NULL;

    if (leftOrRight == -1) {
        location->left = newn;
        return;
    }

    if (leftOrRight == 1) {
        location->right = newn;
        return;
    }

    return;
}

int calcUnivalSubtrees(univTree *ref) {
    if (ref->left == NULL && ref->right == NULL) {
        return 1;
    }

    int thisOne = 0, leftCount, rightCount;

    if (ref->left != NULL && ref->right != NULL) {
        thisOne = (ref->left->data == ref->data && ref->right->data == ref->data)? 1: 0;
    }

    if (ref->left != NULL) {
        leftCount = calcUnivalSubtrees(ref->left);
    }

    if (ref->right != NULL) {
        rightCount = calcUnivalSubtrees(ref->right);
    }

    return thisOne + leftCount + rightCount;
}

int main() {
    
    univTree *baseTree = new univTree;

    /* this is the currently taken tree

       0
      / \
     1   0
        / \
       1   0
      / \
     1   1

    */

    baseTree->data = 0;
    insertIntoTree(baseTree, -1, 1);
    insertIntoTree(baseTree, 1, 0);
    insertIntoTree(baseTree->right, -1, 1);
    insertIntoTree(baseTree->right, 1, 0);
    insertIntoTree(baseTree->right->left, -1, 1);
    insertIntoTree(baseTree->right->left, 1, 1);

    int total = calcUnivalSubtrees(baseTree);
    cout << total;
    
    return 0;

}