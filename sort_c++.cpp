#include <iostream>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace std::chrono;
const int limit = 1000000;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("test_case1.txt", "r ", stdin);
    float *arr = new float[limit];
  
    for (int j = 1; j <= 10; j++){
        for (int i = 0; i < limit; i++)         cin >> arr[i];
    
    auto start = high_resolution_clock :: now();
    sort(arr, arr + limit);
 
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "Executime_SORT_C++ data ["<< j << "]:\t" <<  duration.count() << "\tms\n";
    } 
   return 0;
    
}

