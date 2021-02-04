##### THE SOLUTIONS GIVEN ARE NOT MINIFIED, VARIABLE NAMES CAN BE SHORTENED TO GET THE SMALLEST LENGTH CODE

According to the statement, digits of the jersey number form a subset of digits of the number seen by John. It is possible to iterate through all the subsets in 2<sup>k</sup> operations (where k is length of n). For each subset we need to check whether it is correct (contains all necessary digits) and transform it to "normal" state (sort the digits for example), in order to avoid conflicts with another subsets which differ only at the digits order. We have to keep only unique subsets.

```
long long ans = 0;
for (int i = 1; i <= (1 << k); i++) {
    string c;
    for (int j = 0; j < k; j++)
        if (i & (1 << j))
            c += n[j];
    ans += getans(c);
}
```

Now for each subset of digits we have to calculate amount of corresponding correct jersey numbers. It can be calculated in O(k) operations using permutations of multisets formula

C = k! / (c<sub>0</sub>! * c<sub>1</sub>! * ... * c<sub>9</sub>!), 

where k — total number of digits in the subset and c<sub>i</sub> — number of digits i:

```
long long fact[20];
int c[10];

void setCount(string s, int *c) {
	for (int i = 0; i < 10; i++)
		c[i] = 0;
	for (char ch : s)
		c[ch - 48]++;
}

long long getPerms() {
	long long ans = fact[accumulate(c, c + 10, 0)];
	for (int i = 0; i < 10; i++)
		ans /= fact[c[i]];
	return ans;
}
```

Now, we have to subtract amount of jersey numbers with leading zeroes from the result for this subset if it contains digit 0. This can be done in the very same way: if we place digit 0 at the first position of the number, we have to decrease k by 1 and decrease c<sub>0</sub> by 1; the formula described above will calculate amount of ways to place remaining digits of the subset and this number should be subtract from the answer:

```
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
		c[0]--;
		ans -= getPerms();
	}
	return ans;
}
```

In total, even with such rough evaluation of complexity and naive implementation we get O(2<sup>k</sup> * k) operations, where k ≤ 19 — amount of digits in n.