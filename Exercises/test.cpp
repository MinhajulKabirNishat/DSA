#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void activity_selection(int N,int s[],int f[])
{
    int i=0,j;
    vector<int> ans;
    int chosen=i;
    ans.push_back(chosen);
    for(int j=1;j<N;j++){
        if(s[j]>f[chosen]){
            chosen=j;
            ans.push_back(chosen);
        }
    }
    for(i=0;i<ans.size();i++){
        cout<<ans[i]+1<<",";
    }

}

int main()
{
    int i,N;
    cout<<"enter N:";
    cin>>N;
    int s[N];
    int f[N];
    cout<<"S:";
    for(i=0;i<N;i++){
        cin>>s[i];
    }
    cout<<"f:";
    for(i=0;i<N;i++){
        cin>>f[i];
    }
    activity_selection(N,s,f);

}
