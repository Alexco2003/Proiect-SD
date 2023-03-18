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


void shellsort(long long int v[], int n)
{

    int interval = n/2,i,j;

    while (interval > 0)
    {
        for ( i = interval; i < n; i++)
        {
            j = i;
            while (j >= interval && v[j-interval] > v[j])
            {
                swap(v[j], v[j-interval]);
                j = j-interval;
            }
        }

        interval = interval/2;
    }
}

int main()

{
    srand(time(NULL));
    ifstream f1("teste.txt");
    ofstream f2("shellsort.txt");
    int i,N,MAXIM;
    while (f1>>N>>MAXIM)
    {

        long long int *v = new long long int[N]();
        f2 << "N=" << N << " "<< "MAXIM=" << MAXIM << " ";
        for (i = 0; i < N; i++)
            f1>>v[i];
        auto start = chrono::high_resolution_clock::now();
        shellsort(v,N);
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
          shellsort(v,N);
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
