/*	装饰模式
*	由于有人建议我命名的问题，
*	所以这次写的高端一点
*	这个由于Decorate的数据成员
*	是私有的，因此会出现波浪形调用，
*	类似于责任链模式 
* 
*/ 
#include <iostream>
using namespace std;
class Component{
public:
	virtual void Operation() = 0;
	virtual ~Component(){
	}	
};
class ConCreteComponet:public Component{
public:
	void Operation(){
		cout << "ConCreteComponet Operation..." << endl; 
	}
};
class Decorate:public ConCreteComponet{
private:
	Component * p;
public:
	Decorate(Component * p){
		this->p = p;
	}
	void Operation(){
		p->Operation();
	}
}; 
class DecorateA:public Decorate{
public:
	DecorateA(Component * p):Decorate(p){}
	void Operation(){
		Decorate::Operation();
		cout << "DecorateA Operation..." << endl;
	}
};
class DecorateB:public Decorate{
public:
	DecorateB(Component * p):Decorate(p){}
	void Operation(){
		Decorate::Operation();
		cout << "DecorateB Operation..." << endl;
	}
};
int main(){
	ConCreteComponet *pC = new ConCreteComponet();
	Decorate *pB = new DecorateB(pC);
	Decorate *pA = new DecorateA(pB);
	
	pA->Operation();
	
	delete pC;
	delete pB;
	delete pA;
	 
	return 0;
} 

