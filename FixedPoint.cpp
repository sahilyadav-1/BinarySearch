int fixedPoint(int arr[], int n){
    int s = 0;
    int e = n - 1;
    int m = s + (e-s)/2;

    while(s<=e){
        if(arr[m] == m){
            return m;
        }
        if(arr[m] > m){
            e = m-1;
        }
        else
        {
            s = m+1;
        }
        m = s+(e-s)/2;
    }
    return -1;
}
