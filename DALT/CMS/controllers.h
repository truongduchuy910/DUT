Views views;
Modules modules;
class Controllers
{
public:
    void initialize()
    {
        switch (views.home())
        {
        case 1:
            Review data = views.inputReview();
            Review result = modules.insertReview(data);
        };
    }
};