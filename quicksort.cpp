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

void quicksort(int left, int right, long long int v[])
{
    if (left < right)
    {

        int pozpivot = left + rand() % (right - left + 1);
        int pivot = v[pozpivot];
        int i = left-1,j=right+1;
        while (true)
        {
            do
            {
                i++;
            }
            while(v[i]<pivot);

            do
            {
                j--;
            }
            while(v[j]>pivot);

            if (i>=j)
                break;

            swap(v[i], v[j]);
        }

        pozpivot = i + 1;
        quicksort(left, j,v);
        quicksort(j+1, right,v);
    }
}


int main()
{
    srand(time(NULL));
    ifstream f1("teste.txt");
    ofstream f2("quicksort.txt");
    int i,N,MAXIM;
    while (f1>>N>>MAXIM)
    {

        long long int *v = new long long int[N]();
        f2 << "N=" << N << " "<< "MAXIM=" << MAXIM << " ";
        for (i = 0; i < N; i++)
            f1>>v[i];
        auto start = chrono::high_resolution_clock::now();
        quicksort(0, N-1,v);
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
              quicksort(0,N-1,v);
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


