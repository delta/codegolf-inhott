##### THE SOLUTIONS GIVEN ARE NOT MINIFIED, VARIABLE NAMES CAN BE SHORTENED TO GET THE SMALLEST LENGTH CODE

The question basically asks to assign small integers to letters which have smaller place values, while making sure 0 is not assigned to some letter that occurs at the beginning of any string

First of all, we iterate over each string from end to beginning, and add the place value of each character to a map. We also keep track of letters which are the first letters of the strings, let's call letters which do not start any string `nonStartLetter`

```
while (n--) {
    cin >> s;
    placeVal = 1;
    len = s.length();
    for (int i=len-1; i>=0; i--) {
        cnt[s[i] - 'a'].first += placeVal;
        placeVal *= 10;
    }
    starts[s[0] - 'a'] = true;
}
```

Then sort the letters in order of the increasing total place value
```
sort(cnt.begin(), cnt.end());
```

Finally we iterate over the sorted counts in reverse, and assign values 1 to 9 to the letters, and accordingly calculate the sum. However, when we encounter the first `nonStartLetter`, we skip that letter (which essentially means that we assign 0 to that letter). This is done to ensure that the `nonStartLetter` with the highest placeValue is assigned 0 to keep the sum minimum.

```
int digit = 1, ans = 0;
bool flag = true;
for (int i=9; i>=0; i--) {
    if (!starts[cnt[i].second] and flag) flag = false;
    else {
        ans += cnt[i].first * digit;
        digit++;
    }
}
```
