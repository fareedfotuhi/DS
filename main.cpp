#include <iostream>

using namespace std;

struct Node {
    struct Node *next;
    struct Node *previous;
    struct Node *tail;
    int id;
};

struct Node *push(struct Node *head, int id) {
    struct Node *newNode = new Node;
    newNode->id = id;
    newNode->previous = nullptr;
    newNode->next = head;
    if (head != nullptr) {
        head->previous = newNode;
        newNode->tail = head->tail;
    } else
        newNode->tail = newNode;
    return newNode;
}

bool isEmpty(struct Node *head) {
    return head == nullptr;
}

int pop(struct Node **head, int type) {
    if (type == 1) {
        int id = (*head)->id;
        (*head) = (*head)->next;
        if ((*head) != nullptr)
            (*head)->previous = nullptr;
        return id;
    } else if (type == 2) {
        int id = (*head)->tail->id;
        (*head)->tail = (*head)->tail->previous;
        if ((*head)->tail != nullptr)
            (*head)->tail->next = nullptr;
        else
            (*head) = nullptr;
        return id;
    }
    return -1;
}

int main() {
    int productLineLength, numberOfJellies;
    cin >> productLineLength >> numberOfJellies;
    int workersTime[productLineLength];
    for (int i = 0; i < productLineLength; i++) {
        cin >> workersTime[i];
    }
    int workersType[productLineLength];
    for (int i = 0; i < productLineLength; i++) {
        cin >> workersType[i];
    }

    struct Node *workersBigJelly[productLineLength];
    int currentWorkersJelly[productLineLength];
    for (int i = 0; i < productLineLength; i++) {
        workersBigJelly[i] = nullptr;
        currentWorkersJelly[i] = -1;
    }
    int jellyRemainedTime[numberOfJellies];
    int jellyTotalTime[numberOfJellies];
    for (int i = 0; i < numberOfJellies; i++) {
        workersBigJelly[0] = push(workersBigJelly[0], i);
        jellyRemainedTime[i] = workersTime[0];
    }

    int numberOfOutputs = 0;
    int clock = 0;
    while (numberOfOutputs < numberOfJellies) {
        clock++;
        for (int i = productLineLength - 1; i >= 0; i--) {
            int jellyIndex = currentWorkersJelly[i];
            if (jellyIndex == -1 && !isEmpty(workersBigJelly[i])) {
                jellyIndex = pop(&workersBigJelly[i], workersType[i]);
                currentWorkersJelly[i] = jellyIndex;
            }

            if (jellyIndex != -1) {
                jellyRemainedTime[jellyIndex]--;
                if (jellyRemainedTime[jellyIndex] == 0) {
                    currentWorkersJelly[i] = -1;
                    if (i == productLineLength - 1) {
                        jellyTotalTime[jellyIndex] = clock;
                        numberOfOutputs++;
                    } else {
                        workersBigJelly[i + 1] = push(workersBigJelly[i + 1], jellyIndex);
                        jellyRemainedTime[jellyIndex] = workersTime[i + 1];
                    }
                }
            }
        }
    }

    for (int i = 0; i < numberOfJellies; i++) {
        cout << jellyTotalTime[i] << " ";
    }

    return 0;
}