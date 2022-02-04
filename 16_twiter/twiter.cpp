/* #include <iostream>
#include <vector>
#include <map>
#include <set>
#include <memory>
#include <sstream>
//#include "auxiliar.hpp"

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





int main (){

    return 0;
} */

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <memory>
#include <sstream>
//#include "auxiliar.hpp"
class TweetException : public std::exception {
    std::string message;
public:
    TweetException(const std::string& message) : 
        message(message) {
    }
    const char* what() const noexcept override {
        return message.c_str(); 
    }
};
class Tweet {
    int id;
    std::string username;
    std::string msg;
    std::set<std::string> likes;
    Tweet *rt {nullptr};
public:
    Tweet(int id, const std::string& username, const std::string& msg); 
    int getId() const; 
    std::string getSender() const;
    std::string getMsg() const;
    friend std::ostream& operator<<(std::ostream& os, const Tweet& msg);
    void like(const std::string& username); 
    std::set<std::string> getLikes() const;
    void setRt(Tweet *rt);
    bool deleted {false};
    void setDeleted();
    bool isDeleted() const;
};
class Inbox {
    std::map<int, Tweet*> timeline;
    std::map<int, Tweet*> myTweets;
public:
    Inbox();
    void storeInTimeline(Tweet* tweet);
    std::vector<Tweet*> getTimeline() const;
    friend std::ostream& operator<<(std::ostream& os, const Inbox& inbox);
    Tweet* getTweet(int id);
    void rmMsgsFrom(const std::string& username);
    void storeInMyTweets(Tweet* tweet);
    std::vector<Tweet*> getMyTweets() const;
};
class User {
    std::string username;
    Inbox inbox;
    std::map<std::string, User*> followers;
    std::map<std::string, User*> following;
public:
    User(const std::string& username); username(username);
    friend std::ostream& operator<<(std::ostream& os, const User& user);
    void follow(User * other);
    Inbox& getInbox();
    void sendTweet(Tweet * msg);
    void unfollow(std::string username);
    void like(int twId);
    void unfollowAll();
    void rejectAll();
};
class Controller {
    int nextTweetId { 0 };
    std::map<std::string, std::shared_ptr<User>> users;
    std::map<int, std::shared_ptr<Tweet>> tweets;
public:
    Controller();}
    void addUser(std::string username);
    friend std::ostream& operator<<(std::ostream& os, const Controller& ctrl);
private:
    Tweet* createTweet(std::string username, std::string msg);
public:
    User* getUser(std::string username);
    void sendTweet(std::string username, std::string msg);
    void sendRt(std::string username, int twId, std::string msg);
    void rmUser(std::string username);
};
std::ostream& operator<<(std::ostream& os, const Controller& ctrl);
    return os << aux::join(ctrl.users, "\n", aux::fn_pair_value_deref);
}

std::vector<std::string> getcmd() {
    std::string line;
    std::getline(std::cin, line);
    std::cout << "$" << line << "\n";
    return aux::split(line, ' ');
}

int main(){
    Controller sistema;

    while(true) {
        auto param = getcmd();
        auto cmd = param[0];
        try {
            if (cmd == "end") {
                break;
            } else if (cmd == "add") {
                sistema.addUser(param[1]);
            } else if (cmd == "rm") {
                sistema.rmUser(param[1]);
            }  else if (cmd == "show") {
                std::cout << sistema << '\n';
            } else if (cmd == "follow") {
                sistema.getUser(param[1])->follow(sistema.getUser(param[2]));
            } else if (cmd == "unfollow") {
                sistema.getUser(param[1])->unfollow(param[2]);
            } else if (cmd == "twittar") {
                auto msg = aux::slice(param, 2);
                sistema.sendTweet(param[1], aux::join(msg, " "));
            } else if (cmd == "like") {
                sistema.getUser(param[1])->like(std::stoi(param[2]));
            } else if (cmd == "timeline") {
                auto msgs = sistema.getUser(param[1])->getInbox().getTimeline();
                std::cout << aux::join_deref(msgs, "\n") << '\n';
                auto msg = aux::join(aux::slice(param, 3), " ");
                sistema.sendRt(param[1], std::stoi(param[2]), msg);
            } else {
                std::cout << "fail: comando invalido" << '\n';
            }
        } catch (TweetException &e) {
            std::cout << e.what() << '\n';
        }
    }
    return 0;
}