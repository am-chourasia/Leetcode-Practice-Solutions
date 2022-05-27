class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int length1 = name.length();
        int length2 = typed.length();
        
        if(length2 < length1)
            return false;
        
        int p = 0; // pointer to the name string;
        int pointer2 = 0; // pointer to the typed string
        
        while(pointer2 < length2){
            int count = 1;
            char c = name[p];
            while(p + 1 < length1 and c == name[p + 1]){
                count++;
                p++;
            }
            
            while(pointer2 < length2 and typed[pointer2] == c){
                count--;
                pointer2++;
            }
            
            if(count > 0)
                return false;
            p++;
        }
        if(p < length1)
            return false;
        
        return true;
    }
};