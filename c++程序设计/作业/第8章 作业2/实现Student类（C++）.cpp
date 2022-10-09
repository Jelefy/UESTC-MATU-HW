#include <iostream>
#include <cstring>
using namespace std;

int sum[3];
class Student{
public:
    Student(char *Name, char *Num, int g0, int g1, int g2){
        strcpy(name, Name);
        strcpy(num, Num);
        grade[0] = g0, grade[1] = g1, grade[2] = g2;
        sum[0] += g0, sum[1] += g1, sum[2] += g2;
    }
    void display(){
        cout << name << ' ' << num << ' ' << grade[0] << ' ' << grade[1] << ' ' << grade[2] << endl;
    }
    double average1(){
        return sum[0] / 3.0;
    }
    double average2(){
        return sum[1] / 3.0;
    }
    double average3(){
        return sum[2] / 3.0;
    }

private:
    char name[15], num[15];
    int grade[3];
};

int main(){
    Student *stu1, *stu2, *stu3;
    char name1[10], name2[10], name3[10];
    char num1[12], num2[12], num3[12];
    int grade1[3], grade2[3], grade3[3];
    cin >> name1 >> num1 >> grade1[0] >> grade1[1] >> grade1[2];
    cin >> name2 >> num2 >> grade2[0] >> grade2[1] >> grade2[2];
    cin >> name3 >> num3 >> grade3[0] >> grade3[1] >> grade3[2];
    stu1 = new Student(name1, num1, grade1[0], grade1[1], grade1[2]);
    stu2 = new Student(name2, num2, grade2[0], grade2[1], grade2[2]);
    stu3 = new Student(name3, num3, grade3[0], grade3[1], grade3[2]);

    stu1->display();
    stu2->display();
    stu3->display();

    cout << "The average grade of course1:" << stu2->average1() << endl;
    cout << "The average grade of course2:" << stu2->average2() << endl;
    cout << "The average grade of course3:" << stu2->average3() << endl;
    return 0;
}