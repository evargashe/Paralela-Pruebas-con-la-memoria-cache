#include <iostream> 
#include <cstdlib>
#include <ctime> 
#include <chrono>
#include <unistd.h>
using namespace std;

void multiplicacion(int **A,int **B,int MAX,int **C ){
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            for(int k=0;k<MAX;k++){
                C[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
} 
void generarA(int **A, int **B, int**C ,int MAX)
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
    generarA(A,B,C,MAX);
    /* generarB(B,MAX); */

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