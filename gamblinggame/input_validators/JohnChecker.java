import java.util.ArrayList;
import java.util.Scanner;
import java.util.StringTokenizer;

public class JohnChecker
{
	public static final int MAXM = 33;
	public static final int MAX_LEN = 1000;
	public static int exitCode = 42;

	public static void printError(int line, String msg)
	{
		System.out.println("ERROR Line " + line + ": " + msg);
		exitCode = -1;
	}

	public static void checkIntBounds(int x, int min, int max, String name, int nLines)
	{
		if (x < min || x > max)
			printError(nLines, "invalid " + name + " value: " + x);
	}

	public static void checkCharBounds(char x, char min, char max, String name, int nLines)
	{
		if (x < min || x > max)
			printError(nLines, "invalid " + name + " value: " + x);
	}

	public static void checkDoubleBounds(double x, double min, double max, String name, int nLines)
	{
		if (x < min || x > max)
			printError(nLines, "invalid " + name + " value: " + x);
	}

	public static int nextInt(StringTokenizer st)
	{
		return Integer.parseInt(st.nextToken());
	}

	public static void main(String [] args)
	{
		Scanner in = new Scanner(System.in);
		int m, n, p;
		String line;
		int nLines=0;

		line = in.nextLine();
		nLines++;
		StringTokenizer st = new StringTokenizer(line);
		if (st.countTokens() != 3)
			printError(nLines, "number of values on line incorrect");

		m = nextInt(st);
		n = nextInt(st);
		p = nextInt(st);
		checkIntBounds(m, 1, MAXM, "m", nLines);
		checkIntBounds(n, 0, m/2, "n", nLines);
		checkIntBounds(p, 0, m, "p", nLines);

		if (in.hasNextLine())
			printError(nLines, "too many lines");
		System.exit(exitCode);
	}
}