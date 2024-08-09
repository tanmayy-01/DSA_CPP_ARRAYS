/*
    840. Magic Squares In Grid

    A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.

    Given a row x col grid of integers, how many 3 x 3 contiguous magic square subgrids are there?

    Note: while a magic square can only contain numbers from 1 to 9, grid may contain numbers up to 15.

*/

class Solution {
public:

    int findRowSum(vector<vector<int>>& grid, int r, int c) {
        vector<bool> visited(10, false);
        int sum = 0; 
        for(int i = 0; i < 3; i++) {
            int rSum = 0;
            for(int j = 0; j < 3; j++) {
                int val = grid[r + i][c + j];
                if(val == 0 || val >= 10 || visited[val]) {
                    return -1;
                }
                visited[val] = true;
                rSum += val;
            }
            if(i == 0) {
                sum = rSum;
            } else if(sum != rSum) {
                return -1;
            }
        }
        return sum;
    }

    int findColSum(vector<vector<int>>& grid, int r, int c) {
        int sum = 0; 
        for(int j = 0; j < 3; j++) {
            int cSum = 0;
            for(int i = 0; i < 3; i++) {
                int val = grid[r + i][c + j];
                cSum += val;
            }
            if(j == 0) {
                sum = cSum;
            } else if(sum != cSum) {
                return -1;
            }
        }
        return sum;
    }

    int findDiagonalSum(vector<vector<int>>& grid, int r, int c) {
        int sum1 = grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2]; 
        int sum2 = grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c]; 
        if(sum1 == sum2) {
            return sum1;
        } else {
            return -1;
        }
    }

    bool isMagicSquare(vector<vector<int>>& grid, int r, int c) {
        int rowSum = findRowSum(grid, r, c);
        if(rowSum == -1) return false;
        int colSum = findColSum(grid, r, c);
        if(colSum == -1) return false;
        int diagonalSum = findDiagonalSum(grid, r, c);  // Corrected function name
        if(diagonalSum == -1) return false;

        return (rowSum == colSum && rowSum == diagonalSum);
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;
        for(int i = 0; i < rows - 2; i++) {
            for(int j = 0; j < cols - 2; j++) {
                if(isMagicSquare(grid, i, j)) {
                    count++;
                }
            }
        }
        return count;
    }
};

/*
    Space Complexity: O(rows * cols)
*/