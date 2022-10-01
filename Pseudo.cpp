#include <cmath>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <chrono>
#include <ctime>
#include <Windows.h>

int minValue; // the min value for our pseudo-random number
int maxValue; // the max value for our pseudo-random number
int startingValue;
int randValue; //the pseudo-random value we will be generating

int main(int argc, char const *argv[])
{

    clock_t start, end;
    start = clock();

    time_t now = time(0);
    tm *ltm = localtime(&now);
    int time_t;
    
    std::cout << "Input Minimum Value" << std::endl;
    std::cin >> minValue;
    std::cout << "Input Maximum Value" << std::endl;
    std::cin >> maxValue;

    int valueOne;
    int valueTwo;
    int valueThree;

    valueOne = now;
    valueTwo = 1 + ltm->tm_mon;
    valueThree = ltm->tm_mday;

    startingValue = ((valueOne / (now / 50018329)) * valueTwo * valueThree * clock());

    while (startingValue > maxValue || startingValue < minValue){
        if (startingValue > maxValue)
        {
            startingValue /= 2;
        }
        else if (startingValue < minValue)
        {
            startingValue *= 2;
        }
    }

    randValue = startingValue;

    if(randValue < maxValue && randValue > minValue)
    {
        std::cout << randValue;
    }

    return randValue;
}