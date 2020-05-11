class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust)
    {
        map<int,bool> mp;
        map<int,int> score;
        for(int i = 1;i<=N;i++)
            mp[i] = true;

        for(int i=0;i<trust.size();i++)
        {
            mp[trust[i][0]] = false;
            score[trust[i][1]]++;
        }

        for(auto it = mp.begin(); it!=mp.end(); it++)
        {
            if(it->second == true && score[it->first] == N-1)
                return it->first;
        }
        return -1;
    }
};