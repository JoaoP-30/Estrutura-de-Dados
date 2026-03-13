#include <iostream>

using namespace std;

struct Hidrocarboneto
{
    int C;
    int H;
};

int main()
{
    Hidrocarboneto *hidrocarboneto = new Hidrocarboneto; 

    cin >> hidrocarboneto->C >> hidrocarboneto->H;

    int massa = (hidrocarboneto->C * 12) + hidrocarboneto->H;

    cout << massa << '\n';

    delete hidrocarboneto;

    return 0;
}
