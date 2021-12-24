class Solution {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, new Comparator<int[]>(){
            public int compare(int[] a, int[] b){
                return Integer.compare(a[0], b[0]);
            }
        });
        ArrayList<int[]> ans = new ArrayList<int[]>();
        
        int start = 0, end = 0;
        for(int i = 0; i < intervals.length; i++){
            start = intervals[i][0];
            end = intervals[i][1];
            while(i+1 < intervals.length && end >= intervals[i+1][0]){
                i++;
                end = Math.max(intervals[i][1], end);
            }
            int[] merged = {start, end};
            ans.add(merged);
        }
        return ans.toArray(new int[ans.size()][]);
    }
}