/*
560. Subarray sum Equal K

Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

*/

// Brute Solution 

/*
    Time Complexity: near to O(n^2)
    Space Complexity: O(1)
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        for(int i = 0 ; i < nums.size() ; i++) {
            int sum = 0;
            for(int j = i ; j < nums.size() ; j++) {
                sum += nums[j];
                if(sum == k) {
                    count++;
                }
            }
        }
        return count;
    }
};

// Optimal Solution

/*
    Time Complexity: O(n logn)
    Space Compexity: O(n)
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> mpp;
        mpp[0] = 1;
        int preSum = 0, count = 0;
        for(int i = 0 ; i < nums.size() ; i++) {
            preSum += nums[i];
            int remove = preSum - k;
            count += mpp[remove];
            mpp[preSum] += 1;
        }

        return count;
    }
};
