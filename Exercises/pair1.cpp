#include <iostream>
#include <utility>
using namespace std;

int main() {
    pair<string, double> product1 = make_pair("lightbulbs", 0.99);
    pair<string, double> product2 = {"tomatoes", 2.30};
    pair<string, double> product3 = product2;

    product2 = {"shoes", 39.90};

    cout << "The price of " << product1.first << " is $" << product1.second << '\n';
    cout << "The price of " << product2.first << " is $" << product2.second << '\n';
    cout << "The price of " << product3.first << " is $" << product3.second << '\n';

    return 0;
}
