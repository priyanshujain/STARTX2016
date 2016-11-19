/*
Author - Priyanshu Jain
*/
//#include <atomic>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cassert>
using namespace std;

#define mod 1000000007
#define inf 100000000000000000LL
struct _{ios_base::Init i; _(){
  cin.sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
}}_ ;
typedef long long int  ll;
#define pll pair<ll,ll>
#define ict int t;cin>>t;while(t--)
#define rep(i,n) for(ll i=0;i<n;i++)
#define repi(i,a,b) for(ll i=a;i<=b;i++)
#define endl '\n'

const int N = 2001;

int m, n;
double dp[N][N];

int main() {

  std::ifstream in("small.in");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

    std::ofstream out("small.out");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

	for (int i = 1; i < N; i++) dp[i][0] = 1;
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < N; j++) {
			if (i > j) {
				double p1 = (double)i / (i + j);
				double p2 = 1 - p1;
				dp[i][j] = dp[i-1][j] * p1 + dp[i][j-1] * p2;
			}
		}
	}
	int t, tt;
	cin>>t;
	for (int tt = 1; tt <= t; tt++) {
		cin>>n>>m;
    std::cout.setf(std::ios::fixed, std::ios::floatfield);
    cout<<std::setprecision(6);
		cout<<dp[n][m]<<endl;
	}
	return 0;
}
