int firstOccurence(int arr[], int n, int target){
    int s=0;
    int e= n-1;
    
    int ans = -1;

    while(s<=e){
        int m = s + (e-s)/2;

        if(target < arr[m]){
            e = m-1;
        }
        else if(target > arr[m]){
            s = m+1;
        }
        else{
            ans = m;
            e = m-1;
        }
    }
    return ans;
}
