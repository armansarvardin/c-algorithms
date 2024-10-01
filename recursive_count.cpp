#include <iostream>
#include <vector>

using namespace std;

int count(vector<int> array) {

    if (array.empty()) {
        return 0;
    }

    array.pop_back();
    
    return count(array) + 1;
}

int main() {

    vector<int> input {1, 2, 3, 4, 5, 6};

    cout << count(input) << endl;

    return 0;
}
