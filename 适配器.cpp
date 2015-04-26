/*   适配器设计模式 
*    以两线插座转换三线为例 
*	 电风扇需要三线的插孔，
*    则就用适配器转换为三线
*    其双孔还可以被双孔电器使用，
*    还可转换为别的孔数
*    这样就可以保持原有代码不修改，
*    只扩充 
*/ 
#include <iostream>
using namespace std;
class Base{
public:
	virtual void fun() = 0;
	virtual ~Base(){}
}; 
class Two:public Base{
public:
	void fun(){
		cout << "我是傲娇的双线插座!" << endl; 
	}
};
class Adaptee:public Base{
private:
	Base *p; 
public:
	Adaptee(){
		p = new Two();
	}
	void fun(){
		cout << "转换：" << endl;
		p->fun();
		cout << "我是低调的三线插孔！" << endl; 
	}
	~Adaptee(){
		delete p;
	}
};
class DFS{
private:
	Base *p;
public:
	DFS(){
		p = new Adaptee();
	}
	void fun(){
		cout << "我是可爱的电风扇,我需要三线插孔!" << endl; 
		p->fun();
	}
	~DFS(){
		delete p;
	}	
};

int main(){
	DFS *p;
	
	p =  new DFS();
	
	p->fun();
	
	delete p;
	 
	return 0;
}
