#include <iostream>
#include <vector>

using namespace std;

vector<int> quickSort(vector<int> arr) {
    if (arr.size() < 2) {
        return arr;
    } else {
        int pivot = arr[0];
        
        vector<int> less {};
        vector<int> greater {};


        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] <= pivot) {
                less.push_back(arr[i]);
            } else {
                greater.push_back(arr[i]);
            }
        }


        vector<int> sortedLess = quickSort(less);
        vector<int> sortedGreater = quickSort(greater);


        sortedLess.push_back(pivot);
        sortedLess.insert(sortedLess.end(), sortedGreater.begin(), sortedGreater.end());

        return sortedLess;
    }
}

int main() {
    vector<int> input {1, 10, 5, 6, 2, 12, 90};

    for (int x : quickSort(input)) {
        cout << x << " ";
    }

    return 0;
}
