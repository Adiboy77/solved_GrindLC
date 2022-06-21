class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        bool isCol = false;
        for(int i = 0; i<n; i++)
        {
            if(matrix[i][0] == 0)
                isCol = true;
            for(int j = 1; j<m; j++)//j starts from 1
            {
                if(matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;//marking first element of col as 0
                    matrix[0][j] = 0;//marking first element of row as 0
                }
            }
        }
        for(int i = 1; i<n;i++)
        {
            for(int j = 1;j<m;j++)
            {
                if(matrix[i][0] == 0 || matrix[0][j]==0)
                    matrix[i][j] = 0;
            }
        }
        if(matrix[0][0] == 0)//checking first row
        {
            for(int j =0 ;j<m;j++)
                matrix[0][j] = 0;
        }
        if(isCol)//checking first column
        {
            for(int i=0;i<n;i++)
                matrix[i][0] = 0;
        }
        return;
    }
};
