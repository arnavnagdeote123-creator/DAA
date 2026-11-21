#include<stdio.h>
#include<stdlib.h>

#define INF 1e9
int n;
int cost[20][20];
int memo[1<<20][20];

int min(int a, int b){
	return(a<b)? a:b;
}

int tsp(int mask, int pos){
	if (mask==(1<<n)-1){
		return (cost[pos][0] != -1) ? cost[pos][0] : INF;
	}
	if(memo[mask][pos] != -1){
		return memo[mask][pos];
	}
	int ans = INF;
	for(int next_city=0; next_city<n; next_city++){
		if((mask &(1<<next_city))==0){
			if(cost[pos][next_city]!=-1){
				int new_cost=cost[pos][next_city]+tsp(mask| (1<< next_city), next_city);
				ans= min(ans,new_cost);
			}
		}
	}
	return memo[mask][pos]=ans;
}
int main(){
	if(scanf("%d", &n)!=1) return 0;
	for(int i=0; i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d", &cost[i][j]);
		}
}
