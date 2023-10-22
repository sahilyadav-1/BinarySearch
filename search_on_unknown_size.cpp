int binarYsearch(int arr[], int s, int e, int target){
    int m = s + (e-s)/2;

    while(s<=e){
    if(target == arr[m]){
        return m;
    }
    else if(target < arr[m]){
        e = m-1;
    }
    else{
        s = m+1;
    }
    m = s + (e-s)/2;
    }
    return -1;
}

int search_on_unknown_size(int arr[], int target){
    int s = 0;
    int e = 1;
    int val = arr[s];

    while(val < target){
        s = e;
        e = 2*e;
        val = arr[e];
    }
    return binarYsearch(arr,s,e,target);
}
