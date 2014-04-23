#include <iostream>
#include "mfifo.h"
using namespace std;
using namespace FIFO;
typedef int mytype;
int main()
{

    MFifo *Fifo=new MFifo;
    int num_operation=0,run=1;
    mytype *element;
    mytype *firstelement;
    mytype *lastElement;
    mytype *curElement;
    int numElements;
    int numElement;
    while(run)
    {
        switch(num_operation)
        {
        case 0:
            cout
                    <<"if you want to put element at the end choose  - 1"<<endl
                    <<"if you want to see element on the top choose  - 2"<<endl
                    <<"if you want to see element at the end choose  - 3"<<endl
                    <<"if you want to see element choose  - 4"<<endl
                    <<"if you want to see all elements choose  - 5"<<endl
                    <<"Exit - 6"<<endl
                    <<"Select operation:  "<<endl;
            cin >> num_operation;
            break;
        case 1:
            element=new mytype;
            cout<<"Enter element  ";
            cin>>*element;
            Fifo->PutItem((unsigned int)*element);
            num_operation=0;
            break;

        case 2:
            firstelement=new mytype;
            *firstelement=Fifo->GetItem();
            cout<<"First element  "<<*firstelement<<endl;
            num_operation=0;
            break;

        case 3:
            numElements = Fifo->GetItems();
            *lastElement=Fifo->PeekItem((unsigned int)numElements-1);
            cout<<"Last element  "<<*lastElement<<endl;
            num_operation=0;
            break;

        case 4:
            cout<<"Choose number of element (numeration from 1 to N)  ";
            cin>>numElement;
            *curElement=Fifo->PeekItem((unsigned int)numElement-1);
            cout<<"Your element  "<<*curElement<<endl;
            num_operation=0;
            break;

        case 5:

            numElements = Fifo->GetItems();
            cout<<"Num elements:"<<numElements << endl;
            cout<<"Your elements are:"<<endl;
            while(numElements)
            {
                 *curElement=Fifo->PeekItem((unsigned int)numElements-1);
                cout<<*curElement<<endl;
                numElements--;
            }

            num_operation=0;
            break;

        case 6:

            delete Fifo;
            run=0;
            break;
       default : num_operation=0;
            break;
        }
    }
    return 0;
}
