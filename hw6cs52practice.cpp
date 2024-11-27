#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>

struct Card
{
    int cardRank;
    std::string cardSuit;
};

std::string cardToString(Card inputCard)
{
    std::stringstream ss;
    
    switch (inputCard.cardRank)
    {
    case 11:
        ss << "Jack";
        break;
    case 12:
        ss << "Queen";
        break;
    case 13:
        ss << "King";
        break;
    case 14:
        ss << "Ace";
        break;
    default:
        ss << inputCard.cardRank;
        break;
    }
    
    ss << " of " << inputCard.cardSuit;
    return ss.str();
}

Card makeCard(int inputRank, std::string inputSuit)
{
    Card newCard;
    newCard.cardRank = inputRank;
    newCard.cardSuit = inputSuit;
    return newCard;
}

int getRandRank()
{
    return (rand() % 12) + 2;
}

std::string getRandSuit()
{
    int randSuit = (rand() % 3);
    switch (randSuit)
    {
    case 0:
        return "Hearts";
    case 1:
        return "Clubs";
    case 2:
        return "Spades";
    case 3:
        return "Diamonds";
    
    default:
        break;
    }    
}

bool isEqual(Card c1, Card c2)
{
    if (c1.cardRank == c2.cardRank)
    {
        return true;
    }
    else
    {
        return false;
    }   
}

bool isLess(Card c1, Card c2)
{
    if (c1.cardRank < c2.cardRank)
    {
        return true;
    }
    else
    {
        return false;
    } 
}

bool isGreater(Card c1, Card c2)
{
    if (c1.cardRank > c2.cardRank)
    {
        return true;
    }
    else
    {
        return false;
    }    
}

int main()
{
    std::srand(std::time(0));
    std::string playerOneName;
    std::string playerTwoName;
    int playerOneScore = 0;
    int playerTwoScore = 0;
    Card playerOneCard;
    Card playerTwoCard;
    int roundCounter = 1;
    char playAgain;

    std::cout << "Welcome to the world champion High-card tournament finals!" << std::endl;
    std::cout << "Please Enter the names of the two players: " << std::endl;
    std::cin >> playerOneName;
    std::cin >> playerTwoName;
    std::cout << "It's a match between " << playerOneName << " and " << playerTwoName << std::endl << std::endl;

    do
    {   
        std::cout << "They are starting round " << roundCounter << "." << std::endl;
        std::cout << "The players are shuffling..." << std::endl;
        playerOneCard = makeCard(getRandRank(), getRandSuit());
        playerTwoCard = makeCard(getRandRank(), getRandSuit());

        if(isGreater(playerOneCard, playerTwoCard))
        {
            std::cout << "Isn't this exciting!" << std::endl;
            std::cout << playerOneName << "'s " << cardToString(playerOneCard) << " beat " << playerTwoName << "'s " << cardToString(playerTwoCard) << "!" << std::endl;
            ++playerOneScore;
        }
        else if (isEqual(playerOneCard, playerTwoCard))
        {
            std::cout << "I didn't see that coming!" << std::endl;
            std::cout << playerOneName << "'s " << cardToString(playerOneCard) << " to match " << playerTwoName << "'s " << cardToString(playerTwoCard) << "!" << std::endl;
            std::cout << "It's a DRAW!" << std::endl;
        }
        else
        {
            std::cout << "Look at that!" << std::endl;
            std::cout << playerTwoName << "'s " << cardToString(playerTwoCard) << " beat " << playerOneName << "'s " << cardToString(playerOneCard) << "!" << std::endl;
            ++playerTwoScore;
        }

        std::cout << "The score is..." << std::endl;
        std::cout << playerTwoName << " : " << playerTwoScore << ", " << playerOneName << " : " << playerOneScore << std::endl;
        std::cout << "Should the 2 players go again (y/n)?" << std::endl;
        std::cin >> playAgain;
        ++roundCounter;    
    } 
    while (playAgain == 'Y' || playAgain == 'y');

    std::cout << "Well that's all we have time for tonight." << std::endl;
    std::cout << "For ESPN, this is Bob Jarvis, reporting live!" << std::endl;
    
    return 0;
}









// std::srand(std::time(0));
    // Card c1;
    // c1.cardRank = 13;
    // c1.cardSuit = "Spades";
    // std::cout << cardToString(c1) << std::endl;

    // Card myCard = makeCard(14, "Hearts");
    // std::cout << cardToString(myCard) << std:: endl;

    // if (isGreater(myCard, c1))
    // {
    //     std::cout << "My card is greater";
    // }
    // else
    // {
    //     std::cout << "My card is lower";
    // }