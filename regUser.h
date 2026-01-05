#include <iostream>
#include <fstream>

struct Nutrition{
  string date;
  int id;
  string meals;
  int caloriesIntake;
};

struct Exercise{
  string Type;
  string date;
  int Duration;
  int intensity;
  int caloriesBurnt;
  int id;
};

class regUsers:public Users{
  
private:
  
  //attributes used by simple users
  int age;
  int weight;
  int height;
  string exercisePref[5];
  string location;
  static int totalRegUsers;
  int total;
  int rank;
  int trainerId;

public:

  //constructors
  regUsers(string name = "", string email = "",string location = "", string password = "", int age = 0, int weight = 0, int height =0,int rank = 0, int trainerId = 0){

    //increment total user upon instance creation and assign to ID (this way Id always Unique)
    totalRegUsers++;
    uId = totalRegUsers;

    for (int i = 0 ; i< 5; i++ ){
      exercisePref[i] = " ";
    }

    //assigning attributes
    this->name = name;
    this->email = email;
    this->password = password;
    this->location=location;
    this->age = age;
    this->weight = weight;
    this->height = height;
    this->rank = rank;
    this->trainerId = trainerId;
  }

  regUsers( regUsers &obj){

    //increment total user upon instance creation and assign to ID (this way Id always Unique)
    this->totalRegUsers= obj.totalRegUsers;

    uId = obj.uId;

    for (int i = 0 ; i< 5; i++ ){
      exercisePref[i] = obj.exercisePref[i];
    }

    //assigning attributes
    this->name = obj.name;
    this->email = obj.email;
    this->password = obj.password;
    this->location=obj.location;
    this->age = obj.age;
    this->weight = obj.weight;
    this->height = obj.height;
    this->rank = obj.rank;
    this->trainerId= obj.trainerId;

  }

  //getters
  int getAge() const {return age;}
  int getWeight() const {return weight;}
  int getHeight() const {return height;}
  string getExercise(int i) const {return exercisePref[i];}
  int getTotal(){return total;}
  string getLocation(){return location;}
  int getRank(){return rank;}
  int getTrainerId(){return trainerId;}
  
  //setters
  void setAge(int age){this->age = age;}
  void setWeight(int weight){this->weight = weight;}
  void setHeight(int height){this->height = height;}
  void setExercise(int i , string pref){ exercisePref[i] = pref;}
  void setTotal(int total){this->total = total;}
  void setLocation(string location){this->location = location;}
  void setRank(int rank){ this-> rank = rank;}
  void setTrainerId(int id){ trainerId = id;}
  
  //overrided methods
  void incrementTotal(){totalRegUsers++;}
  void decrementTotal(){totalRegUsers--;}
  int getTotalUsers() {return totalRegUsers;}
  

  //member functions

  //add user
  void addToArr( regUsers *&arr, int size);
  //check log in
  bool authenticateLogin(int uid, string password, regUsers *arr);
  //display user info
  void displayInfo();
  //display main menu
  void displayMenu();
  //update user info
  void updateInfo(regUsers *arr);
  //display forum
  int openForum();
  //display nutrtion log
  int openLog();
  //display recommendations in nutrition log
  int displayRecs();
  //display workout
  int workoutMenu();
  //rank calculation
  int calculateRank(int duration,int intensity,int count);
  //display location menu
  int LocationMenu();
  //location features functionality
  void openLocationMenu(regUsers *usersData);
  //challanges menu
  int challangesMenu();
  //challanges functionality
  void openChallangesMenu();
  //view messages
  void viewMessages(string file1);
  //add message to message file
  void addMessage(string message);
  //chatbox display
  int chatMenu();
  //chat box functionality
  void openChatMenu();

  //operator overloading
  friend istream& operator>>(istream &in , regUsers &obj){
    
    in>>obj.name;
    in>>obj.email;
    in>>obj.age;
    in>>obj.weight;
    in>>obj.height;
    
    return in;
  }
  
  ~regUsers(){

    //deletion of DMA
    totalRegUsers--;

  }

};

//initialise static variable total count
int regUsers::totalRegUsers = 0;


  void regUsers::addToArr( regUsers *&arr, int size){
  
  //copy old arr
  regUsers *arr2= new regUsers[size+1];

  for (int i = 0; i<size; i++){
    
    arr2[i].setName(arr[i].getName());
    arr2[i].setId(arr[i].getId());
    arr2[i].setAge(arr[i].getAge());
    arr2[i].setEmail(arr[i].getEmail());
    arr2[i].setHeight(arr[i].getHeight());
    arr2[i].setPassword(arr[i].getPassword());
    arr2[i].setWeight(arr[i].getWeight());

    for (int j = 0; j<5; j++){
      arr2[i].setExercise(j, arr[i].getExercise(j));
    }

  }
  
  //add in new record
  arr2[size].setName(getName());
  arr2[size].setId(getId());
  arr2[size].setAge(getAge());
  arr2[size].setEmail(getEmail());
  arr2[size].setHeight(getHeight());
  arr2[size].setPassword(getPassword());
  arr2[size].setWeight(getWeight());

  for (int j = 0; j<5; j++){
    arr2[size].setExercise(j, getExercise(j));
  }
  
  //delete memory allocated to old arr
  delete [] arr;
  arr=arr2;

}

  bool regUsers::authenticateLogin(int uid, string password, regUsers *arr){
    
    for (int i = 0; i< arr[0].getTotalUsers();i++){
      if (uid == arr[i].getId()){
        if (password == arr[i].getPassword()){
          return true;
        }
        else {
          cout<<"password incorrect"<<endl;
          return false;
        }
      }
      else {
        cout<<"account not found";
        return false;
      }
    }

  }

  void regUsers::displayInfo(){
    cout << "\n╔══════════════════════════════════════╗" << endl;
    cout << "║       Your Account Information       ║" << endl;
    cout << "╚══════════════════════════════════════╝" << endl;

    cout << "User ID: " << uId << endl;
    cout << "Name: " << name << endl;
    cout << "Email: " << email << endl;
    cout << "Age: " << age << endl;
    cout << "Weight: " << weight << endl;
    cout << "Height: " << height << endl;
  }

  void regUsers::displayMenu(){
    
    cout << "\n╔══════════════════════════════════════════════╗" << endl;
    cout << "║             Main Menu:                       ║" << endl;
    cout << "╠══════════════════════════════════════════════╣" << endl;
    cout << "║ 1. Update User Info                          ║" << endl;
    cout << "║ 2. View Latest Exercise Details              ║" << endl;
    cout << "║ 3. Open Community Forum                      ║" << endl;
    cout << "║ 4. Open Nutrition Log                        ║" << endl;
    cout << "║ 5. Check Progress Analysis                   ║" << endl;
    cout << "║ 6. Check Challenges and Competitions         ║" << endl;
    cout << "║ 7. Location Based Features                   ║" << endl;
    cout << "║ 8. Trainer Chat box                          ║" << endl;
    cout << "║ 9. Select trainer                            ║" << endl;
    cout << "║ 10. Exit                                     ║" << endl;
    cout << "╚══════════════════════════════════════════════╝" << endl;
    cout << "\nEnter your choice (1-10): ";
    
  }

  void regUsers::updateInfo(regUsers *arr) {
    
    bool exit = false;

    while (exit == false){
      
      cout << "\n╔════════════════════════════════════════════════╗" << endl;
      cout << "║             Update User Info                   ║" << endl;
      cout << "╠════════════════════════════════════════════════╣" << endl;
      cout << "║ 1. Name                                        ║" << endl;
      cout << "║ 2. Email                                       ║" << endl;
      cout << "║ 3. Age                                         ║" << endl;
      cout << "║ 4. Weight                                      ║" << endl;
      cout << "║ 5. Height                                      ║" << endl;
      cout << "║ 6. Password                                    ║" << endl;
      cout << "║ 7. Back to Main Menu                           ║" << endl;
      cout << "╚════════════════════════════════════════════════╝" << endl;
      cout << "Enter the number corresponding to the information you want to update: ";

      int choice;
      cin >> choice;

      while (choice > 7 || choice < 1){
        cout << "Invalid choice. Please enter a number between 1 and 7: " << endl;
        cin>>choice;
      }

      bool invalid = false;
      string temp1;
      
    
      switch (choice) {
        case 1:
        
          do {

            cout << "Enter new name: ";
            cin.ignore(); // Clear buffer
            getline(cin, name);

            //check if new name is entered 
            if (name == temp1){
              
              cout << "Name already in use, ";
              invalid = true;
            
            }
            
          }while (invalid == true);

          cout<<"\nName updated successfully ^_^\n";
          break;

        case 2:
        
          do {

            cout << "Enter new email address : ";
            cin.ignore(); // Clear buffer
            getline(cin, email);

            for (int i =0; i<totalRegUsers; i++){
              //check if new email is entered 
              if (name == temp1){
              
                cout << "email address already in use, ";
                invalid = true;
                break;

              }
              //check if email entered already exist
              else if (temp1 == arr[i].getName()){
            
                cout<<"email address already exists, ";
                invalid = true;
                break;

              }
            }

          }while (invalid == true);

          cout<<"\nEmail address updated successfully ^_^\n";
          break;

        case 3:
        
          do{
          
            cout << "Enter new age: ";
            cin >> age;

            if (age <-1){
              cout<<"Entered age invalid, ";
            }

          }while (age < -1);
        
          cout<<"\nAge updated successfully ^_^\n";
          break;

        case 4:
        
          do{
          
            cout << "Enter new weight: ";
            cin >> weight;

            if (age <-1){
              cout<<"Entered weight invalid, ";
            }

          }while (weight < -1);
        
          cout<<"\nWeight updated successfully ^_^\n";
          break;

        case 5:
        
          do{
          
            cout << "Enter new height in cm: ";
            cin >> weight;

            if (age <-1){
              cout<<"Entered height invalid, ";
            }

          }while (weight < -1);
        
          cout<<"\nHeight updated successfully ^_^\n";
          break;

        case 6:
          do{
            cout << "Enter new password: ";
            cin >> password;

            if (validPassword(password)== false){
              cout<<"Entered password invalid, ";
            }
          } while (validPassword(password)== false);
          cout<<"\nPassword updated successfully ^_^\n";

          break;

        case 7:
        
          //return back to user menu
          exit = true;
          break;
      }
    }

    
  }

  int regUsers::openForum(){
    
      cout << "\n╔════════════════════════════════╗" << endl;
      cout << "║      Community Forum Menu      ║" << endl;
      cout << "╠════════════════════════════════╣" << endl;
      cout << "║ 1. View Latest Posts           ║" << endl;
      cout << "║ 2. Add a Message               ║" << endl;
      cout << "║ 3. Back to Main Menu           ║" << endl;
      cout << "╚════════════════════════════════╝" << endl;
      cout << "\nEnter your choice (1-3): ";


      int choice;
      cin >> choice;

      while (choice > 3 || choice < 1){
        cout << "Invalid choice. Please enter a number between 1 and 3: " << endl;
        cin>>choice;
      }

      return choice;
    
  }

  int regUsers::openLog(){
    
    bool exit = false;

    while (exit == false){
      
      cout << "\n╔════════════════════════════════╗" << endl;
      cout << "║       Nutrition Log Menu       ║" << endl;
      cout << "╠════════════════════════════════╣" << endl;
      cout << "║ 1. View Log                    ║" << endl;
      cout << "║ 2. Add Entry                   ║" << endl;
      cout << "║ 3. Delete Log                  ║" << endl;
      cout << "║ 4. Recommendations             ║" << endl;
      cout << "║ 5. Return to Main Menu         ║" << endl;
      cout << "╚════════════════════════════════╝" << endl;
      cout << "Enter your choice (1-5): ";

      int choice;
      cin >> choice;

      while (choice > 5 || choice < 1){
        cout << "Invalid choice. Please enter a number between 1 and 5: " << endl;
        cin>>choice;
      }

      return choice;
    }  
  }

  int regUsers::displayRecs(){
     bool exit = false;

      while (exit == false){
      
        cout << "\n╔════════════════════════════════╗" << endl;
        cout << "║     Recommendation Options     ║" << endl;
        cout << "╠════════════════════════════════╣" << endl;
        cout << "║ 1. Lose Weight                 ║" << endl;
        cout << "║ 2. Build Muscle                ║" << endl;
        cout << "║ 3. Improve Overall Health      ║" << endl;
        cout << "╚════════════════════════════════╝" << endl;
        cout << "Enter your choice (1-3): ";

        int choice;
        cin >> choice;

        while (choice > 3 || choice < 1){
          cout << "Invalid choice. Please enter a number between 1 and 3: " << endl;
          cin>>choice;
        }

      return choice;
    }  
  }

  int regUsers::workoutMenu(){
     
    cout << "\n╔══════════════════════════════╗" << endl;
    cout << "║    Workout Session Menu      ║" << endl;
    cout << "╠══════════════════════════════╣" << endl;
    cout << "║ 1. Add Session               ║" << endl;
    cout << "║ 2. Set up Workout Preference ║" << endl;
    cout << "║ 3. View Workout Log          ║" << endl;
    cout << "║ 4. Clear Workout Log         ║" << endl;
    cout << "║ 5. Move Back to Main Menu    ║" << endl;
    cout << "╚══════════════════════════════╝" << endl;
    cout << "\nEnter your choice (1-5): ";

    int choice;
    cin >> choice;

    while (choice > 5 || choice < 1){
      cout << "Invalid choice. Please enter a number between 1 and 5: " << endl;
      cin>>choice;
    }

    return choice;
  }

  int regUsers::calculateRank(int duration,int intensity,int count){
    //consistency*intensity*duration
    int rank =  (count / duration)*(intensity/count)*duration;
    return rank;
  }

  int regUsers::LocationMenu(){
  
    cout << "=========================================" << endl;
    cout << "|       Location-Based Features Menu    |" << endl;
    cout << "|---------------------------------------|" << endl;
    cout << "| 1. Gyms Near You                      |" << endl;
    cout << "| 2. Workout Buddy Finder               |" << endl;
    cout << "| 3. Nutrition Places                   |" << endl;
    cout << "| 4. Back to Main Menu                  |" << endl;
    cout << "=========================================" << endl;
    cout << "\nEnter your choice (1-4): ";

    int choice;
    cin >> choice;

    while (choice > 4 || choice < 1){
      cout << "Invalid choice. Please enter a number between 1 and 4: " << endl;
      cin>>choice;
    }

    return choice;
  }

  void regUsers::openLocationMenu(regUsers *usersData){
    bool exit1 = false;

    while (exit1 == false){
        
      int input1=0;
      
      string temp;
      Exercise obj;

      input1 = LocationMenu();  

      switch (input1){
        
        case 1 :
            
          if (location=="Pak0"){
            for (int i = 0; i< 3; i++){
              cout<<"gym # "<<i+1<<": ";
              cout << "building "+ to_string(rand()%27) <<" , ";
              cout << "lane "+ to_string(rand()%27) <<" , ";
              cout << "block"+ to_string(rand()%27) <<" , ";
              cout << location;
              cout<<endl;
            }
          }
          else if (location=="Pak1"){
            for (int i = 0; i< 5; i++){
              cout<<"gym # "<<i+1<<": ";
              cout << "building "+ to_string(rand()%27) <<" , ";
              cout << "lane "+ to_string(rand()%27) <<" , ";
              cout << "block"+ to_string(rand()%27) <<" , ";
              cout << location;
              cout<<endl;
            }
          }
          else {
            for (int i = 0; i< 7; i++){
              cout<<"gym # "<<i+1<<": ";
              cout << "building "+ to_string(rand()%27) <<" , ";
              cout << "lane "+ to_string(rand()%27) <<" , ";
              cout << "block"+ to_string(rand()%27) <<" , ";
              cout << location;
              cout<<endl;
            }
          }
          break;

        case 2 :
          
          for (int i = 0 ; i< getTotal(); i++){
            
            if (location==usersData[i].getLocation()){
              cout<<"name: "<<usersData[i].getName()<< " || ID: "<<usersData[i].getId();
              cout<<endl;
            }
            cout<<endl;
          }
          break;

        case 3:
          
          if (location=="Pak0"){
            for (int i = 0; i< 2; i++){
              cout<<"Nutrition store # "<<i+1<<": ";
              cout << "building "+ to_string(rand()%27) <<" , ";
              cout << "lane "+ to_string(rand()%27) <<" , ";
              cout << "block"+ to_string(rand()%27) <<" , ";
              cout << location;
              cout<<endl;
            }
          }
          else if (location=="Pak1"){
            for (int i = 0; i< 4; i++){
              cout<<"Nutrition store # "<<i+1<<": ";
              cout << "building "+ to_string(rand()%27) <<" , ";
              cout << "lane "+ to_string(rand()%27) <<" , ";
              cout << "block"+ to_string(rand()%27) <<" , ";
              cout << location;
              cout<<endl;
            }
          }
          else {
            for (int i = 0; i< 3; i++){
              cout<<"Nutrition store # "<<i+1<<": ";
              cout << "building "+ to_string(rand()%27) <<" , ";
              cout << "lane "+ to_string(rand()%27) <<" , ";
              cout << "block"+ to_string(rand()%27) <<" , ";
              cout << location;
              cout<<endl;
            }
          }
          
          break;

        case 4:

          exit1=true;
          break;    
      }
    }
  }

  int regUsers::challangesMenu(){

    cout << "\n╔═══════════════════════════╗" << endl;
    cout << "║       Challenges Menu     ║" << endl;
    cout << "╠═══════════════════════════╣" << endl;
    cout << "║ 1. 10x Situps             ║" << endl;
    cout << "║ 2. 10x Pushups            ║" << endl;
    cout << "║ 3. 10x Crunches           ║" << endl;
    cout << "║ 4. 1 min Plank            ║" << endl;
    cout << "║ 5. 15x Pullups            ║" << endl;
    cout << "║ 6. Return to Menu         ║" << endl;
    cout << "╚═══════════════════════════╝" << endl;
    cout << "\nEnter challanges completed choice (1-6): ";

    int choice;
    cin >> choice;

    while (choice > 6 || choice < 1){
      cout << "Invalid choice. Please enter a number between 1 and 6: " << endl;
      cin>>choice;
    }

    return choice;

  }

  void regUsers::openChallangesMenu(){
    
    bool exit1 = false;

    while (exit1 == false){
        
      int input1=0;
      
      
      string temp;
      Exercise obj;

      input1 = challangesMenu();  

      switch (input1){
        
        case 1 :
            
          rank++;
          cout<<"\nRank updated!!! ^_^"<<endl;
          break;

        case 2 :
          
          rank+=2;
          cout<<"\nRank updated!!! ^_^"<<endl;
          break;

        case 3:
          
          rank++;
          cout<<"\nRank updated!!! ^_^"<<endl;
          break;
        
        case 4:
          
          rank+=3;
          cout<<"\nRank updated!!! ^_^"<<endl;
          break;
        
        case 5:
          
          rank+=2;
          cout<<"\nRank updated!!! ^_^"<<endl;
          break;

        case 6:

          exit1=true;
          break;    
      }
    }

  }
  
  void regUsers::viewMessages(string file1){
    //open file
    fstream file;
    file.open(file1, ios::binary | ios::in);

    cout << "____ _  _ ____ ___    ___  ____ _  _ " << endl;
    cout << "|    |__| |__|  |     |__] |  |  \\/  " << endl;
    cout << "|___ |  | |  |  |     |__] |__| _/\\_ " << endl<<endl;

    int size2,tId,temp;

    //read and display whole forum
    while (file.read((char*)&tId, sizeof(int))){
      
      if (tId==trainerId){
        file.read((char*)&temp, sizeof(int));
        if (temp==uId){
          file.read((char*)&size2, sizeof(int));
          //read messages as character arrays
          char* temp = new char[size2 + 1];
          file.read(temp, size2);
          temp[size2] = '\0';

          cout<<temp<<endl;
          delete[] temp;
        }
      }
      
    }

    file.close();
    cout<<endl;
  }

  void regUsers::addMessage(string message){
   fstream file;

   file.open("messages.bin", ios::binary | ios::app);

    //add trainer id 
    file.write((char*)&trainerId, sizeof(int));
    //user id
    file.write((char*)&uId, sizeof(int));

    //add message
    //store size and then the message as a cstring(character array)
    int size1 = message.size();
    file.write((char*)&size1, sizeof(int));
    file.write(message.c_str(), size1);

    file.close(); 
  }

  int regUsers::chatMenu(){

    cout << "\n╔══════════════════════════════════════╗" << endl;
    cout << "║             Chatbox Menu             ║" << endl;
    cout << "╠══════════════════════════════════════╣" << endl;
    cout << "║ 1. View Messages                     ║" << endl;
    cout << "║ 2. Add Message                       ║" << endl;
    cout << "║ 3. Return to Main Menu               ║" << endl;
    cout << "╚══════════════════════════════════════╝" << endl;
    cout << "Enter your choice (1-3): ";

    int choice;
    cin >> choice;

    while (choice > 4 || choice < 1){
      cout << "Invalid choice. Please enter a number between 1 and 4: " << endl;
      cin>>choice;
    }

    return choice;
  }

  void regUsers::openChatMenu(){
    bool exit1 = false;

    while (exit1 == false){
        
      int input1=0;
      
      string temp;
      Exercise obj;
      string message;

      input1 = chatMenu();  

      switch (input1){
        
        case 1 :
            
          viewMessages("messages.bin");
          cout<<"";
          break;

        case 2 :
          
          cin.ignore(); 
          cout << "Enter new message to upload : ";
          getline(cin,message);

          message = name + " : "+ message;

          addMessage(message);

          cout<<"\nMessage uploaded successfully ^_^\n";
          break;

        case 3:

          exit1=true;
          break;    
      }
    }
  }
