#include<bits/stdc++.h>
using namespace std;

class segment
{
   vector<int> seg;
   public:
     segment(int n)
     {
     	seg.resize(n);
     }	

   void construct(int l,int r,int ind,int arr[])
   {
	 if(l==r)
	 {
		seg[ind]=arr[l];
		return;
	 }
	int mid=(l+r)>>1;
	 construct(l,mid,2*ind+1,arr);
   construct(mid+1,r,2*ind+2,arr);
    seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
   }

int query(int l,int r,int qs,int qe,int ind)
{
//no overlap
  if(qs>r || qe<l)return INT_MAX;
  //complete overlap
  if(l>=qs && r<=qe)return seg[ind];	
  //partial overlap
  int mid=(l+r)>>1;
  int left=query(l,mid,qs,qe,2*ind+1);
  int right=query(mid+1,r,qs,qe,2*ind+2);
  return min(left,right);
}

void update(int i,int value,int ind,int l,int r)
{
	if(l==r)
	{
		seg[ind]=value;
		return;
	}
	int mid=(l+r)>>1;
	if(i<=mid)
	  update(i,value,2*ind+1,l,mid);
	else
	  update(i,value,2*ind+2,mid+1,r);
	 seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);   
  }
};

int main(int argc, char const *argv[])
{

	int n1;
	cin>>n1;
	segment s1(4*n1);
	int arr1[n1];
	for(int i=0;i<n1;i++)
	{
		cin>>arr1[i];
	}
	
	int n2;
	cin>>n2;
	segment s2(4*n2);
	int arr2[n2];
	
	for(int i=0;i<n2;i++)
	{
		cin>>arr2[i];
	}
	
	s1.construct(0,n1-1,0,arr1);
	s2.construct(0,n2-1,0,arr2);
	s1.update(2,1,0,0,n1-1);
	cout<<s1.query(0,n1-1,2,4,0)<<endl;
	cout<<s2.query(0,n2-1,2,3,0)<<endl;
	return 0;
}
