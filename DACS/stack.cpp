
struct File
{
    /* error */
    bool error;
    /* data */
    int value;
};

class Files
{
private:
    File *next;
    File *previous;
    File data;

public:
    Files(/* args */);
    ~Files();
    File push(File file);
    File pop();
    File &operator[](int i);
};

Files::Files(/* args */)
{
}

Files::~Files()
{
}

File Files::push(File file)
{
}

File Files::pop() 
{
}

File &Files::operator [] (int i) {
}

int main () {
    return 0;
}