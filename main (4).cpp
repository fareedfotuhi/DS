#include <iostream>

using namespace std;

void insert(int *meanHeap, int size, int value);

void bubbleUp(int *meanHeap, int index);

int main() {
    int length;
    cin >> length;
    int heap[length];
    for (int i = 0; i < length; i++) {
        int newData;
        cin >> newData;
        insert(heap, i, newData);
    }
    return 0;
}

void insert(int *meanHeap, int size, int value) {
    meanHeap[size] = value;
    bubbleUp(meanHeap, size);
}

void bubbleUp(int *meanHeap, int index) {
    while (index > 0) {
        if (meanHeap[index] < meanHeap[(index - 1) / 2]) {
            int temp = meanHeap[index];
            meanHeap[index] = meanHeap[(index - 1) / 2];
            meanHeap[(index - 1) / 2] = temp;
            cout << meanHeap[(index - 1) / 2] << " " << meanHeap[index] << endl;
        } else {
            break;
        }
        index = (index - 1) / 2;
    }
}