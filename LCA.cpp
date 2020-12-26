#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> adj[200001];
ll dp[200001][21];
ll n;
ll lvl[200001];

void dfs(ll x,ll par)
{
	dp[x][0]=par;
	for(auto i:adj[x])
	{
		if(i==par) continue;
		lvl[i]=lvl[x]+1;
		dfs(i,x);
	}
}
ll lca(ll x,ll y)
{
	if(lvl[x]<lvl[y])
	swap(x,y);
	for(ll i=20;i>=0;i--)
	{
		if(lvl[x]-(1ll<<i)>=lvl[y])
		x=dp[x][i];
	}
	if(x==y)
	return x;
	for(ll i=20;i>=0;i--)
	{
		if(dp[x][i]!=dp[y][i])
		x=dp[x][i],y=dp[y][i];
	}
	return dp[x][0];
}
int main()
{
	ll i,j,k,m,q,x;
	cin>>n>>x;//X IS ROOT NODE
	x--;
	for(i=0;i<n-1;i++)
	{
		cin>>j>>k;
		j--,k--;
		adj[j].push_back(k);
		adj[k].push_back(j);
	}
	lvl[x]=0;
	dfs(x,x);
	for(j=1;j<=20;j++)
	{
		for(i=0;i<n;i++)
		{
			dp[i][j]=dp[dp[i][j-1]][j-1];
		}
	}
	
	ll test;
	cin>>test;
	while(test--)
	{
		ll u,v;
		cin>>u>>v;
		u--,v--;
		{
			ll ans=lca(u,v);
			cout<<ans+1<<'\n';
		}
	}
}
