#include <iostream>
#include <vector>

using namespace std;

int sum(vector<int> array) {
    if (array.empty()) {
        return 0;
    }

    int last = array.back();
    array.pop_back();
    
    return last + sum(array);
}

int main() {

    vector<int> input {1, 2, 3, 4, 5, 6};

    cout << sum(input);

    return 0;
}