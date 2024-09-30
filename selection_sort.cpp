#include <iostream>
#include <vector>

using namespace std;

int findSmallestIndex(const vector<int>& arr) {
    int smallest = arr[0];
    int smallestIndex = 0;

    for(int i = 1; i < arr.size(); i++) {  
        if (arr[i] < smallest) {

            smallest = arr[i];

            smallestIndex = i;
            
        }
    }

    return smallestIndex;
}

vector<int> selectionSort(vector<int> arr) {
    vector<int> newArr;
    newArr.reserve(arr.size());
    while (!arr.empty()) {

        int smallest = findSmallestIndex(arr);

        int smallestElement = arr[smallest];
        arr.erase(arr.begin() + smallest);  

        newArr.push_back(smallestElement);

    }

    return newArr;
}

int main() {
    vector<int> v{12, 2, 65, 100, 11, 5, 9};

    vector<int> sorted = selectionSort(v);

    for (int i = 0; i < sorted.size(); i++) {  
        cout << sorted[i] << " ";
    }

    return 0;
}
