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

vector<vector<int> > child;
vector<int> p;
vector<int> time_in;
vector<int> time_out;
int last_time;

void dfs(int st)
{
	for (int a: child[st])
    {
        last_time++;
        time_in[a]=last_time;
        dfs(a);
        last_time++;
        time_out[a]=last_time;
    }
}


int main()
{
    ios::sync_with_stdio(false);
    freopen("ancestor.in", "r", stdin);
	freopen("ancestor.out", "w", stdout);
	int n=next();
    int st;
    p=vector<int>(n);
    child=vector<vector<int> >(n);
    for (int i=0; i<n; i++)
    {
        int x=next()-1;
        p[i]=x;
        if (x<0) st=i;
        else child[x].pb(i);
    }
    time_out=vector<int>(n);
    time_in=vector<int>(n);
    time_in[st]=0;
    last_time=0;
    dfs(st);
    time_out[st]=last_time+1;
    int m=next();
    /*for (int i=0; i<n; i++)
    {
        cout<<time_in[i]<<" "<<time_out[i]<<endl;
    }
    cout<<endl;*/
    for (int i=0; i<m; i++)
    {
        int x=next()-1, y=next()-1;
        if (time_in[x]<time_in[y] && time_out[x]>time_out[y]) cout<<1<<"\n";
        else cout<<0<<"\n";
    }
}

