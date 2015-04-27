/*	װ��ģʽ
*	�������˽��������������⣬
*	�������д�ĸ߶�һ��
*	�������Decorate�����ݳ�Ա
*	��˽�еģ���˻���ֲ����ε��ã�
*	������������ģʽ 
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

