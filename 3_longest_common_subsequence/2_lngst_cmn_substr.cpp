// LONGEST COMMON SUBSTRING


#include<bits/stdc++.h>
using namespace std;


int lcs(string s1, string s2, int n, int m)
{
    int dp[n+1][m+1];
    int ans = 0;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0) dp[i][j] = 0;
            else if(s1[i-1]==s2[j-1]) 
            {
                dp[i][j] = 1+dp[i-1][j-1];
                ans = max(ans,dp[i][j]);  // we need to find max in entire dp matrix
            }
            else dp[i][j] = 0;
        }
    return ans;
}

int main()
{
    string s1 = "abcdgh";
    string s2 = "abedfhr";
    int n = s1.length();
    int m = s2.length();
    cout << lcs(s1,s2,n,m) << endl;

    // tabulation method;
    // cout << lcs2(s1,s2,n,m);
    
    return 0;
}