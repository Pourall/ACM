/*
CDOJ 2016 UESTC Training for Search Algorithm & String B
bfs迷宫问题
*/

#include <cstdio>
#include <queue>

#define N 50

int vis[N][N][N] = {0};
int n,r,l;

struct node{
  int x,y,z,dis;
};

using namespace std;


int can_move(int x,int y,int z,int dz){
	if(x<0||y<0||z<0||x>=l||y>=r||z>=n){
		return 0;
	}
    if(dz == 0 && (vis[x][y][z] == 0 ||vis[x][y][z] == 2||vis[x][y][z] == 3)){
    	return 1;
    }else if(vis[x][y][z] == 3 && dz == 1){
    	return 1;
    }else if(vis[x][y][z] == 2 && dz == -1){
        return 1;
    }else{
    	return 0;
    }
}

int bfs(node start,node end){
   int dx[6]={1,-1,0,0,0,0};
   int dy[6]={0,0,1,-1,0,0};
   int dz[6]={0,0,0,0,1,-1};
   queue<node> q;
   q.push(start);
   vis[start.x][start.y][start.z] = 1;

   while(!q.empty()){
   	 node tmp = q.front();
   	 q.pop();
   	 if(tmp.x==end.x && tmp.y==end.y && tmp.z == end.z){
   	 	return tmp.dis;
   	 }
   	 for(int i = 0;i<6;i++){
   	 	int tx = tmp.x+dx[i];
   	 	int ty = tmp.y+dy[i];
   	 	int tz = tmp.z+dz[i];
   	 	if(can_move(tx,ty,tz,dz[i])){
   	 		vis[tx][ty][tz] = 1;
   	 		node newnode;
   	 		newnode.x = tx,newnode.y = ty,newnode.z = tz,newnode.dis = tmp.dis+1;
   	 		q.push(newnode);
   	 	} 
   	 }
   }
   return -1;
}

int main(void){
	int ans;
	char str[N+2];
	node start,end;
	start.dis=0;
	scanf("%d%d%d",&n,&l,&r);
	for(int i = 0;i<n;i++)
		for(int j = 0;j<l;j++){
			scanf("%s",str);
			for(int k = 0;str[k]!='\0';k++){
				if(str[k] =='.') vis[j][k][i] = 0;
				if(str[k] =='x') vis[j][k][i] = 1;
                if(str[k] =='U') vis[j][k][i] = 2;
                if(str[k] =='D') vis[j][k][i] = 3;
                if(str[k] =='X') start.x = j,start.y = k,start.z = i;
                if(str[k] =='Y') end.x = j,end.y = k,end.z = i;
            }
		}
    ans = bfs(start,end);
    printf("%d\n",ans);
	return 0;
}
