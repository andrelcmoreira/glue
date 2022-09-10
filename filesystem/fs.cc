#include <cstring>
#include <iostream>
#include <sstream>
#include <string>

#include <dirent.h>
#include <limits.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

bool is_path(const std::string &path) {
  return path.find('/') != std::string::npos;
}

bool is_absolute_path(const std::string &path) {
  return path[0] == '/';
}

bool directory_exists(const std::string &dir) {
  auto d = opendir(dir.c_str());

  if (d) {
    closedir(d);
    return true;
  }

  return false;
}

bool create_single_directory(const std::string &path) {
  return static_cast<bool>(!mkdir(path.c_str(), S_IRWXU));
}

// TODO: handle errors
void create_path(const std::string &path) {
  std::stringstream st{path};
  std::string dir;
  char cwd[PATH_MAX];

  getcwd(cwd, PATH_MAX);

  if (is_absolute_path(path)) {
    chdir("/");
  }

  while (std::getline(st, dir, '/')) {
    if (!dir.empty()) {
      if (!directory_exists(dir)) {
        create_single_directory(dir);
      }

      chdir(dir.c_str());
    }
  }

  // restore old cwd
  chdir(cwd);
}

void create_directory(const std::string &entry) {
  if (is_path(entry)) {
    create_path(entry);
  } else {
    create_single_directory(entry);
  }
}

int main(void) {
  create_directory("my_dir_1");
  create_directory("my_dir_2");
  create_directory("my_dir_3");

  create_directory("my_dir_4/my_dir_5");
  create_directory("my_dir_5/my_dir_6/my_dir_7");
  create_directory("/tmp/my_dir_8/my_dir_9");
}
