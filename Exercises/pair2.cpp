#include <iostream>
#include <utility>
#include <tuple> // for tuple

using namespace std;

struct Edge{
    int from, to, weight;
};

int main(){
    Edge e1 = {1, 2, 5};
    cout <<"Edge{from: "<<e1.from<<", to: "<<e1.to<<", weight: "<<e1.weight<<"}\n";

    pair<int, pair<int, int>> p = {5, {1, 2}};
    cout <<"Edge{from: "<<p.second.first<<", to: "<<p.second.second<<", weight: "<<p.first<<"}\n";

    tuple<int, int, int> t = {5, 1, 2};
    cout <<"Edge{from: "<<get<1>(t)<<", to: "<<get<2>(t)<<", weight: "<<get<0>(t)<<"}\n";

    return 0;
}