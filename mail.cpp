#include<iostream>
#include "mail.h"
#include <stdlib.h>
#include <sstream>

using namespace std;

mail::mail()
{
    head = NULL;
    tail = NULL;
}

mail::~mail()
{
    //dtor
}

void mail::build(){

    mailservice *y = new mailservice;
    y->cityname= "Los Angeles";
    y->next = NULL;
    y->previous = NULL;
    head = y;

    mailservice *n1 = new mailservice;
    n1->cityname = "Phoenix";
    n1->next= NULL;
    n1->previous = y;
    y->next = n1;

    mailservice *n2 = new mailservice;
    n2->cityname = "Denver";
    n2->next = NULL;
     n2->previous = n1;
    n1->next = n2;

    mailservice *n3 = new mailservice;
    n3->cityname = "Dallas";
    n3->next = NULL;
    n3->previous = n2;
    n2->next = n3;

    mailservice *n4 = new mailservice;
    n4->cityname = "St. Louis";
    n4->next = NULL;
    n4 -> previous = n3;
    n3->next = n4;

    mailservice *n5 = new mailservice;
    n5->cityname = "Chicago";
    n5->next= NULL;
    n5->previous = n4;
    n4->next= n5;

    mailservice *n6 = new mailservice;
    n6->cityname= "Atlanta";
    n6->next = NULL;
    n6->previous = n5;
    n5->next = n6;

    mailservice *n7 = new mailservice;
    n7->cityname = "Washington, D.C.";
    n7->next= NULL;
    n7-> previous = n6;
    n6->next = n7;

    mailservice *n8 = new mailservice;
    n8->cityname = "New York";
    n8->next = NULL;
    n8->previous = n7;
    n7->next = n8;

    mailservice *n9 = new mailservice;
    n9->cityname = "Boston";
    n9->next = NULL;
    n9->previous = n8;
    n8->next = n9;

    mailservice* tmp = head;
    cout<< "Default routes used for delivery" <<endl;
    cout<<"NULL <- ";
    while(tmp->next != NULL){
        cout<<tmp->cityname<<" <-> ";
        tmp = tmp->next;
            }
    cout<<tmp->cityname<<" -> ";
    cout<<"NULL"<<endl;
    cout<<"=================="<<endl;
    cout<<endl;
}

void mail::build2()
{
    mailservice *m1 = new mailservice;
    m1->cityname = "Los Angeles";
    m1->next = NULL;
    m1->previous = NULL;
    head2 = m1;


    mailservice *m2 = new mailservice;
    m2->cityname = "Denver";
    m2->next = NULL;
    m2->previous = m1;
    m1->next = m2;

    mailservice *m3 = new mailservice;
    m3->cityname = "Dallas";
    m3->next = NULL;
    m3->previous = m2;
    m2->next = m3;

    mailservice *m4 = new mailservice;
    m4->cityname = "Chicago";
    m4->next = NULL;
    m4->previous = m3;
    m3->next = m4;

    mailservice *m5 = new mailservice;
    m5->cityname = "New York";
    m5->next = NULL;
    m5->previous = m4;
    m4->next = m5;

    cout<<"These our the roots we have for our one day shipping"<<endl;
    mailservice * tmp = head;
     while(tmp->next != NULL)
        {
            cout<<tmp->cityname<<" <-> ";
            tmp = tmp->next;
        }

        cout<<endl;
}

void mail::addCity(std::string newCity, std::string previousCity)
{
    mailservice *temps =head;
    mailservice *newmail = new mailservice;
    while(temps != NULL && temps->cityname != previousCity)
        {
        temps = temps->next;
        }
        if(temps->cityname == previousCity){
            newmail -> cityname = newCity;
            newmail -> next = temps->next;
            temps->next = newmail;
        }
        }


void mail::printNetwork(){
    if(head==NULL)
    {
        std::cout << "Empty list or Cleared" << std::endl;
    }
    else{
    cout<<"Route map for delivery"<<endl;
    cout<<"NULL <- ";
    mailservice *temp = head;
    while(temp->next != NULL)
        {
        cout<<temp->cityname<< " <-> ";
        temp = temp -> next;
    }

    cout<<temp->cityname<<" ->";
    cout<<"NULL"<<endl;
    cout<<"=================="<<endl;
    }
}

void mail::deleteCity(std::string cityNameDelete)
{
    mailservice *current = head;
    int x = 0;

    while(current != NULL && current -> cityname != cityNameDelete)
    {
        current = current -> next;
    }


    if(current == NULL)
    {
        std::cout<<cityNameDelete <<"Not Found"<<std::endl;
        x = 1;
    }

    if(x == 0 && current == head)
    {
        head = head->next;
        head->previous = NULL;
        delete current;
    }

    if(x==0 && current == tail)
    {
        tail = tail->previous;
        tail->next=NULL;
        delete current;
    }

    if(x == 0)
    {
        current->previous->next = current->next;
        current->next->previous = current->previous;
        delete current;
    }
}

void mail::deleteNetwork()
{
    mailservice *current = head;
    mailservice *nextCity = current->next;
    while (current->next != NULL)
    {
        std::cout<< "deleting " << current -> cityname << std::endl;
        delete current;
        current = nextCity;
        nextCity = nextCity->next;
    }
    std::cout << "deleting " << current -> cityname << std::endl;
    head = NULL;
    std::cout << "Network Cleared " << std::endl;
}

void mail::costfast(string kind, int weight){
    int cost;
    if ( weight < 5 ){
    cost = 15;
    cout<<"Cost of your shipping is $"<<cost<<endl;
    }
    else if (weight >= 5 && kind == "paper"){
        cost = weight*2 + 10;
        cout<<"Cost of your shipping is $"<<cost<<endl;
    }
    else if (weight >= 5 && kind == "Metal"){
        cost = weight*4 + 10;
         cout<<"Cost of your shipping is $"<<cost<<endl;
    }
    else if (weight >= 10 && kind == "Misc"){
    cost = weight*3 + 10;
    cout<<"Cost of your shipping is $"<<cost<<endl;
    }
}

void mail::costnormal(string kind, int weight){
  int cost;
    if ( weight < 5 ){
    cost = 8;
    cout<<"Cost of your shipping is $"<<cost<<endl;
    }
    else if (weight >= 5 && kind == "Paper"){
        cost = weight*2;
        cout<<"Cost of your shipping is $"<<cost<<endl;
    }
    else if (weight >= 5 && kind == "Metal"){
        cost = weight*4;
         cout<<"Cost of your shipping is $"<<cost<<endl;
    }
    else if (weight >= 10 && kind == "Misc"){
    cost = weight*3;
    cout<<"Cost of your shipping is $"<<cost<<endl;;
    }
}

void mail::supportNumber(){
    mailservice *tmp = head;
    mailservice *tmp2 = head2;
    int areaCode;
    int second;
    int last;
    string phoneNumber;



    while (tmp->next != NULL){
        areaCode = rand() % 800 + 100;
        string strArea = static_cast<ostringstream*>( &(ostringstream() << areaCode) )->str();
        second = rand() % 800 + 100; //std::to_string(second);
        string strSecond = static_cast<ostringstream*>( &(ostringstream() << second) )->str();
        last = rand() % 8000 + 1000; //std::to_string(last);
        string strLast = static_cast<ostringstream*>( &(ostringstream() << last) )->str();

        phoneNumber = "(" + strArea + ") " + strSecond + "-" + strLast;

        tmp->phone = phoneNumber;
        tmp2->phone = phoneNumber;
        tmp = tmp->next;
    }
}

mailservice* mail::search(string lookCity){
    mailservice *tmp = head;
    while (tmp->next != NULL){
        if (tmp->cityname == lookCity){
            return tmp;
        }
        tmp = tmp->next;
    }
}
