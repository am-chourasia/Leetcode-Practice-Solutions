class Solution {
    public int[] plusOne(int[] digits) {
        int length = digits.length;
        int carry = 1;
        
        for(int i = length - 1; i >= 0 && carry > 0; i--){
            digits[i] += carry;
            if(digits[i] > 9){
                digits[i] = digits[i] - 10;
                carry = 1;
            }
            else
                carry = 0;
        }
        if(carry == 1){
            int[] ans = new int[length + 1];
            ans[0] = 1;
            for(int i = 1; i <= length; i++)
                ans[i] = digits[i-1];
            return ans;
        }
        else
            return digits;
    }
}