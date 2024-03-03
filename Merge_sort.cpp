#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
const int limit = 1000000;

void merge(float *arr, int const left, int const mid, int const right)
{
	int const subArrayOne = mid - left + 1;
	int const subArrayTwo = right - mid;

	auto *leftArray = new int[subArrayOne],
		*rightArray = new int[subArrayTwo];

	for (auto i = 0; i < subArrayOne; i++)
		leftArray[i] = arr[left + i];
	for (auto j = 0; j < subArrayTwo; j++)
		rightArray[j] = arr[mid + 1 + j];

	auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
	int indexOfMergedArray = left;

	while ((indexOfSubArrayOne < subArrayOne) && (indexOfSubArrayTwo < subArrayTwo)) {
		if (leftArray[indexOfSubArrayOne]   <=  rightArray[indexOfSubArrayTwo]) {
			arr[indexOfMergedArray]   =   leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else {
			arr[indexOfMergedArray]	=   rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}

	while (indexOfSubArrayOne < subArrayOne) {
		arr[indexOfMergedArray]   =    leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}

	while (indexOfSubArrayTwo < subArrayTwo) {
		arr[indexOfMergedArray]   =   rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}
	delete[] leftArray;
	delete[] rightArray;
}

void mergeSort(float *arr, int const begin, int const end)
{
	if (begin >= end)
		return;

	int mid = begin + (end - begin) / 2;
	mergeSort(arr, begin, mid);
	mergeSort(arr, mid + 1, end);
	merge(arr, begin, mid, end);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	float *arr = new float[limit] ;
	freopen("test_case1.txt","r",stdin);

    for (int j=1;j<=10;j++){
        for (int i=0;i<limit ; i++)  cin>> arr[i];

        auto start = high_resolution_clock :: now(); 
        mergeSort( arr, 0, limit - 1);
       
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);

        cout << "Executime_Merge_SORT_data ["<< j << "]:\t" <<  duration.count() << "\tms\n";
    }
	return 0;
}


