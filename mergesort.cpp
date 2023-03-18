#include <iostream>
#include <fstream>
#include <random>
#include <stdlib.h>
#include <time.h>
#include <chrono>

using namespace std;

long long int *w = new long long int[100000000] {};

bool test_sort(long long int v[],int n)
{
    int i;
    for (i=1; i<n; i++)
        if(v[i]<v[i-1])
            return false;
    return true;

}

void mergesort(int left, int right, long long int v[])
{
    int i,j,k=0;
    int mid=(left+right)/2;
    if (left==right)
        return;
    mergesort(left,mid,v);
    mergesort(mid+1,right,v);
    for (i=left,j=mid+1; i<=mid && j<=right;)
    {
        if (v[i]<v[j])
        {
            w[k]=v[i];
            i++;
        }
        else
        {
            w[k]=v[j];
            j++;
        }
        k++;
    }

    for (; i<=mid; i++)
        w[k]=v[i],k++;
    for (; j<=right; j++)
        w[k]=v[j],k++;

    for (i=left; i<=right; i++)
        v[i]=w[i-left];

}

int main()
{
    srand(time(NULL));
    ifstream f1("teste.txt");
    ofstream f2("mergesort.txt");
    int i,N,MAXIM;
    while (f1>>N>>MAXIM)
    {

        long long int *v = new long long int[N]();
        f2 << "N=" << N << " "<< "MAXIM=" << MAXIM << " ";
        for (i = 0; i < N; i++)
            f1>>v[i];
        auto start = chrono::high_resolution_clock::now();
        mergesort(0, N-1,v);
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
          mergesort(0,N-1,v);
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




