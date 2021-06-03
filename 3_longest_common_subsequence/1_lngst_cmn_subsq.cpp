//longest common subsquence

#include<bits/stdc++.h>
using namespace std;
int dp[10000][10000];

int lcs(string s1, string s2, int n, int m)
{
    if(n==0 || m==0) return 0;
    if(dp[n][m]!=-1) return dp[n][m];
    if(s1[n-1] == s2[m-1])
        return dp[n][m]=1+lcs(s1,s2,n-1,m-1);
    return dp[n][m]=max(lcs(s1,s2,n,m-1),lcs(s1,s2,n-1,m));
}
int lcs2(string s1, string s2, int n, int m)
{
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0) dp[i][j] = 0;
            else if(s1[i-1]==s2[j-1]) 
                dp[i][j] = 1+dp[i-1][j-1];
            else dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
        }
    return dp[n][m];
}
int main()
{
    memset(dp,-1,sizeof dp);
    string s1 = "abcdgh";
    string s2 = "abedfhr";
    int n = s1.length();
    int m = s2.length();
    cout << lcs(s1,s2,n,m) << endl;

    // tabulation method;
    cout << lcs2(s1,s2,n,m);
    
    return 0;
}