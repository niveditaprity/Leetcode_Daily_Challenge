// Time complexity -: O(2n)+O(k)
// space complexity -: O(log n)

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {

        priority_queue<int>pq;// O(log n)

        for(int i = 0; i < piles.size(); i++) // O(n)
        {
            pq.push(piles[i]);
        }

        while(k != 0)         // O(k)
        {
            int val = pq.top();
            pq.pop();
            pq.push(val - floor(val/2));
            k--;
        }

        int ans = 0;
        while(!pq.empty())  // O(n)
        {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};