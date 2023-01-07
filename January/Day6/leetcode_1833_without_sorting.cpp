class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
     vector<int>mp(100001,0);
     int count = 0;
     for(int i=0;i<costs.size();i++){
            mp[costs[i]]++;
        }
    int i = 1;
    while(i<100001 && coins>=i)
    {
        if((long)mp[i]*i > coins && coins>=i)
        {
            int bars = coins/i;
            coins = coins - bars*i;
            count+=bars;
            break;
        }
        if(mp[i]!=0 && coins>=0)
        {
            coins = coins - mp[i]*i;
            count+=mp[i];
        }
        i++;
    }
    return count;  
    }
};
