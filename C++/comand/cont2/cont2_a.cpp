#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define pw2(x) ((x)*(x))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))

void make_str(int n, string& s){
    s.clear();
    while (n>0){
        s+=n%10+'0';
        n/=10;
    }
    reverse(s.begin(), s.end());
}

int make_int(string& s){
    int ans=0;
    for (int i=0; i<s.size(); i++){
        ans*=10;
        ans+=s[i]-'0';
    }
    return ans;
}

int main(){
    int n, k;
    cin>>n>>k;
    string s1, s2;
    make_str(n, s1);
    make_str(k, s2);

//    watch(s1);
//    watch(s2);
//    watch(make_int(s1));
//    watch(make_int(s2));

    if (s1.size()==s2.size()){
        cout<<n-k;
        return 0;
    }
    string new_s1="";
    int ans=0;
    ans+=s1.size()-s2.size();
    for (int i=0; i<s2.size(); i++)
        new_s1+=s1[i];
    if (new_s1>=s2){
        cout<<ans+make_int(new_s1)-make_int(s2);
        return 0;
    }
    new_s1+=s1[s2.size()];
    ans--;
    cout<<ans+make_int(new_s1)-make_int(s2);
}

