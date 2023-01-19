class Solution {
    public int subarraysDivByK(int[] nums, int k) {
       int count=0;
       int runningsum=0;
       HashMap<Integer,Integer> map = new HashMap<>();
       map.put(0,1);
       for(int num:nums){
           runningsum+=num;
           int rem=runningsum%k;
           rem=rem<0?rem+k:rem;
           if(map.containsKey(rem)){
               count=count+map.get(rem);
               map.put(rem,map.getOrDefault(rem,0)+1);
           }
           else{
               map.put(rem,1);
           }
       } 
       return count;
    }
}
