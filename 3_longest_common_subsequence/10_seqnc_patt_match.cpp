// Sequence Pattern Matching

#include<bits/stdc++.h>
using namespace std;

bool LCS(string a, string b, int n, int m)
{
	int dp[n+1][m+1];
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++)
		{
			if(i==0 || j==0) dp[i][j] = 0;
			else if(a[i-1] == b[j-1])
				dp[i][j] = 1 + dp[i-1][j-1];
			else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
		}
	if(dp[n][m]==n) return true;
	return false;
}

int main() {
   string a = "axy"; //so we have to find subsequence of length of string a; 
   string b = "adxcpy";

   int n = a.size();
   int m = b.size();

   if(LCS(a,b,n,m)) cout << "True";
   else cout << "false";
}