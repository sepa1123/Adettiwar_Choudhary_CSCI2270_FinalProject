#include<iostream>
#include "mail.h"

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

void mail::addCity(std::string newCity, std::string previousCity)
{
    mailservice *temps =head;
    while(temps->next != NULL){

        if(temps->cityname == previousCity){
            break;
        }

        temps = temps -> next;
    }
    mailservice *k = new mailservice(newCity,temps, temps->next, "");
    temps->next = k;

}

void mail::ship(char * ){

}

void mail::track(){

}

void mail::printNetwork(){
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
