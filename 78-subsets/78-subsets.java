class Solution {
    boolean isSet(int n, int i){
        return (n & (1 << i)) != 0;
    }
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        int len = nums.length;
        for(int i = 0; i < (1 << len); i++){
            List<Integer> k = new ArrayList<>();
            for(int j = 0; j < 32; j++){
                if(isSet(i, j))
                    k.add(nums[j]);
            }
            ans.add(k);
        }
        return ans;
    }
}