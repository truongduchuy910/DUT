List::List()
{
    cout << "List linking constructed" << endl;
    this->next = NULL;
    do
    {
        this->data->_id = random();
    } while (this->data->_id > 10000000);
};
List::~List(){

};
unsigned int List::create()
{
    Data *temp = new Data;
}