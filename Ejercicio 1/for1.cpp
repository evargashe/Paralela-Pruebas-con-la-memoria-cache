#include <iostream>
#include <cstdlib>
#include <ctime> 


using namespace std;

#define MAX 1000
void function1(double A[][MAX],double x[MAX],double y[])
{
    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++)
        {
            y[i] += A[i][j] * x[j];
        }   
    }
}

void function2(double A[][MAX],double x[MAX],double y[])
{
    for (int j = 0; j < MAX; j++){
        for (int i = 0; i < MAX; i++)
        {
            y[i] += A[i][j] * x[j];
        }   
    }
}

void generarA(double A[][MAX])
{
    for(int i=0 ; i<MAX ; i++){
        for(int j=0; j<MAX; j++){
            int a=1+rand()%20;
            A[i][j]=a;
        }
    }
    cout<<"MATRIZ A"<<endl;
    for(int i=0 ; i<MAX ; i++){
        for(int j=0; j<MAX; j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
}
void generarx(double x[MAX])
{
    for(int i=0; i<MAX ; i++)
    {
        int a=1+rand()%20;
        x[i]=a;
    }
    cout<<"MATRIZ x" <<endl;
    for(int i=0 ; i<MAX ; i++){
        cout<<x[i]<<" ";
;
    }
}

int main()
{

    unsigned A0, A1;
    unsigned B0, B1;

    double A[MAX][MAX], x[MAX], y[MAX]={0};

    generarA(A);
    generarx(x);
    cout<<endl;
    A0=clock();
    function1(A,x,y);
    A1 = clock();

    double time0 = (double(A1-A0)/CLOCKS_PER_SEC);
    cout << "Execution Time Block 1: " << time0 << endl;

    cout<<endl;



    B0=clock();
    function2(A,x,y);
    B1 = clock();

    double time1 = (double(B1-B0)/CLOCKS_PER_SEC);
    cout << "Execution Time Block 2: " << time1 << endl;

    return 0;
}