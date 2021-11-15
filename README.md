# OOP Assignment

OOP Assignment 1 SCS213 Course- FCAI CU

## MyPhoneBook Class
### Member Variables:
- [x] names (private): Dynamic array of strings
- [x] phones (private): Dynamic array of strings
- [x] phoneBookSize (private): integer
### Functions:
#### Constructors:

- [x] Parameterized One that takes the size of PhoneBook and allocate dynamic arrays of names and phones    MyPhoneBook(int)
- [x] Copy constructor to initialize a PhoneBook using another PhoneBook    MyPhoneBook(const MyPhoneBook&)


---

- [x] Member function (public): addEntry(string,string)
- Add name and phone number at the first empty space
- An entry is added if there's space in the array and if the phone number is valid (11 digits and doesn't include alphabet or special characters)
- return true if entry is added, false otherwise

---

- [x] Member function (public): displayAll()
- Displays all entries in the phone book

---

- [x] Member function (public): displayEntryAtIndex(int)
- Displays name and phone number at a specific index
- returns true if index is in range, false otherwise

---

- [x] Member function (public): displayEntryAtIndices(int*)
- Takes an array of zeroes and ones ( has the same size as class arrays (name and phone number))
- The entry where there is a one (in its index position) in the array will be displayed

---

- [x] Member function (public): findByName(string)
- Search in the PhoneBook by either
  - Full name
  - Part of a name
- Returns an array of ones and zeroes with the same size as PhoneBook (one for a match and zero otherwise)

---

- [x] Member function (public): findByPhone(string)
- Search in the PhoneBook by either
  - Full phone number
  - Part of a phone number
- Returns an array of ones and zeroes with the same size as PhoneBook (one for a match and zero otherwise)

---

- [x] Member function (public): updateNameAt(string,int)
- Update name in PhoneBook using the index of it
- Returns bool, true if the parameter index
  - is within range
  - and name is updated

---

- [x] Member function (public): updatePhoneAt(string,int)
- Update phone number in PhoneBook using the index of it
- Returns bool, true if the parameter index
  - is within range
  - and phone number is updated

---

- [x] Destructor
- Deallocate the dynamic arrays and leave no memory leak

To be done:
- [ ] Separate the class from the main.cpp (Header file and another cpp)
