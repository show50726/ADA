#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<queue>
#include<cstddef>
#include<stack>
#include<cstring>
#define ll long long

using namespace std;

typedef struct Node {int a; int b;int p; int c;}node;
int n, p[2000], ans1 = 0, ans2 = 0;
bool operator<(node n1, node n2) {
    if(n1.c==n2.c) return n1.p>n2.p;
    return n1.c<n2.c;
}
node a[2000*2000];

int init(){
    for(int i = 0; i <= n; i++){
        p[i] = i;
    }
}

int f(int x){
    return (x==p[x]?x:(p[x]=f(p[x])));
}

void unionn(int x, int y){
    p[f(x)] = f(y);
}

void ff(){
    init();
    sort(a, a+(n*(n+1)/2));
    //int cnt = 0;
    /*for(int i = 0; i < n; i++){
        for(int j = i+1; j <= n; j++){
            printf("%d %d %d %d\n",a[cnt].a,a[cnt].b,a[cnt].c, a[cnt].p);
            cnt++;
        }
    }*/
    int i, j;
    for(i = 0, j = 0; i < n&&j < (n*(n+1)/2); i++, j++){
        while(f(a[j].a)==f(a[j].b)) j++;
        unionn(a[j].a, a[j].b);
        ans1+=a[j].p;
        ans2+=a[j].c;
        //cout << "起點：" << a[j].a
         //    << "終點：" << a[j].b
         //    << "權重：" << a[j].c;
    }

}

int main(){
    int cnt = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = i+1; j <= n; j++){
            scanf("%d",&a[cnt].p);
            a[cnt].a = i;
            a[cnt].b = j;
            cnt++;
        }
    }

    cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j <= n; j++){
            scanf("%d",&a[cnt++].c);
        }
    }

    cnt = 0;
    /*for(int i = 0; i < n; i++){
        for(int j = i+1; j <= n; j++){
            printf("%d %d %d %d\n",a[cnt].a,a[cnt].b,a[cnt].c, a[cnt].p);
            cnt++;
        }
    }*/


    ff();
    int k;
    if((k=__gcd(ans1, ans2))!=1){
        ans1/=k;
        ans2/=k;
    }
    printf("%d %d\n", ans1, ans2);

    return 0;
}
