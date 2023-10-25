#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool ispossiblesoln(vector<int>&v, int n, int p, int m){
    int numPainters = 1;
    int sum = 0;//blocksum

    for(int i=0;i<n;i++){
        if(v[i]+sum <= m){
            sum = sum + v[i];
        }
        else{
            numPainters++;
            if(numPainters > p || v[i] > m){
                return false;
            }
            sum = v[i];
        }
    }
    return true;
}

int minimumTime(vector<int>&v, int n, int p){
    int s = 0;
    int sum = 0;
    for(int i=0;i<n;i++){
        sum+=v[i];
    }
    int e = sum;
    int ans = -1;

    while(s<=e){
        int m = s + (e-s)/2;

        if(ispossiblesoln(v,v.size(),p,m)){
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
    int b;
    cout<<"PLEASE ENTER !!"<<endl;
    cin>>p>>b;
    vector<int>v;
    while(b--){
        int a;
        cin>>a;
        v.push_back(a);
    }
    int ans = minimumTime(v,v.size(),p);
    cout<<ans<<endl;
    return 0;
}
