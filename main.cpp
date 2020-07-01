#include<iostream>
#include"neededHeader.h"

int main()
{
  WorkerManager manager;

   while(true) 
   {
      manager.ShowMenu_();  

      int select = 0;

      cin >> select;

      switch(select)
      { 
        case 0: //退出
          cout<<"欢迎下次使用"<<endl;
          system("read");
          exit(0);
          break;
        case 1: 
          manager.addWorker();
          break;
        case 2:
          manager.getNum_();
          manager.showInf_();
          break;
        case 3:
          manager.deleteWorker_();
          break;
        case 4:
          manager.findWorker_();
          break;
        case 5:
          manager.updataWork_();
          break;
        case 6:

          break;
        case 7:
          manager.clearFile_();
          break;

        default:
          system("clear");
          break;
      }
      
   }
  


}
