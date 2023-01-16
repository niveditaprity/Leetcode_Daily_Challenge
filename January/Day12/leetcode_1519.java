class Solution {
    
    public int[] countSubTrees(int n, int[][] edges, String labels) {
        int []ans=new int[n];
        List<List<Integer>> ls = new ArrayList<>();
        for(int i=0;i<n;i++){
            ls.add(new ArrayList<Integer>(0));
        }
        for(int i=0;i<edges.length;i++){
            ls.get(edges[i][0]).add(edges[i][1]);
            ls.get(edges[i][1]).add(edges[i][0]);
        }
        boolean [] visited=new boolean[n];
        int [] label= new int[26];
         dfs(ls,labels,visited,label,0,ans);
         return ans;
        
    }
    private void dfs(List<List<Integer>> ls,String labels,boolean [] visited,int [] label,int i,int []ans){
        if(visited[i]==true)return;
        visited[i]=true;
        int prevCount = label[labels.charAt(i)-'a'];
        label[labels.charAt(i)-'a']++;
        for(int index:ls.get(i)){
            if(visited[index]!=true){
                dfs(ls,labels,visited,label,index,ans);
               
            }


        }
        ans[i]=label[labels.charAt(i)-'a']-prevCount;
         //label=new int[26];
        return ;
    }
}
