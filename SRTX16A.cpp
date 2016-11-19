/*
Author - Priyanshu Jain
*/
//#include <atomic>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cassert>
using namespace std;
#define REP(i,n) for (int i = 1; i <= n; i++)
typedef long long ll;

int main() {
    std::ifstream in("in.txt");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

    std::ofstream out("out.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!
  int t;
  cin>>t;
  for (size_t i = 0; i < t; i++) {
    int N,M;
    cin>>N>>M;
    cout<<N%M<<endl;
  }
  return 0;
}
