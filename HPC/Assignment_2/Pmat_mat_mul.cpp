#include<iostream>
#include<omp.h>
#include<time.h>
#include<bits/stdc++.h>
using namespace std;

int matrix1[100][100];
int matrix2[100][100];
double seq_time1,par_time1;

void seq_mat_mul()
{
    int result[100][100];
    memset(result, 0, sizeof(result));
    double start_time = omp_get_wtime();
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            for(int k=0;k<100;k++)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    seq_time1 = omp_get_wtime() - start_time;

    cout<<"\n***Sequential Matrix Multiplication ***\n"<<endl;
    cout<<"For 100 :"<<seq_time1<<endl;
}
void par_mat_mul(int t)
{
    int result[100][100];
    memset(result, 0, sizeof(result));
    double start_time = omp_get_wtime();
    #pragma omp parallel for collapse(1) num_threads(t)
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            for(int k=0;k<100;k++)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    par_time1 = omp_get_wtime() - start_time;

    cout<<"\n***Parallel Matrix Multiplication ***\n"<<endl;
    cout<<"For 100 :"<<par_time1<<endl;
}
int main()
{
    //cout<<"YESS";
    int choice;
    int result[100][100];
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            result[i][j] = rand() % 100;
        }
    }
    do
    {
        cout<<"***MENU***"<<endl;
        cout<<"1. Sequential Matrix Multiplication :"<<endl;
        cout<<"2. Parallel Matrix Multiplication   :"<<endl;
        cout<<"3. Exit"<<endl;
        cin>>choice;
        if(choice == 1) {seq_mat_mul();}
        else if(choice == 2)
        {
            cout<<"\nThread Num  :2"<<endl;
            par_mat_mul(2);
            cout<<"\nThread Num  :3"<<endl;
            par_mat_mul(3);
            cout<<"\nThread Num  :4"<<endl;
            par_mat_mul(4);
        }
    }while(choice != 3);
    return 0;
}