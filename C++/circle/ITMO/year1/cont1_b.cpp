#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb(x) push_back(x)
#define pow2(x) ((x)*(x))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))

typedef long long lint;

using namespace std;

int next()
{int x;cin>>x;return x;}

lint lnext()
{lint x;cin>>x;return x;}

vector<vector<int>> gr;
vector<bool> was;
vector<int> time_in;
vector<int> time_out;
vector<int> p;
bool cycle=false;
int st_cycle=-1, end_cycle=-1;
int time;

void dfs(int st)
{
    was[st]=true;
    time++;
    time_in[st]=time;
    for (int a:gr[st])
    {
        if(was[a])
        {
            if (time_in[a]>=0 && time_out[a]==-1)
            {
                cycle=true;
                st_cycle=a;
                end_cycle=st;
                return;
            }
        }
        else
        {
            p[a]=st;
            dfs(a);
        }
    }
    time++;
    time_out[st]=time;
}

int main()
{
    freopen("cycle2.in", "r", stdin);
	freopen("cycle2.out", "w", stdout);
    int n=next(), m=next();
    gr=vector<vector<int> >(n);
    was=vector<bool>(n, false);
    time_in=vector<int>(n, -1);
    time_out=vector<int>(n, -1);
    p=vector<int>(n, -1);
    time=0;

    for (int i=0; i<n; i++)
    {
        int x=next()-1, y=next()-1;
        gr[x].pb(y);
    }

    for (int i=0; i<n; i++)
    {
        if (!was[i])
        {
            dfs(i);
            if (cycle)
            {
                cout<<"YES\n";
                while(end_cycle!=st_cycle)
                {
                    cout<<end_cycle+1<<" ";
                    end_cycle=p[end_cycle];
                }
                cout<<st_cycle+1;
                return 0;
            }
        }
    }
    cout<<"NO\n";
}
/*
2 2
2 1
1 2
*/
