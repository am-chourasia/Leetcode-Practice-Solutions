class Solution {
    public int calculate(String s) {
        // We calculate the intermediatary results between every pair of parenthesis
        // and add them all together with appropriate sign along the way with the use of stack.
        Stack<Integer> stack = new Stack<Integer>();
        int result = 0;
        int number = 0;
        int sign = 1;
        
        for(int i = 0; i < s.length(); i++){
            char c = s.charAt(i);
            if(Character.isDigit(c)){
                number =  number*10 + (c-'0');
            } else if(c == '+'){
                result += number*sign;
                number = 0;
                sign = 1;
            } else if(c == '-'){
                result += number*sign;
                number = 0;
                sign = -1;
            } else if(c == '('){
                // store the result before the paranthesis in the stack with a proper sign
                // and reset the result and sign to calculate intermediatary result ahead
                stack.push(result);     
                stack.push(sign);
                result = 0;
                sign = 1;
            } else if(c == ')'){
                result += sign * number;  
                number = 0;
                result *= stack.pop();  // multiplying with the sign before the opening parenthesis
                result += stack.pop();  // adding with the result outside the parathesis 
            }
        }
        if(number != 0) // for last number
            result += sign * number;
        return result;
    }
}