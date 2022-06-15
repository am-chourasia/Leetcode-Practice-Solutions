class Solution {
    private boolean traversePath(int[] arr, int index, boolean[] visited){
        if(index < 0 || index >= arr.length || visited[index])
            return false;
        if(arr[index] == 0)
            return true;
        visited[index] = true;
        int prevIndex = index - arr[index];
        int nextIndex = index + arr[index];
        return traversePath(arr, prevIndex, visited) 
            || traversePath(arr, nextIndex, visited);
    }
    public boolean canReach(int[] arr, int start) {
        int len = arr.length;
        boolean[] visited = new boolean[len];
        return traversePath(arr, start, visited);
    }
}