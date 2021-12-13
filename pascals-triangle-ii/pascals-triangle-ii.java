class Solution {
    int[][] dp;
    public List<Integer> getRow(int rowIndex) {
        dp = new int[34][34];
        List<Integer> ans = Arrays.asList(new Integer[rowIndex+1]);

        for(int j=1; j<rowIndex; j++)
            ans.set(j, get(rowIndex, j));
        ans.set(0, 1);
        ans.set(rowIndex, 1);
        return ans;
    }
    int get(int i, int j){
        if(dp[i][j] != 0)
            return dp[i][j];
        if(i == j || j == 0)
            return dp[i][j] = 1;
        return dp[i][j] = get(i-1, j-1) + get(i-1, j);
    }
}