#include <iostream>

using namespace std;

int getIndex(const int* array, int size, int value);

int getMaxXOR(const int* array, int size, int value);

int main() {
    int numberOfQueries, x;
    char type;
    int khorjin[100000];
    int size = 1;
    cin >> numberOfQueries;
    for (int i = 0; i < numberOfQueries; i++) {
        cin >> type >> x;
        if (type == '+') {
            khorjin[size] = x;
            size++;
        } else if (type == '-') {
            int index = getIndex(khorjin, size, x);
            int temp = khorjin[index];
            khorjin[index] = khorjin[size - 1];
            khorjin[size - 1] = temp;
            size--;
        } else if (type == '?') {
            cout << getMaxXOR(khorjin, size, x) << endl;
        }
    }

    return 0;
}

int getIndex(const int* array, int size, int value) {
    for (int i = 0; i < size; i++) {
        if (array[i] == value)
            return i;
    }
    return -1;
}

int getMaxXOR(const int* array, int size, int value) {
    int max = 0, temp;
    for (int i = 0; i < size; i++) {
        temp = value ^ array[i];
        if (temp > max)
            max = temp;
    }
    return max;
}