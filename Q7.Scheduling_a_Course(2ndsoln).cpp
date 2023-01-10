class Solution {
public:
//we can use topo sort using bfs ,we cannot use topo dfs as we don,t know it
//is DAG or not
//if topo.size()==N return true;
    bool canFinish(int N, vector<vector<int>>& pre) {
        vector<int>adj[N],topo;
        for(int i=0;i<pre.size();i++)
        {
            adj[pre[i][0]].push_back(pre[i][1]);
        }
        vector<int>indegree(N,0);
        for(int i=0;i<N;i++)
        {
            for(auto it:adj[i])
            indegree[it]++;
        }
        queue<int>q;
        for(int i=0;i<N;i++)
        {
            if(indegree[i]==0)
            q.push(i);
        }
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node])//as node is in topo sort we can reduce 
            //indegree of adjacent nodes
            {
                indegree[it]--;
                if(indegree[it]==0)
                q.push(it);
            }
        }
        if(topo.size()==N)
        return true;
        return false;
    }
};
