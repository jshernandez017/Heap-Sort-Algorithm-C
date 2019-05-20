#include <iostream>
#include <limits.h>
using namespace std;
//Sudo code Pg. 152
//Left Node Initializer
int Left(int index){
	return 2*index;
}
//Right Node Initializer
int Right( int index){
	return 2*index + 1;
}
//Max-Heapify Function sudo from Pg.154
void maxHeapify(int *data, int index, int size){
	//initialize left,right, and max
	int left = Left(index);
	int right = Right(index);
	int max = INT_MIN;
	//Check left child
	if(left <= size && data[left] > data[index])
		max = left;
	else
		max = index;
	//Checks right child
	if(right <= size && data[right] > data[max])
		max = right;
	//If max index is changend, we perfome a swap
	if(max != index){
		int temp = data[index];
		data[index] = data[max];
		data[max] = temp;
		maxHeapify( data, max, size);
	}
	
}
//Build-Max-Heap Function Sudo Code Pg.157
void buildMaxHeap(int *data, int size){
	//Builds maxHeap
	for(int i = size/2; i >= 0; i--)
		maxHeapify(data, i, size);
}
//Heapsort sudo Code pg.160
void heapSort(int *data, int size){
	//Build max heap
	buildMaxHeap(data, size);
	//Sort elements
	for(int i = size; i >= 0; i--){
		int temp = data[i];
		data[i] = data[0];
		data[0] = temp;
		size--;
		maxHeapify(data, 0, size);
	}
}
//Simple print fuction itteratea through array.
void print(int *data, int size){
	for(int i = 0; i < size;i++)
		cout << data[i] << ";";
}
//Main
int main(int argc, char **argv){
	//initialize variables.
	int size;
	cin >> size;
	int *data = new int[size];
	//Collect data.
	for(int i = 0; i < size; i++)
		cin >> data[i];
	//print heapSorted array.
	heapSort(data,size - 1);
	print(data, size);
	//delete the array from memory.
	delete[] data;
	return 0;
}	
	
	