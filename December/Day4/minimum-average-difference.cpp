class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        
        // Calculate sum of all elements on nums.
        long long totalSum = 0;
        for(int i=0; i<n; ++i) {
            totalSum += nums[i];
        }
        
        // Initialize the variables.
        int leftNums = 0, rightNums = n;
        long long leftSum = 0, rightSum;
        int minAvg = INT_MAX;
        int ans = -1;
        
        // Calculate average of every element and find the minimum average.
        for(int i=0; i<n; ++i) {
            // Calculate sum of elements at left and at right.
            leftSum += nums[i];
            rightSum = totalSum - leftSum;
            
            // Calculate the number of elements at left and at right.
            ++leftNums;
            --rightNums;
            
            // Calculate the average of left side lements and right side elements.
            int leftAvg = leftSum/leftNums;
            int rightAvg = 0;
            // If there are no elemets at right, take right side average as 0.
            if(rightNums > 0) {
                rightAvg = rightSum/rightNums;
            }
            
            // Calculate the absolute difference between left avg. and right avg.
            int avg = abs(leftAvg - rightAvg);
            
            // If the absolute difference is less than the prev. absolute difference.
            if(avg < minAvg) {
                ans = i;
                minAvg = avg;
            }
        }
        
        return ans;
    }
};