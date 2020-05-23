class Solution {
public:
    string frequencySort(string s)
    {
        string res = "";
        map<char,int> mp;
        for(int i=0;i<s.size();i++)
            mp[s[i]]++;

        vector<pair<int,char>> v;
        for(auto it = mp.begin(); it!= mp.end(); it++)
            v.push_back(make_pair(it->second,it->first));

        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        for(int i=0;i<v.size();i++)
        {
            pair<int,char> p = v[i];
            res += string(p.first,p.second);
        }
        return res;
    }
};