class Solution {
public:
   bool static sorted(const vector<int>& v1,const vector<int>& v2) { 
     return v1[1] < v2[1]; 
} 
    int findMinArrowShots(vector<vector<int>>& points) {
      sort(points.begin(),points.end(),sorted);
      int x = points[0][1];
      int count = 1;
      for(int i = 1 ;i<points.size(); i++)
      {
        if(x>=points[i][0] && x<=points[i][1])
        {
            continue;
        }
        else
        {
            count++;
            x = points[i][1];
        }
      }
      return count;
    }
};
