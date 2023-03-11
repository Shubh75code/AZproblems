#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using lli =long long;
lli n, k;
map<lli, lli> mp;
bool check(lli y)
{
    lli usefullballs = 0;
    for (auto i : mp)
    {
        usefullballs += min(i.second, y);
    }
    if (usefullballs >= k * y)
        return true;
    else
        return false;
}
void solve()
{
    cin >> n >> k;
    for (lli i = 0; i < n; i++)
    {
        lli x;
        cin >> x;
        mp[x]++;
    }
    lli lo = 0;
    lli hi = n / k;
    lli ans = 0;
    while (hi >= lo)
    {
        lli mid = (lo + hi) / 2;
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
    mp.clear();
    cout << ans << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli t;
    cin >> t;
    while (t-- > 0)
    {
        solve();
    }
}