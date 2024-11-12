#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

const int SIZE = 27;
const int LOWER_BOUND = -35;
const int UPPER_BOUND = 25;

void generateArray(int arr[], int size) {
    if (size == 0) return;
    arr[SIZE - size] = rand() % (UPPER_BOUND - LOWER_BOUND + 1) + LOWER_BOUND;
    generateArray(arr, size - 1);
}

void printArray(const int arr[], int size) {
    if (size == 0) return;
    cout << setw(4) << arr[SIZE - size];
    printArray(arr, size - 1);
}

int countElements(const int arr[], int size, bool (*criteria)(int)) {
    if (size == 0) return 0;
    return criteria(arr[SIZE - size]) + countElements(arr, size - 1, criteria);
}

int sumElements(const int arr[], int size, bool (*criteria)(int)) {
    if (size == 0) return 0; // Базовий випадок
    return (criteria(arr[SIZE - size]) ? arr[SIZE - size] : 0) + sumElements(arr, size - 1, criteria);
}

void replaceWithZero(int arr[], int size, bool (*criteria)(int)) {
    if (size == 0) return;
    if (criteria(arr[SIZE - size])) {
        arr[SIZE - size] = 0;
    }
    replaceWithZero(arr, size - 1, criteria);
}

bool isPositive(int num) {
    return num > 0;
}

bool isOdd(int num) {
    return num % 2 != 0;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    int arr[SIZE];


    generateArray(arr, SIZE);


    cout << "The generated array: ";
    printArray(arr, SIZE);
    cout << endl;


    int countPos = countElements(arr, SIZE, isPositive);
    int sumPos = sumElements(arr, SIZE, isPositive);
    replaceWithZero(arr, SIZE, isPositive);


    cout << "The number of paired elements: " << countPos << endl;
    cout << "The sum of paired elements: " << sumPos << endl;


    cout << "Modified array after replacing with zeros: ";
    printArray(arr, SIZE);
    cout << endl;


    int countOdd = countElements(arr, SIZE, isOdd);
    int sumOdd = sumElements(arr, SIZE, isOdd);
    replaceWithZero(arr, SIZE, isOdd);


    cout << "The number of odd elements: " << countOdd << endl;
    cout << "The sum of odd elements: " << sumOdd << endl;


    cout << "Last modified array after replacing with zeros: ";
    printArray(arr, SIZE);
    cout << endl;

    return 0;
}
