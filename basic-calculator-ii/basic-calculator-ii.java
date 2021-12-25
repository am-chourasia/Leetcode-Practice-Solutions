class Solution {
    public int calculate(String exp) {
        int len = exp.length();
        Stack<Integer> stack = new Stack<>();
        int number = 0;
        char operator = '+';
        
        for(int i = 0; i < len; i++){
            char lexim = exp.charAt(i);
            if(Character.isDigit(lexim)){
                number = number * 10 + (lexim - '0');
            }
            if (!Character.isDigit(lexim) && !Character.isWhitespace(lexim) || i == len - 1){
                if(operator == '+'){
                    stack.push(number);
                }
                else if(operator == '-'){
                    stack.push(-number);
                }
                else if(operator == '*'){
                    int top = stack.pop();
                    int result = top * number;
                    stack.push(result);
                }
                else if(operator == '/'){
                    int top = stack.pop();
                    int result = top / number;
                    stack.push(result);
                }
                operator = lexim;
                number = 0;
            }
        }
        int result = 0;
        while(!stack.isEmpty())
            result += stack.pop();
        
        return result;
    }
}