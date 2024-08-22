/*
    78. Subsets

    Given an integer array nums of unique elements, return all possible subsets (the power set).

    The solution set must not contain duplicate subsets. Return the solution in any order.

    Example 1:

    Input: nums = [1,2,3]
    Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
*/

// 1. Solution: Brute

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int subsetsCount = 1 << nums.size();
        vector<vector<int>> ans;

        for(int num = 0 ; num <= subsetsCount - 1 ; num++) {
            vector<int> subset;
            for(int i = 0 ; i <= nums.size() - 1 ; i++) {
                if(num & (1 << i)) {
                    subset.push_back(nums[i]);
                }
            }
            ans.push_back(subset);
        }
        return ans;
    }
};

/*
    Time Complexity: O(2^n * n) // n = size of array
    Space Complexity: near about O(2^n * n)
*/

// 2. Solution: Recursive

class Solution {
public:
    void subsets(int ind, int N, vector<vector<int>> &ans, vector<int> &nums, vector<int> &ds) {
        if(ind == N) {
            ans.push_back(ds);
            return ;
        }
        ds.push_back(nums[ind]);
        subsets(ind + 1 , N, ans, nums, ds);

        ds.pop_back();
        subsets(ind + 1, N, ans, nums, ds);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        subsets(0, nums.size(), ans, nums, ds);
        return ans;
    }
};