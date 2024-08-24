/*
    90. Subsets II

    Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

    The solution set must not contain duplicate subsets. Return the solution in any order.

    Example 1:

    Input: nums = [1,2,2]
    Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

*/

// Solution: 

class Solution {
public:

    void findSubsets(int ind, vector<int>& nums, vector<vector<int>>& ans,vector<int>& ds) {
        ans.push_back(ds);
        for(int i = ind; i < nums.size() ; i++) {
            if(i != ind && nums[i] == nums[i - 1]) continue;
            ds.push_back(nums[i]);
            findSubsets(i + 1, nums, ans, ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        findSubsets(0, nums, ans, ds);
        return ans;
    }
};


/*

    Time Complexity: O(2^n * n), n = array size
    Space Complexity: O(2^n) + O(k), k = average size of ds(single subset)

*/ 