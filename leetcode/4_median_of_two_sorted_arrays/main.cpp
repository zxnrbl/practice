#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
            double median = numeric_limits<double>::max();
            double previous = numeric_limits<double>::max();

            const size_t total_size = nums1.size() + nums2.size();
            const size_t iterations = (total_size / 2) + 1;
            const bool even = total_size % 2 == 0;

            std::vector<int>::const_iterator one = nums1.begin();
            std::vector<int>::const_iterator two = nums2.begin();

            for(int i = 0; i < iterations; ++i) {
                previous = median;
                if(one != nums1.end() && two != nums2.end()) {
                    if(*one > *two) {
                        median = *two;
                        ++two;
                    }
                    else {
                        median = *one;
                        ++one;
                    }
                }
                else if(two == nums2.end()) {
                    median = *one;
                    ++one;
                }
                else if(one == nums1.end()) {
                    median = *two;
                    ++two;
                }
            }

            return even ? (median + previous) / 2.0 : median;
        }

    private:
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    std::vector<int> test1_1{1, 3};
    std::vector<int> test1_2{2};

    std::vector<int> test2_1{1, 2};
    std::vector<int> test2_2{3, 4};

    std::vector<int> test3_1{0, 0};
    std::vector<int> test3_2{0, 0};

    std::vector<int> test4_1{};
    std::vector<int> test4_2{1};

    std::vector<int> test5_1{2};
    std::vector<int> test5_2{};

    Solution s;
    std::cout << s.findMedianSortedArrays(test1_1, test1_2) << "\n";
    std::cout << s.findMedianSortedArrays(test2_1, test2_2) << "\n";
    std::cout << s.findMedianSortedArrays(test3_1, test3_2) << "\n";
    std::cout << s.findMedianSortedArrays(test4_1, test4_2) << "\n";
    std::cout << s.findMedianSortedArrays(test5_1, test5_2) << "\n";

    return 0;
}
