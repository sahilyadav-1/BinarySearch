class Solution {
public:
    
    int getpivot(vector<int>& nums, int n){
        int s = 0;
        int e = n-1;

        int mid = s + (e-s)/2;
        
        while(s<e){
            cout<<mid;
            if(nums[mid]>nums[e]){
                s = mid + 1;
            }
            else{
                e = mid;
            }
            mid = s + (e-s)/2;
        }
        return s;
    }
    
    int binarysearch(vector<int>& nums, int s, int e, int target){
        int start = s;
        int end = e;
        int m = start + (end-start)/2;
        

        while(start<=end){
            if(target == nums[m]){
                return m;
            }
            else if(target < nums[m]){
                end = m-1;
            }
            else{
                start = m+1;
            }
            m = start + (end-start)/2;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
       
        int n = nums.size();
        int s = 0;
        int e = n-1;
  
        int m = getpivot(nums,n);
        
        if(nums[m] == nums[s]){
            return binarysearch(nums,s,e,target);
        }
        
        if(target>=nums[s] && target<=nums[m-1]){
            return binarysearch(nums,s,m-1,target);
        }
        else{
            return binarysearch(nums,m,e,target);
        }
        return -1;
    }
};
