class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int len1 = arr1.size();
        int len2 = arr2.size();
        int xorred = 0;
        int xorsum = 0;
        
        for(int i = 0; i < len2; i++)
            xorred ^= arr2[i];
        
        for(int i = 0; i < len1; i++)
            xorsum ^= (arr1[i] & xorred);
        
        return xorsum;
    }
};