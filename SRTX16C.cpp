#include<algorithm>
#include<iostream>
#include<fstream>

#include<cmath>

using namespace std;

int main()
{
  std::ifstream in("in.txt");
  std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
  std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

  std::ofstream out("out.txt");
  std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
  std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!
  int test,n;
  cin>>test;
  while(test--)
  {
    cin>>n;
    int a[n+3];
    for(int i=0;i<n;i++)cin>>a[i];
    a[n] = a[n+1] = a[n+2] = 1;
    int oneStreak = 0, current = 0, jumps = 0;
    bool flag = true;
    while(current != n-1)
    {
        if(a[current + 3] == 0)
        {
            current += 3;
            jumps++;
        }
        else if(a[current + 2] == 0)
        {
          current += 2;
          jumps++;
        }
        else if(a[current + 1] == 0)
        {
          current += 1;
          jumps++;
        }
        else
        {
          flag = false;
          break;
        }
      }
      if(flag)
        cout<<jumps<<"\n";
      else
        cout<<"Never Give Up\n";
    }
  }
