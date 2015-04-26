/* C++���ģʽʵ��
* 	ʹ�ó��󹤳�ģʽ���н��������
*	���ض��������з�װ��
*	�Լ���ͻ��˵�ѹ�� 
*/ 
#include <iostream>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class Function{
public:
	virtual void fun() = 0;
	~Function(){}
};
//����1 
class D1:public Function{
public:
	void fun(){
		cout << "D1���ܺ���ִ����..." << endl;
	}
};
//����2 
class D2:public Function{
public:
	void fun(){
		cout << "D2���ܺ���ִ����..." << endl;
	}
};
//����3 
class D3:public Function{
public:
	void fun(){
		cout << "D3���ܺ���ִ����..." << endl;
	}
};
class Facade{
public:
	virtual void fun() = 0;
	~Facade(){} 
};
//ʵ��D1��D2��D3˳�� 
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
		cout << "F1�ĺ���ִ����..." << endl;
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
//ʵ��D2,D1˳�� 
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
		cout << "F2�ĺ���ִ����..." << endl;
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
	//ʵ��D1,D2,D3˳�� 
	
	p = new F1(); 
	p->fun();
	
	delete p;
	 
	return 0;
}
