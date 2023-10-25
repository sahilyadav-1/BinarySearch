#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

bool ispossiblesoln(vector<int>& arr, int n, int m, int target){
    int sum = 0;

    for(int i=0;i<n;i++){
        int diff = 0;
        if(arr[i] > m)
            diff = arr[i]-m;
        sum = sum + diff;
    }
    
    if(sum >= target)
        return true;
    else
        return false;
}

int getMaximumHeightOfSaw(vector<int>& arr, int n, int target){
    int s = 0;
    int maxi = INT_MIN;
    for(int i = 0; i<n; i++)
        maxi = max(maxi,arr[i]);
    int e = maxi;
    int m = s + (e-s)/2;
    int ans = -1;

    while(s<=e){
        if(ispossiblesoln(arr,n,m,target))
        {
            ans = m;
            s = m+1;
        }
        else{
            e = m-1;
        }
        m = s + (e-s)/2;
    }
    return ans;
}


int main(){
    int target;
    int n;
    cout<<"PLEASE ENTER"<<endl;
    cin>>n>>target;
    vector<int>arr;
    while(n--){
        int a;
        cin>>a;
        arr.push_back(a);
    }
    sort(arr.begin(),arr.end());
    int ans = getMaximumHeightOfSaw(arr,arr.size(),target);
    cout<<ans<<endl;
    return 0;
}
