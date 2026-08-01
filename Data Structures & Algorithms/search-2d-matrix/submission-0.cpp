class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size()-1;
        int n = matrix[0].size()-1;
        if(matrix[0][0]>target || matrix[m][n]<target) return false;
        int low = 0, high = m;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(matrix[mid][0]>target) high = mid-1;
            else if(matrix[mid][n]<target) low = mid+1;
            else{
                int low1 = 0, high1 = n;
                while(low1<=high1){
                    int mid1 = low1 + (high1-low1)/2;
                    if(matrix[mid][mid1]==target) return true;
                    if(matrix[mid][mid1]<target) low1 = mid1+1;
                    else high1 = mid1-1;
                }
                return false;
            }
        }
        return false;
    }
};
