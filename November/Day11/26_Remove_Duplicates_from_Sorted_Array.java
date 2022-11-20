class Solution {
    public int removeDuplicates(int[] nums) {
        int point=0;
        for(int i=0;i<nums.length-1;i++){
            if(nums[i]!=nums[i+1]){
                nums[++point]=nums[i+1];
            }
        }
        return point+1;
    }
}
