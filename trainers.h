//inherits Users
class Trainers : public Users {

private:

  static int totalTrainers;
  int total;
  int price;
  string availability;


public:

  //constructors
  Trainers(string name = "", string email = "", string password = "",int price=0, string availability= ""){

    //increment total user upon instance creation and assign to ID (this way Id always Unique)
    totalTrainers++;
    uId = totalTrainers;

    //assigning attributes
    this->name = name;
    this->email = email;
    this->password = password;
    this->availability= availability;
    this->price = price;

  }

  Trainers( Trainers &obj){

    //increment total user upon instance creation and assign to ID (this way Id always Unique)
    this->totalTrainers= obj.totalTrainers;

    uId = obj.uId;
    
    //assigning attributes
    this->name = obj.name;
    this->email = obj.email;
    this->password = obj.password;
    this->availability= obj.availability;
    this->price = obj.price;

  }

  //getters
  int getTotal(){return total;}
  int getPrice(){return price;}
  string getAvailability(){ return availability;}

  //setters
  void setTotal(int total){this->total = total;}
  void setPrice(int price){this->price = price;}
  void setAvailability(string avail){ availability= avail;}


  //overrided methods
  int getTotalUsers() {return totalTrainers;}
  void incrementTotal(){totalTrainers++;}
  void decrementTotal(){totalTrainers--;}

  //member functions 

  //adds trainer
  void addToArr( Trainers *&arr, int size);
  //displays trainer info
  void DisplayInfo();
  //trainer main menu
  void displayMenu();
  //updates trainer info
  void updateInfo(Trainers *arr);
  //views current customers of the trainer
  void viewCustomerList();
  //send message to desired customer
  void addMessage(int id, string message);
  //view messages from different customers
  void viewMessages(string file1);
  //chatbox display
  int chatMenu();
  //chatbox functionality
  void openChatMenu();
  
  //operator overloading
  friend istream& operator>>(istream &in , Trainers &obj){
    
    in>>obj.name;
    in>>obj.email;
    in>>obj.price;
    in>>obj.availability;
    
    return in;

  }

  ~Trainers(){

    totalTrainers--;
  }
};

//initialise static variable total count
int Trainers::totalTrainers = 0;

  void Trainers::addToArr( Trainers *&arr, int size){
  
  //copy old arr
  Trainers *arr2= new Trainers[size+1];

  for (int i = 0; i<size; i++){
    
    arr2[i].setName(arr[i].getName());
    arr2[i].setId(arr[i].getId());
    arr2[i].setAvailability(arr[i].getAvailability());
    arr2[i].setPrice(arr[i].getPrice());
    arr2[i].setEmail(arr[i].getEmail());
    arr2[i].setPassword(arr[i].getPassword());
    
  }
  
  //add in new record
  arr2[size].setName(getName());
  arr2[size].setId(getId());
  arr2[size].setAvailability(getAvailability());
  arr2[size].setPrice(getPrice());
  arr2[size].setEmail(getEmail());
  arr2[size].setPassword(getPassword());

  //delete memory allocated to old arr
  delete [] arr;
  arr=arr2;

}

  void Trainers::DisplayInfo(){

    cout << "Trainer ID: " << uId << endl;
    cout << "Name: " << name << endl;
    cout << "Email: " << email << endl;
    cout << "Package price: " << price << endl ;
    cout << "Availability: " << availability << endl ;

  }

  void Trainers::displayMenu(){
    
    cout << "\n╔════════════════════════════════════╗" << endl;
    cout << "║        Trainer Main Menu           ║" << endl;
    cout << "╠════════════════════════════════════╣" << endl;
    cout << "║ 1. Update Info                     ║" << endl;
    cout << "║ 2. View Customers                  ║" << endl;
    cout << "║ 3. Send Message                    ║" << endl;
    cout << "║ 4. Exit Program                    ║" << endl;
    cout << "╚════════════════════════════════════╝" << endl;
    cout << "Enter your choice (1-4): ";

  }

  void Trainers::updateInfo(Trainers *arr) {
    
    bool exit = false;

    while (exit == false){
      
      cout << "\n╔════════════════════════════════════════════╗" << endl;
      cout << "║            Update Trainer Info             ║" << endl;
      cout << "╠════════════════════════════════════════════╣" << endl;
      cout << "║ 1. Name                                    ║" << endl;
      cout << "║ 2. Email                                   ║" << endl;
      cout << "║ 3. availability timings                    ║" << endl;
      cout << "║ 4. Package price                           ║" << endl;
      cout << "║ 5. Password                                ║" << endl;
      cout << "║ 6. Back to Main Menu                       ║" << endl;
      cout << "╚════════════════════════════════════════════╝" << endl;
      cout << "Enter the number corresponding to the information you want to update: ";

      int choice;
      cin >> choice;

      while (choice > 6 || choice < 1){
        cout << "Invalid choice. Please enter a number between 1 and 6: " << endl;
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

            for (int i =0; i<totalTrainers; i++){
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
        
          cout << "Enter availability timing: ";    
          cin.ignore(); // Clear buffer
          getline(cin, availability);

          cout<<"\nAvailability timing updated successfully ^_^\n";
          break;

        case 4:
        
          do{
          
            cout << "Enter new package pricing: ";
            cin >> price;

            if (price <-1){
              cout<<"Entered weight invalid, ";
            }

          }while (price < -1);
        
          cout<<"\nPackage pricing updated successfully ^_^\n";
          break;

        case 5:
          do{
            cout << "Enter new password: ";
            cin >> password;

            if (validPassword(password)== false){
              cout<<"Entered password invalid, ";
            }
          } while (validPassword(password)== false);
          cout<<"\nPassword updated successfully ^_^\n";

          break;

        case 6:
        
          //return back to user menu
          exit = true;
          break;
      }
    }  
  }

  void Trainers::viewCustomerList(){
    
    fstream file;
    bool found= false;;

    //open file to read
    file.open("users.bin", ios::binary | ios::in);

    //create temp object
    regUsers obj;
    obj.decrementTotal();

    file.read((char*)&obj, sizeof(obj));
    int size = obj.getTotal();

    if (obj.getTrainerId()==uId){
      cout<<endl;
      obj.displayInfo();
      cout<<endl;
      found = true;
    }
    else {
      //read rest of the data into the array
      for (int i = 1; i < size; i++) {
        file.read((char*)&obj, sizeof(regUsers));
        if (obj.getTrainerId()==uId){
          cout<<endl;
          cout<<"customer id: "<<obj.getId()<<endl;
          cout<<"customer name: "<<obj.getName();
          cout<<endl;
          found = true;
          
        }
      }
    }

    file.close();

    //increment total to set it back
    obj.incrementTotal();

    if (found == false){
      cout<<"\nNo customers found !\n";
    }
  }

  void Trainers::addMessage(int id, string message){
   fstream file;

   file.open("messages.bin", ios::binary | ios::app);

    //add trainer id 
    file.write((char*)&uId, sizeof(int));
    //user id
    file.write((char*)&id, sizeof(int));

    //add message
    //store size and then the message as a cstring(character array)
    int size1 = message.size();
    file.write((char*)&size1, sizeof(int));
    file.write(message.c_str(), size1);

    file.close(); 
  }

  void Trainers::viewMessages(string file1){
    //open file
    fstream file;
    file.open(file1, ios::binary | ios::in);

    cout << "____ _  _ ____ ___    ___  ____ _  _ " << endl;
    cout << "|    |__| |__|  |     |__] |  |  \\/  " << endl;
    cout << "|___ |  | |  |  |     |__] |__| _/\\_ " << endl<<endl;

    int size2,tId,temp;

    //read and display whole forum
    while (file.read((char*)&tId, sizeof(int))){
      
      if (tId==uId){
        file.read((char*)&temp, sizeof(int));
        cout<<"customer id: "<<temp<<" --> ";
        file.read((char*)&size2, sizeof(int));
        //read messages as character arrays
        char* temp = new char[size2 + 1];
        file.read(temp, size2);
        temp[size2] = '\0';

        cout<<temp<<endl;

        delete[] temp;
        
      }
      
    }

    file.close();
    cout<<endl;
  }

  int Trainers::chatMenu(){
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
  
  void Trainers::openChatMenu(){
    bool exit1 = false;

    while (exit1 == false){
        
      int input1=0;
      int temp1;

      
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
          cout << "Enter customer id you want to send message to: ";
          cin>> temp1;

          cin.ignore(); 
          cout << "Enter new message to upload : ";
          getline(cin,message);

          message = name + " : "+ message;

          addMessage(temp1,message);

          cout<<"\nMessage uploaded successfully ^_^\n";
          break;

        case 3:

          exit1=true;
          break;    
      }
    }
  }