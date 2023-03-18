#include <iostream>
#include <fstream>
#include <random>
#include <stdlib.h>
#include <time.h>
#include <chrono>

using namespace std;

bool test_sort(long long int v[],int n)
{
    int i;
    for (i=1; i<n; i++)
        if(v[i]<v[i-1])
            return false;
    return true;

}

void radixsort256(long long int v[], int n)
{
    int mx = v[0],i,cifra,exp;

    for (i = 1; i < n; i++)
    {
        if (mx < v[i])
        {
            mx = v[i];
        }
    }

    for (exp = 1; mx / exp > 0; exp = exp << 8)
    {
        int cifre[256] = {0};

        for (i = 0; i < n; i++)
        {
            cifra = (v[i] / exp) % 256;
            cifre[cifra]++;
        }

        for (i = 1; i < 256; i++)
        {
            cifre[i] = cifre[i]+ cifre[i - 1];
        }

        long long int *w = new long long int[n]();
        for (i = n - 1; i >= 0; i--)
        {
            cifra = (v[i] / exp) % 256;
            w[cifre[cifra] - 1] = v[i];
            cifre[cifra]--;
        }

        for (i = 0; i < n; i++)
        {
            v[i] = w[i];

        }
        delete [] w;


    }

}


int main()
{
    srand(time(NULL));
    ifstream f1("teste.txt");
    ofstream f2("radixsort256.txt");
    int i,N,MAXIM;
    while (f1>>N>>MAXIM)
    {

        long long int *v = new long long int[N]();
        f2 << "N=" << N << " "<< "MAXIM=" << MAXIM << " ";
        for (i = 0; i < N; i++)
            f1>>v[i];
        auto start = chrono::high_resolution_clock::now();
        radixsort256(v,N);
        auto end = chrono::high_resolution_clock::now();
        long long duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
        if (test_sort(v, N) == true)
            f2 << "Ok"<< " ";
        else
            f2 << "Nu e ok"<< " ";
        f2 << duration << endl;

        delete[] v;
    }

    /*
     ///Pentru teste suplimentare:

    for (N = 10; N <= 100000000; N = N * 10)
      for (MAXIM = 10; MAXIM <= 100000000; MAXIM = MAXIM * 10)
      {
          long long int *v = new long long int[N]();
          f2 << "N=" << N << " "<< "MAXIM=" << MAXIM << " ";
          for (i = 0; i < N; i++)
              v[i] = rand() % MAXIM;
          auto start = chrono::high_resolution_clock::now();
          radixsort256(v,N);
          auto end = chrono::high_resolution_clock::now();
          long long duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
          if (test_sort(v, N) == true)
              f2 << "Ok"<< " ";
          else
              f2 << "Nu e ok"<< " ";
          f2 << duration << endl;

          delete[] v;
      }

    */



    return 0;
}
