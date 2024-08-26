/*
    46. Permutations
    Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

    Example 1:

    Input: nums = [1,2,3]
    Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

*/

// Solution : with extra space

class Solution {
public:

    void findPermutations(vector<int>& ds, vector<int>& nums, vector<vector<int>>& ans, int freq[]) {
        if(ds.size() == nums.size()) {
            ans.push_back(ds);
            return ;
        }

        for(int i = 0 ; i < nums.size() ; i++ ){
            if(!freq[i]) {
                ds.push_back(nums[i]);
                freq[i] = 1;
                findPermutations(ds, nums, ans, freq);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int freq[nums.size()];
        for(int i = 0 ; i < nums.size() ; i++) freq[i] = 0;
        findPermutations(ds, nums, ans, freq);
        return ans;
    }
};

/*
    Time Complexity: O(n! * n), n = size of array
    Space Complexity: O(n) + O(n)
*/

// Solution: Without extra space

class Solution {
public:

    void findPermutations(int ind, vector<int>& nums, vector<vector<int>>& ans) {
        if(ind == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for(int i = ind ; i < nums.size() ; i++) {
            swap(nums[ind], nums[i]);
            findPermutations(ind + 1, nums, ans);
            swap(nums[ind], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        findPermutations(0, nums, ans);
        return ans;
    }
};

/*
    Time Complexity: O(n! * n)
 */