class Solution {
    public List<Integer> majorityElement(int[] nums) {
        int n = nums.length;
        ArrayList<Integer> ans = new ArrayList<Integer>();
        int count1, element1, count2, element2;
        count1 = count2 = 0;
        element1 = element2 = Integer.MIN_VALUE;
        
        for(int i=0; i<n; i++){
            if(nums[i] == element1)
                count1++;
            else if(nums[i] == element2)
                count2++;
            else if(count1 == 0){
                element1 = nums[i];
                count1 = 1;
            }
            else if(count2 == 0){
                element2 = nums[i];
                count2 = 1;
            }
            else{
                count1--;
                count2--;
            }
        }
        count1 = count2 = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == element1)
                count1++;
            else if(nums[i] == element2)
                count2++;
        }
        if(count1 > n/3)
            ans.add(element1);
        if(count2 > n/3)
            ans.add(element2);
        return ans;
    }
}