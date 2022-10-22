#include "CNumberFactory.h"
class CNumber : public CNumberFactory{
private:
    int data;
public:
    virtual void SetValue(int val){
        data = val;
    }
    virtual int GetValue(){
        return data;
    }
    virtual void Add(int val){
        data += val;
    }
    virtual void Sub(int val){
        data -= val;
    }
};
CNumberFactory *CNumberFactory::Create(){
	return new CNumber();
}