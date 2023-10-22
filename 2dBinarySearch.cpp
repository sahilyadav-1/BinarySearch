class Solution {
public:
    bool binarysearch(vector<vector<int>>& a, int row, int col, int rowsearch, int target){
        int s = 0;
        int e = col-1;
        int m = s + (e-s)/2;

        while(s<=e){
            if(a[rowsearch][m]==target){
                return true;
            }
            if(a[rowsearch][m]>target){
                e = m-1;
            }
            else{
                s = m+1;
            }
            m = s+(e-s)/2;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& a, int target) {
        int row = a.size();
        int col = a[0].size();
        
        int s = 0;
        int e = row - 1;
        int m = s+(e-s)/2;

        while(s<=e){
            if(a[m][0] <= target && a[m][col-1] >= target){
                return binarysearch(a,row,col,m,target);
            }
            if(a[m][0] > target){
                e = m-1;
            }
            else{
                s = m+1;
            }
            m = s+(e-s)/2;
        }
        return false;
    }
};
