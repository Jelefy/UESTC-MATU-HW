#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int num;
    vector<int> vec[2];
    for (int i = 0; i < 10 && (cin >> num) && num >= 0; i++)
        vec[num % 2].push_back(num);
    for (int i = 1; i >= 0; i--){
        sort(vec[i].begin(), vec[i].end());
        for (int j = 0; j < vec[i].size(); j++)
            printf("%d ", vec[i][j]);
    }
    return 0;
}