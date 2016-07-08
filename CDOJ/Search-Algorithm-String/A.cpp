/*
CDOJ 2016 UESTC Training for Search Algorithm & String A
八皇后问题
Input

一个数SIZE(9<=SIZE<=9)，代表棋盘的大小
 
Output

第一行输出一个数N，表示所有的方案数。
接下来N行，每行输出SIZE个数，第i个数ai表示在第i行第ai列放了皇后。
*/
#include <cstdio>
#define size 9
#define N 1000

int ans[N][size+1];
int a[size+1];
int cnt = 0;
int vis[3][2*size+2];

int check(int row,int col){
 return !(vis[0][col] || vis[1][row + col] || vis[2][row - col + size]);  
}

void dfs(int row){
	if(row == size+1){
       cnt++;
       for(int i = 1;i <= size ;i++)
       	   ans[cnt][i] = a[i]; 
	}
	for(int col = 1;col <= size;col++){
		if(check(row,col)){
        a[row] = col;
        vis[0][col] = vis[1][row + col] = vis[2][row - col + size ] = 1;
        dfs(row+1);
        vis[0][col] = vis[1][row + col] = vis[2][row - col + size ] = 0;
		}
	}
}
int main(void){
	//int n;
	//scanf("%d", &n);
	dfs(1);
	printf("%d\n", cnt);
	for (int i = 1; i <= cnt; i++) {
		for (int j = 1; j <= size; j++)
			printf("%d ", ans[i][j]);
		printf("\n");
	}
	return 0;
}
