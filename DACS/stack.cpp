
#include <iostream>
struct File
{
    /* data */
    int value;
};

class Files
{
private:
    Files *next;
    Files *previous;
    File file;

public:
    int length;
    Files(/* args */);
    ~Files();
    File push(File file);
    File pop();
    File &operator[](int i);
};

Files::Files(/* args */)
{
    this->next = NULL;
    length = 0;
}

Files::~Files()
{
}

File Files::push(File file)
{
    Files *newFile = new Files;
    newFile->file = this->file;
    newFile->next = this->next;
    newFile->previous = this;

    this->previous = NULL;
    this->file = file;
    this->next = newFile;
    this->length++;
    return newFile->file;
}

File Files::pop()
{
}

File &Files::operator[](int i)
{
    Files *files = this;
    int index = 0;
    while (index != i && files->next != NULL)
    {
        index++;
        files = files->next;
    };

    if (files->next == NULL)
    {
        std::cout << "Warning: You access to undifine item" << std::endl;
    }
    return files->file;
}

int main()
{
    Files files;
    File newFile;
    newFile.value = 1;
    files.push(newFile);
    newFile.value = 2;
    files.push(newFile);
    newFile.value = 3;
    files.push(newFile);
    for (int i = 0; i < files.length; i++)
    {
        std::cout << files[i].value << std::endl;
    }
    return 0;
}
