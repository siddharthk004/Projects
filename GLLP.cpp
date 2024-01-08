///////////////////////////////////////////////////////////////
//
// Author :- Siddharth satish kardile
// date :- 24-08-2023
//
///////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

///////////////////////////////////////////////////////////////
// structure for singly linear and singly circular
///////////////////////////////////////////////////////////////

// Singly linear link list
// Singly circular link list
template <class T>
struct nodeS
{
    T data;
    struct nodeS *next;
};

///////////////////////////////////////////////////////////////
// structure for doubly linear and doubly circular
///////////////////////////////////////////////////////////////

// doubly linear link list
// doubly circular link list
template <class T>
struct nodeD
{
    T data;
    struct nodeD *next;
    struct nodeD *prev;
};

///////////////////////////////////////////////////////////////
// class of singly linear linklist
///////////////////////////////////////////////////////////////

// Singly linear link list
template <class T>
class singlyLL
{
public:
    struct nodeS<T> *First;
    int icount;

    singlyLL();

    void display();
    int count();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};

///////////////////////////////////////////////////////////////
// class of singly circular linklist
///////////////////////////////////////////////////////////////

// Singly circular link list
template <class T>
class singlyCL
{
public:
    struct nodeS<T> *First;
    struct nodeS<T> *Last;
    int icount;

    singlyCL();

    void display();
    int count();

    void InsertFirst(T no);
    void InsertLast(T no);
    void InsertAtPos(T no, int ipos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int ipos);
};

///////////////////////////////////////////////////////////////
// class of doubly linear linklist
///////////////////////////////////////////////////////////////

// doubly linear link list
template <class T>
class doublyLL
{
public:
    struct nodeD<T> *First;
    struct nodeD<T> *Last;
    int icount;

    doublyLL();

    void display();
    int count();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};

///////////////////////////////////////////////////////////////
// class of doubly circular linklist
///////////////////////////////////////////////////////////////

// doubly circular link list
template <class T>
class doublyCL
{
public:
    struct nodeD<T> *First;
    struct nodeD<T> *Last;
    int icount;

    doublyCL();

    void display();
    int count();

    void InsertFirst(T no);
    void InsertLast(T no);
    void InsertAtPos(T no, int ipos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int ipos);
};

///////////////////////////////////////////////////////////////
// logic of 32 functions
///////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////
// constructor of linked list
//////////////////////////////////////////////////////////////

// Singly linear link list
template <class T>
singlyLL<T>::singlyLL()
{
    First = NULL;
    icount = 0;
}

// Singly circular link list
template <class T>
singlyCL<T>::singlyCL()
{
    First = NULL;
    icount = 0;
}

// doubly linear link list
template <class T>
doublyLL<T>::doublyLL()
{
    First = NULL;
    Last = NULL;
    icount = 0;
}

// doubly circular link list
template <class T>
doublyCL<T>::doublyCL()
{
    First = NULL;
    Last = NULL;
    icount = 0;
}

///////////////////////////////////////////////////////////////
// Insert element at a first position
///////////////////////////////////////////////////////////////

// Singly linear link list
template <class T>
void singlyLL<T>::InsertFirst(T no)
{
    nodeS<T> *newn = new nodeS<T>;
    newn->data = no;
    newn->next = NULL;

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    icount++;
}

// Singly circular link list
template <class T>
void singlyCL<T>::InsertFirst(T no)
{
    nodeS<T> *newn = new nodeS<T>;
    newn->data = no;
    newn->next = NULL;

    if (First == NULL)
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    Last->next = First;
    icount++;
}

// doubly linear link list
template <class T>
void doublyLL<T>::InsertFirst(T no)
{
    nodeD<T> *newn = new nodeD<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if ((First == NULL) || (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
    icount++;
}

// doubly circular link list
template <class T>
void doublyCL<T>::InsertFirst(T no)
{
    nodeD<T> *newn = new nodeD<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if ((First == NULL) || (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
    Last->next = First;
    First->prev = Last;
    icount++;
}

///////////////////////////////////////////////////////////////
// Insert element at a given position
///////////////////////////////////////////////////////////////

// Singly linear link list
template <class T>
void singlyLL<T>::InsertAtPos(T no, int ipos)
{
    int icount = count();
    if ((ipos < 1) || (ipos > icount + 1))
    {
        cout << "invalid position\n";
        return;
    }
    if (ipos == 1)
    {
        InsertFirst(no);
    }
    else if (ipos == icount + 1)
    {
        InsertLast(no);
    }
    else
    {
        nodeS<T> *Temp = First;
        nodeS<T> *newn = new nodeS<T>;

        newn->data = no;
        newn->next = NULL;

        for (int icnt = 1; icnt < ipos - 1; icnt++)
        {
            Temp = Temp->next;
        }
        newn->next = Temp->next;
        Temp->next = newn;
        icount++;
    }
}

// Singly circular link list
template <class T>
void singlyCL<T>::InsertAtPos(T no, int ipos)
{
    nodeS<T> *Temp = First;
    if ((ipos < 1) || (ipos > icount + 1))
    {
        return;
    }
    if (ipos == 1)
    {
        InsertFirst(no);
    }
    else if (ipos == icount + 1)
    {
        InsertLast(no);
    }
    else
    {
        for (int icnt = 1; icnt < ipos - 1; icnt++)
        {
            Temp = Temp->next;
        }
        nodeS<T> *newn = new nodeS<T>;
        newn->data = no;
        newn->next = NULL;

        newn->next = Temp->next;
        Temp->next = newn;

        icount++;
    }
}

// doubly linear link list
template <class T>
void doublyLL<T>::InsertAtPos(T no, int ipos)
{
    int icount = count();
    if ((ipos < 1) || (ipos > icount + 1))
    {
        cout << "invalid position\n";
        return;
    }
    if (ipos == 1)
    {
        InsertFirst(no);
    }
    else if (ipos == icount + 1)
    {
        InsertLast(no);
    }
    else
    {
        nodeD<T> *Temp = First;
        nodeD<T> *newn = new nodeD<T>;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        for (int icnt = 1; icnt < ipos - 1; icnt++)
        {
            Temp = Temp->next;
        }
        newn->next = Temp->next;
        Temp->next->prev = newn;
        Temp->next = newn;
        newn->prev = Temp;
        icount++;
    }
}

// doubly circular link list
template <class T>
void doublyCL<T>::InsertAtPos(T no, int ipos)
{
    if ((ipos < 1) || (ipos > icount + 1))
    {
        cout << "invalid position"
             << "\n";
        return;
    }

    if (ipos == 1)
    {
        InsertFirst(no);
    }
    else if (ipos == icount + 1)
    {
        InsertLast(no);
    }
    else
    {
        nodeD<T> *temp = First;
        for (int icnt = 1; icnt < ipos - 1; icnt++)
        {
            temp = temp->next;
        }
        nodeD<T> *newn = new nodeD<T>;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp->next->prev = newn;
        newn->next = temp->next;
        temp->next = newn;
        newn->prev = temp;

        icount++;
    }
}

///////////////////////////////////////////////////////////////
// Insert element at a Last position
///////////////////////////////////////////////////////////////

// Singly linear link list
template <class T>
void singlyLL<T>::InsertLast(T no)
{
    nodeS<T> *newn = new nodeS<T>;
    newn->data = no;
    newn->next = NULL;

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        nodeS<T> *Temp = First;
        while (Temp->next != NULL)
        {
            Temp = Temp->next;
        }
        Temp->next = newn;
    }
    icount++;
}

// Singly circular link list
template <class T>
void singlyCL<T>::InsertLast(T no)
{
    nodeS<T> *newn = new nodeS<T>;
    newn->data = no;
    newn->next = NULL;

    if (First == NULL)
    {
        First = newn;
        Last = newn;
        First->next = First;
    }
    else
    {
        Last->next = newn;
        Last = newn;
        Last->next = First;
    }
    icount++;
}

// doubly linear link list
template <class T>
void doublyLL<T>::InsertLast(T no)
{
    nodeD<T> *newn = new nodeD<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if ((First == NULL) || (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        Last->next = newn;
        newn->prev = Last;
        Last = newn;
    }
    icount++;
}

// doubly circular link list
template <class T>
void doublyCL<T>::InsertLast(T no)
{
    nodeD<T> *newn = new nodeD<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if ((First == NULL) || (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->prev = Last;
        Last->next = newn;
        Last = newn;
    }
    Last->next = First;
    First->prev = First;
    icount++;
}

///////////////////////////////////////////////////////////////
// Delete element at a first position
///////////////////////////////////////////////////////////////

// Singly linear link list
template <class T>
void singlyLL<T>::DeleteFirst()
{
    if (First == NULL)
    {
        return;
    }
    else if (First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        nodeS<T> *Temp = First;

        First = First->next;
        delete Temp;
    }
    icount--;
}

// Singly circular link list
template <class T>
void singlyCL<T>::DeleteFirst()
{
    if (First == NULL)
    {
        return;
    }
    else if (First->next == First)
    {
        delete First; // free(first);
        First = NULL;
        Last = NULL;
    }
    else
    {
        First = First->next;
        delete Last->next;
        Last->next = First;
    }
    icount--;
}

// doubly linear link list
template <class T>
void doublyLL<T>::DeleteFirst()
{
    if ((First == NULL) || (Last == NULL))
    {
        return;
    }
    else if (First->next == NULL)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        First = First->next;
        delete First->prev;
        First->prev = NULL;
    }
    icount--;
}

// doubly circular link list
template <class T>
void doublyCL<T>::DeleteFirst()
{
    nodeD<T> *temp = First;
    if (First == NULL && Last == NULL)
    {
        return;
    }
    else if (First->next == First)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        First = First->next;
        delete temp;
        Last->next = First;
        First->prev = Last;
    }
    icount--;
}

///////////////////////////////////////////////////////////////
// Delete element at given position
///////////////////////////////////////////////////////////////

// Singly linear link list
template <class T>
void singlyLL<T>::DeleteAtPos(int ipos)
{
    int icount = count();
    if ((ipos < 1) || (ipos > icount))
    {
        cout << "invalid position\n";
        return;
    }
    if (ipos == 1)
    {
        DeleteFirst();
    }
    else if (ipos == icount)
    {
        DeleteLast();
    }
    else
    {
        nodeS<T> *Temp1 = First;
        nodeS<T> *Temp2 = NULL;
        for (int icnt = 1; icnt < ipos - 1; icnt++)
        {
            Temp1 = Temp1->next;
        }
        Temp2 = Temp1->next->next;
        delete Temp1->next;
        Temp1->next = Temp2;

        icount--;
    }
}

// Singly circular link list
template <class T>
void singlyCL<T>::DeleteAtPos(int ipos)
{
    nodeS<T> *temp = First;
    if ((ipos < 1) || (ipos > icount))
    {
        return;
    }
    if (ipos == 1)
    {
        DeleteFirst();
    }
    else if (ipos == icount)
    {
        DeleteLast();
    }
    else
    {
        nodeS<T> *temp1 = NULL;
        for (int icnt = 1; icnt < ipos - 1; icnt++)
        {
            temp = temp->next;
        }
        temp1 = temp->next->next;
        delete temp->next;
        temp->next = temp1;
        icount--;
    }
}

// doubly linear link list
template <class T>
void doublyLL<T>::DeleteAtPos(int ipos)
{
    int icount = count();
    if ((ipos < 1) || (ipos > icount))
    {
        cout << "invalid position\n";
        return;
    }
    if (ipos == 1)
    {
        DeleteFirst();
    }
    else if (ipos == icount)
    {
        DeleteLast();
    }
    else
    {
        nodeD<T> *Temp1 = First;
        nodeD<T> *Temp2 = NULL;
        for (int icnt = 1; icnt < ipos - 1; icnt++)
        {
            Temp1 = Temp1->next;
        }
        Temp2 = Temp1->next->next;
        delete Temp1->next;
        Temp2->prev = Temp1;
        Temp1->next = Temp2;

        icount--;
    }
}

// doubly circular link list
template <class T>
void doublyCL<T>::DeleteAtPos(int ipos)
{
    if ((ipos < 1) || (ipos > icount))
    {
        cout << "invalid position"
             << "\n";
        return;
    }

    if (ipos == 1)
    {
        DeleteFirst();
    }
    else if (ipos == icount)
    {
        DeleteLast();
    }
    else
    {
        nodeD<T> *temp = First;
        nodeD<T> *tempx = First;

        for (int icnt = 1; icnt < ipos - 1; icnt++)
        {
            temp = temp->next;
        }
        tempx = temp->next->next;
        delete temp->next;
        temp->next = tempx;
        tempx->prev = temp;
        icount--;
    }
}

///////////////////////////////////////////////////////////////
// Delete element at a Last position
///////////////////////////////////////////////////////////////

// Singly linear link list
template <class T>
void singlyLL<T>::DeleteLast()
{
    if (First == NULL)
    {
        return;
    }
    else if (First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        nodeS<T> *Temp = First;
        while (Temp->next->next != NULL)
        {
            Temp = Temp->next;
        }
        delete Temp->next;
        Temp->next = NULL;
    }
    icount--;
}

// Singly circular link list
template <class T>
void singlyCL<T>::DeleteLast()
{
    if (First == NULL)
    {
        cout << "empty link list"
             << "\n";
        return;
    }
    else if (First->next == First)
    {
        delete First; // free(first);
        First = NULL;
        Last = NULL;
    }
    else
    {
        nodeS<T> *temp = First;
        while (temp->next->next != First)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = First;
        Last = temp;
    }
    icount--;
}

// doubly linear link list
template <class T>
void doublyLL<T>::DeleteLast()
{
    if ((First == NULL) || (Last == NULL))
    {
        return;
    }
    else if (First->next == NULL)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        Last = Last->prev;
        delete Last->next;
        Last->next = NULL;
    }
    icount--;
}

// doubly circular link list
template <class T>
void doublyCL<T>::DeleteLast()
{
    nodeD<T> *temp = Last;
    if (First == NULL && Last == NULL)
    {
        return;
    }
    else if (First->next == First)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        Last = temp->prev;
        delete temp;
        Last->next = First;
        First->prev = Last;
    }
    icount--;
}

///////////////////////////////////////////////////////////////
// total counting of total nodes in the link list
///////////////////////////////////////////////////////////////

// Singly linear link list
template <class T>
int singlyLL<T>::count()
{
    return icount+1;
}

// Singly circular link list
template <class T>
int singlyCL<T>::count()
{
    return icount;
}

// doubly linear link list
template <class T>
int doublyLL<T>::count()
{
    return icount;
}

// doubly circular link list
template <class T>
int doublyCL<T>::count()
{
    return icount;
}

///////////////////////////////////////////////////////////////
// Display all elements in the link list
///////////////////////////////////////////////////////////////

// Singly linear link list
template <class T>
void singlyLL<T>::display()
{
    cout << "Elements of singly linear list are : "
         << "\n";

    nodeS<T> *temp = First;

    while (temp != NULL)
    {
        cout << "| " << temp->data << " |->";
        temp = temp->next;
    }
    cout << "NULL"
         << "\n";
}

// Singly circular link list
template <class T>
void singlyCL<T>::display()
{
    cout << "Elements of singly circular list are : "
         << "\n";

    nodeS<T> *temp = First;

    while (temp != Last)
    {
        cout << "| " << temp->data << " |->";
        temp = temp->next;
    }
    cout << "\n";
}

// doubly linear link list
template <class T>
void doublyLL<T>::display()
{
    cout << "Elements of doubly linear list are : "
         << "\n";

    nodeD<T> *temp = First;

    while (temp != NULL)
    {
        cout << "| " << temp->data << " |->";
        temp = temp->next;
    }
    cout << "NULL"
         << "\n";
}

// doubly circular link list
template <class T>
void doublyCL<T>::display()
{
    cout << "Elements of doubly circular list are : "
         << "\n";

    nodeD<T> *temp = First;

    while (temp->next != First)
    {
        cout << "| " << temp->data << " |->";
        temp = temp->next;
    }
    cout << "NULL"
         << "\n";
}

///////////////////////////////////////////////////////////////
// Link List selection function
///////////////////////////////////////////////////////////////

int LinkListChoice()
{
    int LLchoice = -99;
    cout << "------------------------------------------------------\n";
    cout << "Choose a link list ..."
         << "\n";
    cout << "------------------------------------------------------\n";
    cout << "please enter a choice for Link List..."
         << "\n";

    cout << "1: Singly Linear Link List\n";
    cout << "2: Singly Circular Link List\n";
    cout << "3: Doubly Linear Link List\n";
    cout << "4: Doubly Circular Link List\n";
    cout << "5: terminate the application\n";

    cin >> LLchoice;
    cout << "------------------------------------------------------\n";
    if (LLchoice == 1)
    {
        cout << "------------------------------------------------------\n";
        cout << "Singly linear link list has been ready to create.."
             << "\n";
        cout << "------------------------------------------------------\n";
        return 1;
    }
    else if (LLchoice == 2)
    {
        cout << "------------------------------------------------------\n";
        cout << "Singly circular link list has been ready to create.."
             << "\n";
        cout << "------------------------------------------------------\n";
        return 2;
    }
    else if (LLchoice == 3)
    {
        cout << "------------------------------------------------------\n";
        cout << "doubly linear link list has been ready to create.."
             << "\n";
        cout << "------------------------------------------------------\n";
        return 3;
    }
    else if (LLchoice == 4)
    {
        cout << "------------------------------------------------------\n";
        cout << "doubly circular link list has been ready to create.."
             << "\n";
        cout << "------------------------------------------------------\n";
        return 4;
    }
    else if (LLchoice == 5)
    {
        cout << "stop creating the link list or stop the process.."
             << "\n";
        return 5;
    }
    else
    {
        cout << "your selected position is been wrong ..."
             << "\n";
        return 0;
    }
}

///////////////////////////////////////////////////////////////
// data type selection function
///////////////////////////////////////////////////////////////

int DataTypeChoice()
{
    int DTchoice = 0;
    cout << "choose one data type in the following statements..."
         << "\n";
    cout << "------------------------------------------------------\n";
    cout << "please enter a choice for data type..."
         << "\n";

    cout << "1: INT ( integer )\n";
    cout << "2: FLOAT ( float )\n";
    cout << "3: DOUBLE ( double )\n";
    cout << "4: CHAR ( character )\n";
    cout << "5: terminate the application\n";

    cin >> DTchoice;
    cout << "------------------------------------------------------\n";
    if (DTchoice == 1)
    {
        cout << "------------------------------------------------------\n";
        cout << "you select integer data type for creating  link list .."
             << "\n";
        cout << "insert data like 87   93    82"
             << "\n";
        cout << "------------------------------------------------------\n";
        return 1;
    }
    else if (DTchoice == 2)
    {
        cout << "------------------------------------------------------\n";
        cout << "you select float data type for creating  link list .."
             << "\n";
        cout << "insert data like 24.34   19.43    12.82"
             << "\n";
        cout << "------------------------------------------------------\n";
        return 2;
    }
    else if (DTchoice == 3)
    {
        cout << "------------------------------------------------------\n";
        cout << "you select double data type for creating  link list .."
             << "\n";
        cout << "insert data like 87.8724   93.9722    82.9832"
             << "\n";
        cout << "------------------------------------------------------\n";
        return 3;
    }
    else if (DTchoice == 4)
    {
        cout << "------------------------------------------------------\n";
        cout << "you select character data type for creating  link list .."
             << "\n";
        cout << "insert data like  a  b  c  //  A  B  C  "
             << "\n";
        cout << "------------------------------------------------------\n";
        return 4;
    }
    else if (DTchoice == 5)
    {
        cout << "------------------------------------------------------\n";
        cout << "stop the process of link list.."
             << "\n";
        cout << "------------------------------------------------------\n";
    }
    else
    {
        cout << "------------------------------------------------------\n";
        cout << "your selected position of data type is been wrong ..."
             << "\n";
        cout << "------------------------------------------------------\n";
        return 0;
    }
}

///////////////////////////////////////////////////////////////
// entry point function
///////////////////////////////////////////////////////////////

int main()
{
    singlyLL<int> iobj1;
    singlyCL<int> iobj2;
    doublyLL<int> iobj3;
    doublyCL<int> iobj4;
    
    singlyLL<float> fobj1;
    singlyLL<float> fobj2;
    singlyLL<float> fobj3;
    singlyLL<float> fobj4;
    
    singlyLL<double> dobj1;
    singlyLL<double> dobj2;
    singlyLL<double> dobj3;
    singlyLL<double> dobj4;

    singlyLL<char> cobj1;
    singlyLL<char> cobj2;
    singlyLL<char> cobj3;
    singlyLL<char> cobj4;
    

    int ichoice1 = 0;
    int ichoice = 0;
    int ichoice2 = 0;
    int iposition = 0;
    int ivalue = 0;
    float fvalue = 0.0f;
    double dvalue = 0.0;
    char cvalue = '\0';

    cout << "------------------------------------------------------\n";
    cout << "            ------  Siddharth  -------"
         << "\n";
    cout << "------------------------------------------------------\n";

    cout << "------------------------------------------------------\n";
    cout << "Welcome to Creating Link list application.."
         << "\n";
    cout << "------------------------------------------------------\n";
    ichoice1 = LinkListChoice();
    switch (ichoice1)
    {
    case 0:
        cout << "------------------------------------------------------\n";
        cout << "thank you.."
             << "\n";
        cout << "if you want to create link list then please restart the application.."
             << "\n";
        cout << "this application run on single path then you cant backtrack the position to choose another choice..."
             << "\n";
        cout << "your faithfull Siddharth..."
             << "\n";
        cout << "------------------------------------------------------\n";
        break;

    case 1:
        cout << "------------------------------------------------------\n";
        cout << "congrats you select singly linear link list..."
             << "\n";
        cout << "------------------------------------------------------\n";
        cout << "select a data type.."
             << "\n";
        ichoice2 = DataTypeChoice();
        switch (ichoice2)
        {
        case 0:
            cout << "------------------------------------------------------\n";
            cout << "thank you.."
                 << "\n";
            cout << "if you want to create link list then please restart the application.."
                 << "\n";
            cout << "this application run on single path then you cant backtrack the position to choose another choice..."
                 << "\n";
            cout << "your faithfull Siddharth..."
                 << "\n";
            cout << "------------------------------------------------------\n";
            break;

        case 1:
            cout << "congrats you select int data type.."
                 << "\n";
            while (1)
            {
                cout << "------------------------------------------------------\n";
                cout << "please enter your choice: \n";
                cout << "------------------------------------------------------\n";

                cout << "1: Insert node at First position\n";
                cout << "2: Insert node at last position\n";
                cout << "3: Insert node at the given position\n";
                cout << "4: delete node at first position\n";
                cout << "5: delete node at last position\n";
                cout << "6: delete node at the given position\n";
                cout << "7: display the elements of the linked list\n";
                cout << "8: count number of nodes from the linked list\n";
                cout << "9: terminate the application\n";
                cout << "------------------------------------------------------\n";

                cin >> ichoice;
                cout << "------------------------------------------------------\n";
                switch (ichoice)
                {
                case 1:
                    cout << "enter value that you want to insert: \n";
                    cin >> ivalue;
                    iobj1.InsertFirst(ivalue);
                    break;

                case 2:
                    cout << "enter value that you want to insert: \n";
                    cin >> ivalue;
                    iobj1.InsertLast(ivalue);
                    break;

                case 3:
                    cout << "enter the value that you want to insert: \n";
                    cin >> ivalue;

                    cout << "enter the position: \n";
                    cin >> iposition;

                    iobj1.InsertAtPos(ivalue, iposition);
                    break;

                case 4:
                    iobj1.DeleteFirst();
                    break;

                case 5:
                    iobj1.DeleteLast();
                    break;

                case 6:
                    cout << "enter the position\n";
                    cin >> iposition;

                    iobj1.DeleteAtPos(iposition);
                    break;

                case 7:
                    iobj1.display();
                    break;

                case 8:
                    cout << "number of elements are: " << iobj1.count() << "\n";
                    break;

                case 9:
                    cout << "thank you for using the application\n";
                    cout << "your faithfull Siddharth..."
                         << "\n";
                    return 0;

                default:
                    cout << "Invalid input\n";
                    cout << "your faithfull Siddharth..."
                         << "\n";
                    break;
                }
            }
        case 2:
            cout << "congrats you select float data type.."
                 << "\n";
            while (1)
            {
                cout << "------------------------------------------------------\n";
                cout << "please enter your choice: \n";
                cout << "------------------------------------------------------\n";

                cout << "1: Insert node at First position\n";
                cout << "2: Insert node at last position\n";
                cout << "3: Insert node at the given position\n";
                cout << "4: delete node at first position\n";
                cout << "5: delete node at last position\n";
                cout << "6: delete node at the given position\n";
                cout << "7: display the elements of the linked list\n";
                cout << "8: count number of nodes from the linked list\n";
                cout << "9: terminate the application\n";
                cout << "------------------------------------------------------\n";

                cin >> ichoice;
                cout << "------------------------------------------------------\n";
                switch (ichoice)
                {
                case 1:
                    cout << "enter value that you want to insert: \n";
                    cin >> fvalue;
                    fobj1.InsertFirst(fvalue);
                    break;

                case 2:
                    cout << "enter value that you want to insert: \n";
                    cin >> fvalue;
                    fobj1.InsertLast(fvalue);
                    break;

                case 3:
                    cout << "enter the value that you want to insert: \n";
                    cin >> fvalue;

                    cout << "enter the position: \n";
                    cin >> iposition;

                    fobj1.InsertAtPos(fvalue, iposition);
                    break;

                case 4:
                    fobj1.DeleteFirst();
                    break;

                case 5:
                    fobj1.DeleteLast();
                    break;

                case 6:
                    cout << "enter the position\n";
                    cin >> iposition;

                    fobj1.DeleteAtPos(iposition);
                    break;

                case 7:
                    fobj1.display();
                    break;

                case 8:
                    cout << "number of elements are: " << fobj1.count() << "\n";
                    break;

                case 9:
                    cout << "thank you for using the application\n";
                    cout << "your faithfull Siddharth..."
                         << "\n";
                    return 0;

                default:
                    cout << "Invalid input\n";
                    cout << "your faithfull Siddharth..."
                         << "\n";
                    break;
                }
            }
        case 3:
            cout << "------------------------------------------------------\n";
            cout << "congrats you select double data type.."
                 << "\n";
            cout << "------------------------------------------------------\n";
            while (1)
            {
                cout << "------------------------------------------------------\n";
                cout << "please enter your choice: \n";

                cout << "1: Insert node at First position\n";
                cout << "2: Insert node at last position\n";
                cout << "3: Insert node at the given position\n";
                cout << "4: delete node at first position\n";
                cout << "5: delete node at last position\n";
                cout << "6: delete node at the given position\n";
                cout << "7: display the elements of the linked list\n";
                cout << "8: count number of nodes from the linked list\n";
                cout << "9: terminate the application\n";

                cin >> ichoice;
                cout << "------------------------------------------------------\n";
                switch (ichoice)
                {
                case 1:
                    cout << "enter value that you want to insert: \n";
                    cin >> dvalue;
                    dobj1.InsertFirst(dvalue);
                    break;

                case 2:
                    cout << "enter value that you want to insert: \n";
                    cin >> dvalue;
                    dobj1.InsertLast(dvalue);
                    break;

                case 3:
                    cout << "enter the value that you want to insert: \n";
                    cin >> dvalue;

                    cout << "enter the position: \n";
                    cin >> iposition;

                    dobj1.InsertAtPos(dvalue, iposition);
                    break;

                case 4:
                    dobj1.DeleteFirst();
                    break;

                case 5:
                    dobj1.DeleteLast();
                    break;

                case 6:
                    cout << "enter the position\n";
                    cin >> iposition;

                    dobj1.DeleteAtPos(iposition);
                    break;

                case 7:
                    dobj1.display();
                    break;

                case 8:
                    cout << "------------------------------------------------------\n";
                    cout << "number of elements are: " << dobj1.count() << "\n";
                    cout << "------------------------------------------------------\n";
                    break;

                case 9:
                    cout << "------------------------------------------------------\n";
                    cout << "thank you for using the application\n";
                    cout << "your faithfull Siddharth"<<"\n";
                    cout << "------------------------------------------------------\n";
                    return 0;

                default:
                    cout << "Invalid input\n";
                    cout << "your faithfull Siddharth..."
                         << "\n";
                    break;
                }
            }
        case 4:
            cout << "------------------------------------------------------\n";
            cout << "congrats you select char data type.."
                 << "\n";
            while (1)
            {
                cout << "------------------------------------------------------\n";
                cout << "please enter your choice: \n";

                cout << "1: Insert node at First position\n";
                cout << "2: Insert node at last position\n";
                cout << "3: Insert node at the given position\n";
                cout << "4: delete node at first position\n";
                cout << "5: delete node at last position\n";
                cout << "6: delete node at the given position\n";
                cout << "7: display the elements of the linked list\n";
                cout << "8: count number of nodes from the linked list\n";
                cout << "9: terminate the application\n";

                cin >> ichoice;
                cout << "------------------------------------------------------\n";
                switch (ichoice)
                {
                case 1:
                    cout << "enter value that you want to insert: \n";
                    cin >> cvalue;
                    cobj1.InsertFirst(cvalue);
                    break;

                case 2:
                    cout << "enter value that you want to insert: \n";
                    cin >> cvalue;
                    cobj1.InsertLast(cvalue);
                    break;

                case 3:
                    cout << "enter the value that you want to insert: \n";
                    cin >> cvalue;

                    cout << "enter the position: \n";
                    cin >> iposition;

                    cobj1.InsertAtPos(cvalue, iposition);
                    break;

                case 4:
                    cobj1.DeleteFirst();
                    break;

                case 5:
                    cobj1.DeleteLast();
                    break;

                case 6:
                    cout << "enter the position\n";
                    cin >> iposition;

                    cobj1.DeleteAtPos(iposition);
                    break;

                case 7:
                    cobj1.display();
                    break;

                case 8:
                    cout << "number of elements are: " << cobj1.count() << "\n";
                    break;

                case 9:
                    cout << "thank you for using the application\n";
                    cout << "your faithfull Siddharth..."
                         << "\n";
                    return 0;

                default:
                    cout << "Invalid input\n";
                    cout << "your faithfull Siddharth..."
                         << "\n";
                    break;
                }
            }
        case 5:
            cout << "invalid input"
                 << "\n";
            cout << "thank you using my application.."
                 << "\n";
            cout << "your faithfull Siddharth..."
                 << "\n";
            cout << "------------------------------------------------------\n";
            break;

        default:
            cout << "invalid input"
                 << "\n";
            cout << "thank you using my application.."
                 << "\n";
            cout << "your faithfull Siddharth..."
                 << "\n";
            cout << "------------------------------------------------------\n";
            break;
        }

    case 2:
        cout << "------------------------------------------------------\n";
        cout << "congrats you select singly circular link list..."
             << "\n";
        cout << "------------------------------------------------------\n";
        cout << "select a data type.."
             << "\n";
        ichoice2 = DataTypeChoice();
        switch (ichoice2)
        {
        case 0:
            cout << "------------------------------------------------------\n";
            cout << "thank you.."
                 << "\n";
            cout << "if you want to create link list then please restart the application.."
                 << "\n";
            cout << "this application run on single path then you cant backtrack the position to choose another choice..."
                 << "\n";
            cout << "your faithfull Siddharth..."
                 << "\n";
            cout << "------------------------------------------------------\n";
            break;

        case 1:
            cout << "------------------------------------------------------\n";
            cout << "congrats you select int data type.."
                 << "\n";
            while (1)
            {
                cout << "------------------------------------------------------\n";
                cout << "please enter your choice: \n";

                cout << "1: Insert node at First position\n";
                cout << "2: Insert node at last position\n";
                cout << "3: Insert node at the given position\n";
                cout << "4: delete node at first position\n";
                cout << "5: delete node at last position\n";
                cout << "6: delete node at the given position\n";
                cout << "7: display the elements of the linked list\n";
                cout << "8: count number of nodes from the linked list\n";
                cout << "9: terminate the application\n";

                cin >> ichoice;
                cout << "------------------------------------------------------\n";
                switch (ichoice)
                {
                case 1:
                    cout << "enter value that you want to insert: \n";
                    cin >> ivalue;
                    iobj2.InsertFirst(ivalue);
                    break;

                case 2:
                    cout << "enter value that you want to insert: \n";
                    cin >> ivalue;
                    iobj2.InsertLast(ivalue);
                    break;

                case 3:
                    cout << "enter the value that you want to insert: \n";
                    cin >> ivalue;

                    cout << "enter the position: \n";
                    cin >> iposition;

                    iobj2.InsertAtPos(ivalue, iposition);
                    break;

                case 4:
                    iobj2.DeleteFirst();
                    break;

                case 5:
                    iobj2.DeleteLast();
                    break;

                case 6:
                    cout << "enter the position\n";
                    cin >> iposition;

                    iobj2.DeleteAtPos(iposition);
                    break;

                case 7:
                    iobj2.display();
                    break;

                case 8:
                    cout << "number of elements are: " << iobj2.count() << "\n";
                    break;

                case 9:
                    cout << "thank you for using the application\n";
                    cout << "your faithfull Siddharth..."
                         << "\n";
                    return 0;

                default:
                    cout << "Invalid input\n";
                    cout << "your faithfull Siddharth..."
                         << "\n";
                    break;
                }
            }
        case 2:
            cout << "------------------------------------------------------\n";
            cout << "congrats you select float data type.."
                 << "\n";
            while (1)
            {
                cout << "------------------------------------------------------\n";
                cout << "please enter your choice: \n";

                cout << "1: Insert node at First position\n";
                cout << "2: Insert node at last position\n";
                cout << "3: Insert node at the given position\n";
                cout << "4: delete node at first position\n";
                cout << "5: delete node at last position\n";
                cout << "6: delete node at the given position\n";
                cout << "7: display the elements of the linked list\n";
                cout << "8: count number of nodes from the linked list\n";
                cout << "9: terminate the application\n";

                cin >> ichoice;
                cout << "------------------------------------------------------\n";
                switch (ichoice)
                {
                case 1:
                    cout << "enter value that you want to insert: \n";
                    cin >> fvalue;
                    fobj2.InsertFirst(fvalue);
                    break;

                case 2:
                    cout << "enter value that you want to insert: \n";
                    cin >> fvalue;
                    fobj2.InsertLast(fvalue);
                    break;

                case 3:
                    cout << "enter the value that you want to insert: \n";
                    cin >> fvalue;

                    cout << "enter the position: \n";
                    cin >> iposition;

                    fobj2.InsertAtPos(fvalue, iposition);
                    break;

                case 4:
                    fobj2.DeleteFirst();
                    break;

                case 5:
                    fobj2.DeleteLast();
                    break;

                case 6:
                    cout << "enter the position\n";
                    cin >> iposition;

                    fobj2.DeleteAtPos(iposition);
                    break;

                case 7:
                    fobj2.display();
                    break;

                case 8:
                    cout << "number of elements are: " << fobj2.count() << "\n";
                    break;

                case 9:
                    cout << "thank you for using the application\n";
                    cout << "your faithfull Siddharth..."
                         << "\n";
                    return 0;

                default:
                    cout << "Invalid input\n";
                    cout << "your faithfull Siddharth..."
                         << "\n";
                    break;
                }
            }
        case 3:
            cout << "------------------------------------------------------\n";
            cout << "congrats you select double data type.."
                 << "\n";
            while (1)
            {
                cout << "------------------------------------------------------\n";
                cout << "please enter your choice: \n";

                cout << "1: Insert node at First position\n";
                cout << "2: Insert node at last position\n";
                cout << "3: Insert node at the given position\n";
                cout << "4: delete node at first position\n";
                cout << "5: delete node at last position\n";
                cout << "6: delete node at the given position\n";
                cout << "7: display the elements of the linked list\n";
                cout << "8: count number of nodes from the linked list\n";
                cout << "9: terminate the application\n";

                cin >> ichoice;
                cout << "------------------------------------------------------\n";
                switch (ichoice)
                {
                case 1:
                    cout << "enter value that you want to insert: \n";
                    cin >> dvalue;
                    dobj2.InsertFirst(dvalue);
                    break;

                case 2:
                    cout << "enter value that you want to insert: \n";
                    cin >> dvalue;
                    dobj2.InsertLast(dvalue);
                    break;

                case 3:
                    cout << "enter the value that you want to insert: \n";
                    cin >> dvalue;

                    cout << "enter the position: \n";
                    cin >> iposition;

                    dobj2.InsertAtPos(dvalue, iposition);
                    break;

                case 4:
                    dobj2.DeleteFirst();
                    break;

                case 5:
                    dobj2.DeleteLast();
                    break;

                case 6:
                    cout << "enter the position\n";
                    cin >> iposition;

                    dobj2.DeleteAtPos(iposition);
                    break;

                case 7:
                    dobj2.display();
                    break;

                case 8:
                    cout << "number of elements are: " << dobj2.count() << "\n";
                    break;

                case 9:
                    cout << "thank you for using the application\n";
                    cout << "your faithfull Siddharth..."
                         << "\n";
                    return 0;

                default:
                    cout << "Invalid input\n";
                    cout << "your faithfull Siddharth..."
                         << "\n";
                    break;
                }
            }
        case 4:
            cout << "------------------------------------------------------\n";
            cout << "congrats you select char data type.."
                 << "\n";
            while (1)
            {
                cout << "------------------------------------------------------\n";
                cout << "please enter your choice: \n";

                cout << "1: Insert node at First position\n";
                cout << "2: Insert node at last position\n";
                cout << "3: Insert node at the given position\n";
                cout << "4: delete node at first position\n";
                cout << "5: delete node at last position\n";
                cout << "6: delete node at the given position\n";
                cout << "7: display the elements of the linked list\n";
                cout << "8: count number of nodes from the linked list\n";
                cout << "9: terminate the application\n";

                cin >> ichoice;
                cout << "------------------------------------------------------\n";
                switch (ichoice)
                {
                case 1:
                    cout << "enter value that you want to insert: \n";
                    cin >> cvalue;
                    cobj2.InsertFirst(cvalue);
                    break;

                case 2:
                    cout << "enter value that you want to insert: \n";
                    cin >> cvalue;
                    cobj2.InsertLast(cvalue);
                    break;

                case 3:
                    cout << "enter the value that you want to insert: \n";
                    cin >> cvalue;

                    cout << "enter the position: \n";
                    cin >> iposition;

                    cobj2.InsertAtPos(cvalue, iposition);
                    break;

                case 4:
                    cobj2.DeleteFirst();
                    break;

                case 5:
                    cobj2.DeleteLast();
                    break;

                case 6:
                    cout << "enter the position\n";
                    cin >> iposition;

                    cobj2.DeleteAtPos(iposition);
                    break;

                case 7:
                    cobj2.display();
                    break;

                case 8:
                    cout << "number of elements are: " << cobj2.count() << "\n";
                    break;

                case 9:
                    cout << "thank you for using the application\n";
                    cout << "your faithfull Siddharth..."
                         << "\n";
                    return 0;

                default:
                    cout << "Invalid input\n";
                    cout << "your faithfull Siddharth..."
                         << "\n";
                    break;
                }
            }
        case 5:
            cout << "------------------------------------------------------\n";
            cout << "invalid input"
                 << "\n";
            cout << "thank you using my application.."
                 << "\n";
            cout << "your faithfull Siddharth..."
                 << "\n";
            cout << "------------------------------------------------------\n";
            break;

        default:
            cout << "------------------------------------------------------\n";
            cout << "invalid input"
                 << "\n";
            cout << "thank you using my application.."
                 << "\n";
            cout << "your faithfull Siddharth..."
                 << "\n";
            cout << "------------------------------------------------------\n";
            break;
        }
    case 3:
        cout << "------------------------------------------------------\n";
        cout << "congrats you select doubly linear link list..."
             << "\n";
        cout << "------------------------------------------------------\n";
        cout << "select a data type.."
             << "\n";
        ichoice2 = DataTypeChoice();
        switch (ichoice2)
        {
        case 0:
            cout << "------------------------------------------------------\n";
            cout << "thank you.."
                 << "\n";
            cout << "if you want to create link list then please restart the application.."
                 << "\n";
            cout << "this application run on single path then you cant backtrack the position to choose another choice..."
                 << "\n";
            cout << "your faithfull Siddharth..."
                 << "\n";
            cout << "------------------------------------------------------\n";
            break;

        case 1:
            cout << "------------------------------------------------------\n";
            cout << "congrats you select int data type.."
                 << "\n";
            while (1)
            {
                cout << "------------------------------------------------------\n";
                cout << "please enter your choice: \n";

                cout << "1: Insert node at First position\n";
                cout << "2: Insert node at last position\n";
                cout << "3: Insert node at the given position\n";
                cout << "4: delete node at first position\n";
                cout << "5: delete node at last position\n";
                cout << "6: delete node at the given position\n";
                cout << "7: display the elements of the linked list\n";
                cout << "8: count number of nodes from the linked list\n";
                cout << "9: terminate the application\n";

                cin >> ichoice;
                cout << "------------------------------------------------------\n";
                switch (ichoice)
                {
                case 1:
                    cout << "enter value that you want to insert: \n";
                    cin >> ivalue;
                    iobj3.InsertFirst(ivalue);
                    break;

                case 2:
                    cout << "enter value that you want to insert: \n";
                    cin >> ivalue;
                    iobj3.InsertLast(ivalue);
                    break;

                case 3:
                    cout << "enter the value that you want to insert: \n";
                    cin >> ivalue;

                    cout << "enter the position: \n";
                    cin >> iposition;

                    iobj3.InsertAtPos(ivalue, iposition);
                    break;

                case 4:
                    iobj3.DeleteFirst();
                    break;

                case 5:
                    iobj3.DeleteLast();
                    break;

                case 6:
                    cout << "enter the position\n";
                    cin >> iposition;

                    iobj3.DeleteAtPos(iposition);
                    break;

                case 7:
                    iobj3.display();
                    break;

                case 8:
                    cout << "number of elements are: " << iobj3.count() << "\n";
                    break;

                case 9:
                    cout << "thank you for using the application\n";
                    cout << "your faithfull Siddharth..."
                         << "\n";
                    return 0;

                default:
                    cout << "Invalid input\n";
                    cout << "your faithfull Siddharth..."
                         << "\n";
                    break;
                }
            }
        case 2:
            cout << "------------------------------------------------------\n";
            cout << "congrats you select float data type.."
                 << "\n";
            while (1)
            {
                cout << "------------------------------------------------------\n";
                cout << "please enter your choice: \n";

                cout << "1: Insert node at First position\n";
                cout << "2: Insert node at last position\n";
                cout << "3: Insert node at the given position\n";
                cout << "4: delete node at first position\n";
                cout << "5: delete node at last position\n";
                cout << "6: delete node at the given position\n";
                cout << "7: display the elements of the linked list\n";
                cout << "8: count number of nodes from the linked list\n";
                cout << "9: terminate the application\n";

                cin >> ichoice;
                cout << "------------------------------------------------------\n";
                switch (ichoice)
                {
                case 1:
                    cout << "enter value that you want to insert: \n";
                    cin >> fvalue;
                    fobj3.InsertFirst(fvalue);
                    break;

                case 2:
                    cout << "enter value that you want to insert: \n";
                    cin >> fvalue;
                    fobj3.InsertLast(fvalue);
                    break;

                case 3:
                    cout << "enter the value that you want to insert: \n";
                    cin >> fvalue;

                    cout << "enter the position: \n";
                    cin >> iposition;

                    fobj3.InsertAtPos(fvalue, iposition);
                    break;

                case 4:
                    fobj3.DeleteFirst();
                    break;

                case 5:
                    fobj3.DeleteLast();
                    break;

                case 6:
                    cout << "enter the position\n";
                    cin >> iposition;

                    fobj3.DeleteAtPos(iposition);
                    break;

                case 7:
                    fobj3.display();
                    break;

                case 8:
                    cout << "number of elements are: " << fobj3.count() << "\n";
                    break;

                case 9:
                    cout << "thank you for using the application\n";
                    cout << "your faithfull Siddharth..."
                         << "\n";
                    return 0;

                default:
                    cout << "Invalid input\n";
                    cout << "your faithfull Siddharth..."
                         << "\n";
                    break;
                }
            }
        case 3:
            cout << "------------------------------------------------------\n";
            cout << "congrats you select double data type.."
                 << "\n";
            while (1)
            {
                cout << "------------------------------------------------------\n";
                cout << "please enter your choice: \n";

                cout << "1: Insert node at First position\n";
                cout << "2: Insert node at last position\n";
                cout << "3: Insert node at the given position\n";
                cout << "4: delete node at first position\n";
                cout << "5: delete node at last position\n";
                cout << "6: delete node at the given position\n";
                cout << "7: display the elements of the linked list\n";
                cout << "8: count number of nodes from the linked list\n";
                cout << "9: terminate the application\n";

                cin >> ichoice;
                cout << "------------------------------------------------------\n";
                switch (ichoice)
                {
                case 1:
                    cout << "enter value that you want to insert: \n";
                    cin >> dvalue;
                    dobj3.InsertFirst(dvalue);
                    break;

                case 2:
                    cout << "enter value that you want to insert: \n";
                    cin >> dvalue;
                    dobj3.InsertLast(dvalue);
                    break;

                case 3:
                    cout << "enter the value that you want to insert: \n";
                    cin >> dvalue;

                    cout << "enter the position: \n";
                    cin >> iposition;

                    dobj3.InsertAtPos(dvalue, iposition);
                    break;

                case 4:
                    dobj3.DeleteFirst();
                    break;

                case 5:
                    dobj3.DeleteLast();
                    break;

                case 6:
                    cout << "enter the position\n";
                    cin >> iposition;

                    dobj3.DeleteAtPos(iposition);
                    break;

                case 7:
                    dobj3.display();
                    break;

                case 8:
                    cout << "number of elements are: " << dobj3.count() << "\n";
                    break;

                case 9:
                    cout << "------------------------------------------------------\n";
                    cout << "thank you for using the application\n";
                    cout << "your faithfull Siddharth..."
                         << "\n";
                    cout << "------------------------------------------------------\n";
                    return 0;

                default:
                    cout << "Invalid input\n";
                    cout << "your faithfull Siddharth..."
                         << "\n";
                    break;
                }
            }
        case 4:
            cout << "------------------------------------------------------\n";
            cout << "congrats you select char data type.."
                 << "\n";
            while (1)
            {
                cout << "------------------------------------------------------\n";
                cout << "please enter your choice: \n";

                cout << "1: Insert node at First position\n";
                cout << "2: Insert node at last position\n";
                cout << "3: Insert node at the given position\n";
                cout << "4: delete node at first position\n";
                cout << "5: delete node at last position\n";
                cout << "6: delete node at the given position\n";
                cout << "7: display the elements of the linked list\n";
                cout << "8: count number of nodes from the linked list\n";
                cout << "9: terminate the application\n";

                cin >> ichoice;
                cout << "------------------------------------------------------\n";
                switch (ichoice)
                {
                case 1:
                    cout << "enter value that you want to insert: \n";
                    cin >> cvalue;
                    dobj3.InsertFirst(cvalue);
                    break;

                case 2:
                    cout << "enter value that you want to insert: \n";
                    cin >> cvalue;
                    dobj3.InsertLast(cvalue);
                    break;

                case 3:
                    cout << "enter the value that you want to insert: \n";
                    cin >> cvalue;

                    cout << "enter the position: \n";
                    cin >> iposition;

                    dobj3.InsertAtPos(cvalue, iposition);
                    break;

                case 4:
                    dobj3.DeleteFirst();
                    break;

                case 5:
                    dobj3.DeleteLast();
                    break;

                case 6:
                    cout << "enter the position\n";
                    cin >> iposition;

                    dobj3.DeleteAtPos(iposition);
                    break;

                case 7:
                    dobj3.display();
                    break;

                case 8:
                    cout << "number of elements are: " << dobj3.count() << "\n";
                    break;

                case 9:
                    cout << "thank you for using the application\n";
                    cout << "your faithfull Siddharth..."
                         << "\n";
                    return 0;

                default:
                    cout << "Invalid input\n";
                    cout << "your faithfull Siddharth..."
                         << "\n";
                    break;
                }
            }
        case 5:
            cout << "invalid input"
                 << "\n";
            cout << "thank you using my application.."
                 << "\n";
            cout << "your faithfull Siddharth..."
                 << "\n";
            break;

        default:
            cout << "invalid input"
                 << "\n";
            cout << "thank you using my application.."
                 << "\n";
            cout << "your faithfull Siddharth..."
                 << "\n";
            break;
        }

    case 4:
        cout << "------------------------------------------------------\n";
        cout << "congrats you select doubly circular link list..."
             << "\n";
        cout << "------------------------------------------------------\n";
        cout << "select a data type.."
             << "\n";
        ichoice2 = DataTypeChoice();
        switch (ichoice2)
        {
        case 0:
            cout << "------------------------------------------------------\n";
            cout << "thank you.."
                 << "\n";
            cout << "if you want to create link list then please restart the application.."
                 << "\n";
            cout << "this application run on single path then you cant backtrack the position to choose another choice..."
                 << "\n";
            cout << "your faithfull Siddharth..."
                 << "\n";
            cout << "------------------------------------------------------\n";
            break;

        case 1:
            cout << "congrats you select int data type.."
                 << "\n";
            while (1)
            {
                cout << "------------------------------------------------------\n";
                cout << "please enter your choice: \n";

                cout << "1: Insert node at First position\n";
                cout << "2: Insert node at last position\n";
                cout << "3: Insert node at the given position\n";
                cout << "4: delete node at first position\n";
                cout << "5: delete node at last position\n";
                cout << "6: delete node at the given position\n";
                cout << "7: display the elements of the linked list\n";
                cout << "8: count number of nodes from the linked list\n";
                cout << "9: terminate the application\n";

                cin >> ichoice;
                cout << "------------------------------------------------------\n";
                switch (ichoice)
                {
                case 1:
                    cout << "enter value that you want to insert: \n";
                    cin >> ivalue;
                    iobj4.InsertFirst(ivalue);
                    break;

                case 2:
                    cout << "enter value that you want to insert: \n";
                    cin >> ivalue;
                    iobj4.InsertLast(ivalue);
                    break;

                case 3:
                    cout << "enter the value that you want to insert: \n";
                    cin >> ivalue;

                    cout << "enter the position: \n";
                    cin >> iposition;

                    iobj4.InsertAtPos(ivalue, iposition);
                    break;

                case 4:
                    iobj4.DeleteFirst();
                    break;

                case 5:
                    iobj4.DeleteLast();
                    break;

                case 6:
                    cout << "enter the position\n";
                    cin >> iposition;

                    iobj4.DeleteAtPos(iposition);
                    break;

                case 7:
                    iobj4.display();
                    break;

                case 8:
                    cout << "number of elements are: " << iobj4.count() << "\n";
                    break;

                case 9:
                    cout << "thank you for using the application\n";
                    cout << "your faithfull Siddharth..."
                         << "\n";
                    return 0;

                default:
                    cout << "Invalid input\n";
                    cout << "your faithfull Siddharth..."
                         << "\n";
                    break;
                }
            }
        case 2:
            cout << "------------------------------------------------------\n";
            cout << "congrats you select float data type.."
                 << "\n";
            while (1)
            {
                cout << "------------------------------------------------------\n";
                cout << "please enter your choice: \n";

                cout << "1: Insert node at First position\n";
                cout << "2: Insert node at last position\n";
                cout << "3: Insert node at the given position\n";
                cout << "4: delete node at first position\n";
                cout << "5: delete node at last position\n";
                cout << "6: delete node at the given position\n";
                cout << "7: display the elements of the linked list\n";
                cout << "8: count number of nodes from the linked list\n";
                cout << "9: terminate the application\n";

                cin >> ichoice;
                cout << "------------------------------------------------------\n";
                switch (ichoice)
                {
                case 1:
                    cout << "enter value that you want to insert: \n";
                    cin >> fvalue;
                    fobj4.InsertFirst(fvalue);
                    break;

                case 2:
                    cout << "enter value that you want to insert: \n";
                    cin >> fvalue;
                    fobj4.InsertLast(fvalue);
                    break;

                case 3:
                    cout << "enter the value that you want to insert: \n";
                    cin >> fvalue;

                    cout << "enter the position: \n";
                    cin >> iposition;

                    fobj4.InsertAtPos(fvalue, iposition);
                    break;

                case 4:
                    fobj4.DeleteFirst();
                    break;

                case 5:
                    fobj4.DeleteLast();
                    break;

                case 6:
                    cout << "enter the position\n";
                    cin >> iposition;

                    fobj4.DeleteAtPos(iposition);
                    break;

                case 7:
                    fobj4.display();
                    break;

                case 8:
                    cout << "number of elements are: " << fobj4.count() << "\n";
                    break;

                case 9:
                    cout << "thank you for using the application\n";
                    cout << "your faithfull Siddharth..."
                         << "\n";
                    return 0;

                default:
                    cout << "Invalid input\n";
                    cout << "your faithfull Siddharth..."
                         << "\n";
                    break;
                }
            }
        case 3:
            cout << "------------------------------------------------------\n";
            cout << "congrats you select double data type.."
                 << "\n";
            while (1)
            {
                cout << "------------------------------------------------------\n";
                cout << "please enter your choice: \n";

                cout << "1: Insert node at First position\n";
                cout << "2: Insert node at last position\n";
                cout << "3: Insert node at the given position\n";
                cout << "4: delete node at first position\n";
                cout << "5: delete node at last position\n";
                cout << "6: delete node at the given position\n";
                cout << "7: display the elements of the linked list\n";
                cout << "8: count number of nodes from the linked list\n";
                cout << "9: terminate the application\n";

                cin >> ichoice;
                cout << "------------------------------------------------------\n";
                switch (ichoice)
                {
                case 1:
                    cout << "enter value that you want to insert: \n";
                    cin >> dvalue;
                    dobj4.InsertFirst(dvalue);
                    break;

                case 2:
                    cout << "enter value that you want to insert: \n";
                    cin >> dvalue;
                    dobj4.InsertLast(dvalue);
                    break;

                case 3:
                    cout << "enter the value that you want to insert: \n";
                    cin >> dvalue;

                    cout << "enter the position: \n";
                    cin >> iposition;

                    dobj4.InsertAtPos(dvalue, iposition);
                    break;

                case 4:
                    dobj4.DeleteFirst();
                    break;

                case 5:
                    dobj4.DeleteLast();
                    break;

                case 6:
                    cout << "enter the position\n";
                    cin >> iposition;

                    dobj4.DeleteAtPos(iposition);
                    break;

                case 7:
                    dobj4.display();
                    break;

                case 8:
                    cout << "number of elements are: " << dobj4.count() << "\n";
                    break;

                case 9:
                    cout << "thank you for using the application\n";
                    cout << "your faithfull Siddharth..."
                         << "\n";
                    return 0;

                default:
                    cout << "Invalid input\n";
                    cout << "your faithfull Siddharth..."
                         << "\n";
                    break;
                }
            }
        case 4:
            cout << "------------------------------------------------------\n";
            cout << "congrats you select char data type.."
                 << "\n";
            while (1)
            {
                cout << "------------------------------------------------------\n";
                cout << "please enter your choice: \n";

                cout << "1: Insert node at First position\n";
                cout << "2: Insert node at last position\n";
                cout << "3: Insert node at the given position\n";
                cout << "4: delete node at first position\n";
                cout << "5: delete node at last position\n";
                cout << "6: delete node at the given position\n";
                cout << "7: display the elements of the linked list\n";
                cout << "8: count number of nodes from the linked list\n";
                cout << "9: terminate the application\n";

                cin >> ichoice;
                cout << "------------------------------------------------------\n";
                switch (ichoice)
                {
                case 1:
                    cout << "enter value that you want to insert: \n";
                    cin >> cvalue;
                    cobj4.InsertFirst(cvalue);
                    break;

                case 2:
                    cout << "enter value that you want to insert: \n";
                    cin >> cvalue;
                    cobj4.InsertLast(cvalue);
                    break;

                case 3:
                    cout << "enter the value that you want to insert: \n";
                    cin >> cvalue;

                    cout << "enter the position: \n";
                    cin >> iposition;

                    cobj4.InsertAtPos(cvalue, iposition);
                    break;

                case 4:
                    cobj4.DeleteFirst();
                    break;

                case 5:
                    cobj4.DeleteLast();
                    break;

                case 6:
                    cout << "enter the position\n";
                    cin >> iposition;

                    cobj4.DeleteAtPos(iposition);
                    break;

                case 7:
                    cobj4.display();
                    break;

                case 8:
                    cout << "number of elements are: " << cobj4.count() << "\n";
                    break;

                case 9:
                    cout << "thank you for using the application\n";
                    cout << "your faithfull Siddharth..."
                         << "\n";
                    return 0;

                default:
                    cout << "Invalid input\n";
                    cout << "your faithfull Siddharth..."
                         << "\n";
                    break;
                }
            }
        case 5:
            cout << "------------------------------------------------------\n";
            cout << "invalid input"
                 << "\n";
            cout << "thank you using my application.."
                 << "\n";
            cout << "your faithfull Siddharth..."
                 << "\n";
            cout << "------------------------------------------------------\n";
            break;

        default:
            cout << "------------------------------------------------------\n";
            cout << "invalid input"
                 << "\n";
            cout << "thank you using my application.."
                 << "\n";
            cout << "your faithfull Siddharth..."
                 << "\n";
            cout << "------------------------------------------------------\n";
            break;
        }
    }
    return 0;
}