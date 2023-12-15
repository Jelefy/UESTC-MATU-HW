#include "Felid.h"
#include <iostream>
using namespace std;

class Cat : public Felid{
public:
    Cat(){
        cout << "Cat constructor.." << endl;
    }
    void sound(){
        
    }
};

class Leopard : public Felid{
    Leopard(){
        cout << "Leopard constructor.." << endl;
    }
};