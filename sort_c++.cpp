#include <iostream>
#include <algorithm>
#include <chrono>
#include <vector>
using namespace std;
using namespace std::chrono;
const int limit = 1000000;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("test_case1.txt", "r ", stdin);
    vector<float>  arr(limit);
    
    for (int j=1;j<=10;j++){
        for (int i=0;i<limit ; i++){
        cin>> arr[i];
    }
    auto start = high_resolution_clock :: now();
    sort(arr.begin(), arr.end());

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "Executime_SORT_C++ data ["<< j << "]:\t" <<  duration.count() << "\tms\n";
    } 
   return 0;
    
}

