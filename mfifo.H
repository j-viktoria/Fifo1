#ifndef MFIFO_H
#define MFIFO_H
namespace FIFO
{
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class Item
{
public:

    Item();

   unsigned int data;
    Item* prev;
    Item* next;
};
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class MFifo
{
public:
    MFifo();
    ~MFifo();
    void         PutItem(const unsigned int data);
    unsigned int GetItem();
    unsigned int PeekItem(const unsigned int index = 0);
    unsigned int GetItems();
    void Clear() ;
private:
    unsigned int items;
    Item* begin;
    Item* end;
};
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#endif // MFIFO_H
}
