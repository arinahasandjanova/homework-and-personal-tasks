#include <iostream>
#include <vector>
std::vector<std::vector<int>> matrix(const std::vector<std::vector<int>>& matrix){
	int n=matrix.size();
	int m=matrix[0].size();
	std::vector<std::vector<int>> rmatrix(m, std::vector<int>(n));
	for(int i=0; i!=n; ++i){
		for(int j=0; j!=m; ++j){
			rmatrix[j][i]=matrix[i][j];
			}
		}
	return rmatrix;
	}
void printmatrix(std::vector<std::vector<int>> matrix){
	for(std::vector<int> elem: matrix){
		for(int elem1: elem){
		std::cout<<elem1<<" ";	
	}
	std::cout<<"\n";
	}
	}
int main(){
	int n;
	int m;
	int a;
	std::cout<<"print the count of rows: \n";
	std::cin>>n;
	std::cout<<"print the count of columns: \n";
	std::cin>>m;
	std::vector<std::vector<int>> matrix1 (n, std::vector<int>(m));
	std::cout<<"\n";
	std::cout<<"print n*m numbers: \n";
	for(int i=0; i!=n; ++i){
		for(int j=0; j!=m; ++j){
			std::cin>>a;
			matrix1[i][j]=a;
		}
	}
	std::cout<<"\n";
	printmatrix(matrix1);
	std::vector<std::vector<int>> rmatrix1 = matrix(matrix1);
	std::cout<<"\n";
	printmatrix(rmatrix1);
	
	return 0;
}
