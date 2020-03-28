#include <iostream>
using namespace std;

template<typename T>
class stack{
	public:
		//Constructor
		stack(int size){
			maxStackSize=size;
			stackTop=0;
			list=new T[maxStackSize];
		}
		//Copy Constructor
		stack(const stack& s){
			list=nullptr;
			delete [] list;
			maxStackSize=s.maxStackSize;
			stackTop=s.stackTop;
			list=new T[maxStackSize];
			for(int j=0;j<stackTop;j++){
				list[j]=s.list[j];
			}
		}
		//Destructor
		~stack(){
			delete [] list;
		}
		//Assignment Operator
		const stack & operator = (const stack &s){
			if(this!=&s){
				delete [] list;
				maxStackSize=s.maxStackSize;
				stackTop=s.stackTop;
				list=new T[maxStackSize];
				for(int j=0;j<stackTop;j++){
					list[j]=s.list[j];
				}
			}
			return *this;
		}
		//Checks if stack is empty
		bool empty(){
			if(stackTop==0){
				return true;
			}
			return false;
		}
		//Pushes
		void push(const T &x){
			list[stackTop]=x;
			stackTop++;
		}
		//Pops
		T pop(){
			if(!empty()){
				stackTop--;
				return list[stackTop];
			}
		}
		//Returns Stack Size
		int size(){
			return stackTop;
		}
		//Overloading << Operator
		friend ostream & operator << (ostream &out, const stack &s){
			if(s.stackTop==0){
				cout<<"[]";
				return out;
			}
			int i;
			cout<<"[";
			for(i=0;i<s.stackTop-1;i++){
				cout<<s.list[i]<<", ";
			}
			cout<<s.list[i]<<"]";
			return out;
			
		}
	private:
		int maxStackSize;
		int stackTop;
		T *list;
};

int main(){
  // let’s play with integers...
  stack<int> s(10);
  cout << "s is empty: "<< s << endl;
  s.push(42);
  cout << "s has one element: " << s << endl;
  s.push(17);
  s.push(34);
  cout << "s has more elements: " << s << endl;
  cout << "How many? " << s.size() << endl;
  stack<int> t(5);
  t.push(7);
  cout << "t: " << t << endl;
  t = s;
  cout << "popping from s: " << s.pop() << endl;

  s.push(8);
  stack<int> a(s);
  t.push(99);
  a.push(77);
  cout << "s: " << s << endl;
  cout << "t: " << t << endl;
  cout << "a: " << a << endl;
  // now with doubles...
  stack<double> c(4);
  c.push(3.14);
  c.push(1.414);
  cout << "c contains doubles " << c << endl;
  // and with characters...
  stack<char> k(4);
  k.push('$');
  cout << "k contains a character " << k << endl;
}
