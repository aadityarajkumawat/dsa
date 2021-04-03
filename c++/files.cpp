#include <bits/stdc++.h>
#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>

class FileSystemUtils {
public:
    void create_directory(std::string& path) {
        const char* type_safe_path = path.c_str();
        if (mkdir(type_safe_path, 0777) == -1) {
            std::cerr << "Error: " << strerror(errno) << std::endl;
        }
        else {
            std::cout << "Directory created!" << std::endl;
        }
    }

    void create_file(std::string& file_name) {
        std::fstream file;
        file.open(file_name, std::ios::out);

        if (!file) {
            std::cout << "Error in creating file!!" << std::endl;
            return;
        }

        std::cout << "File created successfully" << std::endl;
        file.close();
        return;
    }
};

class PathUtils {
public:
    std::string join(std::string& base_path, std::vector<std::string>& parts_of_path) {
        std::string joint_string = "";
        const std::string base = trim_slash(base_path, left_trim);
        joint_string.append(base);

        for (int i = 0;i < parts_of_path.size();i++) {
            if (i != parts_of_path.size() - 1) {
                joint_string.push_back(SLASH);
                joint_string.append(trim_slash(parts_of_path[i], trim));
            }
            else {
                joint_string.push_back(SLASH);
                joint_string.append(trim_slash(parts_of_path[i], left_trim));
            }
        }

        return joint_string;
    }

private:
    std::string left_trim = "LEFT_TRIM";
    std::string right_trim = "RIGHT_TRIM";
    std::string trim = "TRIM";
    const char SLASH = '/';

    std::string trim_slash(std::string& path, std::string& trim_type) {
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
};


int main() {
    std::string path = "./coolh";
    std::string new_file_path = "./coolh/cool.js";

    FileSystemUtils fs;
    PathUtils path_utils;

    fs.create_directory(path);
    fs.create_file(new_file_path);

    std::string base_path = "/home/edydee///";
    std::vector<std::string> parts = { "/cool//", "/bin", "slack" };

    std::string pat = path_utils.join(base_path, parts);

    return 0;
}
