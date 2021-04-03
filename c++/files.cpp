#include <bits/stdc++.h>
#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>

class FileSystemUtils {
public:
    void createDirectory(const char* path) {
        if (mkdir(path, 0777) == -1) {
            std::cerr << "Error: " << strerror(errno) << std::endl;
        }
        else {
            std::cout << "Directory created!" << std::endl;
        }
    }

    void createFile(std::string fileName) {
        std::fstream file;
        file.open(fileName, std::ios::out);

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
    // std::string join(std::vector<std::string>) {

    // }

};


int main() {
    const char* path = "./coolh";
    FileSystemUtils fs;

    fs.createDirectory(path);
    fs.createFile("./coolh/cool.txt");

    return 0;
}
