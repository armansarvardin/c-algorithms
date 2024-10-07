#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // For std::max

using namespace std;

int main() {
    string s1 = "blue";
    string s2 = "clues";

    
    vector<vector<int>> grid(s1.size() + 1, vector<int>(s2.size() + 1, 0));

    
    for (int i = 1; i <= s1.size(); i++) {
        for (int j = 1; j <= s2.size(); j++) {
            if (s1[i - 1] == s2[j - 1]) {
                grid[i][j] = grid[i - 1][j - 1] + 1;
            } else {
                grid[i][j] = max(grid[i - 1][j], grid[i][j - 1]);
            }
        }
    }

    for (int i = 0; i <= s1.size(); i++) {
        for (int j = 0; j <= s2.size(); j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }


    int i = s1.size();
    int j = s2.size();
    string lcs = "";

    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            lcs += s1[i - 1];
            i--;
            j--;
        } else if (grid[i - 1][j] > grid[i][j - 1]) {
            // Move up
            i--;
        } else {
            // Move left
            j--;
        }
    }

    reverse(lcs.begin(), lcs.end());

    cout << "Longest Common Subsequence: " << lcs << endl;

    return 0;
}
