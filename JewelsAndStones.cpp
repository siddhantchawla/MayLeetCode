class Solution
{
public:
    int numJewelsInStones(string J, string S)
    {
        map<char,bool> mp;

        for(int i=0;i<J.length();i++)
            mp[J[i]] = true;

        int count = 0;
        for(int i=0;i<S.length();i++)
        {
            if(mp[S[i]])
                count++;
        }
        return count;
    }
};