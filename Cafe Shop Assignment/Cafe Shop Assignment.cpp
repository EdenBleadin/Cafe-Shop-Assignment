#include <iostream>
#include <string>

int order = 0;
int payment = 0;

void ordering(int Number)
{
    printf("\n\nHow many ");
    switch (Number)
    {
    case 1:
        printf("Pupachinos ");
        break;
    case 2:
        printf("Cup 'o Joes ");
        break;
    case 3:
        printf("Doughnuts ");
        break;
    case 4:
        printf("Cookies ");
        break;
    case 5:
        printf("Big Burgers ");
        break;
    }
    printf("do you want?\n");
    int selector;
    bool donedone = false;
    while (donedone == false)
    {
        try
        {
            std::string input;
            std::getline(std::cin, input);
            selector = stoi(input);
            donedone = true;
        }
        catch (...)
        {
            printf("\nNot a valid input, try again using only numbers.\n");
        }
    }
    
    switch (Number)
    {
    case 1:
        order += (250 * selector);
        break;
    case 2:
        order += (499 * selector);
        break;
    case 3:
        order += (275 * selector);
        break;
    case 4:
        order += (120 * selector);
        break;
    case 5:
        order += (799 * selector);
        break;
    }
}

int main()
{
    bool done = false;
    while (done == false)
    {
        std::cout << R"(
______________________________________________________________________________________________    
|   Pupachino    |     Cup 'o Joe     |     Doughnut     |      Cookie      |   Big Burger   |  
|   $2.50        |     $4.99          |     $2.75        |      $1.20       |   $7.99        |    
|                |                    |                  |                  |                |  
|   Order 1      |     Order 2        |     Order 3      |      Order 4     |   Order 5      |    
______________________________________________________________________________________________  
)" << '\n';
        printf("Total:");
        std::cout << order / 100;
        printf(".");
        std::cout << order % 100;
        printf("\nWhat Order number do you want? Once you're done type \"0\" (Use the keypad.)\n");
        int selector;
        bool donedone = false;
        while (donedone == false)
        {
            try
            {
                std::string input;
                std::getline(std::cin, input);
                selector = stoi(input);
                donedone = true;
            }
            catch (...)
            {
                printf("\n \nNot a valid input, try again using only numbers.\n");
            }
        }
        
        switch (selector)
        {
        case 0: 
            done = true;
            break;
        case 1:
            ordering(1);
            break;
        case 2:
            ordering(2);
            break;
        case 3:
            ordering(3);
            break;
        case 4:
            ordering(4);
            break;
        case 5:
            ordering(5);
            break;
        default:
            printf("\nThat is not an order, please try again");
            break;
        }
    }

    while (payment < order)
    {
        printf("How many dollars will you use? (Use the keypad.)\n");
        try
        {
            std::string input;
            std::getline(std::cin, input);
            payment = stoi(input);
            payment = payment * 100;
        }
        catch(...)
        {
            printf("\n \nNot a valid input, try again using only numbers.");
        }
        if (payment < order)
        {
            printf("\n \nNot enough funds, please offer a higher amount.");
        }
        else
        {
            printf("\n\n Payment Accepted"); 
        }
        
    }
    printf("\nYour Change is: ");
    int remainder = payment - order;
    int Twenties = remainder / 2000;
    remainder = remainder - (Twenties * 2000);
    if (Twenties != 0)
    {
        std::cout << Twenties;
        printf(" Twenties");
    }
    int Tens = remainder / 1000;
    remainder = remainder - (Tens * 1000);
    if (Tens != 0)
    {
        printf(", ");
        std::cout << Tens;
        printf(" Tens");
    }
    int Fives = remainder / 500;
    remainder = remainder - (Fives * 500);
    if (Fives != 0)
    {
        printf(", ");
        std::cout << Fives;
        printf(" Fives");
    }
    int Singles = remainder / 100;
    remainder = remainder - (Singles * 100);
    if (Singles != 0)
    {
        printf(", ");
        std::cout << Singles;
        printf(" Singles");
    }
    int Quarters = remainder / 25;
    remainder = remainder - (Quarters * 25);
    if (Quarters != 0)
    {
        printf(", ");
        std::cout << Quarters;
        printf(" Quarters");
    }
    int Dimes = remainder / 10;
    remainder = remainder - (Dimes * 10);
    if (Dimes != 0)
    {
        printf(", ");
        std::cout << Dimes;
        printf(" Dimes");
    }
    int Nickels = remainder / 5;
    remainder = remainder - (Nickels * 5);
    if (Nickels != 0)
    {
        printf(", ");
        std::cout << Nickels;
        printf(" Nickels");
    }
    int Pennies = remainder / 1;
    remainder = remainder - Pennies;
    if (Pennies != 0)
    {
        printf(", ");
        std::cout << Pennies;
        printf(" Pennies.");
    }
}
