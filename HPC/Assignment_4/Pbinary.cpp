#include<bits/stdc++.h>
#include<time.h>
#include<omp.h>
#define SIZE 100000

using namespace std;
double seq_time, par_time;

int seq_binary(int a[], int key, int l, int r) {
    int mid = (l+r)/2;
    if(a[mid] == key) {
        return mid;
    }
    if(l == r) return -1;
    if(key < a[mid]) seq_binary(a, key, l,mid);
    else seq_binary(a, key, mid+1,r);
}

int para_binary(int a[],int key,int l,int r) {
    int mid = (l+r)/2;
    if(a[mid] == key) return mid;
    if(l == r) return -1;
    #pragma omp parallel sections num_threads(8)
    {
		#pragma omp section
        {
			para_binary(a,key,l,mid);
		}
		#pragma omp section
        {
			para_binary(a,key,mid+1,r);
		}
	}
}


int main() {
    int a[SIZE];
    for(int i=0;i<SIZE;i++) a[i] = rand()%126546;
    sort(a,a+SIZE);
    // a[1] = 1;
    double start_time = omp_get_wtime();
    cout<<seq_binary(a,1,0,SIZE);
    seq_time = omp_get_wtime() - start_time;
    cout<<" Sequential Search Time : "<<seq_time<<endl;

    start_time = omp_get_wtime();
    cout<<para_binary(a,1,0,SIZE);
    par_time = omp_get_wtime() - start_time;
    cout<<" Parallel Search Time : "<<par_time<<endl;

}