#include <iostream>
#include <deque>
#include <string>
std::deque<int> doTrain(std::string command, int n, std::deque<int> train){
	size_t n1=n;
	std::deque<int> train2;
	if(command== "+l"){
		train.push_front(n);
	}else if(command== "+r"){
		train.push_back(n);
	}else if(command== "-r" && n1<=train.size()){
		train.erase(train.end()-n, train.end());
	}else if(command== "-r" && n1>=train.size()){
		train.clear();
	}else if(command== "-l" && n1<=train.size()){
		train.erase(train.begin(), train.begin()+n);
	}else if(command== "-l" && n1>=train.size()){
		train.clear();
	}
	return train;
}

int main(){
	std::deque<int> train;
	std::cout<<"write the commands:\n+l k - add the car on the left\n+r k - add the car on the right\n-l N - delete cars from the left\n-r N - delete cars from the right\nk-number of the car\nN-amount of car\n\n\n\n\n";
	std::string command;
	char u, i;
	int n;
	
	while(std::cin>>u>>i>>n){
		command+=u;
		command+=i;
		//std::cout<<u<<" "<<i<<" "<<n;
		//std::cout<<command<<" "<<n;
		train=doTrain(command, n, train);
		command.clear();
		}
	std::cout<<"\n\n\n";
	if(train.empty()){
		std::cout<<"train is empty";
	}else{
		for(int x: train){
			std::cout<<x<<"\n";
			}
		}
	return 0;
}
