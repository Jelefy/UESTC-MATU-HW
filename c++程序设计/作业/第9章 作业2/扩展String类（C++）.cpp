#include<cstdlib>
#include <iostream>
#include<string.h>
using namespace std;
class String{
protected:
	char *mystr;
	int len;
public:
	String(const char *p){
		len = strlen(p);
		mystr = new char[len+1];
		strcpy(mystr,p);
	}
	~String(){
		if (mystr !=NULL)
		{
			delete []mystr;
			mystr = NULL;
			len = 0;
		}
	}
	void showStr(){cout <<mystr;}
	char * GetStr(){return mystr;}
	virtual bool IsSubString(const char *str){
		int i,j;
		for (i =0;i<len;i++)
		{
			int k = i;
			for (j =0;str[j] !='\0';j++,k++)
			{
				if (str[j]!= mystr[k]) break;
			}
			if(str[j] =='\0') return true;
		}
		return false;
	}
};

class EditString:public String{
public:
	EditString(const char *p):String(p){}
	int IsSubString(int start, const char *str);
	void EditChar(char s, char d); 
	void EditSub(char * subs,char *subd); 

	void DeleteChar(char ch);  
	void DeleteSub(char * sub); 

};
int EditString::IsSubString(int start, const char *str) {
	int len = strlen(mystr);
	int i, j;
	for (i = start; i<len; i++)
	{
		int k = i;
		for (j = 0; str[j] != '\0'; j++, k++)
		{
			if (str[j] != mystr[k])
				break;
		}
		if (str[j] == '\0') 
			return i;
	}
	return -1;
}

void EditString::EditChar(char s, char d) {
	for (int i = 0; mystr[i] != NULL; i++)
	{
		if (mystr[i] == s)
			mystr[i] = d;
	}

}


void EditString::EditSub(char * subs,char *subd)
{
    int start=0;
    char *temp = new char[len+1];
    while(start<len)
    {
        start=IsSubString(start,subs);
        if(start!=-1){
            strncpy(temp,mystr,start);
            temp[start] = '\0';
            strcat(strcat(temp,subd),&mystr[start+strlen(subs)]);
            strcpy(mystr,temp);
            len = strlen(mystr);
        }
        else{
            break;
        }
    }
    delete []temp;
}

void EditString::DeleteChar(char ch) {
	int k = 0, len = strlen(mystr);
	char s[1000];
	for (int i = 0; i < len; ++i) {
		if (mystr[i] == ch)continue;
		s[k++] = mystr[i];
	}
	for (int i = 0; i <= k; ++i)
		mystr[i] = s[i];
}

void EditString::DeleteSub(char *sub) {
	int ss = 0;
	char s[1000];
	int start = 0, lens = strlen(sub), len = strlen(mystr);
	while (1) {
		if (start >= len) 
			break;
		int k = IsSubString(start, sub);
		if (k == -1)
			break;
		for (int i = start; i < k; ++i)
			s[ss++] = mystr[i];
		start = k + lens;
	}
	for (int i = start; i < len; ++i)
		s[ss++] = mystr[i];
	for (int i = 0; i <= strlen(s); ++i)
		mystr[i] = s[i];
}


 void fun(char *s,char str[][1000]){
    int index = 0;
    char *p = s,*q = s;
    while(*p)
    {
        if(*p==','){
            *p = '\0';
            strcpy(str[index++],q);
            q = p+1;
        }
        p++;
    }
    strcpy(str[index++],q);    

}int main()
{   
    char s[1000];
    char str[999][1000]={0};    
    gets(s);
    fun(s,str);    
    EditString es1(str[0]);
    cout<<es1.IsSubString(atoi(str[1]),str[2])<<",";
    EditString es2(str[0]);
    es2.EditChar(str[3][0],str[4][0]);
    es2.showStr();  
    cout<<",";
    EditString es3(str[0]);
    es3.EditSub(str[5],str[6]);
    es3.showStr();
    cout<<",";
    EditString es4(str[0]);
    es4.DeleteChar(str[7][0]);
    es4.showStr();
    cout<<",";
    EditString es5(str[0]);
    es5.DeleteSub(str[8]);
    es5.showStr();
    cout<<endl;
    return 0;
}
