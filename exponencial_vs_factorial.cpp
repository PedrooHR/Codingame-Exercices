#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    int K;
    cin >> K; cin.ignore();

    for (int i = 0; i < K; i++) {
        float A;
        cin >> A; cin.ignore();
        
        int n = 1;
        double res_exp = n * log(A);
        double res_fac = (0.5 * log(2 * M_PIl)) + ((n + 0.5) * log(n)) - n;
        while ( res_exp >= res_fac){
            n++;
            res_exp = n * log(A);
            res_fac = (0.5 * log(2 * M_PIl)) + ((n + 0.5) * log(n)) - n;
        }

        cout << n;
        if (i < K-1) cout << " ";
    }
    cout << endl;
}