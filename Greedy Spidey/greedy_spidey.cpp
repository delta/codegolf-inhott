#include <iostream>
using namespace std;

int m, s;
char a, d, l;

int main() {
    cin >> m;

    for (int i=0; i<m; i++) {
        cin >> a;

        if ((a=='R' && l=='L') || (a=='L' && l=='R') || (a=='U' && d=='D') || (a=='D' && d=='U')) {
            d = 'a';
            l = d;
            s ++;
        }

        if(a=='R' || a=='L')
            l = a;
        else
            d = a;
    }
    
    cout << s + 1;
    return 0;
}