#include <iostream>
#include <vector>
using namespace std;
#define SIZE 10


int findMax(int array[]){

	int max = array[0];

	for(int i = 1; i<SIZE;i++){
		if(array[i]>max)
			max = array[i];
	}
	return max;
}

void countingSort(int array[]){
	
	int vectorSize = findMax(array);
	int newArray[SIZE],i,sum=0,element;
	
	vector<int> pos0(vectorSize,0),pos1(vectorSize+1,0);
	
	for(i=0;i<SIZE;i++){
		if(!pos0[array[i]])
		 	pos0[array[i]] = 0;
	
		pos0[array[i]] = pos0[array[i]] + 1; 				
	}	
	
	for(i=1;i<pos1.size();i++){
		sum += pos0[i-1];
		pos1[i] = sum; 				
	}
	
	for(i=0;i<SIZE;i++){
		element = array[i];
		
		newArray[pos1[element]] = element;
		pos1[element] +=1; 				
	}
	
	cout << "Array after counting sort  : ";
	
	for(i=0;i<SIZE;i++){
		cout << newArray[i]<<" ";			
	}
	cout <<endl;
}

int main(){
	int array[] = {4,2,4,1,5,7,6,3,2,5};
	
	cout << "Array before counting sort : ";
	for(int i=0;i<SIZE;i++){
		cout << array[i]<<" ";			
	}
	cout <<endl;
	
	countingSort(array);
	
	return 0;
}
