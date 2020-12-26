vector<ll> KMPprefix(string s)
{
	ll i,j,k,m,n=s.length();
	vector<ll> lps(n);
	lps[0]=0;
	for(i=1;i<n;i++)
	{
		j=lps[i-1];
		while(j>0 and s[i]!=s[j])
		{
			j=lps[j-1];
		}
		if(s[i]==s[j])
			j++;
		lps[i]=j;
	}
	return lps;
}
