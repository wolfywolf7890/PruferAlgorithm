#include <iostream>
#include <vector>
#include <stdexcept>

bool inVector(std::vector<int>& v, int start, int end, int elem){
  for(int i=start; i<end; i++){
    if(v[i] == elem){
      return true;
    }
  }
  return false;
}

std::vector<std::vector<int>> pruferToAdj(std::vector<int>& p){
  int n = p.size() + 2;
  for(unsigned int i=0; i<p.size(); i++){
    if(p[i] <= 0 || p[i] > n){
      throw std::invalid_argument("out of bounds");
    }
  }
  std::vector<int> v; //empty vector
  std::vector<std::vector<int>> output;
  for(int i=0; i<n; i++){
    output.push_back(v);
  } //fill output with empty vector
  std::vector<int> a = p;
  a.push_back(n);
  std::vector<int> b;
  for(int i=0; i<n-1; i++){
    int min = n;
    for(int j=1; j<n; j++){
      if(!inVector(a,i,n-1,j) && !inVector(b,0,i,j)){
        if(j < min){
          min = j;
        }
      }
    }
    b.push_back(min);
  }
  for(int i=n-2; i >= 0; i--){
    output.at(a[i]-1).push_back(b[i]);
    output.at(b[i]-1).push_back(a[i]);
  }

  return output;
}

int main() {
  std::cout << "Enter the number of nodes in your tree\n";
  int n;
  std::cin >> n;
  if(n <= 2){
    throw std::invalid_argument("out of bounds");
  }
  std::cout << "Enter Prufer vector, seperate the numbers by spaces \n";
  std::vector<int> p;
  for(int i=0; i<n-2; i++){
    int elem;
    std::cin >> elem;
    p.push_back(elem);
  }
  std::vector<std::vector<int>> output = pruferToAdj(p);
  for(unsigned int i=0; i<output.size(); i++){
    std::cout << i+1 << ": ";
    for(unsigned int j=0; j<output.at(i).size(); j++){
      std::cout << output[i][j] << " ";
    }
    std::cout << "\n";
  }
  
}