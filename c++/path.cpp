#include <bits/stdc++.h>
#include "path.h"

std::string PathUtils::join(std::string& base_path, std::vector<std::string>& parts_of_path) {
  std::string joint_string = "";
  const std::string base = trim_slash(base_path, left_trim);
  joint_string.append(base);

  for (int i = 0;i < parts_of_path.size();i++) {
    joint_string.push_back(SLASH);
    if (i != parts_of_path.size() - 1) {
      joint_string.append(trim_slash(parts_of_path[i], trim));
    }
    else {
      joint_string.append(trim_slash(parts_of_path[i], left_trim));
    }
  }

  return joint_string;
}


std::string PathUtils::trim_slash(std::string& path, std::string& trim_type) {
  std::string final_string = "";
  if (trim_type == left_trim || trim_type == right_trim || trim_type == trim) {
    std::string temp = path;

    if (trim_type == left_trim) {
      while (temp != "" && temp[temp.length() - 1] == SLASH) {
        temp.pop_back();
      }
    }
    else if (trim_type == right_trim) {
      while (temp != "" && temp[0] == SLASH) {
        temp = temp.substr(1, temp.length());
      }
    }
    else {
      while (temp != "" && (temp[temp.length() - 1] == SLASH || temp[0] == SLASH)) {
        if (temp[temp.length() - 1] == SLASH) {
          temp.pop_back();
        }
        else {
          temp = temp.substr(1, temp.length());
        }
      }
    }

    final_string = temp;
  }

  return final_string;
}
