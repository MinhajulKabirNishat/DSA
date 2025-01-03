#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef struct
{
    string c;
    int weight,profit;
    item(string c,int weight,int profit)
    {
        this->c=c;
        this->weight=weight;
        this->profit=profit;
    }
}item;

static bool cmp(item a,item b)
{
    double r1=(double)a.profit/(double)a.weight;
    double r2=(double)b.profit/(double)b.weight;
    return r1>r2;
}

void knapsack(int N,int W,item ara[])
{
    int p;
    sort(ara,ara+N,cmp);
    for(int i=N-1;i>=0;i--){
      if(ara[i].weight<=W){
        W-=ara[i].weight;
        p+=ara[i].profit;
        cout<<ara[i].c<<ara[i].weight;
      }
      else{
        p+=ara[i].profit*((double)W/(double)ara[i].weight);
        cout<<ara[i].c<<((double)W/(double)ara[i].weight);
      }
    }
    cout<<"maximum profit"<<p;
}

int main()
{
    int N,W,i;
    cout<<"N,W:";
    cin>>N,W;
    item veg[N];
    for(i=0;i<N;i++){
        int buy,sell,profit;
        cin>>veg[i].c;
        cin>>veg[i].weight;
        cin>>buy;
        cin>>sell;
        profit=sell-buy;
        veg[i].profit=profit;
    }
    knapsack(N,W,veg);

}
