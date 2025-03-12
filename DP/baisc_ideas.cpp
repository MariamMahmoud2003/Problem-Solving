#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
// DONE
int LCS(string & s, string & k){
    vector<vector<int>> dp(s.size() + 1, vector<int>(k.size() + 1, 0));
    for(int i=1;i<=s.size();++i)
        for(int j=1;j<=k.size();++j)
            if(s[i-1]==k[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    return dp[s.size()][k.size()];
}
//////////////////////////////////////////////////////////////////////////////
// DONE
int count_coins(vector<int> & v){
    vector<int>dp(v.size()+1,0);
    dp[1]=v[0];
    dp[2]=max(v[0],v[1]);
    for(int i=3;i<=v.size();++i){
        dp[i]=max(v[i-1]+dp[i-2],dp[i-1]);
    }
    return dp[v.size()];
}
//////////////////////////////////////////////////////////////////////////////
// DONE
int coin_collecting(vector<vector<char>>&v,int n, int m){
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<n+1;i++)
        for(int j=1;j<m+1;j++){
            if(v[i-1][j-1]!='*')
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            else
                dp[i][j]=max(dp[i-1][j]+1,dp[i][j-1]+1);
        }
    return dp[n][m];
}
//////////////////////////////////////////////////////////////////////////////
// DONE
int Knapsack(vector<int>& weight, vector<int>& values, int W, int n) {
    vector<vector<int>> dp(n+1,vector<int>(W+1,0));
    for(int i=1;i<n+1;++i)
        for(int j=1;j<W+1;j++){
            if(weight[i-1]<=j)
                dp[i][j]=max(dp[i-1][j],values[i-1]+dp[i-1][j-weight[i-1]]);
            else
                dp[i][j]=dp[i-1][j];
        }
    cout<<"-------------------------------\n";
    for(int i=0;i<n+1;++i) {
        for (int j = 0; j < W + 1; ++j)
            cout << dp[i][j] << ' ';
        cout << endl;
    }
    cout<<"-------------------------------\n";
    return dp[n][W];
}
//////////////////////////////////////////////////////////////////////////////
// DONE
int coin_change(vector<int>&coins,int amount){
    vector<int>dp(amount+1,INT_MAX);
    dp[0]=0;
    for(int i=1;i<amount+1;++i)
        for(int coin:coins)
            if(i>=coin && dp[i-coin]!=INT_MAX)
                dp[i]=min(dp[i],dp[i-coin]+1);

    return dp[amount]!=INT_MAX ? dp[amount]:-1;
}
//////////////////////////////////////////////////////////////////////////////
// DONE
int longest(vector<int>& v) {
    unsigned int n = v.size();
    if (n == 0)
        return 0;
    vector<int> dp(n, 1);  // Initialize DP array with 1 (each element can be a subsequence of length 1)
    // Nested loop: for each element v[k], find the largest increasing subsequence ending at v[k]
    for (int k = 1; k < n; ++k) {
        for (int i = 0; i < k; ++i) {
            // If v[k] can extend the subsequence ending at v[i]
            if (v[k] > v[i]) {
                dp[k] = max(dp[k], dp[i] + 1);  // Compare dp[k] and dp[i] + 1
            }
        }
    }
    // The longest increasing subsequence is the maximum value in dp
    return *max_element(dp.begin(), dp.end());
}
//////////////////////////////////////////////////////////////////////////////
// DONE
int number_of_possible_coin_exchange(int amount){
    vector<int>dp(amount+1,0);
    dp[0]=1;
    vector<int>coins={1,5,10,25,50};
    for(int coin:coins){
        for(int i=1;i<amount+1;i++){
            if(coin<=i)
                dp[i]+=dp[i-coin];
        }
    }
    return dp[amount];
}
//////////////////////////////////////////////////////////////////////////////
// DONE
string longest_substring_palindrome(string & s){
    vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
    for(int i=0;i<s.size();++i)// base case: means one chara. so it will be palindrome
        dp[i][i]=true;
    int count = 0;
    string result ;
    // (k = j - i)
    for(int k=1;k<s.size();++k) // gap between i & j
        // j = k + i if gap is 4 and i is 3 so j will be 7
        for(int i=0,j=k; j<s.size();++i,++j){ // begin of substring
            if (k==1) // 2 characters so check if they are equal ti each other
                dp[i][j]=(s[i]==s[j]);
            else // more than 2 chara, so we check last and first in substring then we check first item before last j-1
            // and first iem after first i+1
                dp[i][j]=(s[i]==s[j] && dp[i+1][j-1]);
            // get the longest palindrome tell now without updating if equal length
            if(dp[i][j] && count<k+1){
                result = s.substr(i,k+1);
                count = result.size();
            }
        }
    return result;
}
//////////////////////////////////////////////////////////////////////////////
// DONE
string longest_sub_palindrome_to_chara(string &s,string & z){
    vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
    for(int i=0;i<s.size();++i)// base case: means one chara. so it will be palindrome
        if(z.find(s[i])!=-1)
            dp[i][i]=true;
    int count = 0;
    string result="-1" ;
    // (k = j - i)
    for(int k=1;k<s.size();++k) // gap between i & j
        // j = k + i if gap is 4 and i is 3 so j will be 7
        for(int i=0,j=k; j<s.size();++i,++j){ // begin of substring
            if (k==1) // 2 characters so check if they are equal ti each other
                dp[i][j]=(s[i]==s[j] && z.find(s[i])!=-1);
            else // more than 2 chara, so we check last and first in substring then we check first item before last j-1
                // and first iem after first i+1
                dp[i][j]=(s[i]==s[j] && dp[i+1][j-1] && z.find(s[i])!=-1);
            // get the longest palindrome tell now without updating if equal length
            if(dp[i][j] && count<k+1){
                result = s.substr(i,k+1);
                count = result.size();
            }
        }
    return result;
}
//////////////////////////////////////////////////////////////////////////////
int minDifference(int m, vector<int>&coins){ // O(fair)
    // total sum for all coins,
    // fair division we need to get,
    // the best division we got near to fair
    int total = 0,fair,best_fair = 0;
    // calculate sum
    for(int coin : coins) // O(m)
        total += coin;
    fair = total / 2; // get fair that is the equal division
    // each index indicate possibility of sum
    vector<int> dp(fair + 1, 0);
    dp[0] = 1; // base case : nothing can be got
    // loop over every coin
    // (indicate what is the sum
    // (total value of coins one person can take not total number of coins)
    // achieved when we get this coin)
    for(int coin : coins) // O(m)
        // loop from number we need to get or get thing near to it
        // backward bec. we want each coin happen once
        for(int i = fair; i >= coin; --i) // O(coin-fair)
            // is the sum achievable before considering current coin
            // or the i-coin is achieved before current coin (adding current coin)
            dp[i] = dp[i] || dp[i - coin];
    // find nearest achieved sum near to fair ,so we will begin from fair
    for(int i = fair;i >= 0; --i) // O(fair+1)
        if(dp[i]) {
            best_fair = i;
            break;
        }
    // one person got best_fair so the other one got total - best_fair
    return abs(best_fair - (total - best_fair));
}
//////////////////////////////////////////////////////////////////////////////
// DONE
int min_coins(vector<int>&coins, int target){
    vector<int>dp(target+1,INT_MAX);
    dp[0]=0;
    for(int coin:coins)
        for(int i=1;i<=target;++i)
            if(i>=coin && dp[i-coin]!=INT_MAX)
                dp[i]=min(dp[i],dp[i-coin]+1);
    return dp[target]!=INT_MAX ? dp[target]:-1;
}
//////////////////////////////////////////////////////////////////////////////
// DONE
int binomial_coefficient(int n, int k){
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;++i)
        for(int j=0;j<=n;++j)
            // base case : we have only 1 chance to get 0 item from n or get n item from n
            if(i==j || j==0)
                dp[i][j]=1;
            else
                // we can include n item and get k-1 item from n-1 items or exclude n item and get k-1 item from n-1 items
                dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
    return dp[n][k];
}
//////////////////////////////////////////////////////////////////////////////
// DONE
int min_cost_Tickets(vector<int>& days, vector<int>& costs) {
    // all days till last one
    vector<int>dp(days.back()+1);
    // if no days no cost
    dp[0]=0;
    for(int i=1;i<dp.size();++i){
        // for every day in days check if 1day ticket or 7day ticket or 30day ticket will be better
        if(std::find(days.begin(),days.end(),i)!=days.end()){
            dp[i]=dp[i-1]+costs[0];
            dp[i]=min(dp[i],(dp[max(0,i-7)]+costs[1]));
            dp[i]=min(dp[i],(dp[max(0,i-30)]+costs[2]));
        }
        // if not in days make its value the value before it
        else{
            dp[i]=dp[i-1];
        }
    }
    return dp.back();
}
//////////////////////////////////////////////////////////////////////////////
// DONE
vector<int> countBits(int n) {
    vector<int>dp(n+1,0);
    dp[1]=1;
    int master=2;
    for(int i=2;i<=n;++i){
        if(i==master*2){
            dp[i]=1;
            master=i;
        }
        else{
            dp[i]=dp[i-master]+1;
        }
    }
    return dp;
}
int main() {
    string s="algorithm",k="alignment";
    cout<<LCS(s,k)<<'\n';
    vector<int> v = {5,1,2,10,6,2};
    cout<<count_coins(v)<<'\n';
    vector<vector<char>>v1={{'.','.','.','*'},
                            {'.','*','*','*'},
                            {'.','*','.','*'},
                            {'.','.','*','*'}};
    cout<<coin_collecting(v1,4,4)<<'\n';
    vector<int>weight={3,4,5,6},values={2,3,1,4};
    cout<<Knapsack(weight,values,8,4)<<'\n';
    vector<int>coins={1,5,12,25};
    cout<<coin_change(coins,16)<<'\n';
    vector<int>v2={/*7,5,1,2,3,6,4,5,9*/10,1,3,7,13,11,2,4};
    cout<<longest(v2)<<'\n';
    cout<<number_of_possible_coin_exchange(11)<<'\n';
    string t ="abccba";
    cout<<longest_substring_palindrome(t)<<'\n';
    string l = "lkd";
    cout<<longest_sub_palindrome_to_chara(t,l)<<'\n';
    vector<int>coins_={1,5,7};
    cout<<min_coins(coins_,11)<<'\n';
    cout<<binomial_coefficient(5,2)<<'\n';
    return 0;
}
