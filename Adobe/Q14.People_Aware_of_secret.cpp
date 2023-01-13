class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        long long int mod=1e9+7;
        vector<long long int>dp(n,0);
       dp[0]=1;
       long long int no_of_people_sharing=0;
       for(int i=1;i<n;i++)
       {
           int a=i-delay;
           int b=i-forget;
           
           if(a>=0)
           no_of_people_sharing= (no_of_people_sharing+dp[a]);
           if(b>=0)
           no_of_people_sharing= (no_of_people_sharing-dp[b]);
           dp[i]=no_of_people_sharing%mod;
       }
       int secret=0;
       for(int i=n-forget;i<n;i++)
       secret=(secret+dp[i])%mod;
       return secret;
       
    }
    
};
 // // dp[i]->no of new people sharing the secret on ith day
        // i->i+delay(Acting as a spraeder)
        // i->i-forget(Forgetting the secret)
        // no of new people sharing secret on ith day->dp[i-delay]
        // no of people forgetting the secret on same day ith->dp[i-forget]
        // no of people sharing secret+=no of new people sharing secret-no of people forgetting secret
        // dp[i]=dp[i-1]+dp[i-delay]-dp[i-forget];
