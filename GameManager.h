#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

// imports
#include <Business.h>
#include <BankAccount.h>
#include <math.h>
#include <stdio.h>
#include <iostream>

/**
 * @brief The game manager class
 * 
 */
class GameManager{
        private:
            Business tutor; // id = 1
            Business spoke; // id = 2
            Business wave; // id = 3
            Business bookStore; // id = 4
            Business theater; // id = 5
            Business bikeRental; // id = 6
            BankAccount account; // add back in once BankAccount is integrated
                //Manager assignedManager
        public:
                GameManager(); // the constructor
                ~GameManager(); // the deconstructor
                void upgradeBusiness(int businessID); // upgrades the business if the funds are available
                void runBusiness(int businessID); // runs the business and stores the revenue in the bank account
}; // end class

#endif // !


