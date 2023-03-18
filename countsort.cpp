#include <iostream>
#include <fstream>
#include <random>
#include <stdlib.h>
#include <time.h>
#include <chrono>

using namespace std;

bool test_sort(long long int v[], int n)
{
    int i;
    for (i = 1; i < n; i++)
        if (v[i] < v[i - 1])
            return false;
    return true;
}

void countsort(long long int v[], int n)
{
    int maxim = v[0], i, j = 0;

    for (i = 1; i < n; i++)
    {
        if (maxim < v[i])
            maxim = v[i];
    }
    long long int *w = new long long int[maxim + 1]();

    for (i = 0; i < n; i++)
        w[v[i]]++;

    for (i = 0; i < maxim + 1; i++)
        while (w[i] != 0)
        {
            v[j] = i;
            j++;
            w[i]--;
        }

    delete[] w;
}

int main()
{
    srand(time(NULL));
    ifstream f1("teste.txt");
    ofstream f2("countsort.txt");
    int i,N,MAXIM;
    while (f1>>N>>MAXIM)
    {

        long long int *v = new long long int[N]();
        f2 << "N=" << N << " "<< "MAXIM=" << MAXIM << " ";
        for (i = 0; i < N; i++)
            f1>>v[i];
        auto start = chrono::high_resolution_clock::now();
        countsort(v, N);
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
     /// Pentru teste suplimentare:

    for (N = 10; N <= 100000000; N = N * 10)
      for (MAXIM = 10; MAXIM <= 100000000; MAXIM = MAXIM * 10)
      {
          long long int *v = new long long int[N]();
          f2 << "N=" << N << " "<< "MAXIM=" << MAXIM << " ";
          for (i = 0; i < N; i++)
              v[i] = rand() % MAXIM;
          auto start = chrono::high_resolution_clock::now();
          countsort(v, N);
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
