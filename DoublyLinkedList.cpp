// Doubly Linked List Data Type Full Implementation
#include <iostream>
using namespace std;
class Node 
{
    public:
    int data;        // Integer Data Member
    Node* next;      // Pointer to the Next Node. Data type node as pointer.
    Node* prev;      // Pointer to the Previous Node. Data type node as pointer.
    public:
    Node(int val)    // Parametrized Constructor
    {
        data = val;next = NULL;prev = NULL;
    }
};
class DoublyLinkedList   // Class created
{
    public:
    void InsertAtHead(Node* &head, int val)  // Function to Insert Node at beginning
    {
        Node* n = new Node(val);     // New Node created with the given data
        n -> next = head;
        if (head != NULL)   // For the first Node created if head is not NULL
        {
            head -> prev = n;  // Need to create a reverse pointer
        }
        head = n;  // Substituting the value of head back to n
    }
    public:
    void InsertAtTail(Node* &head, int val)
    {
        if (head == NULL)     // If head is NULL that is no node in Doubly Linked List
        {
            InsertAtHead(head, val);   // Function called
            return;   // Control sent back to main
        }
        Node* n = new Node(val);      // New Node created
        Node* temp = head;            // Temporary Node created
        while(temp -> next != NULL)       // While the pointer does not reaches the last
        {
            temp = temp -> next;       // Node pointer incremented
        }
        temp -> next = n;     // Joining the Last Node to the New Node
        n -> prev = temp;     // Joining the New Node to the last Node creating two paths
    }
    public:
    void DisplayList(Node* &head)
    {
        Node* temp = head;   // Temporary Node created with the Head value
        cout << "NULL ";
        while(temp != NULL)  // While entire List is not traversed
        {
            cout <<"<- " << temp -> data << " -> ";   // Printing
            temp = temp -> next;                      // Node pointer incremented
        }
        cout << "NULL";
        cout << endl;              // Statement for jumping control to next Line
    }
    public:
    void FindNodeInList(Node* &head, int val)
    {
        Node* temp = head;          // Creating a Temporary Node
        int iter= 1;int c = 0;         // Iteration variable and control variable
        while(temp -> data != val)     // Checking Nodes by data
        {
            temp = temp -> next;       // Incrementing Node pointer
            iter = iter + 1;         // Iteration variable incremented
            c = 1;                   // Control variable updated
        }
        if(c == 0)         // Displaying final decision of Search
            cout << "Search Unsuccessfull !! The Node is not present in the List" << endl;
        if(c == 1)
            cout << "Search Successfull !! Node is at " << iter << " Position. " << endl;
    }
    public:
    void DeleteNode(Node* &head, int val)
    {
        Node* temp = head;                     // Temporary Node pointer created
        while(temp ->next -> data != val)      // If next node value not satisfied
        {
            temp = temp -> next;             // Temporary Node incremented
        }
        if(temp -> next == NULL)
        {
            Node* t1 = temp;               // When pointer reaches to end while Traversing
            temp -> prev -> next = NULL;
            delete t1;
            return;                 // Function ends herewith
        }
        cout << "The Node with data " << temp -> next -> data << " is deleted !!" << endl;
        temp -> next = temp -> next -> next;   // Forward pointer adjusted
        temp -> next -> prev = temp;           // Backtracking pointer adjusted
    }
    public:
    void InsertNodeAnywhere(Node* head, int val, int var)
    {
        Node* n = new Node(val);      // New Node with given data created
        Node* temp = head;            // Temporary Node formed as the head pointer
        while(temp -> data != var)    // While the required Node is not traversed
        {
            temp = temp -> next;      // Increment the Node pointer
        }
        n -> next = temp -> next;     // Equating the pointer
        temp -> next -> prev = n;     // Setting the backtracking pointer
        temp -> next = n;           // Setting the forward pointer
        n -> prev = temp;           // Setting the backtracking pointer
        cout << "The Node is Inserted !!" << endl;
    }
    public:
    void LengthOfTheList(Node* &head)
    {
        Node* temp = head;               // Temporary Node created as head pointer
        int len = 0;                // Counter variable
        while(temp -> next != NULL)
        {
            temp = temp -> next;         // Increment Temporary pointer
            len = len + 1;           // Increment Counter
        }
        cout << "The Length of the Doubly Linked List is : " << len << endl;
    }
};     // Class ends
int main()          //  main method begins
{
    Node* head = NULL;          // Head Node created with value NULL it wont hold any data
    DoublyLinkedList object;        // Object creation
    int s, x;
    cout << "Enter number of Nodes in the List : ";
    cin >> s;
    for(int i = 1; i <= s; i++)   // Loop to enter Linked List data
    {
        cout << "Enter data of the " << i << " Node : ";
        cin >> x;
        object.InsertAtTail(head, x);
    }
    cout << "The Doubly Linked List formed is : " << endl;  // Displaying the List formed
    object.DisplayList(head);
    cout << "Enter a Node data to be Searched : ";
    cin >> s;
    object.FindNodeInList(head, s);  // Calling Search function
    cout << "Enter the Node data to be deleted : ";
    cin >> s;
    object.DeleteNode(head, s);   // Deleting the Node from the Linked List
    object.DisplayList(head);    // Displaying the Linked List formed
    cout << "Enter the Node data to be Inserted : ";
    cin >> s;
    cout << "Enter the Node data after which to be Inserted : ";
    cin >> x;
    object.InsertNodeAnywhere(head, s, x);   // Inserting Node Value
    object.DisplayList(head);               // Displaying Node
    object.LengthOfTheList(head);      // Getting Length of the List
}