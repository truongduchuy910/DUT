class Review
{
public:
    int _id;
    char name[100];
    char introduce[250];
};

class Category
{
public:
    int _id;
    char name[100];
};

class Hashtag
{
public:
    int _id;
    char name[100];
};

class Description
{
public:
    int _id;
    char content[1000];
};

class Post
{
public:
    int _id;
    Review review;
    Category category;
    Hashtag hashtag;
    Description desciption;
};
