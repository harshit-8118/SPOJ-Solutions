//     ॐ  भगवन् सब आपको समर्पित  ॐ     //
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, c;
    cin>>n>>c;
    int arr[n];
    for(int i= 0; i < n; i++){
        cin>>arr[i];
    }
    sort(arr, arr + n);
    int i = 0, j = arr[n-1] - arr[0];
    int ans = 0, cpos, dist, k, cnt, index;
    while(i <= j){
        dist = (i + j)/2;
        cpos = arr[0];
        k = 0;
        cnt = 1;
        while(k < n){
            auto stall = lower_bound(arr + k, arr + n, cpos + dist);
            if(stall == arr + n){
                break;
            }
            cnt++;
            if(cnt >= c){
                break;
            }
            cpos = *stall;
            index = stall - arr;
            if(index == k){
                break;
            }
        }
        if(cnt >= c){
            ans = dist;
            i = dist + 1;
        }else j = dist - 1;
    }
    cout<<ans<<endl;
}

int32_t main(){

ios_base::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

int tt = 1;
cin>>tt;
while(tt--){
  solve();
}

return 0;
}