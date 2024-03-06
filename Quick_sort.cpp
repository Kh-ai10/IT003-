#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
const int limit = 1e6;

float *arr = new float [limit];

void Quick_Sort(int low, int high){
    int pivot = low + (high-low)/2;
    int left = low,   right = high;
    do{
        while (arr[left] < arr[pivot]) ++left;
        while (arr[right] > arr[pivot]) --right;

        if(left <= right){
            float tmp = arr[left]; arr[left] = arr[right]; arr[right] = tmp;
            ++left; --right;
        }
    }while(left <= right);
    if(low < right) Quick_Sort(low, right);
    if(left < high) Quick_Sort(left, high);

}
			
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("test_case1.txt", "r ", stdin);
    for (int j=1;j<=10;j++){
        for (int i=0;i<limit ; i++)  cin>> arr[i];
       
        auto start = high_resolution_clock :: now(); 
        Quick_Sort(0,limit-1);
       
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);
        

        cout << "Executime_Quick_SORT_C++ data ["<< j << "]:\t" <<  duration.count() << "\tms\n";
    }
    delete[] arr;   
    return 0;
}

