// { Driver Code Starts
//Initial Template for Java


import java.io.*;
import java.util.*;
class GfG
{
    public static void main(String args[])
        {
            Scanner sc = new Scanner(System.in);
            int t = sc.nextInt();
            while(t-->0)
                {
                    int m = sc.nextInt();
                    int N = sc.nextInt();
                    int Arr[] = new int[m];
                    for(int i = 0;i<m;i++)
                        Arr[i] = sc.nextInt();
                    Solution ob = new Solution();
                    System.out.println(ob.countWays(Arr,m,N));
                }
        }
}    // } Driver Code Ends


//User function Template for Java

class Solution
{
    public int countWays(int arr[], int m, int N) 
    { 
        int dp[] = new int[N+1];
        dp[0] = 1;
        
        for(int i = 1; i <= N; i++){
            for(int j = 0; j < m; j++){
                if(arr[j] <= i)
                    dp[i] = (dp[i] + dp[i-arr[j]]) % (int)(1e9 + 7);
            }
        }
        
        return dp[N];
    } 
}