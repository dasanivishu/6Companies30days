// You are given a 0-indexed array of strings nums, where each string is of equal length and consists of only digits.

// You are also given a 0-indexed 2D integer array queries where queries[i] = [ki, trimi]. For each queries[i], you need to:

// Trim each number in nums to its rightmost trimi digits.
// Determine the index of the kith smallest trimmed number in nums. If two trimmed numbers are equal, the number with the lower index is considered to be smaller.
// Reset each number in nums to its original length.
// Return an array answer of the same length as queries, where answer[i] is the answer to the ith query.

// Note:

// To trim to the rightmost x digits means to keep removing the leftmost digit, until only x digits remain.
// Strings in nums may contain leading zeros.
class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        //just simply solve as given
        vector<int>ans;
        int n=nums.size();
        for(auto q:queries)
        {
            int k=q[0];
            int trim=q[1];//it is from right side
            vector<pair<string,int>>arr;
            for(int i=0;i<n;i++)
            {
                // if(trim>nums.size())trim=0;
                arr.push_back({(nums[i].substr(nums[i].size()-trim)),i});
                
            }
            sort(arr.begin(),arr.end());
            ans.push_back(arr[k-1].second);
        }
        return ans;
        
    }
};
