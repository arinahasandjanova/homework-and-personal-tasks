#include <iostream>
#include <string>
#include <vector>
std::string LCP(std::vector<std::string> vec)
{
	std::string prefix=vec[0];
	std::string elem1;
	std::string process;
	for(size_t i=0; i<vec.size(); i++)
	{
		size_t j=0;
		while(j<prefix.size()&&j<vec[i].size()&&prefix[j]==vec[i][j]){
			j++;
		}
		prefix=prefix.substr(0, j);
		if(prefix.empty()){
			return " ";}
	}
	return prefix;
}
int main(){
	std::vector<std::string> mas {"apple", "apricot", "apr"};
	std::string lsp=LCP(mas);
	std::cout<<lsp;
	return 0;
}
