#include <bits/stdc++.h>
using namespace std;

class ST
{
	vector<int> seg,lazy;
public:
	ST(int n)
	{
		seg.resize(4*n);
		lazy.resize(4*n);
	}

	void build(int arr[],int ind,int low,int high)
    {
         if(low==high)
         {
         	seg[ind] = arr[low];
         	return;
         }
         int mid = (low+high)>>1;
         build(arr,2*ind+1,low,mid);
         build(arr,2*ind+2,mid+1,high);
         seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }

    void update(int ind,int l,int r,int low,int high,int val)
    {
    	//do previous remain updates
    	// update the node and propagate it downward
    	if(lazy[ind]!=0)
    	{
    		seg[ind]+=(high-low+1)*lazy[ind];

            if(low!=high)
            {
            	lazy[2*ind+1] = lazy[ind];
            	lazy[2*ind+2] = lazy[ind];
            }
            
            lazy[ind]=0;
    	}

    	//no overlap
    	if(l>high || r<low)return;

    	//complete overlap
    	if(low>=l && high<=r)
    	{
           seg[ind] += (high - low+1)*val;

           if(low!=high)
           {
           	lazy[2*ind+1] = val;
            lazy[2*ind+2] = val;
           }
           return;
    	}

        //partial overlapp
    	int mid = (low+high)>>1;
    	update(2*ind+1,l,r,low,mid,val);
    	update(2*ind+2,l,r,mid+1,high,val);
    	seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }


int query(int ind,int l,int r,int low,int high)
{
	//previous remaining updates 
	// update the node and propagate it downward
	if(lazy[ind]!=0)
    	{
    		seg[ind]+=(high-low+1)*lazy[ind];

            if(low!=high)
            {
            	lazy[2*ind+1] = lazy[ind];
            	lazy[2*ind+2] = lazy[ind];
            }
            
            lazy[ind]=0;
    	}



    	//no overlapp

    	if(l>high || r<low)return 0;

    	if(low>=l && high<=r)
    	{
    		return seg[ind];
    	}
     
     int mid = (low + high)>>1;

     int left = query(2*ind+1,l,r,low,mid);
     int right = query(2*ind+2,l,r,mid+1,high);

     return left+right; 
}
void print()
{
	for(int x:seg)
	{
		cout<<x<<" ";
	}
}

};

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)cin>>arr[i];
    ST st(n);

	st.build(arr,0,0,n-1);	
   
   int q;
   cin>>q;

   while(q--)
   {
   	int type;
   	cin>>type;

   	if(type==1)
   	{
   		int l,r;
   		cin>>l>>r;
   		cout<<st.query(0,l,r,0,n-1)<<endl;
   	}
   	else{
   		int l,r,val;
   		cin>>l>>r>>val;

   		st.update(0,l,r,0,n-1,val);
   	}

   }	

	 
	return 0;
}
