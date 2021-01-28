import java.util.Scanner;
import java.util.TreeMap;
 
public class Potions {
 
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		long n = scan.nextInt(); int m = scan.nextInt(), k = scan.nextInt();
		long x = scan.nextInt(), mana = scan.nextInt();
		long[] a = new long[m], b = new long[m];
		for(int i = 0; i < m; i++) a[i] = scan.nextLong();
		for(int i = 0; i < m; i++) b[i] = scan.nextLong();
		TreeMap<Long, Long> map = new TreeMap<Long, Long>();
		long[] c = new long[k], d = new long[k];
		for(int i = 0; i < k; i++) c[i] = scan.nextLong();
		for(int i = 0; i < k; i++) d[i] = scan.nextLong();
		for(int i = 0; i < k; i++) map.put(d[i], c[i]);
		long p = n;
		if(map.floorKey(mana) != null) p -= map.get(map.floorKey(mana));
		long ans = x*p;
		for(int i = 0; i < m; i++){
			if(b[i] <= mana){
				p = n;
				if(map.floorKey(mana-b[i]) != null) p -= map.get(map.floorKey(mana-b[i]));
				ans = Math.min(ans, p*a[i]);
			}
		}
		System.out.println(ans);
	}
 
}
