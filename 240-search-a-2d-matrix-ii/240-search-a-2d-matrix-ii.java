class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int rows = matrix.length;
        int cols = matrix[0].length;
        
        if(target < matrix[0][0] || target > matrix[rows-1][cols-1])
            return false;
        
        int row = rows - 1, col = 0;
        
        //         ------->
        //         |            
        //      -->|
        //     |
        // --->
        
        while(row >=0 && col < cols){
            int element = matrix[row][col];
            System.out.println(row + " " + col + " " + element);
            if(element == target)
                return true;
            if(target > element)
                col++;
            else
                row--;
        }
        return false;
    }
}