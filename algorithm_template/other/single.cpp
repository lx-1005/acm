
// 懒汉1：类加载时不存在这个唯一对象，而调用static函数才创建，可以使用两次判空实现线程安全
// #include <bits/stdc++.h>

// using namespace std;

// class Singleton {
// public:
//     static Singleton* get() {
        // if (single == nullptr) {
        //     phread_mutex_lock(&lock);
        //     if (single == nullptr) single = new Singleton();
        //     pthread_mutex_unlock(&lock);
        // }
//         return single;
//     }

// private:
//     static pthread_mutex_t lock;
//     static Singleton* single;
//     Singleton() { cout << "ctor" << endl; }
// };
// pthread_mutex_t Singleton::lock ;
// Singleton* Singleton::single = nullptr;

// int main() {
//     Singleton::get();
//     Singleton::get();
//     Singleton::get();

//     return 0;
// }


// 懒汉2：调用static函数才创建一个local-static对象，线程安全(在一个线程执行到初始化语句时，会其他线程会阻塞，直到这个线程初始化完毕)
#include <bits/stdc++.h>

using namespace std;

class Singleton {
public:
    static Singleton* get() {
        static Singleton single; // C++11之后，无需加锁就可以保证局部static变量保证线程安全(一个线程执行这句时，其他线程会阻塞在这里)
        return &single;
    }

private:
    Singleton() { cout << "ctor" << endl; }
};


int main() {
    Singleton::get();
    Singleton::get();
    Singleton::get();

    return 0;
}




// 饿汉：non-local static变量在类加载的时候就创建好了(线程安全,non-local static对象在main执行前就创建了)
// 缺点：在于非静态对象（函数外的static对象）在不同编译单元中的初始化顺序是未定义的。如果在初始化完成之前调用 getInstance() 方法会返回一个未定义的实例。
// #include <bits/stdc++.h>

// using namespace std;

// class Singleton {
// public:
//     static* Singleton get() { return single; }
    
// private:
//     static Singleton* single;
//     Singleton() { cout << "ctor" << endl; }
// };

// Singleton Singleton::single;

// int main() {
//     Singleton::get();
//     Singleton::get();
//     Singleton::get();

//     return 0;
// }