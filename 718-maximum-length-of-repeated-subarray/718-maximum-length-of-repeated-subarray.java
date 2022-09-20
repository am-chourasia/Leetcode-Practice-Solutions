class Solution {
    public int findLength(int[] nums1, int[] nums2) {
        int len1 = nums1.length;
        int len2 = nums2.length;
        int[] dp = new int[len2 + 1];
        int ans = 0;
        
        for (int i = 1; i <= len1; i++) {
            for (int j = len2; j > 0; j--) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[j] = 1 + dp[j - 1];
                    ans = Math.max(ans, dp[j]);
                } else {
                    dp[j] = 0;
                }
            }
        }
        
        return ans;
    }
}