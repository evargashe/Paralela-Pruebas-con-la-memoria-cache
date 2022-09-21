#include<iostream> 
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <unistd.h>
using namespace std;

void multiplicacion(int **A,int **B,int MAX,int **C){
    int bi=0;
    int bj=0;
    int bk=0;
    int i=0;
    int j=0;
    int k=0;
    int blockSize=MAX;    
    for(bi=0; bi<MAX; bi+=blockSize)
        for(bj=0; bj<MAX; bj+=blockSize)
            for(bk=0; bk<MAX; bk+=blockSize)
                for(i=0; i<blockSize; i++)
                    for(j=0; j<blockSize; j++)
                        for(k=0; k<blockSize; k++)
                            C[bi+i][bj+j] += A[bi+i][bk+k]*B[bk+k][bj+j];
} 
void generar(int **A,int **B, int MAX,int **C)
{
    for(int i=0 ; i<MAX ; i++){
        for(int j=0; j<MAX; j++){
            A[i][j]=1+rand()%20;
            B[i][j]=1+rand()%20;
            C[i][j]=0;
        }
    }
}


int main () {
    unsigned A0, A1;
	int MAX = 1000;
    cout<<"tam?";
    cin>>MAX;
	int **A = new int *[MAX];
	int **B = new int *[MAX];
    int **C = new int *[MAX];
    for(int i=0;i<MAX;i++){
		A[i] = new int[MAX];
        B[i] = new int[MAX];
        C[i] = new int[MAX];
	}
    generar(A,B,MAX,C);


    auto start = chrono::steady_clock::now();
    multiplicacion(A,B,MAX,C);   
    auto end = chrono::steady_clock::now();

     cout << "Elapsed time in nanoseconds: "
        << chrono::duration_cast<chrono::nanoseconds>(end - start).count()
        << " ns" << endl;


    for (int i = 0; i < MAX; i++)
	{
		delete[] A[i];
        delete[] B[i];
        delete[] C[i];
	}
	delete [] A;
    delete [] B;
    delete [] C;
/*     free(A[0]);
    free(A);
    free(B[0]);
    free(B);
    free(C[0]);
    free(C); */
    return 0;
}