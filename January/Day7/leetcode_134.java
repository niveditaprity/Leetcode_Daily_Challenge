class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int gascost=0;
        int actualcost=0;
        int index=0;
        int total=0;
        for(int i=0;i<gas.length;i++){
            gascost+=gas[i];
            actualcost+=cost[i];
            total+=gas[i]-cost[i];
            if(total<0){
                index=i+1;
                total=0;
            }

        }
        return gascost<actualcost?-1:index;
    }
}
