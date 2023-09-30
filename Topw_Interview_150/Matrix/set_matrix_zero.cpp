
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int c = matrix[0].size();
        int r = matrix.size();
        vector<bool>col(c, false);
        vector<bool>row(r,false);

        for(int i = 0; i<r; i++) {
            for(int j = 0; j<c; j++) {
                if(matrix[i][j] == 0) {
                    col[j] = true;
                    row[i] = true;
                }
            }
        }

        for(int i = 0; i<r; i++) {
            if(row[i] == true) {
                for(int j = 0; j<c; j++) {
                    matrix[i][j] = 0;
                }

            }
        }
        for(int i = 0; i<c; i++) {
            if(col[i] == true) {
                for(int j = 0; j<r; j++) {
                    matrix[j][i] = 0;
                }
            }
        }

    }
};


//Optimal solution




class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int c = matrix[0].size();
        int r = matrix.size();
        // vector<bool>col(c, false);
        // vector<bool>row(r,false);
        bool col = false;

        for(int i = 0; i<r; i++) {
            for(int j = 0; j<c; j++) {
                if(matrix[i][j] == 0) {
                     matrix[i][0] = 0;
                    if(j== 0) {
                        col = true;
                    }
                    else {
                        matrix[0][j] = 0;
                    }
                }
            }
        }
        for(int i = 1; i<r; i++) {
                for(int j = 1; j<c; j++) {
                    if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                        matrix[i][j] = 0;
                    }
                   
                }
        }
        if(matrix[0][0] == 0 ) {
            for(int j = 0; j<c; j++) {
                matrix[0][j] = 0;
    
            }
        }
        if(col == true) {
                for(int i = 0; i<r; i++) {
                    matrix[i][0] = 0;
                }
            }

    }
};
