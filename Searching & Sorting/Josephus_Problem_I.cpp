#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n; cin >> n;
    multiset<int> ms;
    for(int i=1;i<=n;i++){
        ms.insert(i);
    }
    bool flag = false;
    int step = 2;
    while(!ms.empty()){
        auto back = prev(ms.end());
        auto it = ms.begin();
        int last = *back;
        if(ms.size() == 1){
            cout << *it << " ";
            break;
        }
        if(flag){
            int value = *it;
            while(value <= n){
                cout << value << " ";
                ms.erase(value);
                if(value + step <= n){
                    value += step;
                    continue;
                }
                else{
                    step *= 2;
                    if(value == last){
                        flag = false;
                    }
                    else flag = true;
                    break;
                }
            }
        }
        else{
            int value = *(next(it));
            while(value<=n){
                cout << value << " ";
                ms.erase(value);
                if(value + step <= n){
                    value += step; continue;
                }
                else{
                    step*=2;
                    if(value == last){
                        flag = false;
                    }
                    else flag = true;
                    break;
                }
            }
        }
    }
}
