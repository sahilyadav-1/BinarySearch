int lastOccurence(int arr[], int n, int target){
    int s = 0;
    int e = n-1;
    int m = s + (e-s)/2;
    int ans = -1;

    while(s<=e){
        if(target == arr[m]){
            ans = m;
            s = m+1;
        }
        if(target < arr[m]){
            e = m-1;
        }
        else{
            s = m+1;
        }
        m = s + (e-s)/2;
    }
    return ans;
}
