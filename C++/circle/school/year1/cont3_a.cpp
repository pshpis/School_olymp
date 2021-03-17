#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

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
    int n=next(), sum=0;
    multiset<int> num;
    vector<int> nums;
    for(int i=0; i<n; i++)
    {
        int x=next();
        //watch(x);
        //watch(i);
        num.insert(x);
        nums.pb(x);
    }
    //watch(num.size());
    vector<int> ans1, ans2;
    int k=0;
    for (int a:num)
    {
        if (k<n/2) ans1.pb(a);
        else ans2.pb(a);
        k++;
    }
    //watch(num.size());
    //watch(ans2.size());
    //cout<<"Yes"<<endl;
    //reverse(ans2.begin(), ans2.end());
    vector<int> ans3;
    for (int i=ans2.size()-1; i>=0; i--)
        ans3.pb(ans2[i]);
    ans2=ans3;
    //cout<<"Yes"<<endl;
    //cout<<ans2.size()<<" "<<ans1.size()<<endl;
    /*for (int i=0; i<n/2; i++)
    {
        cout<<ans1[i]<<" "<<ans2[i]<<"\n";
    }*/
    //cout<<"Yes"<<endl;
    vector<bool> used(n, false);
    for (int i=0; i<n/2; i++)
    {
        int x=-1;
        for (int j=0; j<n; j++)
            if (ans1[i]==nums[j] && num.count(nums[j])>0 && !used[j])
            {
                x=j;
                auto it=num.find(nums[j]);
                num.erase(it);
                used[j]=true;
                break;
            }

        int y=-1;
        for (int j=0; j<n; j++)
            if (ans2[i]==nums[j] && num.count(nums[j])>0 && !used[j])
            {
                y=j;
                auto it=num.find(nums[j]);
                num.erase(it);
                used[j]=true;
                break;
            }
            cout<<x+1<<" "<<y+1<<"\n";
    }
}

