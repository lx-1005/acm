#include <bits/stdc++.h>

using namespace std;

// shared_ptr的实现
template <typename T>
class SharedPtr {
private:
    T* _ptr;
    int* _pcount;
public:
    SharedPtr(T* ptr = nullptr) : _ptr(ptr) { // ctor
        if (_ptr) _pcount = new int(1); // 初始化引用计数为1
        else _pcount = new int(0);
    }

    ~SharedPtr() { // dtor
        if (--(*_pcount) == 0) {
            delete _ptr;
            delete _pcount;
            _ptr = _pcount = nullptr;
        }
    }

    SharedPtr(const SharedPtr& s) : _ptr(s._ptr), _pcount(s._pcount) { // copy ctor
        (*_pcount)++;
    }

    SharedPtr& operator=(const SharedPtr<T>& s) { // copy assign: 左减右加
        if (this != &s) {// 检测自赋值
            if (--(*_pcount) == 0) {
                delete _ptr;
                delete _pcount;
            }
            _ptr = s._ptr;
            _pcount = s._pcount;
            (*_pcount)++;
        }

        return *this;
    }

    T& operator*() const {
        return *_ptr;
    }

    T* operator->() const {
        return _ptr;
    }

    size_t use_count(){
        return *_pcount;
    }
};

int main() {
    // 测试shared_ptr
    SharedPtr<int> sp1(new int(20));
    cout << "*sp1=" << *sp1 << ' ' << "sp1计数=" << sp1.use_count() << endl;

    SharedPtr<int> sp2(sp1);
    cout << "*sp1=" << *sp1 << ' ' << "sp1计数=" << sp1.use_count() << endl;
    cout << "*sp2=" << *sp2 << ' ' << "sp2计数=" << sp2.use_count() << endl;

    SharedPtr<int> sp3(new int(30));
    cout << "*sp1=" << *sp1 << ' ' << "sp1计数=" << sp1.use_count() << endl;
    cout << "*sp2=" << *sp2 << ' ' << "sp2计数=" << sp2.use_count() << endl;
    cout << "*sp3=" << *sp3 << ' ' << "sp3计数=" << sp3.use_count() << endl;

    sp2 = sp3;
    cout << "*sp1=" << *sp1 << ' ' << "sp1计数=" << sp1.use_count() << endl;
    cout << "*sp2=" << *sp2 << ' ' << "sp2计数=" << sp2.use_count() << endl;
    cout << "*sp3=" << *sp3 << ' ' << "sp3计数=" << sp3.use_count() << endl;

	return 0;
}


// 循环引用实例:
// #include <iostream>
// #include <memory>

// using namespace std;

// template <typename T>
// class Node {
// public:
//     shared_ptr<Node<T>> _pPre, _pNext;
//     T _value;

//     Node(const T& value) : _pPre(NULL), _pNext(NULL), _value(value) {
//         cout << "Node(int)" << endl;
//     }

//     ~Node() {
//         cout << "~Node()" << endl;
//         cout << "this:" << this << endl;
//     }

// };


// int main() {
//     weak_ptr<Node<int>> wp1, wp2; // 便于作用域外查看sp1,sp2的引用计数
//     {
//         shared_ptr<Node<int>> sp1(new Node<int>(1));
//         shared_ptr<Node<int>> sp2(new Node<int>(2));

//         cout << "sp1.use_count:" << sp1.use_count() << endl; // 1
//         cout << "sp2.use_count:" << sp2.use_count() << endl; // 1

//         sp1->_pNext = sp2;
//         sp2->_pPre = sp1;

//         cout << "sp1.use_count:" << sp1.use_count() << endl; // 2
//         cout << "sp2.use_count:" << sp2.use_count() << endl; // 2

//         wp1 = sp1, wp2 = sp2;
//     }

//     // 形成循环引用
//     cout << "sp1.use_count:" << wp1.use_count() << endl; // 1
//     cout << "sp2.use_count:" << wp2.use_count() << endl; // 1

//     return 0;
// }

// 解决
// #include <iostream>
// #include <memory>

// using namespace std;

// template <typename T>
// class Node {
// public:
//     shared_ptr<Node<T>> _pPre;
//     weak_ptr<Node<T>> _pNext; // 把其中一个换成weak_ptr即可破局
//     T _value;

//     Node(const T& value) : _pPre(NULL), _value(value) {
//         cout << "Node(T)" << endl;
//     }

//     ~Node() {
//         cout << "~Node()" << endl;
//     }

// };


// int main() {
//     weak_ptr<Node<int>> wp1, wp2; // 便于作用域外查看sp1,sp2的引用计数
//     {
//         shared_ptr<Node<int>> sp1(new Node<int>(1));
//         shared_ptr<Node<int>> sp2(new Node<int>(2));

//         cout << "sp1.use_count:" << sp1.use_count() << endl; // 1
//         cout << "sp2.use_count:" << sp2.use_count() << endl; // 1

//         sp1->_pNext = sp2;
//         sp2->_pPre = sp1;

//         cout << "sp1.use_count:" << sp1.use_count() << endl; // 2
//         cout << "sp2.use_count:" << sp2.use_count() << endl; // 1

//         wp1 = sp1, wp2 = sp2;
//     }

//     // 成功
//     cout << "sp1.use_count:" << wp1.use_count() << endl; // 0
//     cout << "sp2.use_count:" << wp2.use_count() << endl; // 0

//     return 0;
// }



/* 实现2
 * /