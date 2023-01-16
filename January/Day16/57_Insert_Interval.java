class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        List<int[]> ls = new ArrayList<>();
        for(int [] p:intervals){
            if(p[1]<newInterval[0]){
                ls.add(p);
            }
            else if(newInterval[1]<p[0]){
                ls.add(newInterval);
                newInterval=p;
            }
            else{
               newInterval[0]=Math.min(p[0],newInterval[0]);
               newInterval[1]=Math.max(p[1],newInterval[1]); 
            }
        }
        ls.add(newInterval);
        return ls.toArray(new int[ls.size()][2]);
    }
}
