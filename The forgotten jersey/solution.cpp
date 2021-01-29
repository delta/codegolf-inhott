#include <bits/stdc++.h>

using namespace std;

long long fact[20];

set<string> visited;
int c0[10];
int c[10];

void setCount(string s, int *c) {
	for (int i = 0; i < 10; i++)
		c[i] = 0;
	for (char ch : s)
		c[ch - 48]++;
}

long long getPerms() {
    // calculate the permutations
	long long ans = fact[accumulate(c, c + 10, 0)];
	for (int i = 0; i < 10; i++)
		ans /= fact[c[i]];
	return ans;
}

long long getans(string s) {
	setCount(s, c);

	// check whether the string contains all digits
	for (int i = 0; i < 10; i++)
		if (c0[i] && !c[i])
			return 0;

	// check whether we already processed such string
	sort(s.begin(), s.end());
	if (visited.count(s))
		return 0;
	visited.insert(s);

	long long ans = getPerms();
	if (c[0] > 0) {
        // take care of numbers which start with 0
		c[0]--;
		ans -= getPerms();
	}

	return ans;
}

int main() {
	fact[0] = 1;
	for (int i = 1; i < 20; i++)
		fact[i] = i * fact[i - 1];

	string n;
	cin >> n;

	int k = n.length();
	setCount(n, c0);

	long long ans = 0;
	for (int i = 1; i <= (1 << k); i++) {
		string c;
		for (int j = 0; j < k; j++)
			if (i & (1 << j))
				c += n[j];
		ans += getans(c);
	}

	cout << ans << endl;
}