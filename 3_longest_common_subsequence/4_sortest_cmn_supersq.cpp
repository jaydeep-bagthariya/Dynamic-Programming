// SORTEST COMMON SUPER SEQUENCE

// Given two strings str1 and str2, the task is to find the length of the shortest string that has both 
// str1 and str2 as subsequences.

// Examples : 

// Input:   str1 = "geek",  str2 = "eke"
// Output: 5
// Explanation: 
// String "geeke" has both string "geek" 
// and "eke" as subsequences.

// Input:   str1 = "AGGTAB",  str2 = "GXTXAYB"
// Output:  9
// Explanation: 
// String "AGXGTXAYB" has both string 
// "AGGTAB" and "GXTXAYB" as subsequences.



#include<bits/stdc++.h>
using namespace std;
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
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    int n = s1.length();
    int m = s2.length();
    // tabulation method;
    int lcs = lcs2(s1,s2,n,m);
    cout <<  n+m-lcs;
    return 0;
}