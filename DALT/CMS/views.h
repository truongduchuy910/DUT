
class Views
{
public:
    int home()
    {
        system("clear");
        int n;
        do
        {
            cout << "1. New Post" << endl;
            cout << "2. List Post" << endl;
            cout << "0. Exit" << endl;
            cout << "Choose your option [0-2]: ";
            cin >> n;
        } while (n < 1 || n > 8);

        return n;
    }

    Review inputReview()
    {
        system("clear");
        Review result;
        cout << "Input name of post :";
        cin >> result.name;
        return result;
    }
};