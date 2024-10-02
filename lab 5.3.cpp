#include <iostream>
#include <cmath>
#include <iomanip>  

using namespace std;

double t(const double x);
int fac(int j);

int main()
{
    double fp, fk, z;
    int n;

    cout << "fp = "; cin >> fp;
    cout << "fk = "; cin >> fk;
    cout << "n = "; cin >> n;

    double dg = (fk - fp) / n;
    double f = fp;

 
    cout << fixed;
    cout << "---------------------------" << endl;
    cout << "|" << setw(10) << "f" << " |" << setw(10) << "z" << " |" << endl;
    cout << "---------------------------" << endl;

    while (f <= fk)
    {
       
        z = t(f * f) + 2 * t(2 * f + 1) + sqrt(t(1));

      
        cout << "|" << setw(10) << setprecision(4) << f << " |"
            << setw(10) << setprecision(4) << z << " |" << endl;

        f += dg;  
    }


    cout << "---------------------------" << endl;

    return 0;
}


double t(const double x)
{
    if (abs(x) >= 1)
        return (cos(x) + 1) / (exp(x) + sin(x) * sin(x));
    else
    {
        double S = 0;
        int j = 0;
        double a = 1;
        S = a;
        do
        {
            j++;
            double R = pow((-1), j) * (pow(x, (2 * j + 1)) / fac(2 * j + 1));
            a *= R;
            S += a;
        } while (j < 5);
        return S;
    }
}

int fac(int j)
{
    if (j == 0 || j == 1)
        return 1;
    return j * fac(j - 1);
}
