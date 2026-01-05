#include <fstream>
#include <iostream>
#include <string>
#include "users.h"
#include "admin.h"

using namespace std;

class FileHandler{

private:

  fstream file;

public:

  //read user file
  regUsers* readFileUsers(string file);
  //write user file
  void writeFileUsers( regUsers* usersData, string file);
  //read trainer file
  Trainers* readFileTrainers(string file);
  //write trainer file
  void writeFileTrainers( Trainers* trainersData, string file);
  //read admin file
  Admin* readFileAdmin(string file);
  //write admin file
  void writeFileAdmin( Admin* adminData, string file);
  //add message to forum
  void addToForum( string file1, string message);
  //read forum as a whole
  void readFileForum(string file1);
  //clear any file given in argument
  void clearFile(string file1);
  //forum functionality
  void openForum(regUsers &uGuest);
  //add to log file of nutrition
  void addToLog( string file1, Nutrition log);
  //red nutrition log file for a user
  void readFileLog(string file1, regUsers uGuest);
  //nutrition log functionality
  void openLog(regUsers &uGuest);
  //add to workout file
  void addToWorkout( string file1, Exercise log);
  //read workout file for user
  void readFileWorkout(string file1, regUsers uGuest);
  //workout log functionality
  void openWorkoutLog(regUsers &uGuest);
  
};

  regUsers* FileHandler::readFileUsers(string file){

    //open file to read
    this->file.open(file, ios::binary | ios::in);

    //create temp object
    regUsers obj;
    obj.decrementTotal();

    this->file.read((char*)&obj, sizeof(obj));
    int size = obj.getTotal();

    //create regular user array of acquired size
    regUsers *usersData = new regUsers[size]; 

    //assign prior read object to start of array
    usersData[0]=obj;
    
    //read rest of the data into the array
    for (int i = 1; i < size; i++) {
      this->file.read((char*)&usersData[i], sizeof(regUsers));
    }

    this->file.close();

    //increment total to set it back
    obj.incrementTotal();

    return usersData;

  }

  void FileHandler::writeFileUsers( regUsers* usersData, string file){

    //set total of first element to value of static total variable
    usersData[0].setTotal(usersData[0].getTotalUsers());
  
    //write file
    this->file.open(file, ios::binary | ios::out);

    for (int i = 0; i < usersData[0].getTotalUsers(); i++) {
      this->file.write((char*)&usersData[i], sizeof(regUsers)); 
    }

    this->file.close();

  }

  Trainers* FileHandler::readFileTrainers(string file){

    //read file 
    this->file.open(file, ios::binary | ios::in);

    //create temp object
    Trainers obj1;
    obj1.decrementTotal();

    this->file.read((char*)&obj1, sizeof(obj1));
    int size = obj1.getTotal();
    
    //create regular user array of acquired size
    Trainers *trainersData = new Trainers[size]; 

    //assign prior read object to start of array
    trainersData[0]=obj1;

    //read rest of the data into the array
    for (int i = 1; i < size; i++) {
      this->file.read((char*)&trainersData[i], sizeof(Trainers));
    }

    this->file.close();

    //increment total to set it back
    obj1.incrementTotal();
    

    return trainersData;
  }
  
  void FileHandler::writeFileTrainers( Trainers* trainersData, string file){
  
    //set total of first element to value of static total variable
    trainersData[0].setTotal(trainersData[0].getTotalUsers());

    //write file
    this->file.open(file, ios::binary | ios::out);
    
    for (int i = 0; i < trainersData[0].getTotalUsers(); i++) {
      this->file.write((char*)&trainersData[i], sizeof(Trainers)); 
    }

    this->file.close();
  }

  Admin* FileHandler::readFileAdmin(string file){
    
    //create temp object
    Admin obj2;
    obj2.decrementTotal();

    //read file 
    this->file.open(file, ios::binary | ios::in);

    this->file.read((char*)&obj2, sizeof(obj2));
    int size = obj2.getTotal();

    //create regular user array of acquired size
    Admin *adminData = new Admin[size]; 

    //assign prior read object to start of array
    adminData[0]=obj2;

    //read rest of the data into the array
    for (int i = 1; i < size; i++) {
      this->file.read((char*)&adminData[i], sizeof(Admin));
    }

    this->file.close();

    //increment total to set it back
    obj2.incrementTotal();

    return adminData;
  }

  void FileHandler::writeFileAdmin( Admin* adminData, string file){

    //set total of first element to value of static total variable
    adminData[0].setTotal(adminData[0].getTotalUsers());

    //write file
    this->file.open(file, ios::binary | ios::out);
    
    for (int i = 0; i < adminData[0].getTotalUsers(); i++) {
      this->file.write((char*)&adminData[i], sizeof(Admin)); 
    }

    this->file.close();
   }

  void FileHandler::addToForum( string file1, string message){
   
    file.open(file1, ios::binary | ios::app);

    //store size and then the message as a cstring(character array)
    int size1 = message.size();
    file.write((char*)&size1, sizeof(int));
    file.write(message.c_str(), size1);

    file.close();

  }

  void FileHandler::readFileForum(string file1){
  
    //open file
    this->file.open(file1, ios::binary | ios::in);

    cout<<endl;
    cout << "_______  _____   ______ _     _ _______" << endl;
    cout << "|______ |     | |_____/ |     | |  |  |" << endl;
    cout << "|       |_____| |    \\_ |_____| |  |  |\n\n" << endl;

    int size2;

    //read and display whole forum
    while (file.read((char*)&size2, sizeof(int))){
      
      //read messages as character arrays
      char* temp = new char[size2 + 1];
      file.read(temp, size2);
      temp[size2] = '\0';

      cout<<temp;
      delete[] temp;
    }

    this->file.close();
    cout<<endl;
  }

  void FileHandler::clearFile(string file1){
    this->file.open(file1, ios::binary | ios::out);
    this->file.close();
  }

  void FileHandler::openForum(regUsers &uGuest){
    bool exit1 = false;

      while (exit1 == false){
        
        int input1;
        string message;

        input1 = uGuest.openForum();  

        switch (input1){
          case 1 :
            
            readFileForum("forum.bin");
            cout<<"";
            break;

          case 2 :
            
            cin.ignore(); 
            cout << "Enter new message to upload : ";
            getline(cin,message);

            message = "\n"+uGuest.getName() + " : "+ message;

            addToForum("forum.bin",message);

            cout<<"\nMessage uploaded successfully ^_^\n";
            break;

          case 3 :
            exit1=true;
            break;
        }

      }
  }

  void FileHandler::addToLog( string file1, Nutrition log){
  
    
    file.open(file1, ios::binary | ios::app);

    file.write((char*)&log, sizeof(Nutrition));

    file.close();

  }

  void FileHandler::readFileLog(string file1, regUsers uGuest){
    
    Nutrition obj;

    //open file
    this->file.open(file1, ios::binary | ios::in);

    cout << "_  _ _  _ ___ ____ _ ___ _ ____ _  _    _    ____ ____ " << endl;
    cout << "|\\ | |  |  |  |__/ |  |  | |  | |\\ |    |    |  | | __ " << endl;
    cout << "| \\| |__|  |  |  \\ |  |  | |__| | \\|    |___ |__| |__] " << endl;
    cout << "                                                        " << endl;

    int count = 0;
    while (this->file.read((char*)&obj, sizeof(Nutrition))) {
      if (uGuest.getId() == obj.id){
        cout<<"\nlog#"<<++count<<endl;
        cout << "Date: " << obj.date << endl;
        cout << "Meal: " << obj.meals << endl;
        cout << "Calories intake: " << obj.caloriesIntake << endl;
        cout << endl;
        count++;
      }
        
    }
    this->file.close();
    if (count == 0){
      cout << "\nNo nutrition log found" << endl;
    }
    cout<<endl;

  }

  void FileHandler::openLog(regUsers &uGuest){
    bool exit1 = false;

    while (exit1 == false){
        
      int input1;
      int cals,recs;
      
      string temp;
      Nutrition obj;

      input1 = uGuest.openLog();  

      switch (input1){
        case 1 :
            
          readFileLog("nLog.bin",uGuest);
          break;

        case 2 :
            
          //set id;
          obj.id = uGuest.getId();

          cin.ignore();
          cout << "Enter meal name: ";
          cin >> temp;
          obj.meals = temp;

          cin.ignore();
          cout << "Enter calories intake: ";
          cin >> cals;
          obj.caloriesIntake = cals;

          cin.ignore();
          cout<<"Enter date in (dd/mm/yy) format: \n";  
          cin>>obj.date;          
          
          addToLog("nLog.bin",obj);

          cout<<"\nLog uploaded successfully ^_^\n";
          break;

        case 3:

          clearFile("nLog.bin");
          cout<<"\n Log cleared successfully ^_^ \n";
          break;

        case 4 :

          recs = uGuest.displayRecs();
          if (recs==1){
            cout << "\nTo lose weight, focus on creating a calorie deficit by consuming fewer calories than you burn." << endl;
            cout << "Include a variety of nutrient-dense foods such as fruits, vegetables, lean proteins, and whole grains in your diet." << endl;
            cout << "Incorporate regular physical activity into your routine, aiming for at least 150 minutes of moderate-intensity aerobic exercise per week." << endl;
            cout << "Monitor your progress regularly and make adjustments to your diet and exercise routine as needed." << endl;
            cout << endl;
          }
          else if(recs==2){
            cout << "To build muscle, prioritize resistance training exercises that target major muscle groups, such as squats, deadlifts, bench presses, and rows." << endl;
            cout << "Gradually increase the intensity and volume of your workouts to promote muscle growth." << endl;
            cout << "Ensure you're consuming enough protein to support muscle repair and growth, aiming for around 1.6 to 2.2 grams of protein per kilogram of body weight per day." << endl;
            cout << "Get adequate rest and recovery between workouts to allow muscles to repair and grow stronger." << endl;
            cout << endl;
          }
          else if(recs == 3){

            cout << "To improve overall health, focus on eating a balanced diet rich in fruits, vegetables, whole grains, lean proteins, and healthy fats." << endl;
            cout << "Incorporate regular physical activity into your routine, including a mix of cardio exercises (e.g., walking, jogging, cycling), strength training, and flexibility exercises (e.g., yoga, stretching)." << endl;
            cout << "Prioritize stress management techniques such as mindfulness, meditation, deep breathing exercises, or engaging in hobbies and activities you enjoy." << endl;
            cout << "Ensure you're getting enough quality sleep each night, aiming for 7-9 hours for most adults." << endl;
          }
          break;

        case 5 :
          exit1=true;
          break;
          
        }

    }
  }

  void FileHandler::addToWorkout( string file1, Exercise log){
  
    
    file.open(file1, ios::binary | ios::app);

    file.write((char*)&log, sizeof(Exercise));

    file.close();

  }
  
  void FileHandler::readFileWorkout(string file1, regUsers uGuest){
    
    Exercise obj;

    //open file
    this->file.open(file1, ios::binary | ios::in);

    cout << "_ _ _ ____ ____ _  _ ____ _  _ ___    _    ____ ____ " << endl;
    cout << "| | | |  | |__/ |_/  |  | |  |  |     |    |  | | __ " << endl;
    cout << "|_|_| |__| |  \\ | \\_ |__| |__|  |     |___ |__| |__] " << endl;
    cout << "                                                      " << endl;


    int count = 0;
    while (this->file.read((char*)&obj, sizeof(Exercise))) {
      if (uGuest.getId() == obj.id){
        cout<<"\nlog#"<<++count<<endl;
        cout << "Date: " << obj.date << endl;
        cout << "Workout Type: " << obj.Type<< endl;
        cout << "Intensity: " << obj.intensity<< endl;
        cout << "Calories burnt: " << obj.caloriesBurnt<< endl;
        cout << "Duration: " << obj.Duration << endl;
        cout << endl;
        count++;
      }
      
        
    }
    this->file.close();

    if (count == 0){
      cout << "\nNo workout log found" << endl;
    }

  }

  void FileHandler::openWorkoutLog(regUsers &uGuest){
    bool exit1 = false;

    while (exit1 == false){
        
      int input1=0;
      int temp1;
      
      string temp;
      Exercise obj;

      input1 = uGuest.workoutMenu();  

      switch (input1){
        
        case 1 :
            
          //set id;
          obj.id = uGuest.getId();

          cin.ignore();
          cout << "Enter type (Strength, Cardio, Core, Cross-fit ): ";
          cin >> temp;
          obj.Type= temp;

          cin.ignore();
          cout << "Enter duration in minutes: ";
          cin >> temp1;
          obj.Duration = temp1;

          //cin.ignore();
          cout << "Enter calories Burnt: ";
          cin >> temp1;
          obj.caloriesBurnt = temp1;

          cin.ignore();
          cout<<"Enter date in (dd/mm/yy) format: ";  
          cin>>obj.date;  

          cin.ignore();
          cout << "Enter intensity: ";
          cin >> temp1;
          obj.intensity = temp1;  
          
          addToWorkout("workout.bin",obj);

          cout<<"\nLog uploaded successfully ^_^\n";
          break;

        case 2 :
          
          for (int i = 0 ; i< 5; i++){
            
            string temp;

            cout<<"Enter exercise in preference "<<i+1<<" : ";
            cin>>temp;

            uGuest.setExercise(i,temp);
          }

        case 3:

          readFileWorkout("workout.bin", uGuest);
          break;

        case 4:

          clearFile("workout.bin");
          cout<<"\n Log cleared successfully ^_^ \n";
          break;

        case 5 :
          exit1=true;
          break;    
      }
    }
  }
