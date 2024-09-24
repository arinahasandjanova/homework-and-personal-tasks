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
	std::vector<std::vector<int>> matrix1 {{1, 2, 3}, {3, 4, 5}, {4, 5, 6}, {7, 8, 9}};
	printmatrix(matrix1);
	std::vector<std::vector<int>> rmatrix1 = matrix(matrix1);
	std::cout<<"\n";
	printmatrix(rmatrix1);
	
	return 0;
}
