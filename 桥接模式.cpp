/*
* 	桥接模式 
*	抽象和实现相分离 
*/ 
#include <iostream>
#include <vector>
using namespace std;
class AbstracitonImp{
public:
	virtual void Operation() = 0;
	virtual ~AbstracitonImp(){}
};
class ConcreteAbstractionImpA:public AbstracitonImp{
public:
	void Operation(){
		cout << "ConcreteAbstractionImpA..." << endl;	
	}		
};
class ConcreteAbstractionImpB:public AbstracitonImp{
public:
	void Operation(){
		cout << "ConcreteAbstractionImpB..." << endl;	
	}		
};
class Abstraction{
private:
	AbstracitonImp *p;
public:
	Abstraction(AbstracitonImp *p){
		this->p = p; 
	}
	virtual void Operation() = 0;
	
	void Do(){
		p->Operation();
	}
	virtual ~Abstraction(){}
};
class RefinedAbstraction1:public Abstraction{
public:
	RefinedAbstraction1(AbstracitonImp *p):Abstraction(p){}
	void Operation(){
		Do();
		cout << "RefinedAbstraction1..." << endl;
	}
};
class RefinedAbstraction2:public Abstraction{
public:
	RefinedAbstraction2(AbstracitonImp *p):Abstraction(p){}
	void Operation(){
		Do();
		cout << "RefinedAbstraction2..." << endl;
	}
	

};
int main(){
	AbstracitonImp * p1 = new ConcreteAbstractionImpB();
	 
	Abstraction * p = new RefinedAbstraction1(p1);
	
	p->Operation();
	
	delete p;
	delete p1;
	
	return 0;
}
