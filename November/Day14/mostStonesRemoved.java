class Solution {

boolean isValid(int[] coord1,  int[]coord2){
    if(coord1[0] == coord2[0]) return true;
    if(coord1[1] == coord2[1]) return true;
    return false;
}

void dfs(int[][] stones, boolean[] visited, int currIndx){
    visited[currIndx]  = true;
    for(int i = 0; i<stones.length;i++){
        if(visited[i]) continue;
        if(isValid(stones[i],stones[currIndx]))
        dfs(stones,visited,i);
    }
}

    public int removeStones(int[][] stones) {
        int n = stones.length;
        boolean[] visited = new boolean[n];
        Arrays.fill(visited,false);
        int count_component = 0;

        for(int i = 0; i<n; i++){
            if(visited[i]) continue;
            dfs(stones,visited,i);
            count_component++;
        }
        return (n-count_component);
    }
}