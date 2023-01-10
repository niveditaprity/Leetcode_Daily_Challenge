class Solution {
    public int minimumRounds(int[] tasks) {
        int count=0;
        HashMap<Integer,Integer> map = new HashMap<>();
        for(int n:tasks){
            map.put(n,map.getOrDefault(n,0)+1);
        }
        for (Map.Entry<Integer,Integer> mapElement : map.entrySet()) {
            Integer value=mapElement.getValue();
            if(value==1)return -1;
            else if(value==2)count++;
            else {
                count+=Math.ceil(value/3.0);
            }
            }
        return count;
    }
}
