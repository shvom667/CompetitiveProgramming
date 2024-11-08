//import java.math.BigInteger;
import java.util.Scanner;

public class Gambling_John
{
	public static final int MMAX = 38;
	public static final int NMAX = MMAX/2;

	public static void main(String [] args)
	{
		int m = 1, n = 1, p = 0;
		Rat[][] arr = new Rat[NMAX+1][MMAX+1];

		Scanner in = new Scanner(System.in);
		m = in.nextInt();
		n = in.nextInt();
		p = in.nextInt();
		// base cases
		arr[0][0] = new Rat(1,1);
		arr[0][1] = new Rat(m-2*n, m);
		for(int j = 2; j<=p; j++) {
			arr[0][j] = new Rat(arr[0][j-1].num*(m-2*n-j+1), arr[0][j-1].den*(m-j+1));
		}
		arr[1][0] = new Rat(0,1);
		for(int i=2; i<=n; i++)
			arr[i][0] = arr[1][0];
		// fill in table
		for(int i=0; i<n; i++) {
			for(int j=0; j<p; j++) {
				Rat t1 = new Rat(arr[i][j].num*2*(n-i), arr[i][j].den*(m-j));
				Rat t2 = new Rat(arr[i+1][j].num*(m-j-2*(n-i-1)), arr[i+1][j].den*(m-j));
				arr[i+1][j+1] = new Rat(t1.num*t2.den + t1.den*t2.num, t1.den*t2.den);
				if (arr[i+1][j+1].num <0) {
					System.out.println("i,j = " + i + "," + j + " " + t1 + " " + t2);
					System.exit(0);
				}
			}
		}
								// now determine prob of winning on exactly the p-th ball
		Rat ans;
		if (p == 0)
			ans = arr[n][p];
		else
			ans = new Rat(arr[n][p].num*arr[n][p-1].den - arr[n][p].den*arr[n][p-1].num, arr[n][p].den*arr[n][p-1].den);
//		System.out.println("Probability of winning on selection " + p + " =\n  " + ans + ".");
		System.out.println(ans);
	}
}


class Rat {
	//
	// Simple rational class
	//
	public long num, den;

	public Rat(long n, long d)
	{
		num = n;
		den = d;
		reduce();
	}


	private void reduce()
	{
		if (num == 0) {
			den = 1;
			return;
		}
		long factor = gcd(num, den);
		num = num / factor;
		den = den / factor;
		return;
	}

	private long gcd(long a, long b)
	{
		while (b != 0) {
			long temp = a % b;
			a = b;
			b = temp;
		}
		return a;
	}
	public String toString()
	{
		return num + "/" + den;
	}

}