#include <iostream>
#include <bits/stdc++.h>
#include <sys/stat.h>
#include <sys/types.h>

#ifndef FS_H
#define FS_H

class FileSystemUtils {
public:
    /**
     * Takes path as a parameter and creates a folder at given location
     * if not already present.
    */
    void create_directory(std::string& path);

    /**
     * Takes file name as parameter and creates a file in present
     * working directory.
    */
    void create_file(std::string& file_name);
};

#endif /* FS_H */
