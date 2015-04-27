/*    单例模式
*/ 
#include <iostream>
using namespace std;
class A{
private:
    A *p;
    A(){}
public:
	A *get(){
        return new A();
    }
    void test(){
        cout << "A的测试程序..." << endl;    	
	} 
};
int main(){
    A *p = A::get();
    
    p->test();
    
    delete p;
    
    return 0;
} 
