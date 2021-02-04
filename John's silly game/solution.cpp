#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, placeVal, len;
    string s;
    vector<pair<int,int>> cnt(10);
    vector<bool> starts(10, false);
    for (int i=0; i<10; i++)
        cnt[i] = {0, i};
    cin >> n;
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
    sort(cnt.begin(), cnt.end());
    
    int digit = 1, ans = 0;
    bool flag = true;
    for (int i=9; i>=0; i--) {
        if (!starts[cnt[i].second] and flag) flag = false;
        else {
            ans += cnt[i].first * digit;
            digit++;
        }
    }
    cout << ans << endl;
}