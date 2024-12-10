#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <stdexcept>

bool isValidExpression(const std::string& input) {
    for (char c : input) {
        if (!(isdigit(c) || c == '+' || c == '-' || c == '*' ||
              c == '/'|| c == '^' || c == '.')) {
            return false;
              }
    }
    return true;
}

double applyOperation(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) {
                throw std::runtime_error("division by zero");
            }
            return a / b;
        case '^': return std::pow(a, b);
        default: throw std::invalid_argument("no available operator");
    }
}

double evaluateExpression(const std::string& expression) {
    std::vector<double> numbers;
    std::vector<char> operators;
    std::string currentNumber;
    char lastChar = 'k';

    for (char currentChar : expression) {
        if(lastChar == '.' && currentChar == '.') {
            throw std::invalid_argument("wrong expresssion");
        }
        if (isdigit(currentChar) || (currentChar == '.' && currentNumber.find(currentChar) == std::string::npos)) {
            currentNumber += currentChar;
        } else {
            if(currentChar == '.' && currentNumber.find(currentChar) != std::string::npos) {
                throw std::invalid_argument("wrong expresssion!!");
            }
            if (!currentNumber.empty()) {
                try {
                    numbers.push_back(std::stod(currentNumber));
                } catch (const std::exception&) {
                    throw std::invalid_argument("can't convert a number" + currentNumber);
                }
                currentNumber.clear();
            }

            if (std::string("+-*/^").find(currentChar) != std::string::npos) {
                if (numbers.size() == operators.size()) {
                    throw std::invalid_argument("operator isn't in a right spot or wrong expression");
                }
                operators.push_back(currentChar);
            } else {
                throw std::invalid_argument(std::string("wrong operator") + currentChar);
            }
        }
        lastChar = currentChar;
    }

    if (!currentNumber.empty()) {
        try {
            numbers.push_back(std::stod(currentNumber));
        } catch (const std::exception&) {
            throw std::invalid_argument("can't convert a number" + currentNumber);
        }
    }

    if (numbers.size() != operators.size() + 1) {
        throw std::invalid_argument("wrong expression");
    }

    for (size_t i = 0; i < operators.size(); ++i) {
        if (operators[i] == '^') {
            numbers[i] = applyOperation(numbers[i], numbers[i + 1], '^');
            numbers.erase(numbers.begin() + i + 1);
            operators.erase(operators.begin() + i);
            --i;
        }
    }

    for (size_t i = 0; i < operators.size(); ++i) {
        if (operators[i] == '*' || operators[i] == '/') {
            numbers[i] = applyOperation(numbers[i], numbers[i + 1], operators[i]);
            numbers.erase(numbers.begin() + i + 1);
            operators.erase(operators.begin() + i);
            --i;
        }
    }

    for (size_t i = 0; i < operators.size(); ++i) {
        numbers[i] = applyOperation(numbers[i], numbers[i + 1], operators[i]);
        numbers.erase(numbers.begin() + i + 1);
        operators.erase(operators.begin() + i);
        --i;
    }

    return numbers[0];
}

int main() {
    std::string expression;

    std::cout << "\n---------Welcome to our, working on the strenght of the goddess, calculator---------\n\n        Remember, that we can help you only with math problems for 6th grade       \n\n";
    do{
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~Please type your math expression~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n                        if you want to escape just say stop                          \n";
        std::getline(std::cin, expression);

        if (expression == "stop")
        {
            std::cout << "\n``Thank you for using our program, but we hope next time you'll choose another one``\n\n";
            break;
        }

        try {
            if (expression.empty()) {
                throw std::invalid_argument("you didn't write anything, try again:(");
            }

            for (size_t i = 0; i < expression.size(); ++i) {
                if (expression[i] == ' ') {
                    expression.erase(i, 1);
                    --i;
                }
            }

            if (!isValidExpression(expression)) {
                throw std::invalid_argument("wrong void");
            }

            double result = evaluateExpression(expression);
            std::cout << "your result: " << result << std::endl;

        } catch (const std::exception& e) {
            std::cerr << "error: " << e.what() << std::endl;
        }
    } while (true);

    return 0;
}
