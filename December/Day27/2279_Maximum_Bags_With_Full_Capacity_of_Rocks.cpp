class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        
        vector<pair<int,int>> nums;
        
        for(int i = 0; i < rocks.size(); i++)
        {
            nums.push_back({capacity[i]-rocks[i], rocks[i]});
        }
        
     
        sort(nums.begin(), nums.end());
      
        int cnt = 0;
        for(auto ell : nums)
        {
            if(ell.first == 0) {
                cnt++;
                continue;
            }
            
            if(additionalRocks >= ell.first)
            {
                cnt++;
                additionalRocks -= ell.first;        
            }
            
            if(additionalRocks == 0) break;
            
        }
    
        return cnt;
    }
};
