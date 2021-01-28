# Question - Throckmorton's Journey

Your cousin Throckmorton runs a consultancy company in India which has **_N_** employees. The company has some number of roles which follow a hierarchy. The role with the code of 0 is the best role and the code 1 is second best and so on. (Multiple employees may have the same role code.)

Throckmorton knows that no role is empty and that his friend James, who is the only one with 0 as his code, was the **_M_** th person to answer him.

In a hurry to answer him, some employees get confused with their code. Your role is to help Throckmorton find the minimum number of such employees. (Note that James can also make a mistake while answering)

# Solutions

## Python

    ```n,s=[int(i) for i in input().split()]
    s-=1
    n-=1
    d=0
    l=[int(i) for i in input().split()]
    if l[s]!=0:d+=1
    l=l[:s]+l[s+1:]
    for i in range(0,len(l)):
        if(l[i]==0):l[i]=n+5
    l.sort()
    j=0
    i=0
    c=0
    while 1:
        while i<len(l) and j==l[i]:
    	    i+=1
        if i>=len(l):
    	    break
        elif l[i]-j==1:
    	    j+=1
    	    i+=1
    	    continue
    	 else:
    	    l.pop()
    		d+=1
    		j+=1
    print(d)
    ```

## C++

    ```#include<bits/stdc++.h>
    using namespace std;
    const int maxn=200001;
    char s[maxn];
    int n,m,a[maxn],x,ans,cnt,res;
    int main() {
    	cin>>n>>m;
        for(int i=1;i<=n;i++){
    	    scanf("%d",&x);
    	    if(i==m)ans+=x>0,cnt++;
    	    else a[x]++;
        }
        for(int i=1;cnt<n;i++){
    	    cnt+=a[i]?a[i]:1;ans+=a[i]==0;
        }
        cout<<ans;
    }
    ```

## Java

    ```import java.io.*;
    import java.util.*;

    public class CF737C extends PrintWriter {
    	CF737C() { super(System.out, true); }
    	Scanner sc = new Scanner(System.in);
    	public static void main(String[] $) {
    		CF737C o = new CF737C(); o.main(); o.flush();
    	}

    	void main() {
    		int n = sc.nextInt();
    		int s = sc.nextInt() - 1;
    		int[] aa = new int[n];
    		for (int i = 0; i < n; i++)
    			aa[i] = sc.nextInt();
    		int m = 0;
    		if (aa[s] != 0) {
    			aa[s] = 0;
    			m++;
    		}
    		aa = Arrays.stream(aa).boxed().sorted().mapToInt($->$).toArray();
    		int h = 0;
    		while (h + 1 < n && aa[h + 1] == 0)
    			h++;
    		int k = h;
    		for (int i = h + 1, j = n - 1; i <= j; i++) {
    			int d = aa[i] - aa[i - 1] - 1;
    			if (d > 0) {
    				int l = Math.min(d, k);
    				m += l;
    				k -= l;
    				d -= l;
    			}
    			if (d > 0) {
    				int l = Math.min(d, j - i + 1);
    				m += l;
    				j -= l;
    			}
    		}
    		m += k;
    		println(m);
    	}
    }
    ```
