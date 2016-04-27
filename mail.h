#ifndef MAIL_H
#define MAIL_H
#include <iostream>

using namespace std;

struct mailservice{
    std::string cityname;
    std::string package;
    mailservice * next;
    mailservice * previous;
    std::string phone;


    mailservice(){};

    mailservice(std::string initName,mailservice *initNext,mailservice *initPrevious,std::string initpackage)
    {
        cityname = initName;
        next = initNext;
        previous = initPrevious;
        package = initpackage;
    }
};

class mail
{
    public:
        mail();
        ~mail();
        void build2();
        void build();
        void addCity(std::string, std::string);
        void printNetwork();
        void deleteCity(std::string);
        void deleteNetwork();
        void costfast(std::string, int);
        void costnormal(std::string,int);
        void supportNumber();
        mailservice* search(std::string);

    protected:
    private:
        mailservice *head;
        mailservice *tail;
        mailservice *head2;
};

#endif // MAIL_H
