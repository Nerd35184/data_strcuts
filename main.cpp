#include<iostream>
#include<vector>
#include<cstdio>
#include<list>
using namespace std;



class Tester{
    public:
    ~Tester(){
        printf("~Tester\n");
    };  

};

int main(){
    vector<Tester> v1;
    list<Tester*> l1;
    Tester t1;
    v1.push_back(t1);
    v1.pop_back();
    printf("----------------\n");
    l1.push_back(&t1);
    l1.erase(l1.begin(),l1.end());
    printf("----------------\n");
}