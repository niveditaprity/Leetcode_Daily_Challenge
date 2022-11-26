class Solution
{
    public:
    int find(int i,vector<vector<int>>& job,vector<int>&startTime,int n){
		if(i>=n) return 0;
		int index = lower_bound(startTime.begin(),startTime.end(),job[i][1])-startTime.begin();
		int pick=job[i][2]+find(index,job,startTime,n);
		int notpick=find(i+1,job,startTime,n);
		return max(pick,notpick);
	}
        int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector< int > &profit) {
        int n=startTime.size();
		vector<vector<int>> job;
		for(int i=0;i<n;i++) 
            job.push_back({startTime[i],endTime[i],profit[i]});  
		sort(job.begin(),job.end());
		sort(startTime.begin(),startTime.end());
		return find(0,job,startTime,n);
        }
};
