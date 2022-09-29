#include <cstdio>
#include <iostream>
#include <string>
#include <windows.h>
#define nullptr 0
using namespace std;

template <class type>
struct single_linked_list{
    struct node{
        node *nxt;
        string key;
        type data;
        node(node *nxt, string key, type data) : nxt(nxt), key(key), data(data){}
        void clear(){
            if(nxt != nullptr){
                nxt->clear();
                delete nxt;
            }
        }
    } *head;
    single_linked_list(){
        head = nullptr;
    }
    void insert(string key, type data){
        head = new node(head, key, data);
    }
    type *find(string key){
        for (node *ptr = head; ptr != nullptr; ptr = ptr->nxt)
            if(ptr->key == key)
                return &(ptr->data);
        return nullptr;
    }
    void clear(){
        head->clear();
        delete head;
    }
    ~single_linked_list(){
        clear();
    }
};

template <class type, int mod>
struct hash_table{
    single_linked_list<type> linked_list[mod];
    int calc_hash(string s){
        int res = 0;
        for (string::iterator it = s.begin(); it != s.end(); it++)
            res = (res * 19260817 + *it) % mod;
        return res;
    }
    void insert(string key, type data){
        linked_list[calc_hash(key)].insert(key, data);
    }
    type *find(string key){
        return linked_list[calc_hash(key)].find(key);
    }
};

struct record{
    string name, phone_number, address;
    record(){}
    record(string name, string phone_number, string address) : name(name), phone_number(phone_number), address(address){}
    void print(){
        cout << "Name: " << name << endl;
        cout << "Phone Number: " << phone_number << endl;
        cout << "Address: " << address << endl;
    }
};

hash_table<record, 17> by_name, by_phone_number;

int main(){
    while(true){
        system("cls");
        puts("Welcome to the phonebook management system!");
        puts("[1] import a record");
        puts("[2] find a record by name");
        puts("[3] find a record by phone number");
        printf("Please enter option code (1, 2 or 3): ");
        int opt;
        cin >> opt;
        string tmp;
        getline(cin, tmp);
        system("cls");
        switch(opt){
            case 1:{
                record tmp;
                printf("Please enter name: ");
                getline(cin, tmp.name);
                printf("Please enter phone number: ");
                getline(cin, tmp.phone_number);
                printf("Please enter address: ");
                getline(cin, tmp.address);
                by_name.insert(tmp.name, tmp);
                by_phone_number.insert(tmp.phone_number, tmp);
                puts("Record import success!");
                break;
            }
            case 2:{
                string name;
                printf("Please enter name: ");
                getline(cin, name);
                record *res = by_name.find(name);
                if(res == nullptr)
                    puts("No records found!");
                else{
                    puts("A record was found.");
                    res->print();
                }
                break;
            }
            case 3:{
                string phone_number;
                printf("Please enter phone number: ");
                getline(cin, phone_number);
                record *res = by_phone_number.find(phone_number);
                if(res == nullptr)
                    puts("No records found!");
                else{
                    puts("A record was found.");
                    res->print();
                }
                break;
            }
            default:
                puts("Option code not valid!");
        }
        system("pause");
    }
    return 0;
}