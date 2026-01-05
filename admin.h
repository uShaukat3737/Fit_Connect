//inherits Users
#include "regUser.h"
#include <fstream>
#include "trainers.h"

class Admin : public Users{

private:
  
  static int totalAdmins;
  int total;

public:

  //constructors
  Admin(string name = "", string email = "", string password = ""){

    //increment total user upon instance creation and assign to ID (this way Id always Unique)
    totalAdmins++;
    uId = totalAdmins;

    //assigning attributes
    this->name = name;
    this->email = email;
    this->password = password;

  }

  //getters
  int getTotal(){return total;}

  //setters
  void setTotal(int total){this->total = total;}

  //overrided methods
  int getTotalUsers() {return totalAdmins;}
  void incrementTotal(){totalAdmins++;}
  void decrementTotal(){totalAdmins--;}

  //member functions
  
  //add new admin
  void addToArr( Admin *&arr);
  //admin main menu
  void displayMenu();
  //views info of desired user
  void ViewUserDetails(int id);
  //views info of desired trainer
  void ViewTrainerDetails(int id);
  //views workout log of desired user
  void ViewWorkoutLog(int id);
  //views nutrition log of desired user
  void ViewNutritionLog(int id);

  ~Admin(){
    totalAdmins--;
  }
  
};

//initialise static variable total count
int Admin::totalAdmins = 0;

  void Admin::addToArr( Admin *&arr){
  
  int size = getTotalUsers();

  //copy old arr
  Admin *arr2= new Admin[size+1];

  for (int i = 0; i<size; i++){
    
    arr2[i].setName(arr[i].getName());
    arr2[i].setId(arr[i].getId());
    arr2[i].setEmail(arr[i].getEmail());
    arr2[i].setPassword(arr[i].getPassword());

  }

  //add in new record
  arr2[size].setName(getName());
  arr2[size].setId(getId());
  arr2[size].setEmail(getEmail());
  arr2[size].setPassword(getPassword());

  //increase size of arr
  totalAdmins++;
  
  //delete memory allocated to old arr
  delete [] arr;
  arr=arr2;

}

  void Admin::displayMenu(){

    cout << "\n╔══════════════════════════════════════╗" << endl;
    cout << "║           Admin Main Menu            ║" << endl;
    cout << "╠══════════════════════════════════════╣" << endl;
    cout << "║ 1. View User Details                 ║" << endl;
    cout << "║ 2. View Trainer Details              ║" << endl;
    cout << "║ 3. Clear Forum                       ║" << endl;
    cout << "║ 4. Add Trainer                       ║" << endl;
    cout << "║ 5. Add User                          ║" << endl;  
    cout << "║ 6. view workout logs                 ║" << endl;  
    cout << "║ 7. view nutrition logs               ║" << endl;  
    cout << "║ 8. Exit                              ║" << endl;
    cout << "╚══════════════════════════════════════╝" << endl;
    cout << "Enter your choice (1-8): ";

  }

  void Admin::ViewUserDetails(int id){
    
    fstream file;
    bool found = false;

    //open file to read
    file.open("users.bin", ios::binary | ios::in);

    //create temp object
    regUsers obj;
    obj.decrementTotal();

    file.read((char*)&obj, sizeof(obj));
    int size = obj.getTotal();

    if (obj.getId()==id){
      cout<<endl;
      obj.displayInfo();
      cout<<endl;
      found = true;
    }
    else {
      //read rest of the data into the array
      for (int i = 1; i < size; i++) {
        file.read((char*)&obj, sizeof(regUsers));
        if (obj.getId()==id){
          cout<<endl;
          obj.displayInfo();
          cout<<endl;
          found = true;
          break;
        }
      }
    }

    file.close();

    //increment total to set it back
    obj.incrementTotal();

    if (found == false){
      cout<<"\nuser not found !\n";
    }

  }

  void Admin::ViewTrainerDetails(int id){
    
    fstream file;
    bool found = false;

    //open file to read
    file.open("trainers.bin", ios::binary | ios::in);

    //create temp object
    Trainers obj;
    obj.decrementTotal();

    file.read((char*)&obj, sizeof(obj));
    int size = obj.getTotal();
    cout<<"size is : "<<size<<endl;

    if (obj.getId()==id){
      cout<<endl;
      obj.DisplayInfo();
      cout<<endl;
      found = true;
    }
    else {
      //read rest of the data into the array
      for (int i = 1; i < size; i++) {
        cout<<"size is : "<<size<<endl;
        file.read((char*)&obj, sizeof(Trainers));
        if (obj.getId()==id){
          cout<<endl;
          obj.DisplayInfo();
          cout<<endl;
          found = true;
          break;
        }
      }
    }

    file.close();

    //increment total to set it back
    obj.incrementTotal();

    if (found == false){
      cout<<"\nuser not found !\n";
    }

  }

  void Admin::ViewWorkoutLog(int id){
    
    Exercise obj;
    fstream file;
    bool found ;

    //open file
    file.open("workout.bin", ios::binary | ios::in);

    int count = 0;
    while (file.read((char*)&obj, sizeof(Exercise))) {
      if (id == obj.id){
        cout<<"\nlog#"<<++count<<endl;
        cout << "Date: " << obj.date << endl;
        cout << "Workout Type: " << obj.Type<< endl;
        cout << "Intensity: " << obj.intensity<< endl;
        cout << "Calories burnt: " << obj.caloriesBurnt<< endl;
        cout << "Duration: " << obj.Duration << endl;
        cout << endl;
        count++;
        found = true;
      }
      
        
    }
    file.close();

    if (count == 0 || found == true){
      cout << "\nNo workout log found" << endl;
    }
    
    cout<<endl;
  }

  void Admin::ViewNutritionLog(int id){
    
    Nutrition obj;
    fstream file;
    bool found ;

    //open file
    file.open("nLog.bin", ios::binary | ios::in);

    int count = 0;
    while (file.read((char*)&obj, sizeof(Nutrition))) {
      if (id == obj.id){
        cout<<"\nlog#"<<++count<<endl;
        cout << "Date: " << obj.date << endl;
        cout << "Meal: " << obj.meals << endl;
        cout << "Calories intake: " << obj.caloriesIntake << endl;
        cout << endl;
        count++;
        found = true;
      }
        
    }
    file.close();
    if (count == 0 || found == true){
      cout << "\nNo nutrition log found" << endl;
    }
    
    cout<<endl;
  }
