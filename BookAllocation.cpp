#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool ispossiblesoln(vector<int>&v, int n, int m,int mid){
    int studentCount = 1;
    int sum = 0;//pagesum

    for(int i=0;i<n;i++){
        if(v[i]+sum <= mid){
            sum+=v[i];
        }
        else{
            studentCount++;
            if(studentCount > m || v[i] > mid){
                return false;
            }
            sum = v[i];
        }
    }
    return true;
}

int minimumPagesAllocated(vector<int>&v, int n, int m){
    int s = 0;
    int sum = 0;
    int ans = -1;
    for(int i=0;i<n;i++){
       sum = sum + v[i];
    }
    int e = sum;
    while(s<=e){
        int mid = s + (e-s)/2;
        if(ispossiblesoln(v,v.size(),m,mid)){
            ans = mid;
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    return ans;
}

int main(){
    int n;
    int m;
    cout<<"PLEASE ENTER !!"<<endl;
    cin>>m>>n;
    vector<int>v;
    while(n--){
        int a;
        cin>>a;
        v.push_back(a);
    }
    int ans = minimumPagesAllocated(v,v.size(),m);
    cout<<ans<<endl;
    return 0;
}
