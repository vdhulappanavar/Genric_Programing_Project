#include <iostream>
#include <vector>
#include <cstdlib>
#include "dsexceptions.h"
#include "PairingHeap.h"

using namespace std;
int main()
{
    int choice, num, pos;
    char ch;
    PairingHeap<int> h;
    PairNode<int> * pn;
    while (1)
    {
        cout<<"-----------------"<<endl;
        cout<<"Operations on Pairing Heap"<<endl;
        cout<<"-----------------"<<endl;
        cout<<"1.Insert Element and Decrease key"<<endl;
        cout<<"2.Delete Minimum Element "<<endl;
        cout<<"3.Quit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter the number to be inserted : ";
            cin>>num;
            pn = h.insert(num);
            cout<<"Want to decrease the key:(Y = Yes | N = No) ";
            cin>>ch;
            if (ch == 'Y')
            {
                cout<<"Enter new key value: ";
                cin>>pos;
                h.decreaseKey(pn, pos);
            }
            break;
        case 2:
            h.deleteMin(num);
            break;
        case 3:
            exit(1);
        default:
            cout<<"Wrong choice"<<endl;
        }
    }
    return 0;
}
