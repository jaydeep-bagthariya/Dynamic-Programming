//PRINT LONGEST COMMON SUBSEQUENCE IN TWO STRING

#include<bits/stdc++.h>
using namespace std;

string printlcs(string s1, string s2, int n, int m)
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
    int i=n, j=m;
    string res = "";
    while(i>0 && j>0)
    {
        if(s1[i-1]==s2[j-1])
        {
            res += s1[i-1];
            i--,j--;
        }
        else{
            if(dp[i][j-1]>dp[i-1][j]) j--;
            else i--;
        }
    }
    reverse(res.begin(),res.end());
    return res;
}
int main()
{

    string s1 = "abcdgh";
    string s2 = "abedfhr";
    int n = s1.length();
    int m = s2.length();

    // tabulation method;
    cout << printlcs(s1,s2,n,m);
    
    return 0;
}