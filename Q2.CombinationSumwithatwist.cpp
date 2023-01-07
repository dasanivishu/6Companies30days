// Q2.Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

// Only numbers 1 through 9 are used.
// Each number is used at most once.
// Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

class Solution {
public:
//we will just see all the permutations 
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int> vec;
        helper(1,0,ans,vec,n,k);//we will take first digit as 1 and start the recursion
        return ans;
    }
    void helper(int ind,int sum,vector<vector<int>>&ans,vector<int>&vec,int n,int k)
    {
        if(k==0&&sum==n)
        {
            ans.push_back(vec);
            return;
        }
        if(sum>n)
        return;
        for(int i=ind;i<=9;i++)
        {
            vec.push_back(i);
            helper(i+1,sum+i,ans,vec,n,k-1);
            vec.pop_back();//if i cannot be in ans then we will backtrack
        }
        return;
    }
};
