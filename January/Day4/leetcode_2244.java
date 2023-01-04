class Solution {
    public int minimumRounds(int[] tasks) {
        
      HashMap<Integer,Integer> map=new HashMap<>();
      int count=0;

      for(int i=0;i<tasks.length;i++)
        map.put(tasks[i],map.getOrDefault(tasks[i],0)+1);

      for(Map.Entry<Integer,Integer> entry: map.entrySet())
      {
        int temp=entry.getValue();
        if(temp==1) return -1;
        else if(temp%3==0) count+=temp/3;
        else count+=temp/3+1;
      }

      return count;  
    }
}