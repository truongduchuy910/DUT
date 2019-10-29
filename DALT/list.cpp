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
Data List::insert(Data &list)
{
    List *temp = new List;
    temp->next = this->next;
    temp->previous = this->previous;
    temp->_id = this->_id;
};
Data List::removeById(int id){

};
Data List::findById(int id){

};