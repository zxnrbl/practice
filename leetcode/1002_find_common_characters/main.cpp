#include <array>
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::vector<std::string> commonChars(std::vector<std::string>& words) {
        std::array<unsigned int, 26> characters;
        characters.fill(0);

        for(std::vector<std::string>::iterator wp = words.begin(); wp != words.end(); ++wp) {
            std::array<unsigned int, 26> letters;
            letters.fill(0);

            for(std::string::const_iterator cp = wp->begin(); cp != wp->end(); ++cp) {
                letters[char_to_unsigned(*cp)] += 1;
            }

            if(std::distance(words.begin(), wp) == 0) {
                for(unsigned int i = 0; i < characters.size(); ++i)
                    characters[i] = letters[i];
            }
            else {
                for(unsigned int i = 0; i < characters.size(); ++i) {
                    characters[i] = std::min(characters[i], letters[i]);
                }
            }
        }
        std::vector<std::string> common;
        for(unsigned int i = 0; i < characters.size(); ++i) {
            unsigned int n = characters[i];
            while(n > 0) {
                common.push_back(unsigned_to_char(i));
                --n;
            }
        }
        return common;
    }

private:
    unsigned int char_to_unsigned(const char c) {
        return static_cast<unsigned int>(c) - static_cast<unsigned int>('a');
    }

    std::string unsigned_to_char(const unsigned int n) {
        return std::string(1, static_cast<char>(n + static_cast<unsigned int>('a')));
    }
};

int main() {
    Solution s;
    std::vector<std::string> test1 = {"bella", "label", "roller"};
    std::vector<std::string> test2 = {"cool", "lock", "cook"};

    std::vector<std::string> res1 = s.commonChars(test1);
    std::vector<std::string> res2 = s.commonChars(test2);

    return 0;

}
