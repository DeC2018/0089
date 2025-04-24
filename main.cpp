#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans{0}; // Start with the sequence containing only 0

        for (int i = 0; i < n; ++i) {
            // Reflect the current sequence and add 1 << i to the reflected elements
            for (int j = ans.size() - 1; j >= 0; --j) {
                ans.push_back(ans[j] | (1 << i));
            }
        }

        return ans;
    }
};

void printVector(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i + 1 < vec.size()) cout << ",";
    }
    cout << "]" << endl;
}

int main() {
    Solution solution;

    // Example 1
    int n1 = 2;
    cout << "Input: n = " << n1 << endl;
    vector<int> result1 = solution.grayCode(n1);
    cout << "Output: ";
    printVector(result1);

    // Example 2
    int n2 = 1;
    cout << "Input: n = " << n2 << endl;
    vector<int> result2 = solution.grayCode(n2);
    cout << "Output: ";
    printVector(result2);

    return 0;
}
