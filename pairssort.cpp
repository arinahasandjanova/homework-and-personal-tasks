#include <iostream>
#include <utility>
#include <algorithm>
#include <cmath>
#include <vector>
int main(){
	std::vector<std::pair<int, int>> vector{{1, 2}, {2, 3}, {42, 11}, {8, 19}};
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
