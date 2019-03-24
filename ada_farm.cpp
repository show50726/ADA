#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#define ll long long

using namespace std;

ll x[1000010], y[1000010],sum[1000010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        scanf("%lld%lld", &x[i], &y[i]);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i==j) continue;
            ll xx = abs(x[j]-x[i]), yy = abs(y[j]-y[i]);
            ll k = 0;
            if(xx<yy){
                ll t = xx;
                xx = yy;
                yy = t;
            }
            if(yy<=xx){
                ll kk = xx-yy;
                if(xx<kk*2){
                    k += 2*yy;
                    xx -= 2*yy;
                    yy = 0;
                }
                else {
                    xx -= 2*kk;
                    yy -= kk;
                    k += 2*kk;
                }
                if(xx/3>=yy/3){
                    k += yy/3*4;
                    ll t = yy/3*3;
                    xx -= t;
                    yy -= t;
                }
                else{
                    k += xx/3*4;
                    ll t = xx/3*3;
                    xx -= t;
                    yy -= t;
                }

                while((xx>1||yy>1)&&xx!=0&&yy!=0){
                    if(xx>yy){
                        xx -= 2;
                        yy -= 1;
                        k += 2;
                    }
                    else{
                        xx -= 1;
                        yy -= 2;
                        k += 2;
                    }
                }
                if(xx==0){
                    k += yy;
                    yy = 0;
                }
                if(yy==0){
                    k += xx;
                    xx = 0;
                }
                if(xx>0) k = k+xx;
                if(yy>0) k = k+yy;

            }
            sum[i]+=k;
        }
    }

    for(int i = 1; i <= n; i++){
        printf("%lld\n",sum[i]);
    }
    return 0;
}
