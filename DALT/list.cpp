List::List()
{
    cout << "List linking constructed" << endl;
    this->next = NULL;
    do
    {
        this->_id = random();
    } while (this->_id > 10000000);
};
List::~List(){

};