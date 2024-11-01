import java.util.*;

class Solution {
    public int[] solution(int[] numbers) {
        
        SortedSet<Integer> set = new TreeSet<>();
        
        for (int i = 0; i < numbers.length; i++) {
            for (int j = i + 1; j < numbers.length; j++) {
                set.add(numbers[i] + numbers[j]);
            }
        }
        
        int[] answer = new int[set.size()];
        int count = 0;
        for (Integer v : set) {
            answer[count++] = v;
        }
        
        
        return answer;
    }
}