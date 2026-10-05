#include "Engineer.h"

string Engineer::encryptPassword(string password)
{
    string encrypted = "";

    const char hex[] = "0123456789ABCDEF";

    for (int i = 0; i < password.length(); i++)
    {
        unsigned char character = password[i] + 3;

        encrypted += hex[(character >> 4) & 0x0F];
        encrypted += hex[character & 0x0F];
    }

    return encrypted;
}

Engineer::Engineer(string id, string user, string password, string clearance)
{
    engineerID = id;
    username = user;
    clearanceLevel = clearance;

    encryptedPassword = encryptPassword(password);
}

Engineer::Engineer(string id, string user, string encryptedPasswordValue,
    string clearance, bool alreadyEncrypted)
{
    engineerID = id;
    username = user;
    clearanceLevel = clearance;

    if (alreadyEncrypted)
    {
        encryptedPassword = encryptedPasswordValue;
    }
    else
    {
        encryptedPassword = encryptPassword(encryptedPasswordValue);
    }
}

string Engineer::getEngineerID()
{
    return engineerID;
}

string Engineer::getUsername()
{
    return username;
}

string Engineer::getEncryptedPassword()
{
    return encryptedPassword;
}

string Engineer::getClearanceLevel()
{
    return clearanceLevel;
}

bool Engineer::checkPassword(string password)
{
    return encryptPassword(password) == encryptedPassword;
}

bool Engineer::operator==(const Engineer& other)
{
    return username == other.username &&
        encryptedPassword == other.encryptedPassword;
}