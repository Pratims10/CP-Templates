ll mod=1e9+7;
ll power(ll x,ll y)
{
	if(y==0)
	return 1;
	ll ret=power(x,y/2);
	ret*=ret;
	ret%=mod;
	if(y%2==1)
	{
		ret*=x;
		ret%=mod;
	}
	return ret;
}
