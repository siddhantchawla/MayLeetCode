class Solution {
    int kadane(vector<int> a, int n)
    {
        int max_so_far = 0, max_ending_here = 0;
        int i;
        for (i = 0; i < n; i++)
        {
            max_ending_here = max_ending_here + a[i];
            if (max_ending_here < 0)
                max_ending_here = 0;
            if (max_so_far < max_ending_here)
                max_so_far = max_ending_here;
        }
        return max_so_far;
    }

    bool allneg(vector<int> v)
    {
        for(int i=0;i<v.size();i++)
        {
            if(v[i]>=0)
                return false;
        }
        return true;
    }

public:
    int maxSubarraySumCircular(vector<int>& A)
    {
        if(allneg(A))
        {
            sort(A.begin(),A.end());
            return A[A.size()-1];
        }
        int l = A.size();
        vector<int> v;
        for(int i=0;i<l;i++)
            v.push_back(A[i]);

        int m1 = kadane(v,l);

        int s = 0;
        for(int i = 0;i < v.size();i++)
        {
            s += v[i];
            v[i] = -v[i];
        }
        int m2 = s + kadane(v,l);
        return max(m1,m2);
    }
};