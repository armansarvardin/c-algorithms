#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int maximum(vector<int> array) {

    if (array.empty()) {
        return INT_MIN;
    }

    int last = array.back();
    array.pop_back();

    return max(last, maximum(array));
}

int main() {

    vector<int> input {1, 2, 3, 4, 5, 6};

    cout << maximum(input) << endl;
    
    return 0;
}