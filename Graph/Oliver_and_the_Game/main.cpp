#include<bits/stdc++.h>

using namespace std;

typedef long long int lli;

lli intime[100005];

lli outTime[100005];

vector<bool> vis(100005,false);

lli timer=0;

vector<lli> adj[100005];

void dfs(lli node)

{

    vis[node]=true;

    intime[node]=timer++;

    for(auto child:adj[node])

    {

        if(vis[child]==false)

        {

            dfs(child);

        }

    }

    outTime[node]=timer++;

}

int main()

{

    ios_base::sync_with_stdio(false);

cin.tie(NULL);

lli n;

cin>>n;

lli m=n-1;

while(m--)

{

lli a,b;

cin>>a>>b;

adj[a].push_back(b);

adj[b].push_back(a);

}

dfs(1);

lli q;

cin>>q;

while(q--)

{

    lli type,x,y;

    cin>>type>>x>>y;

    if(intime[x]>outTime[y]||intime[y]>outTime[x])

    {

        cout<<"NO"<<endl;

    }

    else{

        if(type==0)

        {

            if(intime[x]<intime[y])

            {

                cout<<"YES"<<endl;

            }

            else{

                cout<<"NO"<<endl;

            }

        }

        else{

            if(intime[x]>intime[y])

            {

                cout<<"YES"<<endl;

            }

            else{

                cout<<"NO"<<endl;

            }

        }

    }

}


 

}