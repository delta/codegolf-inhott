package Sherlocked;

import java.util.*;
 
class Main{
	public static long gcd(long a,long b){
		return b==0?a:gcd(b,a%b);
	}
 
	public static void main(String[] $){
		var s=new Scanner(System.in);
 
		int n=s.nextInt();
 
		long r=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				var t=gcd(i,j);
				for(int k=1;k<=n;++k){
					r+=gcd(t,k);
				}
			}
		}
		System.out.println(r);
	}
}