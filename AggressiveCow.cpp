#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool ispossiblesoln(vector<int>&v, int n, int c, int m){
    int cowCount = 1;
    int lastPos = v[0];

    for(int i=1;i<n;i++){
        if(v[i]-lastPos >= m){
            cowCount++;
            if(cowCount==c){
                return true;
            }
            lastPos = v[i];
        }
    }
    return false;
}

int cowDistance(vector<int>&v, int n, int c){
    sort(v.begin(),v.end());
    int s = v[0];
    int e = v[n-1]-v[0];
    int ans = -1;

    while(s<=e){
        int m =s + (e-s)/2;
        if(ispossiblesoln(v,v.size(),c,m)){
            ans = m;
            s = m+1;
        }
        else{
            e = m-1;
        }
    }
    return ans;
}

int main(){
    int c;
    int stalls;
    cout<<"PLEASE ENTER !!"<<endl;
    cin>>c>>stalls;
    vector<int>v;
    while(stalls--){
        int a;
        cin>>a;
        v.push_back(a);
    }
    int ans = cowDistance(v,v.size(),c);
    cout<<ans<<endl;
    return 0;
}
