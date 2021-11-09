#include <iostream>
#include <string>
using namespace std;

class MyPhoneBook
{
 string* names;
 string* phones;
 int phoneBookSize;

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
//  ~MyPhoneBook();
};
//Constructors
MyPhoneBook::MyPhoneBook(int phoneBookSize){
    this->phoneBookSize=phoneBookSize;
    names=new string[phoneBookSize];
    phones=new string[phoneBookSize];
    for(int i=0;i<phoneBookSize;i++){
        names[i]=" ";
        phones[i]=" ";
        }
}

MyPhoneBook::MyPhoneBook(const MyPhoneBook &phoneBook){
    phoneBookSize=phoneBook.phoneBookSize;
    names=new string[phoneBookSize];
    phones=new string[phoneBookSize];
    for(int i=0;i<phoneBookSize;i++){
        names[i]=phoneBook.names[i];
        phones[i]=phoneBook.phones[i];
    }
}

//Add Entry

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
}else{
    return false;
}
}




int main(){
    //Used for testing functionality

    MyPhoneBook pb1(2);
    bool result1=pb1.addEntry("Mostafa","12345678901");//11 valid and empty space available == true
    cout<<"Entry 1: "<<result1<<endl;
    bool result2=pb1.addEntry("Mostafa","12345)78#01");//11 not valid and empty space available == false
    cout<<"Entry 2: "<<result2<<endl;
    bool result3=pb1.addEntry("Mostafa","123456708901");//not 11 but valid and empty space available == false
    cout<<"Entry 3: "<<result3<<endl;
    bool result4=pb1.addEntry("Mostafa","12345778901");//11 valid and empty space available == true
    cout<<"Entry 4: "<<result4<<endl;
    bool result5=pb1.addEntry("Mostafa","223456708901");//11 valid and empty space NOT available == false
    cout<<"Entry 5: "<<result5<<endl;

    // Entry 1: 1
    // Entry 2: 0
    // Entry 3: 0
    // Entry 4: 1
    // Entry 5: 0
    return 0;
}