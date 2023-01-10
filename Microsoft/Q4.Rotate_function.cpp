// You are given an integer array nums of length n.

// Assume arrk to be an array obtained by rotating nums by k positions clock-wise. We define the rotation function F on nums as follow:

// F(k) = 0 * arrk[0] + 1 * arrk[1] + ... + (n - 1) * arrk[n - 1].
// Return the maximum value of F(0), F(1), ..., F(n-1).

class Solution {
public:
    // take example [4 3 2 6]
    // #1->0*4+1*3+2*2+3*6
    // #2->0*6+1*4+2*3+3*2->#1+(4+3+2+6)-4*6->#prev_ans+(sum of array)-4*first element
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            ans+=i*nums[i];
        }
        int ans_req=ans;
        int pivot_index=0;
        for(int i=1;i<n;i++)
        {
            pivot_index=(pivot_index+n-1)%n;
            ans=ans+sum-n*nums[pivot_index];
            ans_req=max(ans_req,ans);
        }
        return ans_req;
    }
};
