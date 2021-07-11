#include <iostream>
#include <string>
#include <algorithm>

int comp(const void* a, const void* b);


bool comp2(const int& a, const int& b){
  return a > b;
}


int main(){
  int arr[] = {3,2,5,4,1};
  
  //qsort函数
  //std::qsort(arr, sizeof(arr)/sizeof(arr[0]), sizeof(arr[0]), comp);

  //std::sort(std::begin(arr), std::end(arr), comp2);  
  
  std::sort(std::begin(arr), std::end(arr), [](int a, int b)->bool{return a > b;});
  for(const auto& a : arr){
    std::cout << a << std::endl;
  }
  return 0;
}

int comp(const void* pa, const void* pb){
  int a = *((int*)pa);
  int b = *((int*)pb);
  if(a < b) return -1;
  else if(a == b) return 0;
  else	return 1;
}
