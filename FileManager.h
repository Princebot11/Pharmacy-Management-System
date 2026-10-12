#ifndef FILEMANAGER_H
#define FILEMANAGER_H
class Pharmacy;
class FileManager {
public:
    FileManager();
    ~FileManager();
    void save(const Pharmacy& pharmacy) const;
    void load(Pharmacy& pharmacy) const;
};
#endif
