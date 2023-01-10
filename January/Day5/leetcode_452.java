class Solution {
    public int findMinArrowShots(int[][] points) {
        Arrays.sort(points, new Comparator<int[]>() {
        @Override              
          public int compare(final int[] entry1, 
                             final int[] entry2) {
            if (entry1[1] > entry2[1])
                return 1;
            else
                return -1;
          }
        });
        int count=1;
        int x=points[0][1];
        for(int i=1;i<points.length;i++){
            if(x>=points[i][0] && x<=points[i][1])continue;
            else{
                count++;
                x=points[i][1];
            }
        }
        return count;
    }
}
