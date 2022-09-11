#include "user_profile.hpp"

#include <iostream>
#include <fstream>

namespace user_profile {

void UserProfile::Load(UserData *data) const {
  std::ifstream file{"profile.txt"};
  std::string line;

  while (std::getline(file, line)) {
    auto pos = line.find(" ");
    std::string key{line.begin(), line.begin() + (pos - 1)};
    std::string value{line.begin() + (pos + 1), line.end()};

    if (!key.compare("name")) data->name.assign(value);
    else if (!key.compare("address")) data->address.assign(value);
    else if (!key.compare("cpf")) data->cpf.assign(value);
    else if (!key.compare("city")) data->city.assign(value);
    else if (!key.compare("age")) data->age = std::atoi(value.c_str());
  }
}

void UserProfile::Save(UserData *data) const {
  std::ofstream file{"profile.txt"};

  file << "name: "    << data->name << "\n"
       << "city: "    << data->city << "\n"
       << "cpf: "     << data->cpf << "\n"
       << "address: " << data->address << "\n"
       << "age: "     << std::to_string(data->age);
}

void UserProfile::Show(UserData *data) const {
  if (data) {
    std::cout << "city: " << data->city << std::endl;
    std::cout << "name: " << data->name << std::endl;
    std::cout << "address: " << data->address << std::endl;
    std::cout << "cpf: " << data->cpf << std::endl;
    std::cout << "age: " << data->age << std::endl;
  }
}

}
