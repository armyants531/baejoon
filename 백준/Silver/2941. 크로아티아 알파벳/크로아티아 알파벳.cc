#include <iostream>

using namespace std;

string str;
int main() {
  cin >> str;
  int i = 0, count = 0;
  while (true) {
    if (str[i] == 'c') {
      i++;
      if (i >= str.length()) {
        count++;
        break;        
      }
      else if (str[i] == '=') {
        count++;
        i++;
      }
      else if (str[i] == '-') {
        count++;
        i++;
      }
      else { // when the alphabet was just c 
        count++;
      }
    } 
    else if (str[i] == 'd') {
      i++;
      if (i >= str.length()) {
        count++;
        break;        
      }
      else if (str[i] == 'z') {
        i++;
        if (i >= str.length()) {
          count+=2; // just d and z
          break;        
        }
        else if (str[i] == '=') {
          count++;
          i++;
        }
        else { // just d and z
          count+=2; 
        }  
      }
      else if (str[i] == '-') {
        count++;
        i++;
      }
      else { // just d
        count++;
      }
    }
    else if (str[i] == 'l') {
      i++;  
      if (i >= str.length()) {
        count++;
        break;        
      }
      else if (str[i] == 'j') {
        count++;
        i++;
      }
      else { // just l
        count++;
      }
    }
    else if (str[i] == 'n') {
      i++;
      if (i >= str.length()) {
        count++;
        break;        
      }
      else if (str[i] == 'j') {
        count++;
        i++;
      }
      else { // just n
        count++;
      }
    }
    else if (str[i] == 's') {
      i++;
      if (i >= str.length()) {
        count++;
        break;        
      }
      else if (str[i] == '=') {
        count++;
        i++;
      }
      else { // just s
        count++;
      }
    }
    else if (str[i] == 'z') {
      i++;
      if (i >= str.length()) {
        count++;
        break;        
      }
      else if (str[i] == '=') {
        count++;
        i++;
      }
      else { // just z
        count++;
      }
    }
    else {
      count++;
      i++;  
    }
    if (i >= str.length()) {
      break;        
    }
  }
  cout << count << "\n";
}