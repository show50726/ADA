#include<cstdio>
#include<algorithm>
#include<iostream>
#include<queue>
#include<cstddef>
#define ll long long

using namespace std;

ll dis[100010], ans[100010],exist[100010];

typedef struct l{
    int id;
    struct l *next;
    ll w;
}link;

struct Node {ll b, d;};

bool operator<(Node n1, Node n2) {return n1.d>n2.d;}

link *head[100010];

void bfs(int start, int endd){
    int visit[100010];
    for(int i = 1; i <= endd; i++){
        visit[i] = 0;
        ans[i] = 1LL<<62;
    }
    priority_queue<Node> pq;

    ans[start] = 0;
    pq.push((Node){1, ans[1]});

    for(int i = 1; i <= endd; i++){
        int a = -1;
        while(!pq.empty() && visit[a = pq.top().b]){
            pq.pop();
            //printf("kkk:%d\n", a);
        }
        if(a==-1) break;
        visit[a] = 1;
        link *ptr = head[a]->next;
        while(ptr!=NULL){
            if(!visit[ptr->id]&&ans[a]+ptr->w<ans[ptr->id]){

                ans[ptr->id] = ans[a]+ptr->w;
                //printf("%d %d %lld\n", ptr->id, a, ans[ptr->id]);
                pq.push((Node){ptr->id, ans[ptr->id]});
            }
            ptr = ptr->next;
        }
    }

}

int main(){
    int ee = 0;
    int n,m;
    scanf("%d%d",&n,&m);

    for(int i = 1; i <= n; i++){
        head[i] = new link;
        head[i]->w = 0LL;
        head[i]->next = NULL;
    }
    ans[1] = 0LL;
    int aa, bb;
    ll d;
    //puts("111");
    for(int i = 0; i < m; i++){

        scanf("%d %d %lld", &aa, &bb, &d);
        if(aa>bb){
            int t = aa;
            aa = bb;
            bb = t;
        }
        if(exist[aa]==0){
            exist[aa] = 1;
            ee++;
        }
        if(exist[bb]==0){
            exist[bb] = 1;
            ee++;
        }
        link *k = new link;
        k->w = d;
        k->id = bb;
        link *ptr = head[aa];

        //while(ptr->next!=NULL&&ptr->next->id<bb){
        //    ptr = ptr->next;
        //}
        k->next = ptr->next;
        ptr->next = k;



        link *kk = new link;
        kk->w = d;
        kk->id = aa;

        ptr = head[bb];
        kk->next = ptr->next;
        ptr->next = kk;

        //a[aa]->next = k;
        //a[aa] = a[aa]->next;
    }

    /*for(int i = 1; i <= n; i++){
        printf("%d: ", i);
        link *ptr = head[i]->next;
        while(ptr!=NULL){
            printf("%d ", ptr->id);
            ptr = ptr->next;
        }
        puts("");
    }*/

    //puts("111");
    if(ee<n||ans[n]==1LL<<62){
        printf("-1\n");
        return 0;
    }

    bfs(1, n);
    ll aaa = ans[n];
    //puts("111");
    for(int i = n; i >= 1; i--){
        //bfs(1, i);
        aaa = max(aaa, ans[i]);
        //printf("%lld\n", ans[i]);
    }

    printf("%lld\n", aaa);

    return 0;
}
