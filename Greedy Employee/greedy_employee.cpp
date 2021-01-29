#include <bits/stdc++.h>
using namespace std;

const int MAX = 5e5+5;
int n, p, q, r, z, c[MAX*2], ans;
char k;

int main()
{
	cin >> n >> p >> q >> r;

	for(int i=0; i<n; i++)
		cin >> k, z += c[i] = c[n+i] = (k == 'd')*q + 1;

	z -= c[0];

	int l = 1, r = n;
	while((l <= n) && (r < 2*n)) {
		z += c[r++];
		while ((r-l > n) || (z + (r-l-1+min(n-l,r-n-1))*p > r))
            z -= c[l++];
        
		if (l > n)
            break;	
		ans = max(ans, r-l);
	}
	cout << ans;
    return 0;
}