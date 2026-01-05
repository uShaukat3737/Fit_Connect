#include <iostream>
#include <string>
//other file headers included in filehandling.h
#include "fileHandling.h"
#include "others.h"

using namespace std;

int main(){

  int input =0 ,id;
  string temp1="";
  bool  allowed = false,regularInterface=false, trainerInterface= false, adminInterface= false; 

  regUsers uGuest;
  Trainers tGuest; 
  Admin aGuest;

  //uGuest.setName("usman");
  uGuest.setId(1);

  uGuest.decrementTotal();
  tGuest.decrementTotal();
  aGuest.decrementTotal();

  regUsers *usersData;
  Trainers *trainersData;
  Admin *adminData ;

  int choice ;
  bool exit = false;
  bool tChoice= false;

  FileHandler file;

  //read data from all files
  usersData = file.readFileUsers("users.bin");
  trainersData = file.readFileTrainers("trainers.bin");
  adminData = file.readFileAdmin("admin.bin");

  cout  << "\n*********************************************************************\n"
        << "___________________     _________                              _____ \n"
        << "___  ____/__(_)_  /_    __  ____/________________________________  /_\n"
        << "__  /_   __  /_  __/    _  /    _  __ \\_  __ \\_  __ \\  _ \\  ___/  __/\n"
        << "_  __/   _  / / /_      / /___  / /_/ /  / / /  / / /  __/ /__ / /_  \n"
        << "/_/      /_/  \\__/      \\____/  \\____//_/ /_//_/ /_/\\___/\\___/ \\__/  \n\n"
        << "*********************************************************************\n\n";
  

  // Displaying options for user types and asking for input
  cout << "\n╔══════════════════════════════════════════════════╗" << endl;
  cout << "║          Select Your User Type                   ║" << endl;
  cout << "╠══════════════════════════════════════════════════╣" << endl;
  cout << "║ 1. Regular User                                  ║" << endl;
  cout << "║ 2. Trainer                                       ║" << endl;
  cout << "║ 3. Admin                                         ║" << endl; 
  cout << "║ 4. Exit                                          ║" << endl;
  cout << "╚══════════════════════════════════════════════════╝" << endl;
  cout << "\nEnter 1 for Regular User, 2 for Trainer, or 3 for Admin: ";
  cin >> input ;
  cout<<endl;

  input = inputValidation(1,4,input);

  if (input==4){
    
    cout << "\n";
    
  }
  else {
    //admin login
    if (input==3){
      cout << "\nWelcome! Enter login credentials: \n"<< "Admin id: ";
      cin>>id;

      allowed= loginAuthenticationAdmin(id,adminData);
      if (allowed==true){
        //call admin menu
        adminInterface=true;
        for (int i =0 ;i<aGuest.getTotal();i++){
          if(id==adminData[i].getId()){
            aGuest=adminData[i];
          }
        }
      }
      
    }
    else if (input == 1){
      //call user menu
      cout << "\nWelcome! What would you like to do?\n"<< "1. Log In\n"<< "2. Sign Up\n"<< "Enter the corresponding number: ";
      cin>>input;

      input = inputValidation(1,2,input);

      if (input == 1){
        cout << "\nEnter login credentials: \n"<< "user id: ";
        cin>>id;

        allowed= loginAuthenticationUser(id,usersData);

        if (allowed==true){
          
          regularInterface=true;
          //set uGuest as current user
          for (int i =0 ;i<usersData[0].getTotal();i++){
            if(id==usersData[i].getId()){
              uGuest=usersData[i];
            }
          }
        }

      }
      else {

        //create user and add to array
       
        cout << "Enter your name, email, age, weight and height (separated by spaces): ";
        cin >> uGuest;
        
        do{
          cout << "Set a 8 digit Alpha-Numeric password: ";
          cin >> temp1;

          if (uGuest.validPassword(temp1)== false){
            cout<<"Entered password invalid, ";
          }

        } while (uGuest.validPassword(temp1) == false);
        
        uGuest.setPassword(temp1);
        uGuest.setId(usersData[0].getTotalUsers());

        uGuest.addToArr(usersData,usersData[0].getTotalUsers());
        uGuest.displayInfo();
        cout << "\nUser account created successfully! \n";
        
        regularInterface=true;
        allowed= true;
        
      }

    }
    else {

      cout << "\nWelcome! Enter log in credentials: \n"<< "trainer id: ";
      cin>>id;

      allowed= loginAuthenticationTrainer(id,trainersData);
      if (allowed==true){
        trainerInterface=true;
        //set uguest as current user
        for (int i =0 ;i<trainersData[0].getTotal();i++){
          if(id==trainersData[i].getId()){
            tGuest=trainersData[i];
          }
        }
      }

    }
  }
    
  if (allowed == true){
    if (regularInterface== true){
      
      do{
        uGuest.displayMenu();
        cin>> choice;

        choice = inputValidation(1,10,choice);

        switch (choice)
        {
        //update info
        case 1:
      
          uGuest.updateInfo(usersData);

          //update changes into array
          for(int i= 0; i<uGuest.getTotalUsers();i++){
            if (usersData[i].getId()==uGuest.getId()){
              usersData[i]=uGuest;
            }   
          }

          break;

        //log in workout
        case 2: 

          file.openWorkoutLog(uGuest);
          break;
    
        //open forum
        case 3:

          file.openForum(uGuest);
          break;

        //open nutrition log
        case 4:

          file.openLog(uGuest);
          break;

        //progress analysis
        case 5:
      
          progressReportUpdate(uGuest);
          break;

        //challanges
        case 6:

          uGuest.openChallangesMenu();
          break;
        //location based features
        case 7:

          uGuest.openLocationMenu(usersData);
          break;
        //chat with trainer
        case 8:
          
          uGuest.openChatMenu();
          break;
        case 9:
          
          for (int i = 0; i< trainersData[0].getTotalUsers(); i++){
            cout<<endl;
            trainersData[i].DisplayInfo();
          }

          tChoice = false;
          cout<<endl<<"current trainer id of your trainer is : "<<uGuest.getTrainerId()<<endl;
         

          do {
            cout<<endl<<"Enter the trainer id you want to be assigned to: ";
            cin>>input;

            for (int i = 0; i< trainersData[0].getTotalUsers(); i++){
              if (trainersData[i].getId() == input){
                tChoice = true;
              }
            }

            if (tChoice == false){
              cout<<"Invalid trainer id, "<<endl;
            }

          }while(tChoice == false);

          uGuest.setTrainerId(input);

          cout<<"\nTrainer assigned successfully ^_^\n";

          cout<<endl<<"current trainer id of your trainer is : "<<uGuest.getTrainerId()<<endl;
          break;

        case 10:
          exit = true;
          //update changes into array
          for(int i= 0; i<usersData[0].getTotal();i++){
            if (usersData[i].getId()==uGuest.getId()){
              
              usersData[i]=uGuest;
              usersData[i].setPassword(uGuest.getPassword());
              
            }   
          }
          break;

        }

      }while (exit == false);

    }
    else if (trainerInterface==true){
      
      do{
        tGuest.displayMenu();
        cin>> choice;

        choice = inputValidation(1,8,choice);

        switch (choice)
        {
        //update info
        case 1:
      
          tGuest.updateInfo(trainersData);

          //update changes into array
          for(int i= 0; i<tGuest.getTotalUsers();i++){
            if (trainersData[i].getId()==tGuest.getId()){
              trainersData[i]=tGuest;
            }   
          }

          break;

        //view customers
        case 2: 

          tGuest.viewCustomerList();
          break;
    
        //open chat
        case 3:

          tGuest.openChatMenu();
          break;

        //exit
        case 4:

          exit = true;
          //update changes into array
          for(int i= 0; i<trainersData[0].getTotal();i++){
            if (trainersData[i].getId()==tGuest.getId()){
              trainersData[i]=tGuest;
            }   
          }
          
          break;

        }

      }while (exit == false);

      

    }
    else if (adminInterface==true){
      do{
        
        aGuest.displayMenu();
        cin>> choice;

        choice = inputValidation(1,8,choice);

        int account;

        switch (choice)
        {
        //user details
        case 1:
      
          do {
            cout << "Enter user id: ";
            cin >> account;

            if (account<0){
              cout<<"invalid user id, ";
            }
          } while (account < 0); 
          
          
          aGuest.ViewUserDetails(account);      
          break;

        //trainer details
        case 2: 

          do {
            cout << "Enter trainer id: ";
            cin >> account;

            if (account<0){
              cout<<"invalid user id, ";
            }
          } while (account < 0); 

          aGuest.ViewTrainerDetails(account);      
          break;
    
        //clear forum file
        case 3:

          file.clearFile("forum.bin");
          cout << "\nForum records cleared successfully! \n";
          break;

        //add trainer
        case 4:
          cout << "Enter trainer name, email, package price, and availabilty hours (separated by spaces): ";
          cin >> tGuest;

          tGuest.setPassword("00000000");
          tGuest.setId(usersData[0].getTotalUsers());
          tGuest.addToArr(trainersData,trainersData[0].getTotalUsers());
          tGuest.DisplayInfo();
          cout << "Password: " << "00000000" << endl;
          cout << "\ntrainer account created successfully! \n";
          
          break;
        
        //add user
        case 5:

          cout << "Enter user name, email, age, weight and height (separated by spaces): ";
          cin >> uGuest;
        
          uGuest.setPassword("00000000");
          uGuest.setId(usersData[0].getTotalUsers());
          uGuest.addToArr(usersData,usersData[0].getTotalUsers());
          uGuest.displayInfo();
          cout << "Password: " << "00000000" << endl;

          cout << "\nUser account created successfully! \n";
        
          break;

        //exit
        case 6:

          do {
            cout << "Enter user id: ";
            cin >> account;

            if (account<0){
              cout<<"invalid user id, ";
            }
          } while (account < 0); 

          aGuest.ViewWorkoutLog(account);
          break;
        
        case 7:

          do {
            cout << "Enter user id: ";
            cin >> account;

            if (account<0){
              cout<<"invalid user id, ";
            }
          } while (account < 0); 

          aGuest.ViewNutritionLog(account);
          break;
        
        case 8:

          exit = true;
          break;

        }

      }while (exit == false);
    }
  }
    
  //update data in all files
  file.writeFileAdmin(adminData,"admin.bin");
  file.writeFileUsers(usersData,"users.bin");
  file.writeFileTrainers(trainersData,"trainers.bin");

  //print goodbye message
  cout << " ____   __   __ _  ____         ___   __   ____  ____         __          __  " << endl;
  cout << "(_  _) / _\\ (  / )(  __)       / __) / _\\ (  _ \\(  __)       /  \\        /  \\ " << endl;
  cout << "  )(  /    \\ )  (  ) _)       ( (__ /    \\ )   / ) _)       (_/\\_) ____ (_/\\_)" << endl; 
  cout << " (__) \\_/\\_/(__/\\)(____)       \\___)\\_/\\_/(__/\\)(____)            (____)      \n" << endl << endl;

  //delete DMA
  delete[] usersData;
  delete[] trainersData;
  delete[] adminData;
  
}