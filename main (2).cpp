#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Node *findParent(struct Node *head, int value);

struct Node *insert(struct Node *head, int value);

long long calculate_sum();

long long result[2][10000]; // index_from_left & value

struct Node {
    Node *parent;
    Node *left;
    Node *right;
    int value;
    long long index_from_left;
};

void setIndex(struct Node *node, long long parentIndex, int isRight) {
    if (2 * parentIndex < parentIndex)
        node->index_from_left = LONG_LONG_MAX;
    else
        node->index_from_left = 2 * parentIndex - isRight;
}

struct Node *insert(struct Node *head, int value) {
    struct Node *parent = findParent(head, value);
    struct Node *newNode = new Node;
    newNode->parent = parent;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->value = value;
    if (parent == nullptr) {
        newNode->index_from_left = 1;
    } else if (parent->value > value) {
        parent->left = newNode;
        setIndex(newNode, parent->index_from_left, 1);
    } else if (parent->value < value) {
        parent->right = newNode;
        setIndex(newNode, parent->index_from_left, 0);
    }

    int depth = 0;
    while (parent != nullptr) {
        parent = parent->parent;
        depth++;
    }
    if (newNode->index_from_left < result[0][depth] || result[0][depth] == -1) {
        result[0][depth] = newNode->index_from_left;
        result[1][depth] = newNode->value;
    }

    if (head == nullptr)
        return newNode;
    else
        return head;
}

struct Node *findParent(struct Node *head, int value) {
    if (head == nullptr)
        return nullptr;

    if (head->value > value) {
        if (head->left == nullptr)
            return head;
        return findParent(head->left, value);
    } else if (head->value < value) {
        if (head->right == nullptr)
            return head;
        return findParent(head->right, value);
    }
    return nullptr;
}

int main() {
    struct Node *head = nullptr;
    for (int i = 0; i < 10000; i++)
        result[0][i] = -1;
    int number, queries, value;
    cin >> number >> queries;
    for (int i = 0; i < number; i++) {
        cin >> value;
        head = insert(head, value);
    }
    cout << calculate_sum() << endl;

    for (int i = 0; i < queries; i++) {
        cin >> value;
        head = insert(head, value);
        cout << calculate_sum() << endl;
    }

    return 0;
}

long long calculate_sum() {
    long long sum = 0;
    for (int i = 0; result[0][i] != -1; i++) {
        sum += result[1][i];
    }
    return sum;
}