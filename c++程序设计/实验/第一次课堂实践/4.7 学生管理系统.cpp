#include <cstdio>
#include <climits>
#include <iostream>
using namespace std;
const int STU_LEN = 1001, NAME_LEN = 21;

struct student{
    char name[NAME_LEN];
    int gender;
    int birthday;
    double height;
    int C_score;
    int Calculus_score;
    void scan(){
        scanf("%s%d%d%lf%d%d", name, &gender, &birthday, &height, &C_score, &Calculus_score);
    }
    void print(){
        printf("%s %d %d %.2f %d %d\n", name, gender, birthday, height, C_score, Calculus_score);
    }
} stu[STU_LEN];

int n;

int main(){
    scanf("%d", &n);
    int C_max = 0, C_min = INT_MAX;
    int Calculus_max = 0, Calculus_min = INT_MAX;
    int C_sum = 0, Calculus_sum = 0;
    for (int i = 0; i < n; i++){
        stu[i].scan();
        C_sum += stu[i].C_score;
        C_max = max(C_max, stu[i].C_score);
        C_min = min(C_min, stu[i].C_score);
        Calculus_sum += stu[i].Calculus_score;
        Calculus_max = max(Calculus_max, stu[i].Calculus_score);
        Calculus_min = min(Calculus_min, stu[i].Calculus_score);
    }
    printf("C_average:%d\n", C_sum / n);
    printf("C_max:%d\n", C_max);
    for (int i = 0; i < n; i++)
        if(stu[i].C_score == C_max)
            stu[i].print();
    printf("C_min:%d\n", C_min);
    printf("Calculus_average:%d\n", Calculus_sum / n);
    printf("Calculus_max:%d\n", Calculus_max);
    for (int i = 0; i < n; i++)
        if(stu[i].Calculus_score == Calculus_max)
            stu[i].print();
    printf("Calculus_min:%d\n", Calculus_min);
    return 0;
}