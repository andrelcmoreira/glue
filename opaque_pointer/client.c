#include "lib/user_profile_interface.h"

#include <stdio.h>

int main(int argc, char *argv[]) {
  {
    printf("=======================\n");
    UserData *data = NULL;

    Create(&data);

    SetName(data, "fulano");
    SetCity(data, "foo");
    SetCpf(data, "XX.XXX.XXX-XX");
    SetAddress(data, "rua beltrano, 666");
    SetAge(data, 30);

    Save(data);
    Show(data);

    Destroy(&data);
    printf("=======================\n\n");
  }

  {
    printf("=======================\n");
    UserData *data = NULL;

    Create(&data);

    Load(data);
    Show(data);

    Destroy(&data);
    printf("=======================\n");
  }

  return 0;
}
