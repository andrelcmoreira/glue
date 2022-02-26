#include "user_profile_interface.h"

#include "data_types.hpp"
#include "user_profile.hpp"

#include <memory>

#define __init __attribute((constructor))

static std::unique_ptr<user_profile::UserProfile> profile;

static void __init Init() {
  profile = std::make_unique<user_profile::UserProfile>();
}

void Create(UserData **data) {
  *data = new UserData();
}

void Destroy(UserData **data) {
  delete (*data);
  *data = nullptr;
}

void Save(UserData *data) {
  profile->Save(data);
}

void Show(UserData *data) {
  profile->Show(data);
}

void Load(UserData *data) {
  profile->Load(data);
}

void SetCity(UserData *data, const char *city) {
  data->city.assign(city);
}

void SetName(UserData *data, const char *name) {
  data->name.assign(name);
}

void SetCpf(UserData *data, const char *cpf) {
  data->cpf.assign(cpf);
}

void SetAddress(UserData *data, const char *address) {
  data->address.assign(address);
}

void SetAge(UserData *data, int age) {
  data->age = age;
}

const char *GetCity(UserData *data) {
  return data->city.c_str();
}

const char *GetName(UserData *data) {
  return data->name.c_str();
}

const char *GetAddress(UserData *data) {
  return data->address.c_str();
}

const char *GetCpf(UserData *data) {
  return data->cpf.c_str();
}

int GetAge(UserData *data) {
  return data->age;
}
