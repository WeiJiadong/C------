//µ¥ÀýÄ£Ê½ 
#include <iostream>
using namespace std; 

class Singleton{
private:
	int x, y;
	static Singleton * p;
    Singleton(int x = 0, int y = 0){
    	this->x = x;
    	this->x = x;
	}	
public:
	static Singleton * Creat(int x, int y){
		if(p == NULL){
			return (p = new Singleton(x, y));
		}
	}
	~Singleton(){
		delete p;
	}
};

Singleton * Singleton::p = NULL;

int main(){
	Singleton * p, * p1;
	
	p1 = p = NULL;
	
	p = Singleton::Creat(3, 5);

	p1 = Singleton::Creat(3, 5);		
  
    cout << p << endl << p1 << endl;
	  
	return 0;	
}
