class Solution {
public:
    
    bool binarysearch(vector<int>& arr, int s, int e, int target){
        int start = s;
        int end = e;
        int mid = s + (e-s)/2;
        
        while(start<=end){
            if(arr[mid] == target){
                return true;
            }
            if(arr[mid] < target){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
            mid = start + (end-start)/2;
        }
        return false;
    }
    
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        
        for(int i=0;i<n;i++){
            int N=arr[i];
            if(N>=0 && binarysearch(arr,i+1,n-1,2*N))
                return true;
            if(N<0 && N%2==0 && binarysearch(arr,i+1,n-1,N/2))
                return true;
        }
        return false;
    }
};
