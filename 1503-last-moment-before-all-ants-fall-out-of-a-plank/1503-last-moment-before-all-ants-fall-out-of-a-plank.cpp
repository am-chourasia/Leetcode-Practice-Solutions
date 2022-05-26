class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int rightmost = 0, leftmost = n;
        if(left.size() > 0)
            rightmost = *max_element(left.begin(), left.end());
        if(right.size() > 0)
            leftmost = *min_element(right.begin(), right.end());
        int ans = max(rightmost, n - leftmost);
        return ans;
    }
};