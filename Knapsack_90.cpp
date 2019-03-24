#include <iostream>
#include <cstdio>
#include <algorithm>
#define ll long long

using namespace std;

typedef struct item{
	int id;
	ll v;
	ll w;
}item;

//bool operator < (item n1, item n2){return (n1.v/n1.w)>(n2.v/n2.w);}
bool f(item n1, item n2){return ((double)n1.v/(double)n1.w)>((double)n2.v/(double)n2.w);}
bool func(item n1, item n2){return n1.id<n2.id;}
bool func2(item n1, item n2){return n1.w<n2.w;}

item a[1010];
item b[1010];
int main(){
	int n;
	ll w;
	scanf("%d %lld", &n, &w);
	for(int i = 0; i < n; i++){
		a[i].id = i+1;
		scanf("%lld %lld", &a[i].v, &a[i].w);
		b[i].id = a[i].id;
		b[i].v = a[i].v;
		b[i].w = a[i].w;
	}

	sort(a, a+n, f);
	sort(b, b+n, func2);

	ll sum2 = 0;
	ll value2 = 0;
	int pos2 = 0;
	for(int i = 0; i < n; i++){
        if(sum2+b[i].w<=w){
            value2+=b[i].v;
            sum2+=b[i].w;
            pos2 = i;
        }
        else break;
	}

	ll sum = 0;
	ll value = 0;
	int pos = 0;
	for(int i = 0; i < n; i++){
		if(sum+a[i].w<=w){
			value+=a[i].v;
			sum+=a[i].w;
			pos = i;
		}
		else break;
	}

    if(value>value2){
            printf("%d\n", pos+1);
            sort(a, a+pos+1, func);
            for(int i = 0; i <= pos; i++){
                printf("%d%s", a[i].id, i==pos?"\n":" ");
            }

    }
    else{
        printf("%d\n", pos2+1);
        sort(b, b+pos2+1, func);
        for(int i = 0; i <= pos2; i++){
            printf("%d%s", b[i].id, i==pos2?"\n":" ");
        }
    }




	return 0;
}
