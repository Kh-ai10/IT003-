#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
const int limit = 1000000;

void heapify(float *arr, int N, int i)
{

	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < N && arr[left] > arr[largest])
		largest = left;

	if (right < N && arr[right] > arr[largest])
		largest = right;

	if (largest != i) {
		swap(arr[i], arr[largest]);

		heapify(arr, N, largest);
	}
}

void heapSort(float *arr, int N)
{

	for (int i = N / 2 - 1; i >= 0; i--)
		heapify(arr, N, i);

	for (int i = N - 1; i > 0; i--) {

		swap(arr[0], arr[i]);

		heapify(arr, i, 0);
	}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	float *arr = new float[limit];
    freopen("test_case1.txt","r",stdin);

    for (int j=1;j<=10;j++){
        for (int i=0;i<limit ; i++)  cin>> arr[i];

        auto start = high_resolution_clock :: now(); 
        heapSort(arr, limit);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);

        cout << "Executime_Heap_SORT_data ["<< j << "]:\t" <<  duration.count() << "\tms\n";
    }
	return 0 ;
}
