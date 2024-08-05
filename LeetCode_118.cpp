/*
    Given an integer numRows, return the first numRows of Pascal's triangle.
*/

//

class Solution {
public:

    vector<int> generateRow(int rowNumber) {
        long long ans = 1;
        vector<int> ansRow;
        ansRow.push_back(1);
        for(int col = 1 ; col < rowNumber ; col++) {
            ans = ans * (rowNumber - col);
            ans = ans / col;
            ansRow.push_back(ans);
        } 
        return ansRow;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i = 1 ; i <= numRows ; i++) {
            ans.push_back(generateRow(i));
        }
    return ans;
    }
};
