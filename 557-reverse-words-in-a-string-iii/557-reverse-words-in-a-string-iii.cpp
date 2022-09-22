class Solution {
public:
    string reverseWords(string sentence) {
        int left = 0, right = 0;
        int len = sentence.length();
        while (right <= len) {
            if (right == len or sentence[right] == ' ') {
                int next = right + 1;
                while (right > left) 
                    swap(sentence[left++], sentence[--right]);
                left = right = next;
            }
            else {
                right += 1;
            }
        }
        return sentence;
    }
};