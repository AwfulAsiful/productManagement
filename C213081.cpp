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
    int arr[101];
    ifstream input("input.txt");
    ofstream output("output.txt");
    int i = 1;
    
    while (input >> arr[i])
    {

        if (check_prime(arr[i]))
        {
            output << "The number " << arr[i] << " is prime"<<endl;
            continue;
        }
        else
        {
            output << "The number " << arr[i] << " is composite"<<endl;
            continue;
        }
        i++;
    }
}