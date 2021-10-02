#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int totalFruit(vector<int>& fruits) {
            unordered_map<int, int> types;
            int max = 1;
            int current_streak = 0;

            for(size_t i = 0; i < fruits.size(); ++i) {
                const int fruit = fruits.at(i);

                if(types.size() < 2) {
                    types.emplace(make_pair(fruit, i));
                }

                if(types.find(fruit) == types.end()) {
                    int last_occurance = i;
                    unordered_map<int, int>::const_iterator target = types.begin();
                    for(unordered_map<int, int>::const_iterator it = types.begin(); it != types.end(); ++it) {
                        if(it->second < last_occurance) {
                            target = it;
                            last_occurance = it->second;
                        }
                    }

                    if(current_streak > max) {
                        max = current_streak;
                    }

                    current_streak = i - last_occurance;
                    types.erase(target);
                    types.emplace(make_pair(fruit, i));
                }
                else {
                    types.at(fruit) = i;
                    ++current_streak;
                }
            }

            return current_streak > max ? current_streak : max;
        }
};

int main() {
    vector<int> tc1 = {1, 2, 1};
    vector<int> tc2 = {0, 1, 2, 2};
    vector<int> tc3 = {1, 2, 3, 2, 2};
    vector<int> tc4 = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};

    Solution s;

    cout << "TC1: " << s.totalFruit(tc1) << "\n";
    cout << "TC2: " << s.totalFruit(tc2) << "\n";
    cout << "TC3: " << s.totalFruit(tc3) << "\n";
    cout << "TC4: " << s.totalFruit(tc4) << "\n";

    return 0;
}
