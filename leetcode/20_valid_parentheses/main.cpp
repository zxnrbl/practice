#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool isValid(string s) {
            stack<char> st;
            unordered_map<char, char> m;
            m.emplace(make_pair('(', ')'));
            m.emplace(make_pair('{', '}'));
            m.emplace(make_pair('[', ']'));

            for(auto& c : s) {
                cerr << c << "\n";
                if(m.find(c) == m.end()) {
                    if(st.empty())
                        return false;

                    const char top = st.top();
                    cerr << "Top " << top << "\n";
                    cerr << "Stk " << m.at(top) << "\n";

                    if(m.at(top) == c)
                        st.pop();
                    else
                        return false;
                }
                else {
                    cerr << "Push " << c << "\n";
                    st.push(c);
                }
            }
            
            return st.empty();
        }
};

int main() {
    string tc1("]");
    Solution s;

    cout << tc1 << "\t" << boolalpha << s.isValid(tc1) << "\n";
    return 0;
}
