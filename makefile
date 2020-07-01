main:main.cpp WorkerManager.o Worker.o Employee.o Boss.o
	g++ -g main.cpp WorkerManager.o  Worker.o  Employee.o  Boss.o -o main

Worker.o:Worker.cpp
	g++ -c Worker.cpp
Employee.o:Employee.cpp
	g++ -c Employee.cpp

Manager.o:Manager.cpp
	g++ -c Manager.cpp
Boss.o:Boss.cpp
	g++ -c Boss.cpp
WorkerManager.o:WorkerManager.cpp
	g++ -c WorkerManager.cpp

clean:
	rm *.o main
