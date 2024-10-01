#include <iostream>
#include <vector>

using namespace std;

// returns index of found element
int binSearch(vector<int> array, int x, int low, int high) {
    if (low >= high) {
        return -1;
    }

    int mid = low + (high - low) / 2;
    
    if (array[mid] == x) {
        return mid;
    }

    if (array[mid] < x) {
        return binSearch(array, x, mid + 1, high);
    }
    else {
        return binSearch(array, x, low, mid - 1);
    }

} 

int main() {

    vector<int> input {1, 2, 3, 4, 5, 6, 8, 10, 12, 50};

    cout << binSearch(input, 12, 0, input.size() - 1) << endl;

    return 0;
}