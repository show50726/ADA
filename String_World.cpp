#include<cstdio>
#include<algorithm>
#include<iostream>
#include<queue>
#include<cstddef>
#include<stack>
#include<cstring>
#define ll long long

using namespace std;

typedef struct Node {int i; int c;}node;
priority_queue<node> pq;

int ans[200020], exist[200020];
bool operator<(node n1, node n2) {return n1.i>n2.i;}
int main(){
    int t, n, k;
    scanf("%d", &t);
    while(t--){
        while(!pq.empty()) pq.pop();
        memset(ans, 0, sizeof(ans));
        memset(exist, 0, sizeof(exist));
        node x[200020];
        scanf("%d%d",&n,&k);
        for(int i = 1; i <= n; i++){
            scanf("%d", &x[i].c);
        }
        for(int i = 1; i <= n; i++){
            scanf("%d", &x[i].i);
        }
        for(int i = 1; i <= n; i++){
            pq.push(x[i]);
        }
        //printf("%d %d\n", pq.top().i, pq.top().c);
        int cnt = 0;
        ans[cnt] = pq.top().c;
        pq.pop();
        while(cnt<=k&&!pq.empty()){
            //printf("%d %d\n", pq.top().c, ans[cnt]);
            if(pq.top().c!=ans[cnt]){
                //printf("%d\n", pq.top().c);
                ans[++cnt] = pq.top().c;
                pq.pop();
            }
            else{
                pq.pop();
            }
        }


        for(int i = 0; i < k&&ans[i]!=0; i++){
            exist[ans[i]] = 1;
            printf("%d%s",ans[i], i==k-1?"\n":" ");
        }

        for(int i = 1; i <= k; i++){
            if(!exist[i])
                printf("%d%s",i, i==k?"\n":" ");
        }

    }


    return 0;
}
