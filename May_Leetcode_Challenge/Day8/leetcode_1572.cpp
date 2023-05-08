class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        
        int totalSum = 0;
        int m = mat.size();
        for(int i = 0; i<m; i++)
        {
            totalSum+= mat[i][i];
            totalSum+= mat[i][m-i-1];
        }
        if(m%2 != 0)
        {
            totalSum-=mat[m/2][m/2];
        }
        return totalSum;
    }
};
