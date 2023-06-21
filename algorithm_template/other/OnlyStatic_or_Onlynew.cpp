#include <bits/stdc++.h>

using namespace std;

// 类只能动态分配
class A {
private:

protected: // 既可以防止外部访问用于静态分配, 又可以让成员函数以及派生类的成员函数访问到
    A() { cout << "A()" << endl; }
    ~A() { cout << "~A()" << endl; }
    
public:  // 外部通过这两个接口创建和释放类对象
    static A* creat() { return new A(); } // 可以访问到A()
    void destroy() { delete this; }// 可以访问到~A()

};

// 类只能静态分配
class B {
private:
    void* operator new(size_t n) { return malloc(n); }
    void operator delete(void* ptr) { free(ptr); }

protected:
    
    
public:
    B() { cout << "B()" << endl; }
    ~B() { cout << "~B()" << endl; }

};

int main() { 
    // A a; // 访问不到构造函数
    A* p1 = A::creat();
    p1->destroy();

    B b;
    // B* p2 = new B(); // 访问不到operator new


    return 0;
}
