class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n = gas.size();
        int totalgas = 0 , totalcost = 0;
        int currentgas = 0;
        int lowest_Index = 0;

        for(int i = 0; i < n; i++)
        {
            totalgas += gas[i];
            totalcost += cost[i];
            currentgas = currentgas + gas[i] - cost[i];

            if(currentgas < 0)
            {
                lowest_Index = i+1;
                currentgas = 0;
            }
        }

        if(totalgas >= totalcost)
        {
            return lowest_Index;
        }
        return -1;
    }
};