#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <sstream>
#include <stdexcept>

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
    std::istringstream stream(expression);
    std::vector<double> numbers;
    std::vector<char> operators;
    char currentChar;
    std::string currentNumber;

    
    while (stream >> currentChar) {
        if (isdigit(currentChar) || currentChar == '.') {
            currentNumber += currentChar;
        } else {
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
                    throw std::invalid_argument("operator isn't in a right spot");
                }
                operators.push_back(currentChar);
            } else {
                throw std::invalid_argument(std::string("wrong operator") + currentChar);
            }
        }
    }

    if (!currentNumber.empty()) {
        try {
            numbers.push_back(std::stod(currentNumber));
        } catch (const std::exception&) {
            throw std::invalid_argument("can't convert a number" + currentNumber);
        }
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

bool isValidExpression(const std::string& input) {
    for (char c : input) {
        if (!(isdigit(c) || c == '+' || c == '-' || c == '*' || 
              c == '/'|| c == '^' || c == '.')) {
            return false;
        }
    }
    return true;
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
                    expression.erase(i, 1);  // Удаляем пробел
                    --i;  // Смещаем индекс назад, так как элементы сдвигаются
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
