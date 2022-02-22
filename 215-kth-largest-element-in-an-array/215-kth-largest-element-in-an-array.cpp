class Solution {
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left], l = left + 1, r = right;
        while (l <= r) {
            if (nums[l] < pivot && nums[r] > pivot) 
                swap(nums[l++], nums[r--]);
            if (nums[l] >= pivot) 
                l++;
            if (nums[r] <= pivot)
                r--;
        }
        swap(nums[left], nums[r]);
        return r;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        while (true) {
            int idx = partition(nums, left, right);
            if (idx == k - 1) 
                return nums[idx];
            if (idx < k - 1) 
                left = idx + 1;
            else 
                right = idx - 1;
        }
    }
};