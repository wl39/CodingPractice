import java.lang.Math;

class Solution
{
    public int solution(int n, int a, int b)
    {
        int answer = 1;
        
        int newA = Math.min(a - 1, b - 1);
        int newB = Math.max(a - 1, b - 1);
                
        while(!(newA % 2 == 0 && newB % 2 == 1 && newB - newA == 1)) {
            answer++;
            newA /= 2; 
            newB /= 2;
        }
        
        
        return answer;
    }
}