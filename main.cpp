#include <iostream>
#include <vector>

using namespace std;

class observer;

class subject{
    int state;
    vector<observer *> observers;
    void notify();
public:
    void attach(observer *obs);
    void detach(observer *obs);

    int getState(){ return state;}
    void setState(int v){
        state = v;
        notify();
    }
};

class observer{
    subject *sub;
    int state;
    int id;

    public:
        observer(subject *s, int i);
        void update();
        int getId(){return id;};
};


void subject::attach(observer *obs) {
    observers.push_back(obs);
}

void subject::detach(observer *obs) {
   //observers.push_back(obs);
   cout<<"detach .."<<endl;
}

void subject::notify() {
    cout<<"Updating all the observers .. "<<endl;
    for(observer *o:observers){
        o->update();
    }

    /*for (int i = 0; i < observers.size(); i++){
        observers[i]->update();
        cout<<">>"<<observers[i]<<endl;
    }*/
}

observer::observer(subject *s, int i){
    sub = s;
    id = i;
    sub->attach(this);
}

void observer::update() {
    std::cout<<"Updating state of the observer "<<this->getId()<<" .. "<<std::endl;
    state = sub->getState();

}

int main()
{
    cout << "Hello world!" << endl;
    subject su;

    observer ob1(&su, 1);
    observer ob2(&su, 2);
    observer ob3(&su, 3);
    observer ob4(&su, 4);
    observer ob5(&su, 5);

    su.setState(15);

    return 0;
}
