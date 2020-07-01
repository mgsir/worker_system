#include<iostream>
#include<fstream>
#include"Employee.cpp"
#include"Manager.cpp"
#include"Boss.cpp"
#define  TEST_FILE "test.txt"
using namespace  std;

class  WorkerManager 
{

  void addToDisk_()
  {
    ofstream ofile(TEST_FILE,ios::app | ios::out);

    if(!ofile.is_open()) 
    {
      cout<<"不能打开文件\n";
      exit(0);
    }

    for(int i = 0; i < num_; ++i)
    {
      ofile <<arrWorkerSet_[i]->name_ <<" "<<arrWorkerSet_[i]->id_<<" "<<arrWorkerSet_[i]->postId_<<" "<<arrWorkerSet_[i]->getPost_()<<endl;
    }
  }

  public:
  int num_;
  Worker ** arrWorkerSet_;
  bool notContent = true;

  WorkerManager()
  {
    ifstream ifile(TEST_FILE,ios::in);

    if(!ifile.is_open())
    {
      num_ = 0;
      arrWorkerSet_ = nullptr;
      notContent = true;
      ifile.close();
      return;
    }

    else
    {
      char ch;
      ifile >> ch;

      if(ifile.eof())
      {
        cout<<"文件为空\n";
        num_ = 0;
        arrWorkerSet_ = nullptr;
        notContent = true;
        ifile.close();

        return;
      }

      num_ = 0;
      arrWorkerSet_ = new Worker *[100];
      diskToArr_();
    }
  }

  void getNum_()
  {
    cout<<"人数："<<num_<<"\n";
  }
  void diskToArr_()
  {
    ifstream ifile(TEST_FILE,ios::in);
    if(!ifile.is_open()) 
    {
      cout<<"文件打开失败\n";
    }

    string name;
    int id;
    int postId;
    int index = 0;
    string post;

    while(ifile>>name&& ifile>> id && ifile >> postId && ifile >> post)
    {
      if(postId == 3)
      {
        arrWorkerSet_[index++] = new Boss(id,name,postId);
      }

      else if(postId ==2)
      {
        arrWorkerSet_[index++] = new Manager(id,name,postId);
      }

      else if(postId == 1) 
      {
        arrWorkerSet_[index++] = new Employee(id,name,postId);
      }
      else 
      {
        cout << "职位信息有误\n";
      }
    }

    num_ =index;
    ifile.close();
  }


  ~WorkerManager()
  {
    delete [] arrWorkerSet_;  
    num_ = 0;
  }

  void ShowMenu_()
  {

    cout<<"****************************"<<endl;
    cout<<"*********0.推出程序****************"<<endl;
    cout<<"*********1.增加职工信息*****************"<<endl;
    cout<<"*********2.显示职工信息*****************"<<endl;
    cout<<"*********3.删除离职信息******************"<<endl;
    cout<<"*********4.查找职工信息******************"<<endl;
    cout<<"*********5.修改职工信息******************"<<endl;
    cout<<"*********6.按编号排序******************"<<endl;
    cout<<"**********7.清空所有文档******************"<<endl;
    cout<<endl;
  }

  void showInf_()
  {
    if(num_ <= 0)
    {
      cout<<"无信息\n";
    }
    for(int i = 0; i < num_; ++i)
    {
      arrWorkerSet_[i]->showInfo_();
    }
    system("read");
    system("clear");
  }

  void addWorker()
  {
    int num;
    cout<<"要增加的成员数量\n";
    cin>>num;
    int  num_1 = num_;
    num_ += num;
    Worker ** workerSet = new Worker *[num_];

    if(num > 0)
    {
      int id;
      string name;
      int postId;
      int count = 0;

      while(true)
      {
        if(count == num) break;

        cout<<"请输入id\n";
        cin>>id;
        cout<<"请输入姓名\n";
        cin>>name;
        cout<<"请输入岗位编号\n";
        cin >> postId;

        cout<<"请选择岗位类型\n";
        cout<<"1.普通员工\n";
        cout<<"2.经理\n";
        cout<<"3.老板\n";
        int select = 0;
        cin >> select;

        switch(select)
        {
          case 1:
            workerSet[count++] = new Employee(id,name,postId);
            break;
          case 2:
            workerSet[count++] = new Manager(id,name,postId);
            break;
          case 3:
            workerSet[count++] = new Boss(id,name,postId);
            break;

          default:
            break;
        }

      }

      if(arrWorkerSet_ == nullptr)
      {
        arrWorkerSet_ = workerSet;
      }

      else 
      {
        for(int i = 0; i < num; ++i)
        {
          workerSet [num_1 + i]= arrWorkerSet_[i];
        }
        arrWorkerSet_ = workerSet;
      }

      this->addToDisk_();
      notContent = false;
      cout<<"增加成功\n";
    }
    else 
    {
      cout<<"输入有误\n";
    }

    system("read");
    system("clear");

  }

  
  void  deleteWorker_()
  {
    diskToArr_();

    while(1)
    {
    int id;
    cout<<"请输入id\n";
    cin >> id;
    if(id == 0)
    {
      cout<<"已退出\n";
      return;
        system("read");
        system("clear");
    }

    for(int i = 0; i < num_; ++i)
    {
      if(arrWorkerSet_[i]->id_ == id )
      {
        Worker **workerSet = new Worker* [num_-1];

        int count = 0;
        for(int j = 0; j < num_; ++j)
        {
          if(j == i) 
          {
            delete arrWorkerSet_[j];
            continue;
          }
          else 
          {
            workerSet[count++] = arrWorkerSet_[j];
          }
        }

        arrWorkerSet_ = workerSet;

        num_--;
        
        cout<<"删除成功\n";
        cout<<"还有继续删除吗\n";
        cout<<"1继续，其他建退出\n";

        int conti;
        cin >> conti;
        if(conti == 1)
        {
          break;
          return;
        }
        else 
        {
          system("read");
          system("clear");
          return;
        }
        break;
      }
    }

    cout<<"员工不存在,请重新输入,按0强制推出\n";
  }
  }

  void findWorker_()
  {

    diskToArr_();

    while(1)
    {
    int id;
    cout<<"请输入id\n";
    cin >> id;
    if(id == 0)
    {
      return;
    }

    for(int i = 0; i < num_; ++i)
    {
      if(arrWorkerSet_[i]->id_ == id)
      {
        arrWorkerSet_[i]->showInfo_();
        system("read");
        system("clear");
      }
    }

    cout<<"不能找到,请继续输入id,按0强制退出\n";

    }

  }

  
  int isExist( int id )
  {
    for(int i = 0; i < num_; ++i)
    {
      if(arrWorkerSet_[i]->id_ == id)
      {
        return i;
      }
    }
    return -1;
  }


  void  updataWork_()
  { 
    cout<<"输入要修改员工对应的id\n";
    int id;
    cin >> id;
    int pos = isExist(id);
    if(pos != -1)
    {
      string name;
      int id;
      int postId; 

      cout<<"新姓名：\n";
      cin >> name;
      cout<<"新id\n";
      cin >> id;
      cout<<"新postId\n";
      cin>>postId;

      int select = 0;
      
      cout<<"请输入员工职位\n";
      cout<<"1.普通员工\n2.经理\n3.老板\n";
      Worker *worker = nullptr;

      switch(select)
      {
        case 1:
          worker =  new Employee(id,name,postId);
          break;

        case 2:
          worker = new Manager(id,name,postId);
          break;

        case 3:
          worker = new Boss(id,name,postId);
          break;
        default:
          break;
      }

      arrWorkerSet_[pos] = worker;

    }
    else 
    {
      cout<<"不存在此员工\n";
      system("read");
      system("clear");
    }

  }

  void clearFile_()
  {
    ofstream ofile(TEST_FILE,ios::out | ios::trunc);
    if(!ofile.is_open())
    {
      cout<<"不能打开文件\n";
    }
    num_ = 0;
    arrWorkerSet_ = nullptr;
    cout<<"清理成功\n";
    system("read");
    system("clear");
  }

};

