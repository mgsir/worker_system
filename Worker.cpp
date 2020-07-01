#ifndef WORKER_CPP
#define WORKER_CPP
#include<iostream>
#include<string>
using namespace std;

class Worker
{
  public:
    int id_;
    string name_;
    int postId_;

    virtual void showInfo_() = 0;
    virtual string getPost_() = 0;
};
#endif 


