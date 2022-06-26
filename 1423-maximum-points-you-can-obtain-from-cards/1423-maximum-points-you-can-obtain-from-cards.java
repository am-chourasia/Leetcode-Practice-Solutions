class Solution {
    public int maxScore(int[] cardPoints, int k) {
        int len = cardPoints.length;
        int left = len - k;
        int right = 0;
        
        int sum = 0;
        for(int i = left; i < len; i++)
            sum += cardPoints[i];
        
        int maxPoints = sum;
        
        while(left < len){
            sum -= cardPoints[left];
            sum += cardPoints[right];
            right++;
            left++;
            maxPoints = Math.max(maxPoints, sum);
        }
        
        return maxPoints;
    }
}