#ifndef ENGINEER_H
#define ENGINEER_H

#include <string>

using namespace std;

class Engineer
{
private:
    string engineerID;
    string username;
    string encryptedPassword;
    string clearanceLevel;

    string encryptPassword(string password);

public:
    Engineer(string id, string user, string password, string clearance);

    Engineer(string id, string user, string encryptedPassword,
        string clearance, bool alreadyEncrypted);

    string getEngineerID();
    string getUsername();
    string getEncryptedPassword();
    string getClearanceLevel();

    bool checkPassword(string password);

    bool operator==(const Engineer& other);
};

#endif