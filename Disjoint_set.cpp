class DSU
{
    private:
    vector<int> parent,rank,size;
    
    public:
   
    DSU(int n)
    {
         
        for(int i=0;i<=n;i++)
        {
            rank.push_back(0);
            parent.push_back(i);
            size.push_back(1);
        }
    }

    int findpar(int x) // find by path compression
    {
        if(parent[x]==x)
          return x;
        return parent[x]=findpar(parent[x]);
    }

   void unionSize(int x,int y)// union by size
    {
         int x_rep=findpar(x);
         int y_rep=findpar(y);
         if(x_rep==y_rep)
         {
             return;
         }
         if(size[x_rep]>size[y_rep])
         {
             parent[y_rep]=x_rep;
             size[x_rep]+=size[y_rep];
         }
         else
         {
             parent[x_rep]=y_rep;
             size[y_rep]+=size[x_rep]; 
         }
    }
    void UnionRank(int x,int y) //union by rank there is something called union by size just take size instead of rank;
    {
        int x_rep=findpar(x);
        int y_rep=findpar(y);
        if(x_rep==y_rep)
        {
            return;
        }
        if(rank[x_rep]>rank[y_rep]){
         parent[y_rep]=x_rep;
        }
        else if(rank[x_rep]<rank[y_rep]){
         parent[x_rep]=y_rep;
        }
        else
        {
            parent[y_rep]=x_rep;
            rank[x_rep]++;
        }
    }
  
};
