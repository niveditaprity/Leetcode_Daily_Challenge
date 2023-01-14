class Solution {
    public int maxIceCream(int[] costs, int coins) {
        Arrays.sort(costs);
        int count=0;
        for(int n:costs){
            coins-=n;
            if(coins<0)break;
            else count++;
        }
        return count;
    }
}
