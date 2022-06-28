/*
Own code(Accepted but not optimal): Time: O(n+log(m)), space: O(1)
int n = matrix.size(), m = matrix[0].size();
        int cmp = target;
        for(int i=0;i<n;i++)
        {
            if(cmp < matrix[i][0])
                return false;
            else if(cmp > matrix[i][m-1])
            {
                if(i == n-1)
                    return false;
                else
                    continue;
            }
            else
            {
                int low = 0, high = m-1;
                while(low <= high)//see ==
                {
                    int mid = low + (high-low)/2;
                    if(matrix[i][mid] == cmp)
                        return true;
                    else if(matrix[i][mid] < cmp)
                        low = mid + 1;
                    else
                        high = mid - 1;
                }
                return false;
            }
        }
        return false;//Code never reaches here, just included to resolve return value in all calls error.
}
*/
class Solution {
public:
    //Time: O(log(mn)), Space: O(1)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row_num = matrix.size();
	int col_num = matrix[0].size();
	
	int begin = 0, end = row_num * col_num - 1;
	
	while(begin <= end){
		int mid = (begin + end) / 2;
		int mid_value = matrix[mid/col_num][mid%col_num];
		
		if( mid_value == target){
			return true;
		
		}else if(mid_value < target){
			begin = mid+1;
		}else{
			end = mid-1;
		}
	}
	return false;
    }
};
