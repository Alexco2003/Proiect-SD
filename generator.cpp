#include <iostream>
#include <fstream>
#include <random>
#include <stdlib.h>
#include <time.h>
#include <chrono>

using namespace std;

int main()
{
    srand(time(NULL));
    ofstream f1("teste.txt");
    int N,MAXIM,i;
    for (N = 10; N <= 100000000; N = N * 10)
        for (MAXIM = 10; MAXIM <= 100000000; MAXIM = MAXIM * 10)
        {


            f1 << N << endl << MAXIM << endl;
            for (i = 0; i < N; i++)
                f1 << rand() % MAXIM <<" ";
        }

    ///Am generat multi vectori pe care i-am bagat in fisierul "teste.txt" ca sa pot testa toti algoritmii de sortare cu aceeasi vectori


    return 0;
}
