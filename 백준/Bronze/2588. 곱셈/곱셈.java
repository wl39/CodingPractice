import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int a = Integer.parseInt(br.readLine());
        int b = Integer.parseInt(br.readLine());
        int result = a * b;
        while (b != 0) {
            System.out.println(a * (b % 10));
            b /= 10;
        }

        System.out.println(result);
    }
}