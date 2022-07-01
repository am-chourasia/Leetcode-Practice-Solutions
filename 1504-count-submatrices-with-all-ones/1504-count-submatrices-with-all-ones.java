class Solution {
    private int countOneRow(int[] heights) {
        int res = 0, cummulative = 0;
        int len = heights.length;
        for (int i = 0; i < len; ++i) {
            cummulative = heights[i] == 0 ? 0 : cummulative + 1;
            res += cummulative;
        }
        return res;
    }
    public int numSubmat(int[][] mat) {
        int rows = mat.length;
        int cols = mat[0].length;
        int count = 0;
        
        for (int row = 0; row < rows; row++) {
            int[] heights = new int[cols];
            Arrays.fill(heights, 1);
            for(int r = row; r < rows; r++){
                for (int col = 0; col < cols; col++) {
                    heights[col] = heights[col] & mat[r][col]; 
                }
                count += countOneRow(heights);
            }
        }
        
        return count;
    }
}