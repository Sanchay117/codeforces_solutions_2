//
// Created by bravefart69 on 16/3/25.
//
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t, n, m, i, j, ans;
    
    cin>>t;
    
    for(;t--;)
    {
        ans=0;
        
        cin>>n>>m;
        
        ll first[n+1];
        
        for(i=0; i<=n; i++)
        {
            first[i]=n+1;
        }
        
        for(;m--;)
        {
            cin>>i>>j;
            
            if(i>j){
                swap(i, j);
            }
            
            first[i]=min(first[i], j);
        }
        
        for(i=n-1; i>=1; i--)
        {
            first[i]=min(first[i], first[i+1]);
        }
        
        for(i=1; i<=n; i++)
        {
            ans=ans+first[i]-i;
        }
        
        cout<<ans<<"\n";
    }
}