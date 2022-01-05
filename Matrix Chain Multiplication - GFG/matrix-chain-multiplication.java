// { Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG
{
    public static void main(String args[])throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(in.readLine());
        while(t-- > 0){
            int N = Integer.parseInt(in.readLine());
            String input_line[] = in.readLine().trim().split("\\s+");
            int arr[]= new int[N];
            for(int i = 0; i < N; i++)
                arr[i] = Integer.parseInt(input_line[i]);
            
            Solution ob = new Solution();
            System.out.println(ob.matrixMultiplication(N, arr));
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution{
    static int matrixMultiplication(int N, int arr[])
    {
        int[][] memo = new int[N][N];
        for(int i = 0; i < N; i++){
            memo[i] = new int[N];
            Arrays.fill(memo[i], -1);
        }
        return helper(arr, 1, N-1, memo);
    }
    static int helper(int A[], int i, int j, int[][] memo){
        if(i >= j)
            return 0;
        if(memo[i][j] != -1)
            return memo[i][j];
        int minimumCost = Integer.MAX_VALUE;
        for(int k = i; k < j; k++){
            int left = helper(A, i, k, memo);
            int right = helper(A, k+1, j, memo);
            int ans = left + right + A[i-1]*A[k]*A[j];
            minimumCost = Math.min(minimumCost, ans);
        }
        memo[i][j] = minimumCost;
        return minimumCost;
    }
}