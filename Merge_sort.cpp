#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
const int limit = 1e6;

float *leftArray = new float[limit/2 + 1];
float *rightArray = new float[limit/2 + 1];

void merge(float arr[], int left, int middle, int right) {
    int len_leftArr = middle - left + 1;
    int len_rightArr = right - middle; 

    for(int i = 0; i < len_leftArr; ++i) 
        leftArray[i] = arr[i + left];
    for(int i = 0; i < len_rightArr; ++i) 
        rightArray[i] = arr[i + middle + 1];

    int leftIndex = 0,
        rightIndex = 0,
        arrIndex = left;

    while (leftIndex < len_leftArr && rightIndex < len_rightArr) {
        if (leftArray[leftIndex] <= rightArray[rightIndex]) {
            arr[arrIndex] = leftArray[leftIndex];
            ++leftIndex;
        }
        else {
            arr[arrIndex] = rightArray[rightIndex];
            ++rightIndex;
        }
        ++arrIndex;
    }


    while (leftIndex < len_leftArr) {
        arr[arrIndex] = leftArray[leftIndex];
        ++leftIndex;
        ++arrIndex;
    }   

    while (rightIndex < len_rightArr) {
        arr[arrIndex] = rightArray[rightIndex];
        ++rightIndex;
        ++arrIndex;
    }
}

void MergeSort(float arr[], int left, int right) {
    if (left >= right) 
        return;
    
    int middle = left + (right - left) / 2;
    MergeSort(arr, left, middle);
    MergeSort(arr, middle+1, right);
    merge(arr, left, middle, right);
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	float *arr = new float[limit] ;
	freopen("test_case1.txt","r",stdin);

    for (int j=1;j<=10;j++){
        for (int i=0;i<limit ; i++)  cin>> arr[i];

        auto start = high_resolution_clock :: now(); 
        MergeSort( arr, 0, limit - 1);
       
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);

        cout << "Executime_Merge_SORT_data ["<< j << "]:\t" <<  duration.count() << "\tms\n";
    }
	return 0;
}


