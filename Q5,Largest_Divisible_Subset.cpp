// Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

// answer[i] % answer[j] == 0, or
// answer[j] % answer[i] == 0
// If there are multiple solutions, return any of them.
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        //just modified function to print longest increasing subsequence
        // L[i] - The longest increasing sub-sequence
        // ends with arr[i]
        int n=nums.size();
         vector<vector<int> > L(n);
         sort(nums.begin(),nums.end());
         //L[0] is equal to arr[0]
         L[0].push_back(nums[0]);
         
         for(int i=1;i<n;i++)
         {
             for(int j=0;j<i;j++)
             {
                  /* L[i] = {Max(L[j])} + arr[i]
            where j < i and arr[j] < arr[i] */
                 if(nums[i]%nums[j]==0&&L[i].size()<L[j].size()+1)
                 L[i]=L[j];
             }
             L[i].push_back(nums[i]);//L[i] will end in nums[i];
         }
         vector<int>max=L[0];
         for(vector<int>x:L)
         {
             if(x.size()>max.size())
             max=x;
         }
         return max;
    }
};
