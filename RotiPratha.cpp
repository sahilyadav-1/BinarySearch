#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool ispossiblesoln(vector<int>&v,int n,int p, int time){
    int sum = 0;
    for(int i=0; i<n; i++){
        int k = 1;
        int t = time;
        while(t-k*v[i] >= 0){
            t = t - k*v[i]; 
            k++;
        }
        sum += k-1;
    }
    if(sum >= p) return true;
    return false;
}

int timetaken(vector<int>&v, int n, int p){
    int s = 0;
    int e = v[0]*(p*(p+1))/2;
    int ans = -1;

    while(s<=e){
        int m = s + (e-s)/2;
        if(ispossiblesoln(v,n,p,m)){
            ans = m;
            e = m-1;
        }
        else{
            s = m+1;
        }
    }
    return ans;
}

int main(){
    int p;
    int l;
    cout<<"PLEASE ENTER !!"<<endl;
    cin>>p>>l;
    vector<int>v;
    while(l--){
        int a;
        cin>>a;
        v.push_back(a);
    }
    int ans = timetaken(v,v.size(),p);
    cout<<ans<<endl;
    return 0;
}
