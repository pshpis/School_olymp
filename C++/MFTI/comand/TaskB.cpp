#include <iostream>
using namespace std;
int main(){
    int x;
    cin >> x;
    int xl[];
    int answer[];
    int c[10];
    for (int i=0;i<10:i++){
        cin >>c[i];
    }
    int i=0;
    while (c[x[i]]>=1){
        answer[i]=x[i];
    c[x[i]]--;
    }
    if (answer!=x){
            while (true){
                int j=x[i];
                while(c[j]<x[i]){
                    j++;
                }
                if (c[j]>=x[i]){
                    answer[i]=c[j];
                    c[j]--;
                    i++;
                    break;
                }
                else{
                    i--;
                    c[answer[i]]++;
                }
            }
            while (i<x.size()){
                int j=9;
                while(c[j]==0){
                    j--;
                }
                answer[i]=j;
                c[j]--;
            }

    }
    for (auto i:answer){
        cout << i;
    }

return 0;
}
