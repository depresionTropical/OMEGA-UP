#include <iostream>

using namespace std;

int main() {
  u_int64_t a,b,c;


  cin >> a >> b >> c;
  if (a < b){
    cout << "True ";
  }else{
    cout << "False ";
  }
  if (c > a){
    cout << "True ";
  }else{
    cout << "False ";
  }
  if(a == b){
    cout << "True ";
  }else{
    cout << "False ";
  }
  if (a != c){
    cout << "True ";
  }else{
    cout << "False ";
  }
  if (c<=b){
    cout << "True ";
  }else{
    cout << "False ";
  }
  return 0;
}