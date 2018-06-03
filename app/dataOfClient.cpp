#include "dataOfClient.h"

Bank::Bank(int a,string str,int x,int y)
{
    id=a;
    name=str;
    count=x;
    sum=y;
}

void Bank::showConsole()const
{
    cout <<"|"<<id<<setw(4)<<")"<<setw(22)<<name<<setw(18)<<count<<setw(9)<<sum<<setw(5)<<"$"<<"|"<<endl;
}

void menu::inPut(std::list<Bank>& b)
{
    ifstream file("list.txt");
    int line=checkLine();
    int a,c,d;
    string str;
    while (line)
    {
        file>>a>>str>>c>>d;
        b.push_back(Bank(a,str,c,d));
        line--;
    }
}

int menu::checkLine()
{
    ifstream file("list.txt");
    string buff;
    getline(file,buff,'\0');
    int line=0;
    int i=0;
    while (buff[i]!='\0')
    {
        if (buff[i]=='\n')
        {
            line++;
        }
        i++;
    }
    return line;
}

void menu::outPut(std::list<Bank> b)
{
    system("cls");
    list <Bank>::iterator First;
    First=b.begin();
    beom();
    while(First!=b.end())
    {
        (*First++).showConsole();
    }
    cout <<"+-----------------------------------------------------------+"<<endl;

    getchar();
    system("cls");
}

void menu::beom()const
{
    cout <<"+-----------------------------------------------------------+"<<endl;
    cout <<"|№ |     Name      |  Count of investing  |  Count of money |"<<endl;
    cout <<"+-----------------------------------------------------------+"<<endl;
}

void menu::addLast(std::list<Bank>& b)
{
    string str;
    int a,c;
    cout <<"Name\n";
    cin >>str;
    cout <<"Count\n";
    cin >>a;
    cout <<"Money\n";
    cin >>c;
    b.push_back(Bank(checkLine()+1,str,a,c));
    getchar();
    system("cls");
}

void menu::addList(std::list<Bank>& b)
{
    list <Bank>::iterator First;
    First=b.begin();
    int i=0,index;
    cout <<"The enter ID after add new data :";
    cin >>index;
    while (First!=b.end())
    {
        i++;
        (*First++);
        if (index+1==i)
        {
            break;
        }
    }
    string str;
    int a,c;
    cout <<"Name\n";
    cin >>str;
    cout <<"Count\n";
    cin >>a;
    cout <<"Money\n";
    cin >>c;
    b.insert(First,Bank(index,str,a,c));
    getchar();
    system("cls");
}

void menu::addPosle(std::list<Bank>& b)
{
    list <Bank>::iterator First;
    First=b.begin();
    int i=0,index;
    cout <<"The enter ID before add new data :";
    cin >>index;
    while (First!=b.end())
    {
        if (index-1==i)
        {
            break;
        }
        i++;
        (*First++);

    }
    string str;
    int a,c;
    cout <<"Name\n";
    cin >>str;
    cout <<"Count\n";
    cin >>a;
    cout <<"Money\n";
    cin >>c;
    b.insert(First,Bank(index,str,a,c));
    getchar();
    system("cls");
}
void menuShow()
{
    cout <<setiosflags(ios::left);
    cout <<"+------------------------------------------+"<<endl;
    cout <<"|                  Menu                    |"<<endl;
    cout <<"+------------------------------------------+"<<endl;
    cout <<"|"<<setw(42)<<"0)Exit and save"<<"|"<<endl;
    cout <<"|"<<setw(42)<<"1)Show all records"<<"|"<<endl;
    cout <<"|"<<setw(42)<<"2)Add new record"<<"|"<<endl;
    cout <<"|"<<setw(42)<<"3)Dell records"<<"|"<<endl;
    cout <<"|"<<setw(42)<<"4)Change record"<<"|"<<endl;
    cout <<"|"<<setw(42)<<"5)The average"<<"|"<<endl;
    cout <<"|"<<setw(42)<<"6)Maximum and minimum"<<"|"<<endl;
    cout <<"|"<<setw(42)<<"7)Sorting"<<"|"<<endl;
    cout <<"+------------------------------------------+"<<endl;
    //cout <<setiosflags(ios::right);
}

void menu::start()
{
    list <Bank> b;
    inPut(b);
    int touch;
    do
    {
        sort(b);
        menuShow();
        cin >>touch;
        switch (touch)
        {
            case 1:
                outPut(b);
                break;
            case 2:
                add(b);
                break;
            case 3:
                del(b);
                break;
            case 4:
                edit(b);
                break;
            case 5:
                searchMid(b);
                break;
            case 6:
                maxMin(b);
                break;
            case 7:
                sortOf(b);
                break;
            case 0:
                system("cls");
                cout <<"Good buy)";
                break;
            default:
                cout <<"Incorrect value";
                exit(1);
                break;
        }
    }while(touch);

    endWork(b);
}

void menu::add(std::list<Bank>& b)
{
    system("cls");
    cout <<"Add\n1)Add in last\n2)Add after \n3)Add before\n";
    int touch;
    cin >>touch;
    switch (touch)
    {
        case 1:
            addLast(b);
            break;
        case 2:
            addList(b);
            break;
        case 3:
            addPosle(b);
            break;
        default:
            break;
    }
}

void menu::del(std::list<Bank>& b)
{
    list <Bank>::iterator First;
    system("cls");
    cout <<"Need ID for dell:";
    int touch,i=1;
    int check=0;
    cin >>touch;
    First=b.begin();
    while(First!=b.end())
    {

        if (i==touch)
        {
            check++;
            break;
        }
        i++;
        (*First++);
    }
    if (check)
    {
        beom();
        (*First).showConsole();
        First=b.erase(First);
    }
    else
    {
        cout <<"Unknown ID\n";
    }
    getchar();
    system("cls");
}

void Bank::setId(int x)
{
    id=x;
}

int Bank::getId()const
{
    return id;
}

void Bank::setName(string str)
{
    name=str;
}

void Bank::setCount(int x)
{
    count=x;
}

void Bank::setSum(int x)
{
    sum=x;
}

int Bank::getCount()const
{
    return count;
}

int Bank::getSum()const
{
    return sum;
}

string Bank::getName()const
{
    return name;
}

void menu::sort(std::list<Bank>&b)
{
    list <Bank>::iterator Head;
    list <Bank>::iterator Last;
    Head=b.begin();
    Last=b.begin();
    int line =checkLine();
    int i=1;
    for (Head;Head!=b.end();(*Head++))
    {
        (*Head).setId(i);
        i++;
    }
}

void menu::edit(std::list<Bank>& b)
{
    list <Bank>::iterator First;
    system("cls");
    First=b.begin();
    cout <<"Enter the ID for change data:"<<endl;
    int touch;
    cin >>touch;
    advance(First,touch-1);
    beom();
    (*First).showConsole();
    cout <<"\n\nWhat do you want change ?\n1)Name\n2)Count\n3)Money\n";
    cin >>touch;
    string str;
    switch (touch)
    {
        case 1:
            cout <<"Enter the new name:";
            cin >>str;
            (*First).setName(str);
            break;
        case 2:
            cout <<"Enter the new count\n";
            cin >>touch;
            (*First).setCount(touch);
            break;
        case 3:
            cout <<"Enter the new money\n";
            cin >>touch;
            (*First).setSum(touch);
        default:
            break;
    }
    system("cls");
    beom();
    (*First).showConsole();
    getchar();
    system("cls");
}

void menu::searchMid(std::list<Bank>& b)
{
    list <Bank>::iterator First;
    First=b.begin();
    system("cls");
    beom();
    while(First!=b.end())
    {
        (*First++).showConsole();
    }
    cout <<"Average\n1)Count\n2)Money"<<endl;
    int touch;
    cin >>touch;
    int count=0,del=0;
    First=b.begin();
    switch (touch)
    {
        case 1:
            while(First!=b.end())
            {
                count+=(*First++).getCount();
                del++;
            }
            break;
        case 2:
            while(First!=b.end())
            {
                count+=(*First++).getSum();
                del++;
            }
            break;
        default:
            cout <<"Unknown ID"<<endl;
            break;
    }
    system("cls");
    beom();
    First=b.begin();
    while(First!=b.end())
    {
        (*First++).showConsole();
    }
    if (touch==1)
    {
        cout <<"\n\nAverage of counts="<<(float)count/del<<endl;
    }
    if (touch==2)
    {
        cout <<"\n\nAverage of money="<<count/del<<"$"<<endl;
    }
    getchar();
    system("cls");
}

void menu::maxMin(std::list<Bank>& b)const
{
    list <Bank>::iterator First;
    First=b.begin();
    system("cls");
    cout <<"The enter choice\n1)Max\n2)Min\n";
    int touch,max,min;
    cin >>touch;
    if (touch==1)
    {
        cout <<"Max\n1)Count\n2)Money\n";
        cin >>touch;
        if (touch==1)
        {
            max=(*First).getCount();
            while(First!=b.end())
            {
                if(max < (*First).getCount())
                {
                    max=(*First).getCount();
                }
                *First++;
            }
            system("cls");
            beom();
            First=b.begin();
            while(First!=b.end())
            {
                (*First++).showConsole();
            }
            cout <<"Max of count:"<<max<<endl;;
            getchar();
            system("cls");
        }
        if (touch==2)
        {
            max=(*First).getSum();
            while(First!=b.end())
            {
                if(max < (*First).getSum())
                {
                    max=(*First).getSum();
                }
                *First++;
            }
            system("cls");
            First=b.begin();
            beom();
            while(First!=b.end())
            {
                (*First++).showConsole();
            }
            cout <<"Max of money:"<<max<<"$"<<endl;;
            getchar();
            system("cls");
        }


    }
    if (touch==2)
    {
        cout <<"Min ?\n1)Count\n2)Money\n";
        cin >>touch;
        if (touch==1)
        {
            min=(*First).getCount();
            while(First!=b.end())
            {
                if(min> (*First).getCount())
                {
                    min=(*First).getCount();
                }
                *First++;
            }
            system("cls");
            beom();
            First=b.begin();
            while(First!=b.end())
            {
                (*First++).showConsole();
            }
            cout <<"\n\nMin of count:"<<min<<endl;;
            getchar();
            system("cls");
        }
        if (touch==2)
        {
            min=(*First).getSum();
            while(First!=b.end())
            {
                if(min > (*First).getSum())
                {
                    min=(*First).getSum();
                }
                *First++;
            }
            system("cls");
            First=b.begin();
            beom();
            while(First!=b.end())
            {
                (*First++).showConsole();
            }
            cout <<"\n\nMin of money:"<<min<<"$"<<endl;;
            getchar();
            system("cls");
        }
    }

}

void menu::endWork(std::list<Bank>&b)
{
    ofstream file("list.txt");
    list <Bank>::iterator First;
    First=b.begin();
    while (First!=b.end())
    {
        file<<(*First).getId()<<" "<<(*First).getName()<<" "<<(*First).getCount()<<" "<<(*First).getSum()<<"\n";
        (*First++);
    }
    file.close();
}

void menu::sortOf(std::list<Bank>& b)
{
    list <Bank>::iterator Head;
    list <Bank>::iterator Last;
    Last=b.begin();
    Head=b.begin();
    advance(Head,1);
    system("cls");
    srand(time(NULL));
    int random=rand()%10;
    cout <<"Sorting by..\n1)Name\n2)Count\n3)Money\n";
    int touch;
    cin >>touch;
    switch (touch)
    {
        case 1:
            if (random < 5)
            {
                for (Head;Head!=b.end();(*Head++))
                {
                    for (Last;Last!=b.end();(*Last++))
                    {
                        if ((*Head).getName()>(*Last).getName())
                        {
                            string str=(*Head).getName();
                            (*Head).setName((*Last).getName());
                            (*Last).setName(str);
                            int buf1=(*Head).getCount();
                            (*Head).setCount((*Last).getCount());
                            (*Last).setCount(buf1);
                            int buf2=(*Head).getSum();
                            (*Head).setSum((*Last).getSum());
                            (*Last).setSum(buf2);
                        }
                    }
                    Last=b.begin();
                }
            }
            else
            {
                for (Head;Head!=b.end();(*Head++))
                {
                    for (Last;Last!=b.end();(*Last++))
                    {
                        if ((*Head).getName()<(*Last).getName())
                        {
                            string str=(*Head).getName();
                            (*Head).setName((*Last).getName());
                            (*Last).setName(str);
                            int buf1=(*Head).getCount();
                            (*Head).setCount((*Last).getCount());
                            (*Last).setCount(buf1);
                            int buf2=(*Head).getSum();
                            (*Head).setSum((*Last).getSum());
                            (*Last).setSum(buf2);
                        }
                    }
                    Last=b.begin();
                }
            }
            break;
        case 2:
            if (random < 5)
            {
                for (Head;Head!=b.end();(*Head++))
                {
                    for (Last;Last!=b.end();(*Last++))
                    {
                        if ((*Head).getCount()>(*Last).getCount())
                        {
                            string str=(*Head).getName();
                            (*Head).setName((*Last).getName());
                            (*Last).setName(str);
                            int buf1=(*Head).getCount();
                            (*Head).setCount((*Last).getCount());
                            (*Last).setCount(buf1);
                            int buf2=(*Head).getSum();
                            (*Head).setSum((*Last).getSum());
                            (*Last).setSum(buf2);
                        }
                    }
                    Last=b.begin();
                }
            }
            else
            {
                for (Head;Head!=b.end();(*Head++))
                {
                    for (Last;Last!=b.end();(*Last++))
                    {
                        if ((*Head).getCount()<(*Last).getCount())
                        {
                            string str=(*Head).getName();
                            (*Head).setName((*Last).getName());
                            (*Last).setName(str);
                            int buf1=(*Head).getCount();
                            (*Head).setCount((*Last).getCount());
                            (*Last).setCount(buf1);
                            int buf2=(*Head).getSum();
                            (*Head).setSum((*Last).getSum());
                            (*Last).setSum(buf2);
                        }
                    }
                    Last=b.begin();
                }
            }
            break;
        case 3:
            if (random < 5)
            {
                for (Head;Head!=b.end();(*Head++))
                {
                    for (Last;Last!=b.end();(*Last++))
                    {
                        if ((*Head).getSum()>(*Last).getSum())
                        {
                            string str=(*Head).getName();
                            (*Head).setName((*Last).getName());
                            (*Last).setName(str);
                            int buf1=(*Head).getCount();
                            (*Head).setCount((*Last).getCount());
                            (*Last).setCount(buf1);
                            int buf2=(*Head).getSum();
                            (*Head).setSum((*Last).getSum());
                            (*Last).setSum(buf2);
                        }
                    }
                    Last=b.begin();
                }
            }
            else
            {
                for (Head;Head!=b.end();(*Head++))
                {
                    for (Last;Last!=b.end();(*Last++))
                    {
                        if ((*Head).getSum()<(*Last).getSum())
                        {
                            string str=(*Head).getName();
                            (*Head).setName((*Last).getName());
                            (*Last).setName(str);
                            int buf1=(*Head).getCount();
                            (*Head).setCount((*Last).getCount());
                            (*Last).setCount(buf1);
                            int buf2=(*Head).getSum();
                            (*Head).setSum((*Last).getSum());
                            (*Last).setSum(buf2);
                        }
                    }
                    Last=b.begin();
                }
            }
        default:
            break;
    }
    cout <<"Sorting was successful"<<endl;
    getchar();
    system("cls");
}