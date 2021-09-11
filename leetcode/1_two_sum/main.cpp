#include <unordered_map>

using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int, int> compliments;
            vector<int> sol;

            for(unsigned i = 0; i < nums.size(); ++i) {
                unordered_map<int, int>::const_iterator it = compliments.find(nums.at(i));

                if(it != compliments.end()) {
                    sol.push_back(it->second);
                    sol.push_back(i);
                    break;
                }

                compliments[target-nums.at(i)] = i;
            }

            return sol;
        }
}

int main() {
    Solution s;

    return 0;
}
