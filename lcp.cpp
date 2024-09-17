#include <iostream>
#include <string>
#include <vector>
// функция для нахождения наибольшего общего префикса
std::string LCP(std::vector<std::string> vec){ 
	if (vec.empty()) return "";  //проверяем заполнение массива
    size_t lenght;
    int size = vec.size();
    std::string prefix = vec[0];
    std::string elem;
    for (int i = 0; i < size; i++){
        lenght = 0;
        elem = vec[i];
        while(lenght < prefix.size() && lenght < elem.size() && prefix[lenght] == elem[lenght]){
            lenght++;
        }
        prefix = prefix.substr(0, lenght);
        if(prefix.empty()){
            return "";
        }
    }
    return prefix;
}
int main(){
	std::vector<std::string> mas;
	int n;
	std::string str;
	std::cout << "Enter the number of strings:\n";
	std::cin >> n;
	std::cin.ignore();  //пропускаем символ новой строки
	for (int i = 0; i < n; i++){
		std::cout << "Enter the string number " << i + 1 << "\n";
		std::getline(std::cin, str);
		mas.push_back(str);
	}
	std::string lsp = LCP(mas);
	if(lsp.empty()){ 
		std::cout<<"There's no recurring prefix\n";
	}else{
		std::cout << "Your recurring prefix is '" << lsp << "'\n";
	}
	return 0;
}
