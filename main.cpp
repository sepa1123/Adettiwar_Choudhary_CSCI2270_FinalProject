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

    /*

    */
    while(true){

        int x;
        int y;
        cout<<"Who would you like to log in as?"<<endl;
        cout<<"1. Admin"<<endl;
        cout<<"2. Customer"<<endl;
        cin>>x;
        cin.ignore(1000, '\n');

        if (x==1){
            string pass; //password is: 12345
            cout<<"Enter the password: ";
            cin>>pass;

            if(pass == "12345")
            {
                while (y != 6 )
                {
                    cout<<"1. Build Network"<<endl;
                    cout<<"2. Print Network Path"<<endl;
                    cout<<"3. Add City"<<endl;
                    cout<<"4. Delete City"<<endl;
                    cout<<"5. Clear Network"<<endl;
                    cout<<"6. quit admin account"<<endl;
                    cin>>y;
                    cin.ignore( 1000, '\n');

                        if(x==1){
                            service.build();
                        }
                        else if (x == 2){
                            service.printNetwork();
                        }
                        else if (x == 3){

                            cout<<"Enter a city name: "<<endl;
                            getline(cin,newCity);
                            cout<<"Enter a previous city name: "<<endl;
                            getline(cin,previousCity);
                            service.addCity(newCity, previousCity);
                        }
                        else if (x == 4){

                        }
                        else if (x == 5){

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
            cout<<"======Main Menu======"<<endl;
            cout<<"1. Shipping type"<<endl;
            cout<<"2. Print Network Path"<<endl;
            cout<<"3. Cost"<<endl;
            //cout<<"4. Add City"<<endl;
            cout<<"5. Support"<<endl;
            cout<<"6. History"<<endl;
            cout<<"7. Schedule pickup "<<endl;
            cout<<"8. Track"<<endl;
            cout<<"9. Quit"<<endl;
            cin>>z;
            cin.ignore(1000, '\n');

            if(z == 1){
                int k;
                cout<<"What kind of shipping would you like?"<<endl;
                cout<<"1. One day"<<endl;
                cout<<"2. Normal"<<endl;
                cin>>k;
                if(k == 1){
                    
                }
                else if(k == 2){
                        service.printNetwork();
                    }
            }
            else if (x == 2){
                
            }
            else if (x == 3){

            }
            else if (x == 4){
                string newCity, previousCity;
                cout<<"Enter a city name: "<<endl;
                getline(cin,newCity);
                cout<<"Enter a previous city name: "<<endl;
                getline(cin,previousCity);
                service.addCity(newCity, previousCity);
            }
            else if (x == 5){
                cout<<"Enter a city name you'd like support for"<<endl;
                for(int i = 0; i<11; i++){
                    //cout<<city[i]<<endl;
                }

            }
            else if (x == 6){

            }
            else if (x == 7){

            }
            else if (x == 8){

            }
            else if (x == 9){
                cout<<"Thanks for using our services, hope we could assist you"<<endl;
                break;
                }
            }
        service.~mail();
    }
}
