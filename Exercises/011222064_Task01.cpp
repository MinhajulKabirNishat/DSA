#include <iostream>
#include <vector>
using namespace std;

class GasStation {
public:
    GasStation() : n(0), m_gasAtStations(1000), m_costToNextStation(1000) {}

    int n;
    vector<int> m_gasAtStations;
    vector<int> m_costToNextStation;

    void readInput() {
        cout << "Enter the number of gas stations: ";
        cin >> n;

        cout << "Enter the gas available at each station: ";
        for (int i = 0; i < n; i++) {
            cin >> m_gasAtStations[i];
        }

        cout << "Enter the cost to travel to the next station: ";
        for (int i = 0; i < n; i++) {
            cin >> m_costToNextStation[i];
        }
    }


    int canCompleteCircuit() {
        int total_gas = 0, current_gas = 0, start_station = 0;

        for (int i = 0; i < n; i++) {
            total_gas += m_gasAtStations[i] - m_costToNextStation[i];
            current_gas += m_gasAtStations[i] - m_costToNextStation[i];

            if (current_gas < 0) {
                start_station = i + 1;
                current_gas = 0;
            }
        }

        return (total_gas >= 0) ? start_station : -1;
    }


    void printResult() {
        int result = canCompleteCircuit();
        if (result == -1) {
            cout << "It is impossible to complete the circular route." << endl;
        } else {
            cout << "Starting gas station index: " << result << endl;
        }
    }
};

int main() {
    GasStation gs;

    gs.readInput();
    gs.printResult();

    return 0;
}
