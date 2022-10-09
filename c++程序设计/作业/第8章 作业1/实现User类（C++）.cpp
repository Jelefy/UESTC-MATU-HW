#include <iostream>
#include <string>
#include <map>
using namespace std;

struct User{
    map<string, string> data;
    void AddUser(const char *name, const char *pass){
        data[name] = pass;
    }
    User(const char *name, const char *pass){
        AddUser(name, pass);
    }
    int login(const char *name, const char *pass){
        map<string, string>::iterator it = data.find(name);
        if(it != data.end() && it->second == pass)
            return 0;
        return -1;
    }
};

int main(){
	char name[10],name1[10],pass[10],pass1[10];
	cin>>name>>pass>>name1>>pass1;
	User user("LiWei","liwei101");
	user.AddUser(name,pass);
	if (user.login(name1,pass1) >=0)
	{
		cout<<"Success Login!"<<endl;
	}
	else{
		cout<<"Login failed!"<<endl;
	}
	  return 0;
}