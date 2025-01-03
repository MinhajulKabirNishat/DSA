#include<bits/stdc++.h>
using namespace std;
 struct Item {
  int profit , weight;
  Item ( int profit, int weight)
      {
      this ->profit = profit;
      this ->weight = weight;
       }
  };

  static bool cmp(struct Item a , struct Item b)
  {
      double x= (double)a.profit / (double)a. weight;
      double y= (double)b.profit / (double)b. weight;

      return x>y;
  }

double fracKnap (int w, struct Item arr[], int N)
{
    // sorting here algo
    sort (arr, arr+N,cmp);
    double result =0;
    for (int i=0; i<N; i++)
    {
        if (arr[i]. weight<=w)
        {
            w=w- arr[i].weight;
            result = result + arr[i].profit;
        }
        else
        {
            result = result + arr[i].profit*((double )w/(double)arr[i].weight);
            break;
        }

    }
    return result;
}
 int main()

{
    int w=5;
     Item arr[]= {{20,4},{9,3},{12,2},{7,1}};
     int N = sizeof (arr)/sizeof(arr[0]);
     cout <<fracKnap(w, arr,N)<<endl;
     return 0;
}
