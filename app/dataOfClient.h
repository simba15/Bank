//
// Created by alx on 6/2/18.
//


#include <list>
#include <string>
#include <iomanip>
#include <fstream>
#include <locale>
#include <time.h>
#include <cstdlib>
#include <iterator>
#include <iostream>
using namespace std;
#ifndef DATAOFCLIENT_H
#define DATAOFCLIENT_H


class Bank {
private :
    int id;
    string name;
    int count;
    int sum;
public :
    Bank (int , string , int ,int);
    void showConsole()const;
    void setId(int);
    void setName(string);
    void setCount(int);
    void setSum(int);
    int getId()const;
    string getName()const;
    int getCount()const;
    int getSum()const;

};

class menu
{
public:
    void inPut(std::list<Bank>& );
    void outPut(std::list<Bank>);
    void add(std::list<Bank>&);
    void addList(std::list<Bank>&);
    void addPosle(std::list<Bank>&);
    void addLast(std::list<Bank>&);
    void beom()const;
    void del(std::list<Bank>&);
    int checkLine();
    void edit(std::list<Bank>&);
    void sort(std::list<Bank>&);		//
    void searchMid(std::list<Bank>&);	//
    void maxMin(std::list<Bank>&)const;
    void sortOf(std::list<Bank>&);
    void endWork(std::list<Bank>&);
    void start();

};

#endif
