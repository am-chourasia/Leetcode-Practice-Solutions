class Solution {
    public boolean validMountainArray(int[] arr) {
        int length = arr.length;
        if(length < 3)
            return false;
        if(arr[0] >= arr[1])
            return false;
        
        boolean reachedPeak = false;
        
        for(int index = 1; index < length; index++){
            int prevIndex = index - 1;
            if(!reachedPeak && arr[index] <= arr[prevIndex])
                reachedPeak = true;
            if(reachedPeak && arr[index] >= arr[prevIndex])
                return false;
        }
        
        return reachedPeak;
    }
}