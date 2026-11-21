#include<stdio.h>
#include<stdlib.h>
int max(int a, int b){
		return (a>b) ? a:b;
}
int main(){
	int n;
	scanf("%d", &n);

	int *value=(int*)malloc(n*sizeof(int));
	int *weight=(int*)malloc(n*sizeof(int));

	for(int i=0; i<n;i++){
		scanf("%d", &value[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d", &weight[i]);
	}
int capacity;
scanf("%d", &capacity);

int **dp=(int**)malloc((n+1)*sizeof(int *));
for(int i=0;i<=n;i++){
	dp[i]=(int *)malloc((capacity+1)*sizeof(int));
}

for(int i=0;i<=n;i++){
	for(int w=0;w<=capacity;w++){
		if(i==0 || w==0){
			dp[i][w]=0;
		}else if(weight[i-1]<=w){
			dp[i][w]= max(value[i-1]+dp[i-1][w-weight[i-1]], dp[i-1][w]);
		}else{
			dp[i][w]=dp[i-1][w];
		}
	}
