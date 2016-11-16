#include <iostream>
using namespace std;

int getMax(int A[],int n){
	
	int max = A[0];
	for(int i=1;i<n;i++){
		if(A[i]>max)
			max = A[i];
	}
	return max;
}

void counting(int A[],int n){

	int max = getMax(A,n);
	
	int B[n],pos1[max]={0},pos2[max+1]={0},i;

	for(i=0;i<n;i++) pos1[A[i]]++;
	
	for(i=1;i<max+1;i++) pos2[i] = pos2[i-1] + pos1[i-1];

	for(i=0;i<n;i++) B[pos2[A[i]]++] = A[i];

	for(i=0;i<n;i++) A[i] = B[i];
}

int main(){

	int A[]= {230,3,4,2,5,1,4,7};
	int n = 8,i;
	
	cout << "Array before sorting : ";
	for(i=0;i<n;i++) cout << A[i] << " ";
	cout << endl;
	
	counting(A,n);
	
	cout << "Array after sorting  : ";
	for(i=0;i<n;i++) cout << A[i] << " ";
	cout << endl;

}
