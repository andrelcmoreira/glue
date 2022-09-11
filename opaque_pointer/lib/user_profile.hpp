#ifndef USER_PROFILE_H_
#define USER_PROFILE_H_

#include "data_types.hpp"

namespace user_profile {

class UserProfile {
  public:
    void Load(UserData *data) const;
    void Save(UserData *data) const;
    void Show(UserData *data) const;
};

}

#endif  // USER_PROFILE_H_
