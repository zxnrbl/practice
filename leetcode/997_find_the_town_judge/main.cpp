#include <unordered_map>

using namespace std;

class Solution {
    public:
        int findJudge(int n, vector<vector<int>>& trust) {
            unordered_map<int, Node> graph;

            for(vector<vector<int>>::const_iterator it = trust.begin(); it != trust.end(); ++it) {
                graph[it->at(1)].neighbors.push_back(it->at(0));
                graph[it->at(0)].trusts = true;
            }

            for(int i = 1; i <= n; ++i) {
                if(graph[i].trusts)
                    continue;

                if(graph[i].neighbors.size() == n - 1)
                    return i;
            }

            return -1;
        }

    private:
        struct Node {
            vector<int> neighbors;
            bool trusts;

            Node(): trusts(false) {neighbors.clear();}
        };
}

int main() {
    Solution s;

    return 0;
}
