import java.math.BigInteger;
import java.util.Scanner;

public class Gambling_BI_John
{
	public static final int NMAX = 100;
	public static final int MMAX = 200;

	public static void main(String [] args)
	{
		int m = 1, n = 1, p = 0;
		Rat_BI[][] arr = new Rat_BI[NMAX+1][MMAX+1];
		int x;

		Scanner in = new Scanner(System.in);
		m = in.nextInt();
		n = in.nextInt();
		p = in.nextInt();
		// base cases
		arr[0][0] = new Rat_BI(1,1);
		arr[0][1] = new Rat_BI(m-2*n, m);
		arr[0][1].reduce();
		for(int j = 2; j<=p; j++) {
			arr[0][j] = new Rat_BI(arr[0][j-1].num.multiply(new BigInteger((m-2*n-j+1)+"")), arr[0][j-1].den.multiply(new BigInteger((m-j+1)+"")));
			arr[0][j].reduce();
		}
		arr[1][0] = new Rat_BI(0,1);
		for(int i=2; i<=n; i++)
			arr[i][0] = arr[1][0];
		// fill in table
		for(int i=0; i<n; i++) {
			for(int j=0; j<p; j++) {
				Rat_BI t1 = new Rat_BI(arr[i][j].num.multiply(new BigInteger((2*(n-i))+"")), arr[i][j].den.multiply(new BigInteger((m-j)+"")));
				t1.reduce();
				Rat_BI t2 = new Rat_BI(arr[i+1][j].num.multiply(new BigInteger((m-j-2*(n-i-1))+"")), arr[i+1][j].den.multiply(new BigInteger((m-j)+"")));
				t2.reduce();
				arr[i+1][j+1] = new Rat_BI(t1.num.multiply(t2.den).add(t1.den.multiply(t2.num)), t1.den.multiply(t2.den));
				arr[i+1][j+1].reduce();
			}
		}
		// now determine prob of
		//   winning on exactly the
		//   Pth ball
		Rat_BI ans;
		if (p == 0)
			ans = arr[n][p];
		else
			ans = new Rat_BI(arr[n][p].num.multiply(arr[n][p-1].den).subtract(arr[n][p].den.multiply(arr[n][p-1].num)), arr[n][p].den.multiply(arr[n][p-1].den));
		ans.reduce();
//		System.out.println("Probability of winning on selection " + p + " =\n  " + ans + ".");
		System.out.println(ans);
	}
}


class Rat_BI {
	//
	// Simple rational class
	//
	public BigInteger num, den;

	public Rat_BI(int n, int d)
	{
		num = new BigInteger(n+"");
		den = new BigInteger(d+"");
	}

	public Rat_BI(BigInteger n, BigInteger d)
	{
		num = n;
		den = d;
	}


	public void reduce()
	{
		if (num.equals(new BigInteger("0"))) {
			den = new BigInteger("1");
			return;
		}
		BigInteger factor = num.gcd(den);
		num = num.divide(factor);
		den = den.divide(factor);
		return;
	}

	public String toString()
	{
		return num + "/" + den;
	}

}