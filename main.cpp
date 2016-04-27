#include <iostream>
#include "mail.h"

using namespace std;

int main()

{
    mail service;
    string newCity;
    string previousCity;

    cout<<"Welcome to fastmail services."<<endl;
    cout<<endl;


    while(true){

        int x;
        int y;
        int choice;
        string kind;
        int weight;

        cout<<"Who would you like to log in as?"<<endl;
        cout<<"1. Admin"<<endl;
        cout<<"2. Customer"<<endl;
        cout << "3. Quit" << endl;
        cin>>x;
        cin.ignore(1000, '\n');

        if (x==1)
            {
            string pass; //password is: 12345
            cout<<"Enter the password: ";
            cin>>pass;

            if(pass == "12345")
            {
                while(y !=6){
                        cout<<"1. Build Network"<<endl;
                        cout<<"2. Print Network Path"<<endl;
                        cout<<"3. Add City"<<endl;
                        cout<<"4. Delete City"<<endl;
                        cout<<"5. Clear Network"<<endl;
                        cout<<"6. quit admin account"<<endl;
                        cin>>y;
                        cin.ignore( 1000, '\n');

                    if(y==1)
                    {
                        service.build();
                    }
                    else if (y == 2){
                        service.printNetwork();
                    }
                    else if (y == 3){

                        cout<<"Enter a city name: "<<endl;
                        getline(cin,newCity);
                        cout<<"Enter a previous city name: "<<endl;
                        getline(cin,previousCity);
                        service.addCity(newCity, previousCity);
                    }
                    else if (y == 4)
                    {
                        cout<<"Enter a city to be deleted"<<endl;
                        cin>>newCity;
                        service.deleteCity(newCity);
                    }

                else if (y == 5)
                    {
                        service.deleteNetwork();
                    }
            }
        }
        else
            {
                cout<<"access denied"<<endl;
            }
    }
        else if (x == 2){ // customer is chosen
            int z;
            cout<<"======Customer Menu======"<<endl;
            cout<<"1. Shipping type"<<endl;
            cout<<"2. Quit"<<endl;
            cin>>z;
            cin.ignore(1000, '\n');

            if(z == 1)
                {
                int k;
                cout<<"What kind of shipping would you like?"<<endl;
                cout<<"1. One day"<<endl;
                cout<<"2. Normal"<<endl;
                cin>>k;

                if (k == 1){ // does not let program leave the sub-menu
                    cout<<"Our one day shipping goes through the following cities"<<endl;
                    service.build2();

                    while( choice != 4 ){ // One day shipping

                        cout<<"Choose from the following"<<endl;
                        cout<<"1. Cost"<<endl;
                        cout<<"2. Schedule pick up"<<endl;
                        cout<<"3.Support"<<endl;
                        cout<<"4. go back to main menu"<<endl;
                        cin>>choice;

                        if (choice == 1){

                                cout<<"Enter the weight of package: ";
                                cin>>weight;
                                cout<<endl;
                                cout<<" Is it Paper, Metal or Misc in nature? ";
                                cin>>kind;
                                cout<<endl;

                                service.costnormal(kind, weight);
                            }

                        else if (choice == 2){

                        }
                         else if (choice == 3){
                        //service.support();
                    }
                }
            }

            if ( k == 2){
                    cout<<"This is our old fashioned reliable shipping"<<endl;
                    service.build();
                    while ( choice != 4 ){    // Normal shipping


                        cout<<"Choose from the following"<<endl;
                        cout<<"1. Cost"<<endl;
                        //cout<<"2. Schedule pick up"<<endl;
                        cout<<"3. Support"<<endl;
                        cout<<"4. Go back to Main Menu"<<endl;
                        cin>>choice;

                        if (choice == 1){

                            cout<<"Enter the weight of package: ";
                            cin>>weight;
                            cout<<endl;
                            cout<<" Is it Paper, Metal or Misc in nature? ";
                            cin>>kind;
                            cout<<endl;

                            service.costnormal(kind, weight);
                        }
                        else if (choice == 3){
                            service.supportNumber();
                            cout << "Enter city: ";
                            string city;
                            getline(cin, city);
                            mailservice *go = new mailservice;
                            go = service.search(city);
                            cout << go->phone << endl;
                        }
                    }
                }
            }

        else if (z == 2)
            {
                cout<<"Thanks for using our services, hope we could assist you"<<endl;
                break;
            }
        }
        else if (x == 3){
            cout << "Thank you for using our services. We hope we could assist you." << endl;
            break;
        }
    service.~mail();
    }
}
