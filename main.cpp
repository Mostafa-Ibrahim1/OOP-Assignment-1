#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class MyPhoneBook
{
 string* names;
 string* phones;
 int phoneBookSize;
 int * findNameArray;
 int * findPhoneArray;

 public:
 MyPhoneBook(int);
 MyPhoneBook(const MyPhoneBook&);
 bool addEntry(string ,string);
 bool displayEntryAtIndex(int);
 void displayEntryAtIndices(int*);
 void displayAll();
 int* findByName(string);
 int* findByPhone(string);
 bool updateNameAt(string, int);
 bool updatePhoneAt(string, int);
 ~MyPhoneBook();
};


//Constructors
MyPhoneBook::MyPhoneBook(int phoneBookSize){
    this->phoneBookSize=phoneBookSize;
    names=new string[phoneBookSize];
    phones=new string[phoneBookSize];
    findNameArray=new int[phoneBookSize];
    findPhoneArray=new int[phoneBookSize];

    for(int i=0;i<phoneBookSize;i++){
        names[i]=" ";
        phones[i]=" ";
        }
}

MyPhoneBook::MyPhoneBook(const MyPhoneBook &phoneBook){
    phoneBookSize=phoneBook.phoneBookSize;
    names=new string[phoneBookSize];
    phones=new string[phoneBookSize];
    findNameArray=new int[phoneBookSize];
    findPhoneArray=new int[phoneBookSize];

    for(int i=0;i<phoneBookSize;i++){
        names[i]=phoneBook.names[i];
        phones[i]=phoneBook.phones[i];
    }
}

// Destructor
MyPhoneBook::~MyPhoneBook()
{
    delete [] names;
    delete [] phones;
    delete [] findNameArray;
    delete [] findPhoneArray;
    names = NULL;
    phones = NULL;
    findNameArray = NULL;
    findPhoneArray = NULL;    
}

// Add Entry
bool MyPhoneBook::addEntry(string name ,string phone){
    bool entryAddedSuccessfully;
    string allowedPhoneNumberCharacters="0123456789";
    bool isPhoneNumberValid;

    if(phone.length()==11){
        for(int i=0;i<phone.length();i++){
            if(allowedPhoneNumberCharacters.find(phone[i])!=string::npos){
                isPhoneNumberValid=true;
            }else{
                isPhoneNumberValid=false;
                break;
            }
    }
    }else{
        isPhoneNumberValid=false;
    }

    // This is one of the conditions that leads to entry insertion failure (Phone number being not valid)
    if(isPhoneNumberValid==false){
        return false;
    }
    //Then it will check if there is an available place in the phonebook
    for(int i=0;i<phoneBookSize;i++){
        if(names[i]==" "&&phones[i]==" "){
            names[i]=name;
            phones[i]=phone;
            entryAddedSuccessfully=true;
            break;
        }else{
            entryAddedSuccessfully=false;
            continue;    
        }
    }
    if(entryAddedSuccessfully==true && isPhoneNumberValid==true){
        return true;
    }
    else
    {
        return false;
    }
}

// displayEntryAtIndex
bool MyPhoneBook::displayEntryAtIndex(int index){
    if(index>(phoneBookSize-1) || index<0){
        return false;
    }
    else{
        cout<<"Name : "<<names[index]<<endl;
        cout<<"Phone number : "<<phones[index]<<endl;
        return true;
    }
}

// findBy

// findByName
int * MyPhoneBook::findByName(string name){
    // entry.find(specific string)
    //int * findNameArray=new int[phoneBookSize]; Old declaration
    for(int i=0;i<phoneBookSize;i++){
        if(names[i].rfind(name,0)!=string::npos){
            findNameArray[i]=1;
        }else{
            findNameArray[i]=0;
        }
    }
    return findNameArray;

}

// findByPhone
int * MyPhoneBook::findByPhone(string phone){
    // entry.find(specific string)
    //int * findPhoneArray=new int[phoneBookSize]; Old declaration 
    for(int i=0;i<phoneBookSize;i++){
        if(phones[i].rfind(phone,0)!=string::npos){
            findPhoneArray[i]=1;
        }else{
            findPhoneArray[i]=0;
        }
    }
    return findPhoneArray;

}

// Function to display all entries.
void MyPhoneBook::displayAll()

{
    
    for (int i = 0; i < phoneBookSize; i++)
    {
        // If conditon to skip blank entries
        if(names[i] == " " && phones[i] == " ")
        {
            continue;
        }
        else 
        {
            cout << setw(20) << left << names[i];
            cout << setw(10) << phones[i];
            cout << endl;
        }
        
    }
    
}

// Update name at index.
bool MyPhoneBook::updateNameAt(string name, int index)
{
    bool indexIsValid = false;

    if (index < phoneBookSize && index >= 0)
    {
        indexIsValid = true;
    }
    
    if (indexIsValid)
    {
        names[index] = name;
        return true; 
    }
    else 
    {
        return false;
    }

}

// Update phone at index.
bool MyPhoneBook::updatePhoneAt(string phone, int index)
{
    string allowedPhoneNumberCharacters="0123456789";
    bool isPhoneNumberValid;

    if(phone.length()==11){
        for(int i=0;i<phone.length();i++){
            if(allowedPhoneNumberCharacters.find(phone[i])!=string::npos){
                isPhoneNumberValid=true;
            }else{
                isPhoneNumberValid=false;
                break;
            }
    }
    }else{
        isPhoneNumberValid=false;
    }

    // This is one of the conditions that leads to entry insertion failure (Phone number being not valid)
    if(isPhoneNumberValid==false){
        return false;
    }

    if (isPhoneNumberValid)
    {
        phones [index] = phone;
        return true;
    }
    else
    {
        return false;
    }
    

}

//Update phone at indices.
void MyPhoneBook::displayEntryAtIndices(int *indicesArray)
{
    bool isArrayValid = true;
    for (int i = 0; i < phoneBookSize; i++)
    {
        if (indicesArray[i] != 1 && indicesArray[i] != 0)
        {
            cout << "Array entered is not valid" << endl;
            isArrayValid = false;
            break;
        }
    }

    if (isArrayValid)
    {
        for (int i = 0; i < phoneBookSize; i++)
        {
            if (indicesArray[i] == 1)
            {
                cout << setw(10) << names[i];
                cout << setw(20) << phones[i];
                cout << endl;
            }
        
        }
    }
    
    
}

int main(){
    //Used for testing functionality

    MyPhoneBook pb1(2);
    bool result1=pb1.addEntry("Mostafa Ibrahim","01045678901");//11 valid and empty space available == true
    
    bool result2=pb1.addEntry("Mostafa","12345)78#01");//11 not valid and empty space available == false
    
    bool result3=pb1.addEntry("Mostafa","123456708901");//not 11 but valid and empty space available == false
    
    bool result4=pb1.addEntry("Mostafa Ibrahim","01134578900");//11 valid and empty space available == true
    
    bool result5=pb1.addEntry("Mostafa","01010101010");//11 valid and empty space NOT available == false
    /*
    // test for displayEntryAtIndices
    int *arr = new int [2];
    for (int i = 0; i < 2; i++)
    {
        cin >> arr[i];
    }
    
    pb1.displayEntryAtIndices(arr);
    */
    
    // Entry 1: 1
    // Entry 2: 0
    // Entry 3: 0
    // Entry 4: 1
    // Entry 5: 0

    //testing displayEntryAtIndex
    //If index is out of range will return false and won't display an entry
    //If index is in range then it will return true and will display the entry of that index
    bool res=pb1.displayEntryAtIndex(1);
    cout<<" "<<endl;

    //testing findBy
    int *resArray=pb1.findByName("M");
    int *resArray2=pb1.findByPhone("010");

    // to test updateNameAt
    bool test = pb1.updateNameAt("Youssef",0);
    pb1.displayEntryAtIndex(0);

    //to test updatePhoneAt
    bool test2 = pb1.updatePhoneAt("12345678900",0);
    pb1.displayEntryAtIndex(0);

    cout<<"----"<<endl;
    pb1.displayAll();
    
    //--------------------------
    cout<<""<<endl;
    cout<<"Program start!"<<endl;
    cout<<""<<endl;
    int sizeOfPhoneBook;
    cout<<"Enter the size of your Phone Book: ";
    cin>>sizeOfPhoneBook;
    MyPhoneBook userPhoneBook(sizeOfPhoneBook);
    for(int i=0;i<sizeOfPhoneBook;i++){
        string name;
        string phone;
        cout<<"Enter name "<<to_string(i+1)<<": ";
        cin>>name;
        cout<<"Enter phone "<<to_string(i+1)<<": ";
        cin>>phone;
        userPhoneBook.addEntry(name,phone);
    }
    cout<<""<<endl;

    bool programIsRunning=true;

    while(programIsRunning){
        string userChoice;
        cout<<""<<endl;
        cout<<""<<endl;
        cout<<"Enter your choice: "<<endl;
        cout<<"1- Display all phone book"<<endl;
        cout<<"2- Search for entry/entries by name"<<endl;
        cout<<"3- Search for entry/entries by phone"<<endl;
        cout<<"4- Find an entry by index"<<endl;
        cout<<"5- Update name by index"<<endl;
        cout<<"6- Update phone by index"<<endl;
        cout<<"7- Copy phone book to another and display entries of the new phone book"<<endl;
        cout<<"8- Exit"<<endl;
        cout<<"Choice: ";
        cin>>userChoice;
        cout<<""<<endl;
        if(userChoice=="1"){cout<<"Display all phone book"<<endl;}
        else if(userChoice=="2"){cout<<"Search by name"<<endl;}
        else if(userChoice=="3"){cout<<"Search by phone"<<endl;}
        else if(userChoice=="4"){cout<<"find entry by index"<<endl;}
        else if(userChoice=="5"){cout<<"update name by index"<<endl;}
        else if(userChoice=="6"){cout<<"update phone by index"<<endl;}
        else if(userChoice=="7"){cout<<"copy pb to another and display entries"<<endl;}
        else if(userChoice=="8"){
            programIsRunning=false;
            cout<<"exit"<<endl;}
        else{cout<<"Choice not available!"<<endl;}


    }
    
    
    return 0;



}