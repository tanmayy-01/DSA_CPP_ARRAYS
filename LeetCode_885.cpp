/*
    885. Spiral Matrix III

*/

// Solution

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        int n = rows*cols;

        vector<vector<int>> res(n, vector<int>(2));
        res[0][0] = rStart;
        res[0][1] = cStart;

        int count = 1;
        int step = 1;
        int index = 0;

        while(count < n) {
            for(int times = 0; times < 2; times++) {
                int dr = directions[index % 4][0];
                int dc = directions[index % 4][1];

                for(int i = 0; i < step; i++ ){
                    rStart += dr;
                    cStart += dc;
                    if(rStart >= 0 && rStart < rows && cStart >=0 && cStart < cols) {
                        res[count][0] = rStart;
                        res[count][1] = cStart;
                        count++;
                    }
                }
                index++;
            }
            step++;
        }
        return res;
    }
};

/*
    Time Complexity: O(rows * cols)
    Space Complexity: O(rows * cols)
*/