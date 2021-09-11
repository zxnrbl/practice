#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
    public:
        int lengthOfLongestSubstring(std::string s) {
            int first = 0;
            int second = 0;
            int longest = 0;
            std::unordered_map<char, int> characters;
            characters.clear();

            while(second < s.size()) {
                const char c = s.at(second);

                if(characters.find(c) == characters.end()) {
                    characters[c] = second;
                }
                else {
                    int advance = characters.at(c);

                    while(first <= advance) {
                        const char e = s.at(first++);
                        characters.erase(e);
                    }

                    characters[c] = second;
                }
                longest = longest > characters.size() ? longest: characters.size();
                ++second;
            }

            return longest;
        }
};

int main() {
    std::string test("bpfbhmipx");
    Solution s;

    std::cout << s.lengthOfLongestSubstring(test) << std::endl;

    return 0;
}
