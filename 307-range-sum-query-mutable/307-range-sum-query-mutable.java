class NumArray {
    int[] segTree;
    int originalLength;
    private int leftChild(int index){
        return 2 * index + 1;
    }
    private int rightChild(int index){
        return 2 * index + 2;
    }
    
    private int build(int index, int range_start, int range_end, int[] nums) {
        if(range_start == range_end){
            segTree[index] = nums[range_start];
            return nums[range_start];
        }   
        int mid = (range_start + range_end) / 2;
        int leftSum = build(leftChild(index), range_start, mid, nums);
        int rightSum = build(rightChild(index), mid + 1, range_end, nums);
        segTree[index] = leftSum + rightSum;
        return segTree[index];
    }
    
    private int query(int index, int range_start, int range_end, int left, int right){
        if(range_start > right || range_end < left)
            return 0;
        if(range_start >= left && range_end <= right)
            return segTree[index];      // completely contained
        
        int mid = (range_start + range_end) / 2;
        int leftSum = query(leftChild(index), range_start, mid, left, right);
        int rightSum = query(rightChild(index), mid + 1, range_end, left, right);
        return leftSum + rightSum;
    }
    
    private void updateTree(int indexToChange, int treeIndex, int range_start, int range_end, int newVal){
        if(indexToChange < range_start || indexToChange > range_end)
            return;
        if(range_start == range_end){
            segTree[treeIndex] = newVal;
            return;
        }
        int mid = (range_start + range_end) / 2;
        updateTree(indexToChange, leftChild(treeIndex), range_start, mid, newVal);
        updateTree(indexToChange, rightChild(treeIndex), mid + 1, range_end, newVal);
        segTree[treeIndex] = segTree[leftChild(treeIndex)] + segTree[rightChild(treeIndex)];
    }
    
    public NumArray(int[] nums) {
        int length = nums.length;
        originalLength = length;
        segTree = new int[4 * length + 1];
        build(0, 0, length - 1, nums);
    }
    
    public void update(int index, int val) {
        updateTree(index, 0, 0, originalLength - 1, val);
    }
    
    public int sumRange(int left, int right) {
        return query(0, 0, originalLength - 1, left, right);
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(index,val);
 * int param_2 = obj.sumRange(left,right);
 */