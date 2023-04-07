#include <iostream>
#include <fstream> // library for working with files
#include <string>
using namespace std;

// TASK 2 (working with file system)

// class with main methods for working with classes (read file, write file and delete it)
class Files {

private:
    string filename;

public:
    Files() { filename = ""; }
    Files(const string& fname) { filename = fname; }

    void Write(const string& data) {
        ofstream file(filename);
        if (file.is_open()) {
            file << data;
            file.close();
            cout << "Data has been written to file!" << endl;
        }
        else {
            cout << "Error: Unable to open file." << endl;
        }
    }

    string Read() {
        string content = "";
        ifstream file(filename);
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                content += line + "\n";
            }
            file.close();
        }
        else {
            cout << "Error: Unable to open file." << endl;
        }
        return content;
    }

    void Delete() {
        if (remove(filename.c_str()) != 0) {
            cout << "Error: Unable to delete file." << endl;
        }
        else {
            cout << "File deleted successfully!" << endl;
        }
    }
};

// class with the logic of processing data from files
class Data {

private:
    Files file;

public:
    Data(Files f) { file = f; }

    void Edit(const string& filename, const string& new_content) {
        ofstream file(filename);
        if (file.is_open()) {
            file << new_content;
            file.close();
            cout << "File edited successfully." << endl;
        }
        else {
            cout << "Error: Unable to open file." << endl;
        }
    }
    // and other logic methods that might be needed...
};

//here we check how it all works
int main() {
    Files f("example.txt");
    Data d(f);

    string text = f.Read();
    cout << "File contents: " << text << endl;
    d.Edit("example.txt", "This is the new text.");
    f.Delete();

    Files f1;
    f1.Write("new_example.txt");

    return 0;
}