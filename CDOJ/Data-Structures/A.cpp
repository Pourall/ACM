/*
CDOJ 2016 UESTC Training for Data Structures A-卿学姐与公主
线段树更新点 区间查询
*/
#include <cstdio>
#include <algorithm>
#define N 100000

using namespace std;

struct node{
	int left,right;
	long long max;
};

node segment_tree[4*N]; 

void biuld_tree(int id,int l,int r){
     segment_tree[id].left=l;
     segment_tree[id].right=r;
     if(l==r){
     	segment_tree[id].max = 0;
     	return;
     }
     biuld_tree(2*id,l,(l+r)/2);
     biuld_tree(2*id+1,(l+r)/2+1,r);
     segment_tree[id].max =max(segment_tree[id*2].max,segment_tree[id*2+1].max);
     
}

void update_tree(int id,int pos,int val){
     int l=segment_tree[id].left;
     int r=segment_tree[id].right;
     if(l==r&&l==pos){
     	segment_tree[id].max+=val;
     	return;
     }
     if(pos>(l+r)/2)
     	update_tree(2*id+1,pos,val);
     else
     	update_tree(2*id,pos,val);
      segment_tree[id].max =max(segment_tree[id*2].max,segment_tree[id*2+1].max);
     
}
long long query_tree(int id,int l,int r){
	  if(segment_tree[id].left==l&&segment_tree[id].right==r)
	  	 return segment_tree[id].max;
	  int mid=(segment_tree[id].left+segment_tree[id].right)>>1;
	  if(r<=mid) return query_tree(2*id,l,r);
	  else if(l>mid)  return query_tree(2*id+1,l,r);
      else return max(query_tree(2*id,l,mid),query_tree(2*id+1,mid+1,r));
}

int main(void){
	int n,q;
	int t,p,x,l,r;
    
    biuld_tree(1,1,N);
	scanf("%d %d",&n,&q);
	while(q--){
		scanf("%d",&t);
		if(t==1){
			scanf("%d%d",&p,&x);
			update_tree(1,p,x);
		}
		if(t==2){
			scanf("%d%d",&l,&r);
			printf("%lld\n",query_tree(1,l,r));
		}
	}
	return 0;
}
