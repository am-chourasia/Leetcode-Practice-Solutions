class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        // calculating row-wise prefix sum
        for (int row = 0; row < rows; row++) 
            for (int col = 1; col < cols; col++) 
                matrix[row][col] += matrix[row][col - 1];
        
        int count = 0;
        for (int left = 0; left < cols; left++){
            for (int right = left; right < cols; right++){
                int sum = 0;
                unordered_map<int, int> sumFreq;
                sumFreq[0] = 1;
                for (int row = 0; row < rows; row++) {
                    sum += matrix[row][right];
                    if (left > 0)
                        sum -= matrix[row][left - 1];
                    if (sumFreq.find(sum - target) != sumFreq.end())
                        count += sumFreq[sum - target];
                    sumFreq[sum] += 1;
                }
            }
        }
        
        return count;
    }
};