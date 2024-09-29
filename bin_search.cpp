#include <iostream>

#include <algorithm>

#include <vector>

using namespace std;

int binSearch(vector<int> a, int item) {
    int low = 0;
    size_t high = a.size() - 1;

    while (low <= high) {

        int mid = (low + high);
        int guess = a[mid];

        if (guess == item) {
            return mid;
        }
        if (guess > item) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    return -1;
}

int main() {
    vector<int> vect{1, 2, 3, 4, 5, 6, 9, 11, 13};

    cout << binSearch(vect, 5) << endl;

    return -1;
}