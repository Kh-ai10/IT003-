#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
const int limit = 1000000;

int partition(float *arr, int low, int high)
{
    auto middle = low + (high - low )/2;
    int pivot=arr[middle];
    int i=(low-1);
    for(int j=low;j<=high;j++)
    {
	    if(arr[j]<pivot)
	    {
	    i++;
	    swap(arr[i],arr[j]);
	    }
    }
    swap(arr[i+1],arr[high]);
    return (i+1);
}
	
void Quick_Sort(float *arr, int low, int high)
{
    if(low<high)
    {
	    int pi=partition(arr,low,high);
	    Quick_Sort(arr,low,pi-1);
	    Quick_Sort(arr,pi+1,high);
    }
}
			
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("test_case1.txt", "r ", stdin);
    float *arr = new float [limit];
    
    for (int j=1;j<=10;j++){
        for (int i=0;i<limit ; i++)  cin>> arr[i];

        auto start = high_resolution_clock :: now(); 

        Quick_Sort(arr,0,limit-1);

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);

        cout << "Executime_SORT_C++ data ["<< j << "]:\t" <<  duration.count() << "\tms\n";
    }
    return 0;
}

