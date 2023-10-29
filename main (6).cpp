#include <iostream>

using namespace std;

long long calculateBackAche(long long *array, long long start, long long end);

long long calculateBackAcheBetweenHalves(const long long *array, long long start, long long end);

long long getMax(const long long arr[], long long n);

void countSort(long long arr[], long long n, long long exp);

void radixSort(long long *arr, long long n);

void reverseArray(long long arr[], long long start, long long end);

int main() {
    long long length;
    cin >> length;
    long long height[length];
    for (long long i = 0; i < length; i++) {
        cin >> height[i];
    }

    cout << calculateBackAche(height, 0, length);
    return 0;
}

long long calculateBackAche(long long *array, long long start, long long end) {
    if (end == start + 1) {
        return 0;
    }

    long long middle = (start + end) / 2;
    long long firstHalf = calculateBackAche(array, start, middle);
    long long secondHalf = calculateBackAche(array, middle, end);
    long long between = calculateBackAcheBetweenHalves(array, start, end);

    return firstHalf + secondHalf + between;
}

long long calculateBackAcheBetweenHalves(const long long *array, long long start, long long end) {
    long long length = end - start;
    long long tempArr[length];
    for (long long i = 0; i < end - start; i++) {
        tempArr[i] = array[start + i];
    }
    radixSort(tempArr, length / 2);
    reverseArray(tempArr, 0, length / 2 - 1);
    radixSort(tempArr + length / 2, length - length / 2);

    long long inversions = 0;
    long long max_inversion_index = length / 2;
    while (tempArr[0] >= 2 * tempArr[max_inversion_index] && max_inversion_index < length - 1) {
        max_inversion_index++;
    }
    for (long long i = 0; i < length / 2; i++) {
        while (tempArr[i] < 2 * tempArr[max_inversion_index]) {
            max_inversion_index--;
        }
        if (max_inversion_index < length / 2)
            break;
        inversions += max_inversion_index - length / 2 + 1;
    }

    return inversions;
}

// A utility function to get maximum value in arr[]
long long getMax(const long long arr[], long long n) {
    long long mx = arr[0];
    for (long long i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(long long arr[], long long n, long long exp) {
    long long output[n]; // output array
    long long i, count[10] = {0};

    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

// The main function to that sorts arr[] of size n using
// Radix Sort
void radixSort(long long *arr, long long n) {
    // Find the maximum number to know number of digits
    long long m = getMax(arr, n);

    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (long long exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

void reverseArray(long long arr[], long long start, long long end) {
    while (start < end) {
        long long temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}