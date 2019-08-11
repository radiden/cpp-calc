#include "calc.h"
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <map>

float add(float num1, float num2)
{
    return num1 + num2;
}

float subtract(float num1, float num2)
{
    return num1 - num2;
}

float multiply(float num1, float num2)
{
    return num1 * num2;
}

float divide(float num1, float num2)
{
    return num1 / num2;
}

int main()
{
    std::cout << "input floats" << std::endl;
    std::cin >> num1;
    std::cin >> num2;
    std::cout << "your nums are " << num1 << " and " << num2 << std::endl;
    std::map<std::string, float (*)(float, float)> actlist;
    actlist["add"] = add;
    actlist["subtract"] = subtract;
    actlist["multiply"] = multiply;
    actlist["divide"] = divide;

    std::cout << "input action: add, subtract, multiply, divide" << std::endl;
    std::string action;
    std::cin >> action;

    std::transform(action.begin(), action.end(), action.begin(), ::tolower);

    if (actlist.find(action) != actlist.end())
    {
        std::cout << actlist[action](num1, num2) << std::endl;
    }

    return 0;
}