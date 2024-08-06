/*
    3016. Minimum number of pushes to type word II
*/

// Greedy Approach

class Solution {
public:
    int minimumPushes(string word) {
        map<char, int> mp;

        for(auto ch: word) {
            mp[ch]++;
        }

        vector<int> v;
        for(auto p : mp) {
            v.push_back(p.second);
        }

        sort(v.begin(), v.end(),greater<int>());

        int ans = 0, count = 0;

        for(auto p : v) {
            count++;
            if(count <= 8) {
                ans += 1 * p;
            }else if(count <= 16) {
                ans += 2 * p;
            }else if(count <= 24) {
                ans += 3 * p;
            }else {
                ans += 4 * p;
            }
        }
        return ans;
    }
};