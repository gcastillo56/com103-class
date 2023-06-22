#include <iostream>
#include <set>

using namespace std;

// ---------------- Observer interface -----------------
class MyObserver {
    public:
        virtual void Notify() = 0;
};

// ---------------- Observable object -------------------
class MyObservable {
        static MyObservable* instance;
        set<MyObserver*> observers;
        MyObservable() { };
    public:
       static MyObservable* GetInstance();
       void AddObserver(MyObserver& o);
       void RemoveObserver(MyObserver& o);
       void NotifyObservers();
       void Trigger();
};

MyObservable* MyObservable::instance = NULL;

MyObservable* MyObservable::GetInstance() {
    if ( instance == NULL ) {
       instance = new MyObservable();
    }
    return instance;
}

void MyObservable::AddObserver(MyObserver& o) {
    observers.insert(&o);
}

void MyObservable::RemoveObserver(MyObserver& o) {
    observers.erase(&o);
}

void MyObservable::NotifyObservers() {
    set<MyObserver*>::iterator itr;
    for ( itr = observers.begin();
          itr != observers.end(); itr++ )
    (*itr)->Notify();
}

// IN THE REAL SCENARIO THIS IS NOT REQUIRED
void MyObservable::Trigger() {
    NotifyObservers();
}

// ------ Concrete class interested in notifications ---
class MyClass : public MyObserver {

        MyObservable* observable;

    public:
       MyClass() {
          observable = MyObservable::GetInstance();
          observable->AddObserver(*this);
       }

       ~MyClass() {
          observable->RemoveObserver(*this);
       }

       void Notify() {
            cout << "Received a change event" << endl;
       }
};

void main() {
    MyObservable* observable = MyObservable::GetInstance();
    MyClass* obj = new MyClass();
    observable->Trigger();
}
