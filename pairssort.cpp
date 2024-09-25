#include <iostream>
#include <utility>
#include <algorithm>
#include <cmath>
#include <vector>
int main(){
	int n;
	int a1;
	int a2;
	std::cout<<"print the count of pairs: \n";
	std::cin>>n;
	std::vector<std::pair<int, int>> vector(n);
	std::cout<<"\n";
	std::cout<<"print pairs: \n";
	for(int i=0; i!=n; ++i){
		std::cin>>a1>>a2;
		vector[i].first=a1;
		vector[i].second=a2;
	}
	std::cout<<"\n";
	for(std::pair<int, int> elem: vector){
		std::cout<<elem.first<<" "<<elem.second<<"\n";	
	}
	std::sort(vector.begin(), vector.end(), []
	(const std::pair<int, int>& a, const std::pair<int, int>& b)
	{return sqrt(pow(a.first, 2)+pow(a.second, 2))<sqrt(pow(b.first, 2)+pow(b.second, 2));});
	std::cout<<"\n";
	for(std::pair<int, int> elem: vector){
		std::cout<<elem.first<<" "<<elem.second<<"\n";	
	}
	return 0;
}
