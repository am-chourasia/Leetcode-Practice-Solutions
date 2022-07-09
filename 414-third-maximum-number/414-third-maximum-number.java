class Solution {
    public int thirdMax(int[] nums) {
        Integer max1 = null, max2 = null, max3 = null;
        
        for (int e : nums) {
            if(max1 != null && e == max1 ||
               max2 != null && e == max2 ||
               max3 != null && e == max3)
                continue;
            
            if(max1 == null || e >= max1) {
                max3 = max2;
                max2 = max1;
                max1 = e;
            } else if (max2 == null || e >= max2) {
                max3 = max2;
                max2 = e;
            } else if (max3 == null || e > max3) {
                max3 = e;
            }
            // System.out.pritnln(max1 + " " + max2 + " " + max3);
        }
        
        if (max3 == null)
            return max1;
        return max3;
    }
}