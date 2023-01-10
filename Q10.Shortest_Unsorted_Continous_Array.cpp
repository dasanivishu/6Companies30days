// Question:Given an integer array nums, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.

// Return the shortest such subarray and output its length.
// Link->https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
class Solution {
public:
//in sorted array ith index element is max element from left side 
//and min element from right side
    int findUnsortedSubarray(vector<int>& nums) {
        int N=nums.size();
        int n=N;
        int start=0,end=n-1;
        int minx=INT_MAX;
        int change=0;
        //as while going from right to left
        //sorted arrayb goes in decreasing order so last point which will increase
        //will be the start point 
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]>minx)
            {
               start=i;
               change++;
            }
            
            minx=min(minx,nums[i]);
        }
        int maxx=INT_MIN;
        //as while going from left to right 
        //sorted arrayb goes in increasing order so last point which will decrease
        //will be the end point 
        for(int i=0;i<n;i++)
        {
            if(nums[i]<maxx)
            {
               change++;
               end=i;
            }
           
            maxx=max(maxx,nums[i]);
        }
        if(change==0)//no change while choosing end and start point 
        // that means whole array is sorted
        return 0;
        return end-start+1;
        
    }
};
// Time -O(N)
// Space-O(1)
