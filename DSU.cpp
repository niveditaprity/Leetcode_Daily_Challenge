#include <bits/stdc++.h>
using namespace std;
 
 class DSU {
     
     vector<int>parent;
     vector<int>rank;
     int n;
 public:
     DSU(int n)
     {
        parent.resize(n);
        rank.resize(n);
        this->n = n;
        for(int i = 0 ;i<n; i++)
        {
         parent[i] = i;   
        }
     }
     int find(int x)
     {
         if(x == parent[x])
         {
             return x;
         }
         return parent[x] = find(parent[x]);
     }
     void Union(int a, int b)
     {
         int pa = find(a);
         int pb = find(b);
         if(pa != pb)
         {
           if(rank[a]> rank[b])
           {
               parent[b]= a;
           }
           else if(rank[a]<rank[b])
           {
               parent[a] = b;
           }
           else
           {
               parent[a] = b;
               rank[b]++;
           }
         }
     }
     bool isUnion(int a , int b)
     {
         if(find(a) == find(b))
         {
             return true;
         }
         return false;
     }
 };
 
int main() {
    DSU ds(8);
	ds.Union(1,2);
	ds.Union(3,4);
	ds.Union(4,5);
	cout<<ds.isUnion(1,2)<<"\n";
	ds.Union(6,7);
	cout<<ds.isUnion(7,5)<<"\n";
	ds.Union(7,5);
	cout<<ds.isUnion(7,5)<<"\n";
	return 0;
}
