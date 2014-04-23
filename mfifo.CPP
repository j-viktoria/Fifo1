#include "mfifo.h"
#include <iostream>
namespace FIFO
{

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Item::Item()
{
    data = 0;
    prev = nullptr;
    next = nullptr;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
MFifo::MFifo()
{
    items = 0;
    begin = nullptr;
    end = nullptr;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
MFifo::~MFifo()
{
    Clear();
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void MFifo::Clear()
{
    while(items)
    {
        Item* item = end;

        if (item -> prev)
        {
            item -> prev -> next = 0;
            end = item -> prev;
        }
        else
        {
            begin = 0;
            end = 0;
        }

        delete item;
        items--;

    }
}


void MFifo::PutItem(const unsigned int data)
{
    Item* item = new Item();

    item -> data = data;
    item -> prev = 0;

    if (items)
    {
        item -> next = begin;
        begin -> prev = item;
    }
    else
    {
        item -> next = 0;
        end = item;
    }

    begin = item;
    items ++;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
unsigned int MFifo::GetItem()
{
    if (!items)  return 0;

    Item* item = end;
    return  item ->data;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
unsigned int MFifo::PeekItem(const unsigned int index)
{
    if (items <= index)  return 0;

    Item* item = end;
    for (unsigned int i = 0; i < index; i++)   item = item->prev;
    return item -> data;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
unsigned int MFifo::GetItems()
{
    return items;
}


}
