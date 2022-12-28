class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        
        priority_queue<int> pq;
        
        for(int i = 0; i < piles.size(); i++)
        {
            pq.push(piles[i]);
        }
        
        while(!pq.empty() && k > 0)
        {
            k--;
            
            float el = pq.top();
            pq.pop();
            
            el = ceil(el/2);
                   
            pq.push(el);
        }
        
        int ans = 0;
        while(!pq.empty())
        {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};
