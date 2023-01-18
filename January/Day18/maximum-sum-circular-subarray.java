class Solution {
    public int maxSubarraySumCircular(int[] nums) {
        int totalsum=0;
        int maxcurr=0;
        int maxsum=nums[0];
        int mincurr=0;
        int minsum=nums[0];
        for(int el:nums){
            maxcurr=Math.max(maxcurr+el,el);
            maxsum=Math.max(maxcurr,maxsum);

            mincurr=Math.min(mincurr+el,el);
            minsum=Math.min(mincurr,minsum);

            totalsum+=el;
        }
        return maxsum>0?Math.max(maxsum,totalsum-minsum):maxsum;
    }
}
