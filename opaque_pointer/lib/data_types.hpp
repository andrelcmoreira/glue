#ifndef DATA_TYPES_H_
#define DATA_TYPES_H_

#include <iostream>
#include <string>

//namespace user_profile {
//namespace data_types {

typedef struct UserData {
  std::string name;
  std::string city;
  std::string cpf;
  std::string address;
  int age;

  UserData() {
    std::cout << __FILE__ << ":" << __FUNCTION__ << std::endl;
  }

  ~UserData() {
    std::cout << __FILE__ << ":" << __FUNCTION__ << std::endl;
  }
} UserData;

//}
//}

#endif
