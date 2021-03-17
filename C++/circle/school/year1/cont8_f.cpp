#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <iterator>

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

int main()
{
    ios::sync_with_stdio(false);
    int n=next(), q=next();
    vector<set<int> >apps(n);
    set<pair<int, int>> notes;
    vector<bool> mark;
    int not_read=0;
    int first=0;
    for (int i=0; i<q; i++)
    {
        int type=next();
        int num=next()-1;
        if (type==1)
        {
            not_read++;
            apps[num].insert(first);
            notes.emplace(first, num);
            first++;
            mark.pb(false);
        }
        if (type==2)
        {
            for (auto nt:apps[num])
            {
                if (!mark[nt]) not_read--;
                mark[nt]=true;
            }
            apps[num].clear();
        }
        if (type==3)
        {
            while(!notes.empty() && num>=(*notes.begin()).first)
            {
                /*cout<<"I was here"<<endl;
                watch((*notes.begin()).first);
                watch(mark.size());
                watch(num);
                watch(apps.size());*/
                if (!mark[(*notes.begin()).first])
                {
                    //cout<<"I was there"<<endl;
                    set<int> ::iterator it=apps[(*notes.begin()).second].begin();
                    //cout<<"I was there"<<endl;
                    apps[num].erase((*notes.begin()).second);
                    //cout<<"I was there"<<endl;
                    not_read--;
                    //cout<<"I was there"<<endl;
                }
                //cout<<"I was there"<<endl;
                mark[(*notes.begin()).first]=true;
                set<pair<int, int> > ::iterator it1=notes.begin();
                notes.erase(*it1);
            }
        }
        cout<<not_read<<"\n";
    }
}

