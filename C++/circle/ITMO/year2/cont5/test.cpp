#include <bits/stdc++.h>

using namespace std;

int main(){
    int v = 64;
    v--;
    v |= v >> 1;
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;
    v++;
    cout << v;
}
