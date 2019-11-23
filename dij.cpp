#include<iostream>

using namespace std;

int main()
{
    int min,i,j,n,u,count,src;
    cout<<"Enter the no. of nodes"<<endl;
    cin>>n;
    int dist[n],vis[n],prev[n];
    cout<<"Enter the matrix"<<endl;
    int adj[n][n]={{0    ,1    ,99999,2    ,99999},
    		 {1    ,0    ,3    ,99999,6    },
    		 {99999,3    ,0    ,3    ,2    },
    		 {2    ,99999,3    ,0    ,99999},
    		 {99999,6    ,2    ,99999,0    }
    		};
    cout<<"enter the source"<<endl;
    cin>>src;
    for(i=0;i<n;i++)
        dist[i]=adj[src][i];
    for(j=0;j<n;j++)
        vis[j]=0;
    vis[src]=1;
    dist[src]=0;
    for(j=0;j<n;j++)
        prev[j]=src;
    
    count=1;
    while(count!=n)
    {
        min=99999;
        for(j=0;j<n;j++)
        {
            if((dist[j]<min) && (vis[j]!=1))
            {
                min=dist[j];
                u=j;
            }
        }
        vis[u]=1;
        count=count+1;
        for(j=0;j<n;j++)
        {
            if((min+adj[u][j]<dist[j]) && (vis[j]!=1))
            {
                dist[j]=min+adj[u][j];
                prev[j]=u;
            }   
        }

        
    } 
    for(i=0;i<n;i++)
    {
            cout<<"minimun distance from "<<src<<" to "<<i<<" is :"<<dist[i]<<endl;
            j=i;
            cout<<"path :"<<i<<"  ";
            do
            {
               cout<<"<-"<<prev[j]<<"<-";
               j=prev[j];
            }while(prev[j]!=src); 
            cout<<src<<" "<<endl; 
    }              
    return 0;    
}
