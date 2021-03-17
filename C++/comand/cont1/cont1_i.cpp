#include <bits/stdc++.h>

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb(x) push_back(x)
#define pow2(x) ((x)*(x))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define fr(i, n) for(int i = 0; i < int(n); ++i)

//#define DBG_in
//#define DBG_out

typedef long long lint;

const int INF=2e9;
const lint INF64=1e18;
const double PI=3.14159265359;
const double EPS=1e-9;
const int MOD=1e9+7;

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
    cin.tie(0);
    cout.tie(0);

    #ifdef DBG_in
        freopen("in.txt", "r", stdin);
    #endif // DEBAG_in
    #ifdef DBG_out
        freopen("out.txt", "w", stdout);
    #endif // DEBAG_out

    unordered_map<string, int> num;
    unordered_set<string> p;
    vector<string> s;

    int n=next();

    for(int i=0; i<n; i++){
        string x=next<string>();
        num[x]=i;
        p.insert(x);
        s.pb(x);
    }

    for (int it=0; it<n; it++){
        for (int l=1; l<s[it].size(); l++){
            int L=s[it].size();
            if ((L+l)%2==1) continue;
            bool fl=true;
            string search_s="";
            for (int i=0, j=(L+l)/2; i<(L-l)/2; i++, j++){
                if (s[it][i]!=s[it][j]){
                    fl=false;
                    break;
                }
            }
            if (fl){
                for (int i=(L-l)/2; i<(L+l)/2; i++){
                    search_s+=s[it][i];
                }
                if (p.count(search_s)>0){
//                    watch(search_s);
//                    watch(s[it]);
//                    watch(l);
//                    watch(L);
                    cout<<"YES\n"<<it+1<<" "<<num[search_s]+1;
                    return 0;
                }
            }



            reverse(s[it].begin(), s[it].end());
            fl=true;
            search_s="";
            for (int i=0, j=(L+l)/2; i<(L-l)/2; i++, j++){
                if (s[it][i]!=s[it][j]){
                    fl=false;
                    break;
                }
            }
            if (fl){
                for (int i=(L-l)/2; i<(L+l)/2; i++){
                    search_s+=s[it][i];
                }
                reverse(search_s.begin(), search_s.end());
                if (p.count(search_s)>0){
//                    watch(search_s);
//                    watch(s[it]);
//                    watch(l);
//                    watch(L);
                    cout<<"YES\n"<<num[search_s]+1<<" "<<it+1;
                    return 0;
                }
            }
            reverse(s[it].begin(), s[it].end());
        }
    }


    cout<<"NO\n";




}
