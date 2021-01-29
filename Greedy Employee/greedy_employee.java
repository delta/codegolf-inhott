import java.util.*;

public class Sol {

	static int n, p, q, R, ans, l, r, mid, res, rr;
	static String ss;
	static char[] s;
	static int[] pp = new int[500005];
	static int[] qq = new int[500005];
 
	public static void main (String[] args) {

		Scanner in=new Scanner(System.in);
		n = in.nextInt();
        p = in.nextInt();
		q = in.nextInt();
        R = in.nextInt();
		ss = " " + in.next();
        s = ss.toCharArray();

		for(int i=1; i<=n; i++) {
			pp[i] = pp[i-1] + 1 + ((s[i] == 'w') ? q : 0);
			if(i > 1)
                pp[i] += p;
		}

		for(int i=1; i<=n; i++) {
			qq[i] = qq[i-1] + 1 + ((s[n-i+1] == 'w') ? q : 0);
			qq[i] += p;
		}

		for(int i=1; i<=n; i++) {
			rr = R - pp[i] - (i-1)*p;
			if(rr < 0)
                continue;

			l = 0;
            r = n;
            res = 0;
			while(l <= r) {
				mid = (l + r)/2;
				if(qq[mid] <= rr) {
                    res = mid;
                    l = mid+1;
                }
				else
                    r = mid-1;
			}

			ans = Math.max(ans, Math.min(n, i+res));
		}
        
		System.out.println(ans);
	}
}