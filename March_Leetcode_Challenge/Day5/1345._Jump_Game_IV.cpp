class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>>map_indices;
        for(int i = 0 ;i<arr.size(); i++)
        {
            map_indices[arr[i]].push_back(i);
        }
        vector<int>visited(arr.size(),false);
        queue<int>q;
        q.push(0);
        visited[0] = true;
        int jump = 0;
        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0 ;i<size; i++)
            {
                int index = q.front();
                q.pop();
                if(index == arr.size()-1)
                {
                   return jump; 
                }

                vector<int>&temp_index = map_indices[arr[index]];
                temp_index.push_back(index+1);
                temp_index.push_back(index-1);
                for(auto ele : temp_index )
                {
                   if(ele>=0 && ele<arr.size() && !visited[ele])
                   {
                       q.push(ele);
                       visited[ele] = true;
                   }
                }
                temp_index.clear();

                
            }
            jump++;
        }
        return -1;

    }
};
