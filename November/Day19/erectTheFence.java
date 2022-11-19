class Solution {
    private int orientation(int[] cord1,int[] cord2,int[] cord3){
        return (cord3[1]-cord2[1]) * (cord2[0]-cord1[0]) - ((cord2[1]-cord1[1]) * (cord3[0]-cord2[0])); 
    }
    public int[][] outerTrees(int[][] trees) {

        Stack<int[]> upperHull= new Stack<>();
        Stack<int[]> lowerHull= new Stack<>();
        Arrays.sort(trees,(p,q) ->q[0]==p[0]?q[1]-p[1]:q[0]-p[0]);

        for(int i=0;i<trees.length;i++){
            int lowLen = lowerHull.size();
            int upLen = upperHull.size();

            while(lowLen>= 2 && orientation(lowerHull.get(lowLen-2),lowerHull.get(lowLen-1),trees[i]) >0){
                lowerHull.pop();
                lowLen--;
            }

            while(upLen>= 2 && orientation(upperHull.get(upLen-2),upperHull.get(upLen-1),trees[i])<0){
                upperHull.pop();
                upLen--;
            }

            lowerHull.push(trees[i]);
            upperHull.push(trees[i]);    
        }

        Set<int[]> ans= new HashSet<>(lowerHull);
        ans.addAll(upperHull);
        return ans.toArray(new int[ans.size()][]);
        
    }
}