#include <iostream>
#include <cstdlib>
#include <string>
#include <functional>
#include <map>

class StrangeCalculator {
public:
    StrangeCalculator() {
        // Registering operations in a very roundabout way
        operations["plus"] = [](int a, int b) { return a + b; };
        operations["minus"] = [](int a, int b) { return a - b; };
        operations["multiply"] = [](int a, int b) { return a * b; };
        operations["divide"] = [](int a, int b) { return b != 0 ? a / b : 42; }; // Dividing by zero returns 42 because why not?
    }

    void askForInput() {
        std::cout << "Welcome to the Strange Calculator!\n";
        std::cout << "Enter the first number, but do it slowly, I insist: ";
        std::cin >> firstNum;

        std::cout << "Now give me a word that describes what you want to do (like 'plus', 'minus', 'multiply', or 'divide'):\n";
        std::cin >> operation;

        std::cout << "Last number, I promise: ";
        std::cin >> secondNum;
    }

    void calculate() {
        if (operations.find(operation) != operations.end()) {
            result = operations[operation](firstNum, secondNum);
            std::cout << "The result is: " << result << ". Isn't that magical?\n";
        } else {
            std::cout << "I don't understand your fancy words! Let's say the answer is 42.\n";
            result = 42;
        }
    }

    void someStrangeThings() {
        int randNum = std::rand() % 100 + 1;  // Random number between 1 and 100
        std::cout << "Just so you know, here’s a random number: " << randNum << ".\n";

        if (randNum % 2 == 0) {
            std::cout << "I think you should multiply the result by 2 for no reason.\n";
            result *= 2;
        } else {
            std::cout << "How about adding 10 to the result? Sounds good? Great!\n";
            result += 10;
        }
    }

    void finalWords() {
        std::cout << "Your new, final, incredibly modified result is: " << result << ".\n";
        std::cout << "This concludes our strange calculation. Have a quirky day!\n";
    }

private:
    int firstNum{}, secondNum{}, result{};
    std::string operation;
    std::map<std::string, std::function<int(int, int)>> operations;
};

int main() {
    StrangeCalculator calc;

    calc.askForInput();
    calc.calculate();
    calc.someStrangeThings();
    calc.finalWords();

    return 0;
}
