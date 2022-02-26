#ifndef USER_PROFILE_INTERFACE_H_
#define USER_PROFILE_INTERFACE_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct UserData UserData;

void Create(UserData **data);
void Destroy(UserData **data);
void Save(UserData *data);
void Show(UserData *data);
void Load(UserData *data);

// getters
const char *GetCity(UserData *data);
const char *GetName(UserData *data);
const char *GetAddress(UserData *data);
const char *GetCpf(UserData *data);
int GetAge(UserData *data);

// setters
void SetCity(UserData *data, const char *city);
void SetName(UserData *data, const char *name);
void SetCpf(UserData *data, const char *cpf);
void SetAddress(UserData *data, const char *address);
void SetAge(UserData *data, int age);

#ifdef __cplusplus
}
#endif

#endif
