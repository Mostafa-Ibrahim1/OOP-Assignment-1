#include <iostream>
#include <string>
#include <iomanip>
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
    int * findNameArray=new int[phoneBookSize];
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
    int * findPhoneArray=new int[phoneBookSize];
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

int main(){
    //Used for testing functionality

    MyPhoneBook pb1(2);
    bool result1=pb1.addEntry("Mostafa Ibrahim","01045678901");//11 valid and empty space available == true
    cout<<"Entry 1: "<<result1<<endl;
    bool result2=pb1.addEntry("Mostafa","12345)78#01");//11 not valid and empty space available == false
    cout<<"Entry 2: "<<result2<<endl;
    bool result3=pb1.addEntry("Mostafa","123456708901");//not 11 but valid and empty space available == false
    cout<<"Entry 3: "<<result3<<endl;
    bool result4=pb1.addEntry("M.Ibrahim Abdellatif","01134578900");//11 valid and empty space available == true
    cout<<"Entry 4: "<<result4<<endl;
    bool result5=pb1.addEntry("Mostafa","01010101010");//11 valid and empty space NOT available == false
    cout<<"Entry 5: "<<result5<<endl;
    
    // Entry 1: 1
    // Entry 2: 0
    // Entry 3: 0
    // Entry 4: 1
    // Entry 5: 0

    //testing displayEntryAtIndex
    //If index is out of range will return false and won't display an entry
    //If index is in range then it will return true and will display the entry of that index
    bool res=pb1.displayEntryAtIndex(1);
    cout<<"display Entry :"<<res<<endl;

    //testing findBy
    int *resArray=pb1.findByName("M");
    cout<<resArray[0]<<endl;
    cout<<resArray[1]<<endl;
    cout<<"Phone :"<<endl;
    int *resArray2=pb1.findByPhone("010");
    cout<<resArray2[0]<<endl;
    cout<<resArray2[1]<<endl;

    // to test updateNameAt
    bool test = pb1.updateNameAt("Youssef",0);
    pb1.displayEntryAtIndex(0);
    cout << test << endl; // 1

    //to test updatePhoneAt
    bool test2 = pb1.updatePhoneAt("12345678900",0);
    pb1.displayEntryAtIndex(0);
    cout << test2 << endl; //1
    return 0;
}