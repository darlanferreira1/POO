#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <memory>
#include <sstream>
#include "auxiliar.hpp"

class TweetException : public std::exception{

};

class Tweet{

};

class Inbox{

};

class User{
    protected:
    std::string username;
    std::map <std::string, User> followers;
    std::map <std::string, User> following;
    public:
    User(std::string username){
        this->username = username;
    }

    void follow(){}
    void getInbox(){}
    void sendTweet(){}
    void unfollow(){}
    void like(){}

};


class Controler{
    protected:
        int nextTweetId;
        std::map<std::string, User> users;
        std::map<int, Tweet> tweets;

    public:

        Controler(){}
        void addUser(){}

 
};

int main () {
    return 0;
}


