class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int length1 = name.length();
        int length2 = typed.length();
        
        if(length2 < length1)
            return false;
        
        int pointer1 = 0;
        
        for(int pointer2 = 0; pointer2 < length2; pointer2 ++){
            if(pointer1 == length1 and typed[pointer2] != name[pointer1 - 1])
                return false;
            else if(name[pointer1] == typed[pointer2])
                pointer1++;
            else if(pointer1 == 0 or name[pointer1 - 1] != typed[pointer2])
                return false;
        }
        
        if(pointer1 < length1)
            return false;
        return true;
    }
};