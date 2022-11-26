    public:
        int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector< int > &profit)
        {

            vector<pair<int, pair<int, int>>> events;
            for (int i = 0; i < profit.size(); i++)
            {
                events.push_back({ startTime[i],
                    {
                        endTime[i],
                        profit[i]
                    } });
            }

            int maxVal = 0;
            priority_queue<pair<int, int>, vector< pair<int, int>>, greater<pair<int, int>>> pq;
            sort(events.begin(), events.end());

            for (auto &e: events)
            {
                while (!pq.empty() && pq.top().first <= e.first)
                {
                    maxVal = max(maxVal, pq.top().second);
                    pq.pop();
                }

                pq.push({ e.second.first,
                    maxVal + e.second.second });
            }

            while (!pq.empty())
            {
                maxVal = max(maxVal, pq.top().second);
                pq.pop();
            }
            return maxVal;
        }
};
