#include "rsa.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

void Generate_e_n_d(Vector& e, Vector& n, Vector& d);
void selectDistinctPrimes(const std::vector<Vector>& primes, Vector& p, Vector& q);
std::vector<Vector> Rsa(const std::string& mes, Vector e, Vector n);
std::string DeRsa(std::vector<Vector>& mes, Vector d, Vector n);

int main() {
    Vector e, n, d;
    Generate_e_n_d(e, n, d);

    std::string inputMessage;
    std::cout << "Input text message: ";
    std::getline(std::cin, inputMessage);
    std::cout<<"\n";
    
    std::vector<Vector> RsaCode = Rsa(inputMessage, e, n);
    
    std::cout << "Rsa message: \n";
    for (const auto& i : RsaCode) {
        std::cout<<i<<"  ";
    }
    std::cout<<"\n";
    std::string decryptedMessage = DeRsa(RsaCode, d, n);
    std::cout << "Decrypted message: " << decryptedMessage << "\n";

    return 0;
}

std::vector<Vector> Rsa(const std::string& mes, Vector e, Vector n){
    std::vector<Vector> result;
    for (char c : mes) {
		Vector part;
        part.textToNumber(std::string(1, c));
        //std::cout<<"cod:"<<part<<"\n";
        Vector encryptedChar = Vector::PowBig_Number(part, e, n);
        //std::cout<<"Num cod:"<<encryptedChar<<"\n";
        result.push_back(encryptedChar);
    }
    
    return result;
}

std::string DeRsa(std::vector<Vector>& mes,const Vector d,const Vector n){
    std::string ourText;
    for (const Vector& encryptedChar : mes) {
		//std::cout<<encryptedChar<<"BBBBBBBB\n";
        Vector decryptedChar = Vector::PowBig_Number(encryptedChar, d, n);
        //std::cout<<decryptedChar<<"________\n";
        ourText += decryptedChar.numberToText();
    }
    
    return ourText;
}

void Generate_e_n_d(Vector& e, Vector& n, Vector& d){
    std::vector<Vector> primes = {
        Vector({5, 0, 3}),    
        Vector({1, 9, 1}),    
        Vector({2, 2, 7}),    
        Vector({2, 9, 3}),
        Vector({3, 7, 1}),
        Vector({4, 1, 9})
    };


    Vector p;// = Vector({5, 0, 3});
    Vector q;// = Vector({5, 0, 9});
    selectDistinctPrimes(primes, p, q);
    std::cout<<"Private key (p) = "<<p<<"\n";
    std::cout<<"Private key (q) = "<<q<<"\n";

    Vector one ({0, 1});
    Vector nul ({0, 0});

    n = p * q;
    std::cout<<"Public key (n) = "<<n<<"\n";
    Vector fi = (p - one) * (q - one);
    std::cout<<"fi = "<<fi<<"\n";
    int ei=1;
    e = Vector({0, 2});
    while (!Vector::IsCoprime(e, fi)) {
        ei = ei<<1;
        e = Vector({0, ei+1});
    }
    std::cout<<"Public key (e) = "<<e<<"\n";
    Vector k({0, 1});
    while ((one + k * fi) % e != nul) {
        k++;
    }
    std::cout<<"k = "<<k<<"\n";
    d = (one + k * fi) / e;
    std::cout<<"Private key (d) = "<<d<<"\n";
}

void selectDistinctPrimes(const std::vector<Vector>& primes, Vector& p, Vector& q) {
    size_t size = primes.size();
    if (size < 2) {
        std::cerr << "Недостаточно простых чисел для выбора p и q." << std::endl;
        return;
    }

    srand(static_cast<unsigned int>(time(0)));

    int index_p = rand() % size;
    p = primes[index_p];

    int index_q;
    do {
        index_q = rand() % size;
        q = primes[index_q];
    } while (index_q == index_p); 
}
