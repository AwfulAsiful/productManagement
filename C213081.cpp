#include <iostream>
#include <fstream>
bool check_prime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
using namespace std;
int main()
{
    int n;
    ifstream input("input.txt");
    ofstream output("output.txt");
    input >> n;
    if (check_prime(n))
        output << "The number " << n << " is prime";
    else
        output << "The number " << n << " is composite";
}