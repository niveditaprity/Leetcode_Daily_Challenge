class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int left = 0, right = matrix[0].size()-1;
        int top = 0, down = matrix.size()-1;
        while(left<=right && top<=down) {
            if(left<=right && top<=down) {
                for(int i = left; i<=right; i++) {
                    ans.push_back(matrix[top][i]);
                }
            }
            top++;
            if(left<=right && top<=down) {
                for(int i = top; i<=down; i++) {
                    ans.push_back(matrix[i][right]);
                }
            }
            right--;
            if(left<=right && top<=down) {
                for(int i = right; i>=left; i--) {
                    ans.push_back(matrix[down][i]);
                }
            }
            down--;
            if(left<=right && top<=down) {
                for(int i = down; i>=top; i--) {
                    ans.push_back(matrix[i][left]);
                }
            }
            left++;

        }
        return ans;
    }
};
