class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> prevDP(matrix[0].begin(), matrix[0].end()), currDP(n, 0);    

        // Loop through the matrix to find minimum path sum.
        for(int i=1; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                // Find the minimum sum path to reach the current cell. 
                int minPath = prevDP[j];
                minPath = (j > 0) ? min(minPath, prevDP[j-1]) : minPath;
                minPath = (j < (n-1)) ? min(minPath, prevDP[j+1]) : minPath;
                
                // Add current cell value and prev. min. path sum to get the current min. sum path. 
                currDP[j] = matrix[i][j] + minPath;
            }
            prevDP = currDP;
        }

        // Find the minimum sum path from the last reached row and return it.
        return *min_element(prevDP.begin(), prevDP.end());
    }
};