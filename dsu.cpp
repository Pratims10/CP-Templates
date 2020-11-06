ll root (ll ar[],ll i)
{
	ll j=i;
    while(ar[i]!=i)
    { 
		i=ar[i]; 
    }
    ar[j]=i;
	return i;
}
void join(ll ar[ ],ll size[ ],ll A,ll B)
{
    ll root_A=root(ar,A);
    ll root_B=root(ar,B);
    if(root_A==root_B)
    return;
    if(size[root_A] < size[root_B])
    {
		ar[root_A]=ar[root_B];
		size[root_B]+=size[root_A];
	}
    else
    {
		ar[root_B]=ar[root_A];
		size[root_A]+=size[root_B];
	}
}
