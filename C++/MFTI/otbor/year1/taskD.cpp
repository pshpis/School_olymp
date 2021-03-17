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
#define fr(i,n) for (int i=0; i<int(n); i++)

typedef long long lint;

using namespace std;

template<typename type>

type next()
{type x;cin>>x;return x;}

int next()
{int x;cin>>x;return x;}

lint lnext()
{lint x;cin>>x;return x;}

int main()
{
    ios::sync_with_stdio(false);
    string team;
    cin>>team;
    int k=next();
    string need;
    cin>>need;
    map<char, int> player;
    map<char, int> squad;
    for (int i=0; i<team.size();)
    {
        char pl=team[i];
        if (!(pl>='A' && pl<='Z')) break;
        int num=0;
        if (i==team.size()-1)
        {
            player[pl]+=1;
            //cout<<pl<<" "<<player[pl]<<endl;
            break;
        }
        int j=i+1;
        bool fl=false;
        while (team[j]>='0' && team[j]<='9')
        {
            fl=true;
            num*=10;
            num+=team[j]-'0';
            if (j==team.size()-1)
            {
                j++;
                break;
            }
            j++;
        }
        if (!fl) num=1;
        player[pl]+=num;
        i=j;
        //cout<<pl<<" "<<player[pl]<<endl;
    }
    for (char x='A'; x<='Z'; x++)
        player[x]*=k;
    for (int i=0; i<=need.size();)
    {
        char x=need[i];
        if (!(x>='A' && x<='Z')) break;
        int num=0;
        if (i==need.size()-1)
        {
            squad[x]+=1;
            //cout<<x<<" "<<squad[x]<<endl;
            break;
        }
        int j=i+1;
        bool fl=false;
        while (need[j]>='0' && need[j]<='9')
        {
            fl=true;
            num*=10;
            num+=need[j]-'0';
            j++;
            if (j==need.size()-1)
                break;
        }
        if (!fl) num=1;
        squad[x]+=num;
        i=j;
        //cout<<x<<" "<<squad[x]<<endl;
    }
    int ans=1e9+7;
    for (auto x: squad)
    {
        char pl=x.first;
        int k1=x.second;
        if (player[pl]<k1)
        {
            cout<<0;
            return 0;
        }
        ans=min(ans, player[pl]/k1);
    }
    if (ans==1e9+7) ans=0;
    cout<<ans;
}

