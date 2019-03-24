#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long

using namespace std;

ll v[50], w[50];
pair<ll, ll> p[1<<(25)];

void solve(int n, ll wk) {
    int n2 = n/2;
    for(int i = 0; i < (1<<n2); i++){
        ll ww = 0, vv = 0;
        for(int j = 0; j <n2; j++){
            if((i>>j)&1){
                ww+=w[j];
                vv+=v[j];
            }
        }
        p[i] = make_pair(ww, vv);
    }

    sort(p, p+(1<<n2));
    int m = 1;
    for(int i = 1; i < (1<<n2); i++){
        if(p[m-1].second<p[i].second){
            p[m++] = p[i];
        }
    }

    ll ans = 0;
    for(int i = 0; i < (1<<n-n2); i++){
        ll ww = 0, vv = 0;
        for(int j = 0; j < n-n2; j++){
            if((i>>j)&1){
                ww+=w[n2+j];
                vv+=v[n2+j];
            }
        }
        if(ww<=wk){
            ll vvv = (lower_bound(p, p+m, make_pair(wk-ww, 1LL<<62))-1)->second;
            ans = max(ans, vv+vvv);
        }
    }
    printf("%lld\n", ans);

}

int main() {
    int n;
    ll wk;
    scanf("%d %lld", &n, &wk);
    //printf("%d\n", n);
    for(int i = 0; i < n; i++){
        scanf("%lld%lld", &v[i], &w[i]);
    }
    solve(n, wk);
    return 0;
}
