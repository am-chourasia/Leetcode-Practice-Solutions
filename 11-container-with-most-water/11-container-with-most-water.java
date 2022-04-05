class Solution {
    public int maxArea(int[] height) {
        int len = height.length;
        int i = 0, j = len - 1;
        int max_area = 0;
        
        while(i < j){
            int left = height[i];
            int right = height[j];
            int area = (j - i);
            if(left < right){
                area *= left;
                i++;
            } else {
                area *= right;
                j--;
            }
            max_area = Math.max(max_area, area);
        }
        
        return max_area;
    }
}