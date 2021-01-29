import java.util.*;
 
public class Sol {
	
	public static void main(String... args) {

		Scanner scanner = new Scanner(System.in);
		int m = scanner.nextInt();
		String s = scanner.next();
		
		int res = 1;
		char h = 'x';
		char v = 'x';
		for (char c : s.toCharArray()) {
			if (c == 'R' || c == 'L') {
				if (c != h && h != 'x') {
					res ++;
					v = 'x';
				}
				h = c;
			}
            else {
				if (c != v && v != 'x') {
					res ++;
					h = 'x';
				}
				v = c;
			}
		}
		
		System.out.println(res);
		scanner.close();
	}
}