/*   ���������ģʽ 
*    �����߲���ת������Ϊ�� 
*	 �������Ҫ���ߵĲ�ף�
*    �����������ת��Ϊ����
*    ��˫�׻����Ա�˫�׵���ʹ�ã�
*    ����ת��Ϊ��Ŀ���
*    �����Ϳ��Ա���ԭ�д��벻�޸ģ�
*    ֻ���� 
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
		cout << "���ǰ�����˫�߲���!" << endl; 
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
		cout << "ת����" << endl;
		p->fun();
		cout << "���ǵ͵������߲�ף�" << endl; 
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
		cout << "���ǿɰ��ĵ����,����Ҫ���߲��!" << endl; 
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
