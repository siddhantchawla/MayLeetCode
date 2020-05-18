class Solution {

    bool checkAnagram(vector<int> a,vector<int> b)
    {
        for(int i=0;i<a.size();i++)
        {
            if(a[i]!=b[i])
                return false;
        }
        return true;
    }

public:
    vector<int> findAnagrams(string s, string p)
    {
        if(s.size() < p.size())
            return {};
        int k = p.size();
        vector<int> result;

        vector<int> mp(26,0);

        for(int i=0;i<k;i++)
            mp[p[i]-'a']++;

        // sliding window of size k on string s
        vector<int> check(26,0);
        for(int i=0;i<k;i++)
            check[s[i]-'a']++;

        if(checkAnagram(mp,check))
            result.push_back(0);

        for(int i = k;i<s.size();i++)
        {
            check[s[i]-'a']++;
            check[s[i-k]-'a']--;

            if(checkAnagram(mp,check))
                result.push_back(i-k+1);
        }
        return result;
    }
};