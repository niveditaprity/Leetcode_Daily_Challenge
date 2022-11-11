class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
         int k, i=1;
        for(k=1;k<nums.size();k++)
        {
          if(nums[k-1]!=nums[k])
          {
              nums[i] = nums[k];
              i++;
          }
        }
        return i;
        
    }
};