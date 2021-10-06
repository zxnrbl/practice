#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> findDuplicates(vector<int>& nums) {
            unordered_set<int> seen;
            vector<int> output;
            seen.reserve(nums.size());

            for(auto& n: nums) {
                if(seen.find(n) == seen.end()) {
                    seen.insert(n);
                }
                else {
                    output.emplace_back(n);
                }
            }

            return output;
        }
};

int main() {
    vector<int> tc1 = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> tc2 = {1, 1, 2};
    vector<int> tc3 = {};

    Solution s;

    cout << s.findDuplicates(tc1) << "\n";
    cout << s.findDuplicates(tc2) << "\n";
    cout << s.findDuplicates(tc3) << "\n";

    return 0;
}
