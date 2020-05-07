class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        // Moore's Voting Algorithm
        int count = 1;
        int majorityElement = nums[0];
        for(int i = 1;i<nums.size();i++)
        {
            if(nums[i]==majorityElement)
                count++;
            else
                count--;
            
            if(count == 0)
            {
                count = 1;
                majorityElement = nums[i];
            }
        }
        return majorityElement;
    }
};