import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int[] p = new int[9];

        for (int i = 0; i < 9; i++) {
            p[i] = Integer.parseInt(br.readLine());
        }

        int[][] combs = getCombinations(p, 7);

        for (int[] row : combs) {
            ArrayList<Integer> result = new ArrayList<>();
            int sum = 0;
            for (int i = 0; i < 7; i++) {
                sum += row[i];
                result.add(row[i]);
                if (sum > 100) {
                    break;
                }
            }

            if (sum == 100) {
                result.sort(Comparator.naturalOrder());

                for (int i : result) {
                    System.out.println(i);

                }

                return;
            }
        }
    }

    public static int[][] getCombinations(int[] numbers, int count) {
        int combCount = getCombinationCount(numbers.length, count);

        int[][] result = new int[combCount][count];

        int allCombs = 1 << numbers.length;

        for (int i = 0, c = 0; i < allCombs; i++) {
            List<Integer> list = new ArrayList<>();
            for (int j = 0; j < numbers.length; j++) {
                if ((i & (1 << j)) != 0) {
                    list.add(numbers[j]);
                }
            }

            if (list.size() == count) {
                result[c] = listToArray(list);

                c++;
            }
        }

        return result;
    }

    public static int getCombinationCount(int n, int r) {
        if (n == r || r == 1) {
            return n;
        }

        return getCombinationCount(n - 1, r) + getCombinationCount(n - 1, r - 1);
    }

    public static int[] listToArray(List<Integer> list) {
        int[] array = new int[list.size()]; // Create an array of the same size as the list
        for (int i = 0; i < list.size(); i++) {
            array[i] = list.get(i); // Unbox each Integer and store in the array
        }
        return array;
    }
}