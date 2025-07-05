#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;
 // charcters types
string generatePassword(int length, bool Uppercase, bool Lowercase, bool Numbers, bool Symbols) {
    string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string lowercase = "abcdefghijklmnopqrstuvwxyz";
    string numbers = "0123456789";
    string symbols = "!@#$%^&*()_-+=<>?";
    string allCharacters = "";

    if (Uppercase) {// ask a user if want uppercase 
        allCharacters += uppercase;
    }
    if (Lowercase) {// ask a user if want Lowercase
        allCharacters += lowercase;
    }
    if (Numbers) {// ask a user if want Numbers
        allCharacters += numbers;
    }
    if (Symbols) {// ask a user if want Symbols 
        allCharacters += symbols;
    }

    if (allCharacters.empty()) {// if a user does not enter anything into variable allcharacters 
        return "Error: No character types selected!";
    }

    string password = "";
    srand(time(0));

    for (int i = 0; i < length; i++) {
        int random = rand() % allCharacters.length();
        password += allCharacters[random];
    }

    return password;
}

int main() {
    int length;
    bool Uppercase, Lowercase,Numbers, Symbols;

    cout << "Enter the desired password length (8 to 16): ";
    cin >> length;

    if (length < 8 || length > 16) { 
        cout << "Invalid password length. Please enter a length between 8 and 16." << endl;
        return 0;
    }

    cout << "Include uppercase letters? (1 for yes, 0 for no): ";// check if want include uppercase (yes :1)(No :0)
    cin >> Uppercase;

    cout << "Include lowercase letters? (1 for yes, 0 for no): ";// check if want include lowercase  (yes :1)(No :0)
    cin >> Lowercase;

    cout << "Include numbers? (1 for yes, 0 for no): ";// check if want include numbers (yes :1)(No :0)
    cin >> Numbers;

    cout << "Include symbols? (1 for yes, 0 for no): ";// check if want include symbols (yes :1)(No :0)
    cin >> Symbols;

    string password = generatePassword(length, Uppercase, Lowercase, Numbers, Symbols);

    if (password == "Error: No character types selected!") {
        cout << password << endl;
    } else {
        cout << "Generated password: " << password << endl;
    }

    return 0;
}

