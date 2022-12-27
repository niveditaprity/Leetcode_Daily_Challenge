class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n = nums.size();
        int lastInd = n-1;
        
        for(int i = n-1; i >= 0; i--)
        {
            if(nums[i] > 0 && i + nums[i] >= lastInd)
                lastInd = i;
        }
        
        return lastInd == 0;
    }
};
