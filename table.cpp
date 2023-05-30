#include<string>
#include<string.h>
#include<stdlib.h>
#include<cstring>
#include<iostream>
using namespace std;


class Menu
{
    public:
    Menu(int no_items)
    {
        items = no_items;
        string *menu = new string[no_items];
        int price = new int[no_items];
        string *quick_access = new string[no_items];
        cout<<"Enter food items follwed by price and quick access code for search"<<endl;
        for(int i = 0; i < no_items; i++)
        {
            cin.getline(menu[i]);
            cin>>price[i];
            cin.getline(quick_access[i])
        } 
    }

    protected:
    string *menu = new string[];
    int price[];
    string *quick_access = new string[];
    int items;
};


class Table : public Menu
{
    public:
    short capacity;
    bool vacancy;
    string *order[];
    short qty[];
    int sub_bill[];
    int bill = 0;
    k = 0;
    Table(short capacity){
        this->capacity = capacity;
        this->vacancy = 1;
        for(int i = 0;i < 20;i++)
        {
            this->order[i] = new char[30];
        }
    }


    void book_table()
    {
        this->vacancy = 0;
    }

    void make_vacancy()
    {
        this->vacancy = 1;
    }

    void add_order(string str)
    {
        bool flag1 = 1;
        bool flag2 = 0;
        for(int i = 0; i < Menu::items; i++)
        {
            if(!strcmp(str, Menu::menu[i]))
            {
                for(int j = 0;j < k; j++)
                    if(!strcmp(str, order[j]))
                        qty[j]++;
            }
            
        }
    }

};