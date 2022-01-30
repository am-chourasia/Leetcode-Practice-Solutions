class Solution {
public:
    void reverse(vector<int>&A, long start, long end){
        while(start<end){
            long temp = A[start];
            A[start] = A[end];
            A[end] = temp;
            start++;
            end--;
        }
    }
    void rotate(vector<int>& A, int k) {
        long n = A.size();
        k = k%n;
        reverse(A, 0, n-1);
        reverse(A, 0, k-1);
        reverse(A, k, n-1);
    }
};