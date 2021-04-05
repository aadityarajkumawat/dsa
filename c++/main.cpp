#include <bits/stdc++.h>
#include <iostream>
#include "fs.h"
#include "path.h"
// #include <unistd.h>
// #include <stdio.h>

int main(int argc, char** argv) {
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

    FileSystemUtils fs;
    PathUtils path_utils;

    // for (int i = 0;i < argc;i++) {
    //     std::cout << argv[i] << std::endl;
    // }

    if (!strcmp(argv[1], "init")) {
        std::cout << "Initiliazed a pit repository" << std::endl;
    }

    return 0;
}
