#include <bits/stdc++.h>
using namespace std;
#define endl '\n' 
int arr[100010];int n, k;
bool check(int y)
{
    int students=1;
    int occupiedseat =0;
    for(int i=1;i<n;i++)
    {
        if(arr[i]-arr[occupiedseat]>=y){
            students++;
            occupiedseat=i;
        }
        if(students>k)return true;
    }if(students>=k) return true;
    else{
        return false;
    }
}
void solve()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }sort(arr,arr+n);
    int lo = 0;
    int hi = 1e9;
    int ans = 0;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (check(mid))
        {
            ans = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    cout << ans << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        solve();
    }
}