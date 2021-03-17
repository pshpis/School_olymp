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
#define fr(i, n) for (int (i)=0; i<int(n); i++)

typedef long long lint;

using namespace std;

template<typename type>

type next()
{type x;cin>>x;return x;}

int next()
{int x;cin>>x;return x;}

lint lnext()
{lint x;cin>>x;return x;}

void make_bracket(string& s, vector<int>& br){
    br.clear();
    for (int i=0; i<s.size(); i++){
        if (s[i]=='(') br.push_back(1);
        if (s[i]==')') br.push_back(-1);
        if (s[i]=='[') br.push_back(2);
        if (s[i]==']') br.push_back(-2);
        if (s[i]=='{') br.push_back(3);
        if (s[i]=='}') br.push_back(-3);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    string s;
    getline(cin, s);
    vector<int> br;
    make_bracket(s, br);
    vector<int> st;
    for (int i=0; i<br.size(); i++){
        if (br[i]>0){
            st.push_back(br[i]);
        }
        else{
            if (st.size()==0){
                cout<<"NO";
                return 0;
            }
            else
                if (st[st.size()-1]==abs(br[i])) st.pop_back();
                else{
                    cout<<"NO";
                    return 0;
                }
        }
    }
    if (st.size()>0){
        cout<<"NO";
        return 0;
    }
    cout<<"YES";
}

