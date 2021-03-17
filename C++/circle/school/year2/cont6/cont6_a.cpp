#include <bits/stdc++.h>

using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define pw2(x) ((x)*(x))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define fr(i, n) for(int i = 0; i < int(n); ++i)

#define int int64_t

//#define FIlE_in
//#define FILE_out

#ifdef FIlE_in
    char file_in[]="C:\\Users\\pshpi\\OneDrive\\Desktop\\in.txt";
#endif // FIlE_in
#ifdef FILE_out
    char file_out[]="C:\\Users\\pshpi\\OneDrive\\Desktop\\out.txt";
#endif // FILE_out

typedef long long ll;

const int INF=2e9;
const ll INF64=1e18;
const double PI=3.14159265359;
const double EPS=1e-9;
const int MOD=1e9+7;

template<typename type>

type next()
{type x;cin>>x;return x;}

int next()
{int x;cin>>x;return x;}

ll lnext()
{ll x;cin>>x;return x;}

string make_2num(int n){
    string ans="";
    while (n>0){
        ans+='0'+n%2;
        n/=2;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int make_10num(string s){
    int ans=0;
    int k=1;
    for (int i=0; i<s.size(); i++){
        ans*=2;
        ans+=s[i]-'0';
    }
    return ans;
}

void test()
{
    int a=next(), b=next(), n=next();
    if (n==0){
        cout<<a<<"\n";
        return;
    }
    if (n==1){
        cout<<b<<"\n";
        return;
    }
    n-=1;
//    cout<<make_2num(next())<<endl;
    string s=make_2num(a), s_=make_2num(b);
    if (s.size()>s_.size()){
        int k=s.size()-s_.size();
        string fake="";
        for (int i=0; i<k; i++) fake+='0';
        fake+=s_;
        s_=fake;
    }
    if (s_.size()>s.size()){
        int k=s_.size()-s.size();
        string fake="";
        for (int i=0; i<k; i++) fake+='0';
        fake+=s;
        s=fake;
    }
    string ans="";
    for (int i=0; i<s.size(); i++){
        if (s[i]=='1' && s_[i]=='0'){
            ans+='1'-(n%3==0);
        } else
        if (s[i]=='0' && s_[i]=='1'){
            ans+='1'-(n%3==2);
        } else
        if (s[i]=='0' && s_[i]=='0'){
            ans+='0';
        } else
        if (s[i]=='1' && s_[i]=='1'){
            ans+='1'-(n%3==1);
        }
    }
    cout<<make_10num(ans)<<"\n";
    return;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    #ifdef FIlE_in
        freopen(file_in, "r", stdin);
    #endif // FIlE_in
    #ifdef FILE_out
        freopen(file_out, "w", stdout);
    #endif // FILE_out

    int t=next();
    for (int i=0; i<t; i++)
        test();
//    cout<<make_10num("1001");

}

