import java.util.*;

class Solution {
    public String[] solution(String[] records) {
        Queue<String> userLogs = new LinkedList<>();
        Queue<String> activityLogs = new LinkedList<>();
        
        HashMap<String, String> userMap = new HashMap<>();
        
        
        for(String record : records) {
            String[] r = record.split(" ");
            
            switch (r[0]) {
                case "Enter":
                    userMap.put(r[1], r[2]);
                case "Leave":
                    activityLogs.add(r[0]);
                    userLogs.add(r[1]);
                    break;
                default:
                    userMap.put(r[1], r[2]);
                    break;
            } 
        }
        
        String[] answer = new String[userLogs.size()];
        int index = 0;
        while(userLogs.size() != 0) {
            String a = userMap.get(userLogs.poll());

            if (activityLogs.poll().equals("Enter")) {
               a += "님이 들어왔습니다.";
            } else {
                a += "님이 나갔습니다.";
            }
            
            answer[index++] = a;
        }

        
        return answer;
    }
}