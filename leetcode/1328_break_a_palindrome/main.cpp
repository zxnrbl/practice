#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        string breakPalindrome(string palindrome) {
            string::iterator start = palindrome.begin();
            string::iterator end = palindrome.end() - 1;
            bool could_decrease = false;
            bool changed = false;

            while(start < end) {
                //cout << *start << "\t" << *end << "\n";
                if(canDecrease(*start)) {
                    //cout << "Letter change\n";
                    could_decrease = true;
                    changed = true;
                    *start = 'a';
                    break;
                }

                ++start;
                --end;
            }

            if(!could_decrease) {
                for(; start < palindrome.end(); ++start) {
                    //cout << *start << "\n";
                    if(start != end) {
                        if(canDecrease(*start)) {
                            //cout << "Letter change\n";
                            could_decrease = true;
                            changed = true;
                            *start = 'a';
                            break;
                        }
                        //else {
                        //    *start = 'b';
                        //    changed = true;
                        //    break;
                        //}
                    }
                }
                if(!changed) {
                    --start;
                    if(start != end) {
                        *start = 'b';
                        changed = true;
                    }
                }
            }

            if(!could_decrease && !changed)
                palindrome.clear();

            return palindrome;
        }

    private:
        bool canDecrease(const char c) {
            return c > 'a';
        }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    Solution s;

    cout << "a\t" << s.breakPalindrome("a") << "\n";
    cout << "abccba\t" << s.breakPalindrome("abccba") << "\n";
    cout << "aa\t" << s.breakPalindrome("aa") << "\n";
    cout << "aba\t" << s.breakPalindrome("aba") << "\n";
    cout << "aabaa\t" << s.breakPalindrome("aabaa") << "\n";

    return 0;
}
