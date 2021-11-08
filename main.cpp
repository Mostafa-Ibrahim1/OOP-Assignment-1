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
    bool entryAddedSuccessfully=false;
    string allowedPhoneNumberCharacters="0123456789";
    bool isPhoneNumberValid=false;

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

    // MyPhoneBook pb1(4);
    // bool result=pb1.addEntry("Mostafa","123456780010");
    // cout<<result<<endl;
    // MyPhoneBook pb2(pb1);
    return 0;
}