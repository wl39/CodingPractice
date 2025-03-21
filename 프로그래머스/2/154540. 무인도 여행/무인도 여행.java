import java.util.*;

class Solution {
    public PriorityQueue<Integer> daysSurvived = new PriorityQueue<>();
    
    public int[] solution(String[] maps) {        
        int[][] parsedMap = parseMap(maps);
        boolean[][] visited = new boolean[parsedMap.length][parsedMap[0].length];
        
        
        for (int i = 0; i < parsedMap.length; i++) {
            for (int j = 0; j < parsedMap[0].length; j++) {
                if (parsedMap[i][j] != 0 && !visited[i][j]) {
                    check(parsedMap, visited, i, j);
                }
            }
        }
        
        if (daysSurvived.size() == 0) {
            return new int[]{-1};
        } else {
            int[] answer = new int[daysSurvived.size()];
            int index = 0;
            
            while (!(daysSurvived.size() == 0)) {
                answer[index++] = daysSurvived.poll();
            }
            
            return answer;    
        }
    }
        
    public int[][] parseMap(String[] maps) {
        int[][] parsedMap = new int[maps.length][maps[0].length()];
        
        for (int i = 0; i < maps.length; i++) {
            for (int j = 0; j < maps[i].length(); j++) {
                char positionValue = maps[i].charAt(j);
                
                if (positionValue != 'X') {
                    parsedMap[i][j] = positionValue - '0';
                }
            }
        }
                
        return parsedMap;
    }
    
    public void check(int[][] parsedMap, boolean[][] visited, int y, int x) {
        int[] sum = { 0 };
        
        dfs(parsedMap, visited, y, x, sum);
        
        if (sum[0] != 0) {
            daysSurvived.add(sum[0]);
        }
    }
    
    
    public void dfs(int[][] parsedMap, boolean[][] visited, int y, int x, int[] sum) {
        if (y < 0 || x < 0 || y >= visited.length || x >= visited[0].length) return ;
        if (visited[y][x]) return ;
        
        visited[y][x] = true;
        
        int food = parsedMap[y][x];
        
        if (food == 0) return;
        
        sum[0] += food;
                
        dfs(parsedMap, visited, y - 1, x, sum);
        dfs(parsedMap, visited, y + 1, x, sum);
        dfs(parsedMap, visited, y, x - 1, sum);
        dfs(parsedMap, visited, y, x + 1, sum);
    }
}

/*
X or 1 ~ 9
X -> sea
Numbers -> island

We will look through the map from left top to right bottom
1. DFS Check
2. 
*/