#include "stdio.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include "conio.h"
#include <memory>
#include <string> // to_string()

using namespace std;

namespace test {

	void unique_ptr_demo() {

		unique_ptr<int> myPtr = make_unique<int>(7);
		unique_ptr<int> myPtr1 = make_unique<int>(7);

		if (*myPtr == *myPtr1)
			cout << "equal value";

		if (myPtr == myPtr)  // c++ 20
			cout << "same location";
		else
			cout << "not same location";

		auto lamb = [lamPtr = move(myPtr)]() {
			return *lamPtr + 3;
		};

//		cout << *myPtr << endl; // no more pointing to valid address

//		cout << lamb() << endl;

	}

	class Int {
		int x;
	public:
		Int(int x_arg) :
				x(x_arg) {
		}
		operator string() // conversion operator
		{
			return to_string(x);
		}
	};

	class Int1 {
	public:
		int x = 0;

		Int1() {
			cout << "const";
		}
//	public:
//				virtual ~Int1() =0;

	};

//	Int1::~Int1(){}
	class Int2: public Int1 {

	};

	int foo(int n) {

		cout << "I am function pointer" << endl;
		return 0;
	}

	void function_pointer() {
		int (*fp)(int) = foo;
		fp(0);
		(*fp)(1);
	}

	void conversion_ctr() {

		{
			int count = 5;

			while (count-- > 0) {
			}
		}

		Int1 obj1(); // creation of object

		Int obj(7);
		obj = 8; // conversion constructor

		string s = obj;

		s = static_cast<string>(obj);

		cout << s << endl;

	}

// -----------------------------------------------------
	/*
	 class abc


	 {


	 public:


	 int *p;


	 abc()


	 {


	 p = new int[2]; // Assume that memory allocation succeeds here.


	 }


	 ~abc()


	 {


	 delete[]p;


	 }


	 };


	 void main()


	 {



	 abc OurObject;
	 OurObject.p[0] = 1;


	 OurObject.p[1] = 2;


	 cout << OurObject.p[0];


	 cout << OurObject.p[0];

	 /**(OurObject.p[0]) = 1;


	 *(OurObject.p[1]) = 2;


	 cout << *(OurObject.p[0]);


	 cout << *(OurObject.p[0]);
	 //_getch();

	 }
	 */
// -----------------------------------------------------
	/*
	 class MyFirst
	 {
	 private:
	 int i,j,k;
	 public:
	 MyFirst( int ii,int jj ) :i( ii ),j( jj )
	 {
	 cout << "In the constr " << "i is " << ii << " j is " << jj << endl;
	 _getch();
	 k = j / i;
	 }
	 virtual ~MyFirst() {}
	 void getVal()
	 {
	 k = j / i;
	 cout << i << j << k << endl;
	 }
	 };

	 void main()
	 {
	 //clrscr();
	 MyFirst my( 0,10 );
	 _getch();
	 my.getVal();
	 _getch();
	 }
	 */
// -----------------------------------------------------
	/*
	 //// LIBRARY START
	 class Base
	 {
	 public:

	 // The "Virtual Constructor"
	 static Base *Create( int id );

	 Base() {}

	 virtual // Ensures to invoke actual object destructor
	 ~Base() {}

	 // An interface
	 virtual void DisplayAction() = 0;
	 };

	 class Derived1 : public Base
	 {
	 public:
	 Derived1()
	 {
	 cout << "Derived1 created" << endl;
	 }

	 ~Derived1()
	 {
	 cout << "Derived1 destroyed" << endl;
	 }

	 void DisplayAction()
	 {
	 cout << "Action from Derived1" << endl;
	 }
	 };

	 class Derived2 : public Base
	 {
	 public:
	 Derived2()
	 {
	 cout << "Derived2 created" << endl;
	 }

	 ~Derived2()
	 {
	 cout << "Derived2 destroyed" << endl;
	 }

	 void DisplayAction()
	 {
	 cout << "Action from Derived2" << endl;
	 }
	 };

	 class Derived3 : public Base
	 {
	 public:
	 Derived3()
	 {
	 cout << "Derived3 created" << endl;
	 }

	 ~Derived3()
	 {
	 cout << "Derived3 destroyed" << endl;
	 }

	 void DisplayAction()
	 {
	 cout << "Action from Derived3" << endl;
	 }
	 };

	 // We can also declare "Create" outside Base
	 // But it is more relevant to limit it's scope to Base
	 Base *Base::Create( int id )
	 {
	 // Just expand the if-else ladder, if new Derived class is created
	 // User code need not be recompiled to create newly added class objects

	 if( id == 1 )
	 {
	 return new Derived1;
	 }
	 else if( id == 2 )
	 {
	 return new Derived2;
	 }
	 else
	 {
	 return new Derived3;
	 }
	 }
	 //// LIBRARY END

	 //// UTILITY START
	 class User
	 {
	 public:
	 User() : pBase( 0 )
	 {
	 // Receives an object of Base heirarchy at runtime

	 int input;

	 cout << "Enter ID (1, 2 or 3): ";
	 cin >> input;

	 while( (input != 1) && (input != 2) && (input != 3) )
	 {
	 cout << "Enter ID (1, 2 or 3 only): ";
	 cin >> input;
	 }

	 // Get object from the "Virtual Constructor"
	 pBase = Base::Create( input );
	 }

	 ~User()
	 {
	 if( pBase )
	 {
	 delete pBase;
	 pBase = 0;
	 }
	 }

	 // Delegates to actual object
	 void Action()
	 {
	 pBase->DisplayAction();
	 }

	 private:
	 Base *pBase;
	 };

	 //// UTILITY END

	 //// Consumer of User (UTILITY) class
	 int main()
	 {
	 User *user = new User();

	 // Action required on any of Derived objects
	 user->Action();

	 delete user;
	 getchar( );
	 getchar();
	 }
	 */

// -----------------------------------------------------
	/*
	 class A
	 {
	 public:
	 virtual ~A() {}
	 //virtual void foo() {}
	 //virtual void bar() {}
	 };

	 class B : public virtual A
	 {

	 public:
	 void test () { cout << "test" ; }


	 };
	 */
// -----------------------------------------------------
	/*
	 class C : public virtual A
	 {
	 public:
	 void bar() { printf("\n c::bar"); }
	 };

	 class D : public B,public C
	 {
	 };
	 */

// -----------------------------------------------------
	/*
	 class A // just an example
	 {
	 int x;
	 public:
	 A() { x = 4; }
	 int getX() { return x; }
	 };

	 class B
	 {
	 static A obj1;  // <- Problem happens here
	 public:
	 static void start();
	 };
	 //
	 A B::obj1; // init static var

	 void B::start()
	 {

	 int x = obj1.getX();
	 cout << x;
	 }


	 class Abc
	 {
	 int i;
	 public:
	 Abc()
	 {
	 i = 0;
	 cout << "constructor";
	 }
	 ~Abc()
	 {
	 cout << "destructor";
	 }
	 };

	 void f()
	 {
	 static Abc obj;

	 }
	 void g()
	 {
	 //Abc::obj.~Abc();
	 }
	 */
//----------------------------------------------------
	/*
	 template<class InputIt,class UnaryFunction>
	 UnaryFunction for_each( InputIt first,InputIt last,UnaryFunction f )
	 {
	 for( ; first != last; ++first ) {
	 f( *first );
	 }
	 return f;
	 }
	 struct st_y
	 {
	 int x;
	 };
	 namespace AB{
	 struct st_x
	 {
	 int x;
	 };

	 void func( st_y x )
	 {
	 cout << " ";
	 }
	 void func()
	 {
	 cout << " ";
	 }
	 }
	 */
//----------------------------------------------------
	/*
	 class Base {};
	 class Derived : public Base {
	 public:
	 ~Derived()
	 {
	 //delete this;
	 }
	 };

	 class test {
	 public:
	 test()
	 {
	 cout << "constuctor \n";
	 }
	 };
	 int main()
	 {
	 Derived d;

	 try {

	 throw d;
	 }


	 catch( Derived& d ) {
	 cout << "Caught Derived Exception";
	 }
	 catch( Base& b ) {
	 cout << "Caught Base Exception";
	 }


	 getchar();
	 return 0;
	 }
	 */
//----------------------------------------------------
	/*
	 int main( int argc,const char* argv[] )
	 {
	 AB::st_x x = {0};
	 //func( x );
	 //func();

	 A *ptr = new A();
	 B *ptrD = dynamic_cast <B*> (ptr);
	 ptrD->test();

	 std::vector<double> v{ 1.0, 2.2, 4.0, 5.5, 7.2 };
	 double r = 4.0;
	 std::for_each( v.begin(),v.end(),[&]( double & v )
	 { v += r; } );
	 std::for_each( v.begin(),v.end(),[]( double v ) { std::cout << v << " "; } );

	 /*
	 B* atr = NULL;
	 atr->test();*/
	//test();
	//f();
//int a = 7;
	//const int b = static_cast <int> (a);
	/*
	 A* obj = new D();
	 obj->foo();

	 */

	//B::start();
	//getchar();
	//return 0;
//}
// -----------------------------------------------------
	/*
	 class  MyClass
	 {
	 public:
	 MyClass() {}
	 ~MyClass() {}
	 virtual   void foo() { std::cout << "\n base"; }
	 private:

	 };
	 class My2:public MyClass
	 {
	 public:
	 // hide :  virtual  void foo() { std::cout << "\n base"; }
	 static void foo() { std::cout << "\n derived"; }// override
	 //int foo() { return 0; }

	 // usage

	 {
	 static My2 obj;
	 static My2 *pParent = new My2();
	 pParent->foo();
	 My2::foo();
	 }

	 };
	 */
// -----------------------------------------------------
	/*
	 class storable
	 {
	 public:
	 storable() {}
	 ~storable() {}
	 virtual void read() = 0;
	 virtual void write() {}
	 };


	 class transmitter : public virtual storable
	 {
	 void write() {}
	 };

	 class reciever : public virtual storable
	 {
	 public:
	 //reciever() {}
	 //virtual ~reciever() {}
	 void write() {}
	 void read() {}
	 };
	 // -----------------------------------------------------
	 struct my_struct
	 {
	 int a;
	 char b;
	 /*
	 my_struct obj;
	 my_struct * pObj = &obj;
	 int sz = sizeof( *pObj );
	 int sz1 = sizeof( pObj );

	 };

	 // -
	 // -----------------------------------------------------
	 */


	/*
	// c++ 20
	template <typename ... T>
	auto sum_variadic_template (const T& ... param)
	{
		return (param + ...);
	}*/

	void structure()
	{
		struct ABC {
			 int a;
			//ABC() :a{10} {};
			//ABC() :a( 10 ) {};
		};

		struct ABC objSt;
		struct ABC *ptrSt;
		struct ABC *ptrSt_1 = NULL;

		struct ABC *ptrSt_2 = new ABC;
		cout << ptrSt_2->a << endl;
		delete ptrSt_2;
	}
	int func_ret_0()
	{
		return 1;
	}
	void callee_check_return()
	{
		int rc = -1;
		if ((rc = func_ret_0()) > 0)
			cout << "rc is greater than zero" << endl;
		else
			cout << "rc is lesser than zero" << endl;

	}

	int main() {

		cout << "test::main()" << endl;

		/*transmitter trans;
		 reciever rec;*/

//		unique_ptr_demo();
//		conversion_ctr();
//		function_pointer();

		//cout << sum_variadic_template (1,2,3) << endl; // c++20

		//structure();
		callee_check_return();
		getchar();
		return 0;
	}

}

/*
int main() {
	test::main();
	return 0;
}
*/


