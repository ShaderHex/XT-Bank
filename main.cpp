#include <iostream>
#include <string.h>

int input = 0;
std::string username;
std::string password;
bool isLoggedIn = false;
bool isRegistered = false;
float wallet = 0.00;

void Register();
void mainMenu();
void Options();
void Deposit();
void withdraw();
void checkWallet();


int main() {
    mainMenu();
    return 0;
}

void Register() {
    std::cout<<"You do not have an account, May I take your username and password?\n";
    std::cout<<"Username: ";
    std::cin.ignore();
    std::getline(std::cin, username);

    std::cout<<"Password: ";
    std::cin.ignore();
    std::getline(std::cin, password);

    std::cout<<"\nGreat, you now have an account! press 1 to go back to the main page and login.\n";
    isRegistered = true;
    std::cin>>input;
    if (input == 1) {
        mainMenu();
    }
}

void login() {
    std::string inputUsername;
    std::string inputPass;
    std::cout<<"\nYou have not logged in but registered, please proceed to enter your password\n";

    std::cout<<"Username: ";
    std::cin.ignore();
    std::getline(std::cin, inputUsername);

    std::cout<<"Password: ";
    std::cin.ignore();
    std::getline(std::cin, inputPass);


    if (inputUsername == username && inputPass == password) {
        Options();
        isLoggedIn = true;
    } else {
        std::cout<<"\nSorry, Username or password are incorrect.\n";
        login();
    }
}

void Options() {
    std::cout<<"\nYou are logged in as " << username <<std::endl;
    std::cout<<"\n1. Deposit\n";
    std::cout<<"2. Withdraw\n";
    std::cout<<"3. Check wallet\n";
    std::cout<<"type any number except the listed one's to exit\n";
    std::cin>>input;
    switch(input) {
        case 1:
            Deposit();
        case 2:
            withdraw();
        case 3:
            checkWallet();
    }
}

void Deposit() {
    int moneyDepo;
    std::cout<<"\nHow much do you want to deposit? (Max: 10k usd at a time)\n";
    std::cin>>moneyDepo;
    if (moneyDepo > 10000){
        std::cout<<"You cannot deposit more than 10,000 usd at a time.\n";
        Deposit();
    } else {
        std::cout<<"Deposited "<< moneyDepo;
        wallet += moneyDepo;
        Options();
    }
}

void withdraw() {

}

void checkWallet() {
    std::cout<<"\nYou currently have "<<wallet<<std::endl;
    Options();
}

void mainMenu() {
    std::cout<<"*******************************************************************************\n";
    std::cout<<"*                           Welcome to XT Bank!                               *\n";
    std::cout<<"*                                                                             *\n";
    std::cout<<"*                 Please Choose one from the list to proceed                  *\n";
    std::cout<<"*******************************************************************************\n";

    std::cout<<"1. login\n";
    std::cout<<"2. Exit\n";

    std::cin>>input;
    std::cin.ignore();
    
    switch(input) {
        case 1:
            if (!isLoggedIn) {
                if (isRegistered){
                    login();
                } else {
                    Register();
                }
            }
    }
}
