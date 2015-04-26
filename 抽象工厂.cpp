/* C++设计模式实例
* 	使用抽象工厂模式进行解耦操作，
*	对特定操作进行封装，
*	以减轻客户端的压力 
*/ 
#include <iostream>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class Function{
public:
	virtual void fun() = 0;
	~Function(){}
};
//功能1 
class D1:public Function{
public:
	void fun(){
		cout << "D1功能函数执行中..." << endl;
	}
};
//功能2 
class D2:public Function{
public:
	void fun(){
		cout << "D2功能函数执行中..." << endl;
	}
};
//功能3 
class D3:public Function{
public:
	void fun(){
		cout << "D3功能函数执行中..." << endl;
	}
};
class Facade{
public:
	virtual void fun() = 0;
	~Facade(){} 
};
//实现D1、D2、D3顺序 
class F1:public Facade{
private:
	Function *p1;
	Function *p2;
	Function *p3; 
public:
	F1(){
		p1 = new D1();
		p2 = new D2();
		p3 = new D3(); 
	}
	void fun(){
		cout << "F1的函数执行中..." << endl;
		p1->fun();
		p2->fun();
		p3->fun();
	} 
	~F1(){
		delete p1;
		delete p2;
		delete p3;
	}
};
//实现D2,D1顺序 
class F2:public Facade{
private:
	Function *p1;
	Function *p2;
public:
	F2(){
		p1 = new D1();
		p2 = new D2();
	}
	void fun(){
		cout << "F2的函数执行中..." << endl;
		p2->fun();
		p1->fun();
	} 
	~F2(){
		delete p1;
		delete p2;
	}
};
int main(int argc, char** argv) {
	Facade * p;
	//实现D1,D2,D3顺序 
	
	p = new F1(); 
	p->fun();
	
	delete p;
	 
	return 0;
}
