#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        ll k, ans = 0;
        cin >> n >> k;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        sort(a.begin() + 1, a.end());
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            int j = i;
            while (j <= n && a[j] == a[i] + j - i) {
                j++;
            }
            int len = j - i;
            if (len > 0) {
                cnt++;
                ans += k * a[i];
                if (len > 1) {
                    ans += k * (len - 1) * (len - 2) / 2;
                }
                i = j - 1;
            }
        }
        if (cnt == 0) {
            ans = k * a[n];
        }
        cout << ans << '\n';
    }
    return 0;
}
