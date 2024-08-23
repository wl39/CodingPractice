import java.io.*;

public class Main {
    static int n = 0;
    static int counts = 0;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());

        int[] table = new int[n];

        for (int i = 0; i < n; i++) {
            table[i] = -1;
        }
        backTracking(0, table);

        System.out.println(counts);
    }

    public static void backTracking(int row, int[] table) { // table index = row / value = column
        if (row == n) {
            counts++;
            return;
        }

        for (int x = 0; x < n; x++) {
            if (table[row] < 0) {
                boolean temp = false;


                for (int queenY = 0; queenY < row; queenY++) {
                    int queenX = table[queenY];

                    if (queenX == x) {
                        temp = true;
                        break;
                    }

                    if (Math.abs(queenY - row) == Math.abs(queenX - x)) {
                        temp = true;
                        break;
                    }

                }

                if (!temp) {
                    table[row] = x;
                    backTracking(row + 1, table);
                    table[row] = -1;
                }
            }
        }
    }
}