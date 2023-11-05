#include <vector>
#include <string>
#include <iostream>
#include <chrono>
#include <functional>
#include <any>
#include <fstream>

// Admin Thingy made by Alto Lawden
// Version 1.0

enum class AdminRanks {
  HEAD_ADMIN = 244,
  OWNER = 255,
  MODERATOR = 200,
  TRIAL_MOD = 100,
  HEAD_MOD = 225
}; 

class Staff {
  AdminRanks level;
  std::string user;
  date hired;
  public:

    Staff(const AdminRanks level, const std::string user, const date hired) {
      this->level = level;
      this->user = user;
      this->hired = hired;
      std::ofstream this->log("log" + user);
    }
};

class date {
  std::vector<int> main;
  public:
    date(const int m, const int d, const int y) {
      main[1] = m;
      main[2] = d;
      main[3] = y; 
    }
};

class Action {
  template<typename... arg>
  std::function<std::any(args...)> func;
  int level;
  public:
    constructor(std::function<std::any(args...)> func, int lvl) {
      this->level = lvl;
      this->func = func;
    }

    std::any operator()(Staff user, args...) {
      if user.level <= this->level) {
            user.log.open()
            user.log << "Unathorized action done at " + std::chrono::system_clock::to_time(std::chrono::system_clock::now()) + std::endl;
            user.log.close();
           return;
      }
      user.log.open();
      user.log << "Authorized action done at " + std::chrono::system_clock::totime(std::chrono::system_clock::now()) + std::endl;
      return this->func(args...);
    }

};

