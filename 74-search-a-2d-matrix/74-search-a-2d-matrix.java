class Solution 
{
    public boolean searchMatrix(int[][] matrix, int target) 
    {
        int rows = matrix.length;
        int cols = matrix[0].length;
        
        int start = 0, end = rows * cols;
        while(start < end){
            int mid = (start + end) / 2;
            int row = mid / cols;
            int col = mid % cols;
            if(matrix[row][col] == target)
                return true;
            if(matrix[row][col] < target)
                start = mid + 1;
            else
                end = mid;
        }
        
        return false;
    }
}