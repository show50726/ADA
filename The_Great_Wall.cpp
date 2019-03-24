#include<cstdio>
#include<algorithm>
#include<iostream>
#include<queue>
#include<cstddef>
#include<stack>
#define ll long long

using namespace std;

typedef struct Node {ll l, r;}node;

stack<node> s;
int main(){
    int n;
    ll ans = 0;
    node k;

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%lld %lld", &k.l, &k.r);
        if(i==0){
            s.push(k);
            ans = (k.r-k.l)*(k.r-k.l);
        }
        else{
            while(!s.empty()&&s.top().r>=k.l){
                k.l = min(k.l, s.top().l);
                ans-=(s.top().r-s.top().l)*(s.top().r-s.top().l);
                s.pop();
            }
            ans+=(k.r-k.l)*(k.r-k.l);
            s.push(k);
        }
        printf("%lld\n", ans);
    }

    return 0;
}
