#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <memory>
#include <sstream>
#include "auxiliar.hpp"
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
    User(const std::string& username): username(username) {};
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
    Controller(){}
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
std::ostream& operator<<(std::ostream& os, const Controller& ctrl){
    return os << aux::join(ctrl.users, "\n", aux::fn_pair_value_deref);
}

int main(){
    Controller sistema;

    while(true) {
        auto cmd = aux::getcmd();
        if (cmd.empty())
            continue;
        auto action = cmd[0];
        try {
            if (action == "end") {
                break;
            } else if (action == "add") {
                sistema.addUser(cmd[1]);
            } else if (action == "rm") {
                sistema.rmUser(cmd[1]);
            }  else if (action == "show") {
                std::cout << sistema << '\n';
            } else if (action == "follow") {
                sistema.getUser(cmd[1])->follow(sistema.getUser(cmd[2]));
            } else if (action == "unfollow") {
                sistema.getUser(cmd[1])->unfollow(cmd[2]);
            } else if (action == "twittar") {
                auto msg = aux::slice(cmd, 2);
                sistema.sendTweet(cmd[1], aux::join(msg, " "));
            } else if (action == "like") {
                sistema.getUser(cmd[1])->like(std::stoi(cmd[2]));
            } else if (action == "timeline") {
                auto msgs = sistema.getUser(cmd[1])->getInbox().getTimeline();
                std::cout << aux::join_deref(msgs, "\n") << '\n';
                auto msg = aux::join(aux::slice(cmd, 3), " ");
                sistema.sendRt(cmd[1], std::stoi(cmd[2]), msg);
            } else {
                std::cout << "fail: comando invalido" << '\n';
            }
        } catch (TweetException &e) {
            std::cout << e.what() << '\n';
        }
    }
    return 0;
}