double precision(int n, int precise, double ans){
    double factor = 1;

    for(int i=0;i<precise;i++){
        factor=factor/10;
        for(double j=ans;j*j<n;j+=factor){
            ans=j;
        }
    }
    return ans;
}

double sqrt(int n, int precise){
    int s = 0;
    int e = n;
    long long int m = s+(e-s)/2;
    long long int ans = -1;
        
    while(s<=e){
        long long int square = m*m;
        
        if(square <= n){
            ans = m;
            s = m+1;
        }
        else{
            e = m-1;
        }
        m = s+(e-s)/2;
    }
    return precision(n,precise,ans);
}
