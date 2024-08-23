import java.io.*;
import java.math.BigInteger;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        System.out.println((new BigInteger("2")).pow(n).subtract(new BigInteger("1")));


        if (n <= 20)
            hanoi(n, 1, 2, 3);
    }

    // n, from, by, to

    public static void hanoi(int n, int from, int by, int to) {
        if (n == 0) {
            return;
        }
        hanoi(n - 1, from, to, by);
        System.out.println(from + " " + to);
        hanoi(n - 1, by, from, to);
    }
}