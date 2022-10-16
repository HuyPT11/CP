#include<bits/stdc++.h>
using namespace std;
const int N=5e4+5;
vector<int>a[N];
int n,r1,r2,par[N];
void dfs(int u,int p)
{
    for (auto v:a[u])
    {
        if (v==p) continue;
        dfs(v,u);
        par[v]=u;
    }
}
int main()
{
    cin>>n>>r1>>r2;
    for (int i=1;i<=n;i++)
    {
        if (i==r1) continue;
        int p;
        cin>>p;
        a[p].push_back(i);
        a[i].push_back(p);
    }
    par[r2]=r2;
    dfs(r2,0);
    for (int i=1;i<=n;i++)
    {
        if (i==r2) continue;
        cout<<par[i]<<" ";
    }
}
