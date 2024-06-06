#include <bits/stdc++.h>

using namespace std;

//seturi disjuncte(avand un reprezentant si un rang)
//find gaseste reprezentantul unui set
//unite uneste 2 seturi ramanand cu un singur reprezentant
class DisjointSet{
    private:
        int *p,*r;
    public:
        DisjointSet(int n){
            p=new int[n];
            r=new int[n];
            for(int i=0;i<=n;i++){
                p[i]=-1;
                r[i]=1;
            }
        }
        int find(int x){
            if(p[x]==-1)
                return x;
            return p[x]=find(p[x]);
        }
        void unite(int x,int y){
            int x1=find(x);
            int y1=find(y);
            if(x1==y1)
                return;
            if(r[x1]<r[y1])
                p[x1]=y1;
            else if(r[x1]>r[y1])
                p[y1]=x1;
            else{
                p[y1]=x1;
                r[x1]++;
            }
        }
};

class G{
    private:
        int root;
        vector<vector<int>> muchii;
    public:
        G(int root):root(root){};
        void add(int x,int y,int w){
            muchii.push_back({w,x,y});
        }
        int kruskal(){
            sort(muchii.begin(),muchii.end());
            DisjointSet ds(root);
            int S=0;
            for(auto i:muchii){
                if(ds.find(i[1])!=ds.find(i[2])){
                    S+=i[0];
                    ds.unite(i[1],i[2]);
                }
            }
            return S;
        }


};

#define V 9

int minK(int k[], bool mstSet[])
{
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && k[v] < min)
            min = k[v], min_index = v;
 
    return min_index;
}
void primMST(int g[V][V])
{
    int p[V];
    int k[V];
    bool mstSet[V];
    for (int i = 0; i < V; i++)
        k[i] = INT_MAX, mstSet[i] = false;
    k[0] = 0;
    p[0] = -1;
    for (int count = 0; count < V - 1; count++) {
        int u = minK(k, mstSet);
        mstSet[u] = true;
        for (int v = 0; v < V; v++)
            if (g[u][v] && mstSet[v] == false
                && g[u][v] < k[v])
                p[v] = u, k[v] = g[u][v];
    }
    int S=0;
    for (int i = 1; i < V; i++)
        S+=g[i][p[i]];
    cout<<S<<endl;
}

int main(){



    G g(9);
    g.add(1,2,8);
    g.add(1,0,4);
    g.add(1,7,11);
    g.add(2,3,7);
    g.add(2,5,4);
    g.add(2,8,2);
    g.add(3,4,9);
    g.add(3,5,14);
    g.add(4,5,10);
    g.add(5,6,2);
    g.add(6,7,1);
    g.add(6,8,6);
    g.add(7,8,7);
    g.add(7,0,8);

    cout<<g.kruskal()<<endl;
    //sortezi muchiile dupa cost
    //adaugi pe cea mai ieftina care nu creaza ciclu
    //repeti pasul 2 pana cand arborele are n-1 muchii n=numarul de noduri


    int g2[V][V] = {{ 0, 4, 0, 0, 0, 0, 0,8,0 },
                    { 4, 0, 8, 0, 0, 0, 0,11,0 },
                    { 0, 8, 0, 7, 0, 4, 0,0,2 },
                    { 0, 0, 7, 0, 9, 14, 0,0,0 },
                    { 0, 0, 0, 9, 0, 10, 0,0,0 },
                    { 0, 0, 4, 14, 10, 0, 2,0,0 },
                    { 0, 0, 0, 0, 0, 2,  0 ,1,6 },
                    { 8, 11, 0, 0, 0, 0, 1,0,7 },
                    { 0, 0, 2, 0, 0, 0, 6,7,0 }};
    primMST(g2);

    //alegi un nod arbitrar si il adaugi in arbore
    //alegi muchia cu costul minim care pleaca din arbore si ajunge in afara lui fara sa creezi cicluri
    //daca 2 muchii au acelasi cost, alegi oricare(de preferat cea care nu are nod in arbore)
    //repeti pasul 2 pana cand arborele are n-1 muchii n=numarul de noduri
    return 0;}