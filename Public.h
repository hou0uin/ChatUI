#ifndef PUBLIC_H
#define PUBLIC_H

#include <QString>

struct UserInfo
{
    int id;
    QString name;
    UserInfo(){
        id = -1;
        name = "NULL";
    }
};

#endif // PUBLIC_H
