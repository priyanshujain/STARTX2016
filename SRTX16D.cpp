/*
** Author - Rishabh Gupta (easy_)
*/
#include<iostream>
#define MAX 105
#define ll int
using namespace std;
ll n, m, xe, ye, xi, yi, xw, yw;
bool cave[MAX][MAX];
void flood(ll matrix[MAX][MAX], ll x, ll y, ll xe, ll ye, ll n)
{
    if(!cave[x][y]) //if it's a wall
        return;
    if(matrix[x][y] == 0 || matrix[x][y] > n)
    {
        matrix[x][y] = n;
        if(x == xe && y == ye)
        {
            return;
            //no need to flood more
        }
        else
        {
            n++;
            flood(matrix, x+1, y, xe, ye, n);
            flood(matrix, x-1, y, xe, ye, n);
            flood(matrix, x, y+1, xe, ye, n);
            flood(matrix, x, y-1, xe, ye, n);
        }
    }
}
ll floodWater()
{
    ll mat[MAX][MAX] = {0};

    flood(mat, xw, yw, xe, ye, 1);
    /*
    cout<<"WATER FLOODED\n";
    for(int i = 0; i < n+2; i++)
    {
        for(int j = 0; j < m+2; j++)
        {
            if(mat[i][j] == -1)
                cout<<"x ";
            else
                cout<<mat[i][j]<<" ";
        }
        cout<<"\n";
    }*/
    return mat[xe][ye];
}
ll runSam()
{
    ll mat[MAX][MAX] = {0};

    flood(mat, xi, yi, xe, ye, 1);
    /*
    cout<<"SAM FLOODED\n";
    for(int i = 0; i < n+2; i++)
    {
        for(int j = 0; j < m+2; j++)
        {
            if(mat[i][j] == -1)
                cout<<"x ";
            else
                cout<<mat[i][j]<<" ";
        }
        cout<<"\n";
    }*/
    return mat[xe][ye];
}
int main()
{
    ll cases;
    char c;
    cin>>cases;
    while(cases--)
    {
        cin>>n>>m>>xe>>ye>>xi>>yi>>xw>>yw;
        for(ll i = 1; i <= n ; i++)
        {
            for(ll j = 1; j <= m; j++)
            {
                cin>>c;
                //true if path, false if wall
                if(c == '0')
                    cave[i][j] = true;
                else
                    cave[i][j] = false;
            }
        }
        for(ll i = 0; i < n+2; i++)
        {
            cave[i][0] = false;
            cave[i][m+1] = false;
        }
        for(ll i = 0; i < m+2; i++)
        {
            cave[0][i] = false;
            cave[n+1][i] = false;
        }
        /*
        cout<<"CAVE\n";
        for(ll i = 0; i <= n+1 ; i++)
        {
            for(ll j = 0; j <= m+1; j++)
            {
                cout<<(cave[i][j]?"_":"x")<<" ";
            }
            cout<<endl;
        }*/
        ll w = floodWater();
        ll s = runSam();
        if(s <= w || w == 0)
            cout<<s-1<<"\n";
        else
            cout<<"-1\n";
    }
    return 0;
}
