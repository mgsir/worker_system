#include<iostream>
#include<string>
using namespace std;

class Manager:public Worker
{
  public:
    Manager(int id, string name, int postId)
    {
      id_ = id;
      postId_ = postId;
      name_ = name;
    }



    virtual string getPost_()
    {
      return string("经理");
    }

    virtual void showInfo_()
    {
      cout<<"信息:\n";
      cout<<"\t职位："<<getPost_()<<endl;
      cout<<"\t岗位id:"<<postId_<<endl;
      cout<<"\t职工id:"<<id_<<endl;
      cout<<"\t姓名:"<<getPost_()<<endl;
    }
};

