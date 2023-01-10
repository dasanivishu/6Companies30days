// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return true if you can finish all courses. Otherwise, return false.
// we can use graph topological sort
//if cycle present in directed graph formed then false else true
//as topological sort is possible in DAG

class Solution {
public:
    bool dfs_cycle(int i,int n,vector<int>adj[],vector<int>&vis,vector<int>&recs)
    {
         vis[i]=1;
         recs[i]=1;
         for(auto it:adj[i])
         {
             if(!vis[it])//if not visited call dfs
             {
                 if(dfs_cycle(it,n,adj,vis,recs))
                 return true;
             }
             //if visited then check if element present in recursion stack
             //return true
             else if(recs[it])
             return true;

         }
         recs[i]=0;//out of recursion so mark recs[i] false
         return false;
         
    }
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        //if cycle present then no topological sort possible 
        //so no course scheduling possible
        int N=numCourses;
        vector<int>adj[N];//adjacency list
        for(int i=0;i<pre.size();i++)
        {
            int u=pre[i][0];
            int v=pre[i][1];
            adj[u].push_back(v);
        }
        vector<int>vis(N,0);
        vector<int>recs(N,0);//for directed graph we have to also maintain recursion stack
        for(int i=0;i<N;i++)
        {
            if(!vis[i])
            {
                if(dfs_cycle(i,N,adj,vis,recs))
                return false;
            }
        }
          return true;
    }
  
};
