#include <iostream>

using namespace std;

#define N 5

int main(){
    int a[N];
    int i, k, max, max2;
    for (i = 0; i < N; i ++) cin >> a[i];
    max = std::max(a[0], a[1]);
    max2 = std::min(a[0], a[1]);
    for (i = 2; i < N; i ++){
        if (a[i] <= max2) continue;
        if (a[i] >= max1){
            max2 = max1;
            max1 = a[i];
        }
        else {
            max2 = a[i];
        }
    }
    cout << max2;
}
