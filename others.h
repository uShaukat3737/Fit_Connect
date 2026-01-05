
bool validateInput(int min, int max,int input){
  if(input > max || input < min){
    return false;
  }
  else {
    return true;
  }
}

int inputValidation(int min, int max, int input){
  
  bool validInput = false;

  validInput = validateInput(min,max,input);
  
  while (validInput == false){
    cout<<"invalid input "<<endl;
    cin>>input;
    validInput=validateInput(min,max,input);
  }

  return input;
}


bool loginAuthenticationAdmin(int input , Admin *arr ){

  string temp1; 
  bool userFound = false, allowed= false;
  
  while (userFound == false){
    //look for user
    for (int j= 0; j<arr[0].getTotal(); j++ ){
      if (input == arr[j].getId()){
      
        userFound = true;

        cout<<"Password: ";
        cin>>temp1;

        //check if password correct
        if (temp1 == arr[j].getPassword()){
          allowed = true;
        }
        //handle incorrect password
        else {
          cout<<"\nPassword incorrect\n";
          cout<<"Re-enter password or enter \"E\" key to exit :";
          cin>>temp1;

          while (!(temp1 == arr[j].getPassword())){
              
            cout<<"\nPassword incorrect\n";
            cout<<"Re-enter password or enter \"E\" key to exit :";
            cin>>temp1;
            if (temp1 == "e"|| temp1 == "E"){
              allowed= false;
              break;
            }
          }

          allowed = true;

          if (temp1 == "e"|| temp1 == "E"){
            allowed= false;
          }

        }
      
        break;
      }
    }
    //handle incorrect user id
    if ( userFound == false ){
    
      cout<<"Id not found\n";
      cout<<"Re-enter id or enter \"E\" key to exit :";
      cin>>input;

      if (temp1 == "e"|| temp1 == "E"){
        allowed = false;
      }
    }
  }
  
  return allowed;
}

bool loginAuthenticationUser(int input , regUsers *arr ){

  string temp1; 
  bool userFound = false, allowed= false;
  
  while (userFound == false){
    //look for user
    for (int j= 0; j<arr[0].getTotal(); j++ ){
      if (input == arr[j].getId()){
      
        userFound = true;

        cout<<"Password: ";
        cin>>temp1;

        //check if password correct
        if (temp1 == arr[j].getPassword()){
          allowed = true;
        }
        //handle incorrect password
        else {
          while ((temp1 != arr[j].getPassword())){
              
            cout<<"\nPassword incorrect\n";
            cout<<"Re-enter password or enter \"E\" key to exit : ";

            cin>>temp1;

            if (temp1 == "e"|| temp1 == "E"){
              allowed= false;
              break;
            }
          }

          allowed = true;

          if (temp1 == "e"|| temp1 == "E"){
            allowed = false;
          }

        }
      
        break;
      }
    }
    //handle incorrect user id
    if ( userFound == false ){
    
      cout<<"Id not found\n";
      cout<<"Re-enter id or enter \"E\" key to exit :";
      cin>>input;

      if (temp1 == "e"|| temp1 == "E"){
        allowed = false;
        break;
      }
    }
  }
  
  return allowed;
}

bool loginAuthenticationTrainer(int input , Trainers *arr ){

  string temp1; 
  bool userFound = false, allowed= false;
  
  while (userFound == false){
    //look for user
    for (int j= 0; j<arr[0].getTotal(); j++ ){
      if (input == arr[j].getId()){
      
        userFound = true;

        cout<<"Password: ";
        cin>>temp1;

        //check if password correct
        if (temp1 == arr[j].getPassword()){
          allowed = true;
        }
        //handle incorrect password
        else {
          cout<<"\nPassword incorrect\n";
          cout<<"Re-enter password or enter \"E\" key to exit :";
          cin>>temp1;

          while (!(temp1 == arr[j].getPassword())){
              
            cout<<"\nPassword incorrect\n";
            cout<<"Re-enter password or enter \"E\" key to exit :";
            cin>>temp1;
            if (temp1 == "e"|| temp1 == "E"){
              allowed= false;
              break;
            }
          }

          allowed = true;

          if (temp1 == "e"|| temp1 == "E"){
            allowed= false;
          }

        }
      
        break;
      }
    }
    //handle incorrect user id
    if ( userFound == false ){
    
      cout<<"Id not found\n";
      cout<<"Re-enter id or enter \"E\" key to exit :";
      cin>>input;

      if (temp1 == "e"|| temp1 == "E"){
        allowed = false;
        break;
      }
    }
  }
  
  return allowed;
}


void progressReportUpdate(regUsers &uGuest){
  
  fstream tempFile;
  Exercise obj;
  
  //open file
  tempFile.open("workout.bin", ios::binary | ios::in);

  int count = 0,intensity=0,duration=0,calBurnt=0;
  while (tempFile.read((char*)&obj, sizeof(Exercise))) {
    if (uGuest.getId() == obj.id){
          
      count++;
      intensity+=obj.intensity;
      duration+=obj.Duration;
      calBurnt+=obj.caloriesBurnt;

    }
        
  }
  tempFile.close();

  cout << "___  ____ ____ ____ ____ ____ ____ ____    ____ _  _ ____ _    _   _ ____ _ ____ " << endl;
  cout << "|__] |__/ |  | | __ |__/ |___ [__  [__     |__| |\\ | |__| |     \\_/  [__  | [__  " << endl;
  cout << "|    |  \\ |__| |__] |  \\ |___ ___] ___]    |  | | \\| |  | |___   |   ___] | ___] " << endl;
  cout << "                                                                                   " << endl;

  //set rank
  uGuest.setRank(uGuest.calculateRank(duration,intensity,count)+uGuest.getRank());

  cout<<"Rank : "<<uGuest.getRank()<<endl;

  if (uGuest.getRank() >20){
    cout<<"Tier : Champion"<<endl;
  }
  else if(uGuest.getRank() >16){
    cout<<"Tier : Diamond"<<endl;
  }
  else if (uGuest.getRank() >8){
    cout<<"Tier : Gold"<<endl;
  }
  else if (uGuest.getRank() >5){
    cout<<"Tier : Silver"<<endl;
  }
  else{
    cout<<"Tier : Bronze"<<endl;
  }

  cout<<"calories burnt (per 10 cals): ";
  for (int i = 0; i<calBurnt/10 ;i++){
    cout<<"*";
  }

  cout<<endl;

}
