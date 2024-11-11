#include <iostream>
using namespace std;

template <typename T>
class DescendingSort {
private:
    T* arr;     
    int size;  

public:
    DescendingSort(T array[], int s) {
        size = s;
        arr = new T[size];
        for (int i = 0; i < size; i++) {
            arr[i] = array[i];
        }
    }

    void sortArray() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (arr[j] < arr[j + 1]) {
                    T temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    void printArray() const {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~DescendingSort() {
        delete[] arr;
    }
};

int main() {
    int intArray[] = { 3, 1, 4, 1, 5, 9 };
    double doubleArray[] = { 2.3, 5.6, 3.4, 7.9, 8.8 };

    DescendingSort<int> intSorter(intArray, 6);
    DescendingSort<double> doubleSorter(doubleArray, 5);

    cout << "Integer array before sorting: ";
    intSorter.printArray();
    intSorter.sortArray();
    cout << "Integer array after sorting in descending order: ";
    intSorter.printArray();

    cout << "Double array before sorting: ";
    doubleSorter.printArray();
    doubleSorter.sortArray();
    cout << "Double array after sorting in descending order: ";
    doubleSorter.printArray();

    return 0;
}

