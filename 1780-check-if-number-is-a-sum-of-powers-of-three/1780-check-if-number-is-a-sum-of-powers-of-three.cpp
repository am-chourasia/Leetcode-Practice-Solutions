class Solution {
    bool isSet(int n, int i){
        return n & (1 << i);
    }
public:
    bool checkPowersOfThree(int n) {
        vector<int> powers(15);
        int element = 1;
        for(int i = 0; i < 15; i++){
            powers[i] = element;
            element *= 3;
        }
        
        for(int i = 0; i < (1 << 15); i++){
            int k = 0;
            for(int j = 0; j < 15; j++){
                if(isSet(i, j))
                    k += powers[j];
            }
            if(k == n)
                return true;
        }
        return false;
    }
};