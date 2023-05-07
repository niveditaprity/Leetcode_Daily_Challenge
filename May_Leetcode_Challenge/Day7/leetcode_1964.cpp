class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int> ans(n, 0);
        vector<int> s;
        for (int i = 0; i < n; i++) {
            if (s.empty() || obstacles[i] >= s.back()) {
                s.push_back(obstacles[i]);
                ans[i] = s.size();
            } else {
                auto it = upper_bound(s.begin(), s.end(), obstacles[i]);
                *it = obstacles[i];
                ans[i] = it - s.begin() + 1;
            }
        }
        return ans;
    }
};
