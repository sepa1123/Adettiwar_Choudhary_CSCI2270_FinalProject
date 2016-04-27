#ifndef MAIL_H
#define MAIL_H
#include <iostream>

using namespace std;

struct mailservice{
    std::string cityname;
    std::string package;
    mailservice * next;
    mailservice * previous;


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
        void build();
        void track();
        void addCity(std::string, std::string);
        void ship(char *);
        void printNetwork();
    protected:
    private:
        mailservice *head;
        mailservice *tail;

};

#endif // MAIL_H

