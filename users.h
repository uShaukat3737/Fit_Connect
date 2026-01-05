#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Users{
  
protected:
  
  //attributes used by all types of users
  string name;
  int uId;
  string email;
  string password;
  
public:

  //constructors
  Users(string name = "", string email = "", string password = ""){

    //assigning attributes
    this->name = name;
    this->email = email;
    this->password = password;
    
  }

  //getters
  string getName() const {return name;}
  int getId() const {return uId;}
  string getEmail() const {return email;}
  string getPassword() const {return password;}

  //setters
  void setName(string name){this->name = name;}
  void setId(int uId){this->uId = uId;}
  void setEmail(string email){this->email = email;}
  void setPassword(string password){this->password = password;}
  
  //override func to use in admin and trainer and regUser
  virtual void incrementTotal() =0;
  virtual int getTotalUsers() =0;
  virtual void decrementTotal() =0;

  //member functions
  //check if password is valid or not
  bool validPassword(string pass){
    
    if (pass.length() < 8){
      return false;
    }
    for (int i = 0; i< pass.length() ; i++){
      if ( ((pass[i]>47 && pass[i]<58) || (pass[i]>64 && pass[i]<91) || (pass[i]>96 && pass[i]<123)) == false ){
        return false;
      }
    }

    return true;
    
  }

  ~Users(){}
};