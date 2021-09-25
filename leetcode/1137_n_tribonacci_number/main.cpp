#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int tribonacci(int n) {
            unordered_map<int, int> table;
            table.clear();

            return calculate(n, table);
        }

    private:
        int calculate(int n, unordered_map<int, int>& table) {
            if(table.find(n) != table.end())
                return table[n];

            int i = 0;

            if(n == 0)
                i = 0;
            else if(n == 1)
                i = 1;
            else if(n == 2)
                i = 1;
            else
                i = calculate(n - 1, table) + calculate(n - 2, table) + calculate(n - 3, table);

            table[n] = i;
            return i;
        }
};

int main() {
    Solution s;

    cout << s.tribonacci(4) << "\n";
    cout << s.tribonacci(25) << "\n";

    return 0;
}
