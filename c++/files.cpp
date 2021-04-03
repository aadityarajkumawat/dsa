// #include <bits/stdc++.h>
#include <iostream>
// #include "./file-system-utils/file-system-utils.h"
#include "Burrito.h"
// #include <unistd.h>
// #include <stdio.h>

// class PathUtils {
// public:
//     /**
//      * Takes two parameters first is a string which is base of the path
//      * and second is a vector of strings, it combines the base path with
//      * all the parts provided in the vector.
//     */
//     std::string join(std::string& base_path, std::vector<std::string>& parts_of_path) {
//         std::string joint_string = "";
//         const std::string base = trim_slash(base_path, left_trim);
//         joint_string.append(base);

//         for (int i = 0;i < parts_of_path.size();i++) {
//             joint_string.push_back(SLASH);
//             if (i != parts_of_path.size() - 1) {
//                 joint_string.append(trim_slash(parts_of_path[i], trim));
//             }
//             else {
//                 joint_string.append(trim_slash(parts_of_path[i], left_trim));
//             }
//         }

//         return joint_string;
//     }

// private:
//     std::string left_trim = "LEFT_TRIM";
//     std::string right_trim = "RIGHT_TRIM";
//     std::string trim = "TRIM";
//     const char SLASH = '/';

//     /**
//      * Takes first argument as a string and second as a string strictly
//      * of type, left_trim, right_trim, trim and trims all slashes from
//      * provided side.
//     */
//     std::string trim_slash(std::string& path, std::string& trim_type) {
//         std::string final_string = "";
//         if (trim_type == left_trim || trim_type == right_trim || trim_type == trim) {
//             std::string temp = path;

//             if (trim_type == left_trim) {
//                 while (temp != "" && temp[temp.length() - 1] == SLASH) {
//                     temp.pop_back();
//                 }
//             }
//             else if (trim_type == right_trim) {
//                 while (temp != "" && temp[0] == SLASH) {
//                     temp = temp.substr(1, temp.length());
//                 }
//             }
//             else {
//                 while (temp != "" && (temp[temp.length() - 1] == SLASH || temp[0] == SLASH)) {
//                     if (temp[temp.length() - 1] == SLASH) {
//                         temp.pop_back();
//                     }
//                     else {
//                         temp = temp.substr(1, temp.length());
//                     }
//                 }
//             }

//             final_string = temp;
//         }

//         return final_string;
//     }
// };

int main() {
    // std::string path = "./coolh";
    // std::string new_file_path = "./coolh/cool.js";

    // FileSystemUtils fs;
    // PathUtils path_utils;

    // fs.create_directory(path);
    // fs.create_file(new_file_path);

    // std::string base_path = "/home/edydee//";
    // std::vector<std::string> parts = { "/home/all/cood.js" };

    // std::string pat = path_utils.join(base_path, parts);
    // std::cout << pat << std::endl;

    // fs.create_file(pat);

    // std::cout << get_current_dir_name() << std::endl;

    Burrito bo;

    return 0;
}
