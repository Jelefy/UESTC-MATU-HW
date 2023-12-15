PersonFactory::PersonFactory(int i, char *nm, int a) : id(i), age(a) {
    if (!nm)
        this->name[0] = '\0';
    else
        strcpy(this->name, nm);
}
class Student : public PersonFactory {
    int grade;

public:
    Student(int i, char *nm, int a, int g = 1) : PersonFactory(i, nm, a), grade(g) {}
    ~Student() {}
    void PrintInfo() {
        PersonFactory::PrintInfo();
        cout << grade << endl;
    };
};
class Teacher : public PersonFactory {
    char department[50];

public:
    Teacher(int i, char *nm, int a, char *de = 0) : PersonFactory(i, nm, a) {
        if (!de)
            this->department[0] = '\0';
        else
            strcpy(this->department, de);
    }
    ~Teacher() {}
    void PrintInfo() {
        PersonFactory::PrintInfo();
        cout << department << endl;
    };
};
PersonFactory *PersonFactory::CreateStudent(int id, char *name, int age, int grade) { return new Student(id, name, age, grade); };
PersonFactory *PersonFactory::CreateTeacher(int id, char *name, int age, char *department) { return new Teacher(id, name, age, department); };