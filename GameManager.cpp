/*
Name: Khaleel
Class: CS3307
Date: 2021-11-07
Desc: The game manager that holds all the objects and manages the game
*/

// imports
#include <GameManager.h>


// Initialize Businesses in ID order
Business tutor; // id = 1
Business spoke; // id = 2
Business wave; // id = 3
Business bookStore; // id = 4
Business theater; // id = 5
Business bikeRental; // id = 6

// Initialize Bank
BankAccount account();

// Initialize UI
// RAOUF WOULD Integrate here

/**
 * @brief Construct a new Game Manager:: Game Manager object
 */
GameManager::GameManager(){
    tutor = Business(1.07f, 1.0f, 1, 10.0, 1.0f, 4.0);
    spoke = Business(1.15f, 1.0f, 0, 50.0, 3.0f, 10.0);
    wave = Business(1.07f, 1.0f, 0, 10.0, 50.0f, 4.0);
    bookStore = Business(1.07f, 1.0f, 0, 10.0, 50.0f, 4.0);
    theater = Business(1.07f, 1.0f, 0, 10.0, 50.0f, 4.0);
    bikeRental = Business(1.07f, 1.0f, 0, 10.0, 50.0f, 4.0);

    account = BankAccount();
    account.deposit(100);
} // end method

/**
 * @brief Destroy the Game Manager:: Game Manager object
 */
GameManager::~GameManager(){

} // end method

/**
 * @brief Takes the business id, and updates the according business if the funds are available
 * 
 * @param businessID 
 */
void GameManager::upgradeBusiness(int businessID){
    Business temp; // the temporary business

    // Set the business we are working on
    switch(businessID){
        case 1:
            temp = tutor;
            break;
        case 2:
            temp = spoke;
            break;
        case 3:
            temp = wave;
            break;
        case 4:
            temp = bookStore;
            break;
        case 5:
            temp = theater;
            break;
        case 6:
            temp = bikeRental;
    } // end switch

    // if we have the funds, buy the upgrade
    if(temp.costToUpgrade(temp.getBusinessLevel()) <= account.getBalance()){
        //std::cout << temp.getBusinessLevel() << std::endl;    
        //std::cout << account.getBalance() << std::endl;   
        account.withdraw(temp.costToUpgrade(temp.getBusinessLevel() + 1));
        temp.upgradeBusiness(temp.getBusinessLevel() + 1);
        //std::cout << temp.getBusinessLevel() << std::endl;
        //std::cout << account.getBalance() << std::endl;   
    } // end if

    // update the businesses
    switch(businessID){
        case 1:
            tutor = temp;
            break;
        case 2:
            spoke = temp;
            break;
        case 3:
            wave = temp;
            break;
        case 4:
            bookStore = temp;
            break;
        case 5:
            theater = temp;
            break;
        case 6:
            bikeRental = temp;
    } // end switch

    // ==COULD CALL UPDATE() HERE TO SHOW CHANGE IN BANK ACCOUNT==

} // end method

/**
 * @brief Runs the business, storing the revenue in the bank account
 * @param businessID 
 */
void GameManager::runBusiness(int businessID){ // ADD BACK IN ONCE BankAccount IS INTEGRATED
    Business temp;
    switch(businessID){
        case 1:
            temp = tutor;
            break;
        case 2:
            temp = spoke;
            break;
        case 3:
            temp = wave;
            break;
        case 4:
            temp = bookStore;
            break;
        case 5:
            temp = theater;
            break;
        case 6:
            temp = bikeRental;
    } // end switch

    //std::cout << account.getBalance() << std::endl;
    account.deposit((double) (temp.getRevenue() * (double) temp.getBusinessLevel())); // Later add a timer before adding money to business
    //std::cout << account.getBalance() << std::endl;

    // ==COULD CALL UPDATE() HERE TO SHOW CHANGE IN BANK ACCOUNT==

} // end method

/* ==HERE YOU COULD ADD SOME KIND OF UPDATE METHOD TO UPDATE THE UI (SUCH AS AMOUNT OF MONEY IN BANK)== */
