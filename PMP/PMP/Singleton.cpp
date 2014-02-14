#pragma once

#include <iostream>

using namespace std;

class Singleton
{
private:
  static bool instanceFlag;
  static Singleton *single;
  Singleton()  {
    //private constructor
  }
public:
  static Singleton* getInstance();
  void method();
  ~Singleton()  {
    instanceFlag = false;
  }
};

bool Singleton::instanceFlag = false;
Singleton* Singleton::single = NULL;
Singleton* Singleton::getInstance()
{
  if(! instanceFlag)  {
    single = new Singleton();
    instanceFlag = true;
    return single;
  } else {
    return single;
  }
}

void Singleton::method()
{
  cout << "Method of the singleton class" << endl;
}

