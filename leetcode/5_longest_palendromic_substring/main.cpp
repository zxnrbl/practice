#include <iostream>
#include <string>

class Solution {
    public:
        std::string longestPalindrome(std::string s) {
            std::string longest("");

            for(std::string::const_iterator begin = s.cbegin(); begin != s.cend(); ++begin) {
                std::cout << *begin << std::endl;
                int pos = s.rfind(*begin);

                while(pos != std::string::npos && pos >= std::distance(s.cbegin(), begin)) {
                    std::cout << pos << std::endl;
                    std::string::const_iterator end = s.begin() + pos;

                    if(isPalindrome(begin, end)) {
                        if(std::distance(begin, end + 1) > longest.size()) {
                            longest.replace(longest.begin(), longest.end(), begin, end + 1);
                            std::cout << "Palindrome " << longest.size() << std::endl;
                        }
                    }

                    if(pos == 0)
                        break;

                    pos = s.rfind(*begin, pos - 1);
                }
            }
            return longest;
        }

    private:
        bool isPalindrome(std::string::const_iterator begin, std::string::const_iterator end) {
            while(begin <= end) {
                if(*begin != *end)
                    return false;

                ++begin;
                --end;
            }

            return true;
        }
};

int main() {
    Solution s;

    //std::cout << s.longestPalindrome("babad") << std::endl;
    //std::cout << s.longestPalindrome("cbbd") << std::endl;
    //std::cout << s.longestPalindrome("a") << std::endl;
    //std::cout << s.longestPalindrome("ac") << std::endl;
    std::cout << s.longestPalindrome("1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111") << std::endl;

    return 0;
}
