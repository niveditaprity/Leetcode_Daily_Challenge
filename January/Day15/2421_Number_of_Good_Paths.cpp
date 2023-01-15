class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int find(int x) {
    if (x == parent[x]) {
        return x;
    }
    return parent[x] = find(parent[x]);
}

void Union(int x, int y) {
    int p1 = find(x), p2 = find(y);
    if (p1 != p2) {
        if (rank[p1] > rank[p2]) {
            parent[p2] = p1;
            rank[p1] += rank[p2];
        }
        else {
            parent[p1] = p2;
            rank[p2] ++;
        }
    }
}
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        vector<int>adj[n];
        for (auto edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
         }
        rank.resize(n);
        parent.resize(n);
        for (int i = 0; i < n; i++) 
        {
            rank[i] = 0;
            parent[i] = i;
        }

    map<int, vector<int>>Node;
    for (int i = 0; i < n; i++) {
        Node[vals[i]].push_back(i);
    }
    int ans = 0;

    for (auto[value,nodes] : Node) {
        for (auto node: nodes) {
            for (auto neighbour : adj[node]) {
                if (vals[neighbour] <= vals[node]) {
                    Union(node, neighbour);
                }
            }
        }

        unordered_map<int, int>freq;
        for (auto node : nodes) {
            freq[find(node)]++;
        }
        for (auto it : freq) {
            int count = (it.second * (it.second+1)) / 2;
            ans += count;
        }
    }
    return ans;  
    }
};
