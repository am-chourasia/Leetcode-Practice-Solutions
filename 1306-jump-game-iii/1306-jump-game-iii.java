class Solution {
    private boolean traversePath(int[] arr, int index, boolean[] visited){
        if(arr[index] == 0)
            return true;
        visited[index] = true;
        int prevIndex = index - arr[index];
        int nextIndex = index + arr[index];
        if(prevIndex >= 0 && !visited[prevIndex])
            if(traversePath(arr, prevIndex, visited))
                return true;
        if(nextIndex < arr.length && !visited[nextIndex])
            if(traversePath(arr, nextIndex, visited))
                return true;
        return false;
    }
    public boolean canReach(int[] arr, int start) {
        int len = arr.length;
        boolean[] visited = new boolean[len];
        return traversePath(arr, start, visited);
    }
}