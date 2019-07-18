#include<iostream>

using namespace std;

// ********Building a Heap class********

class Heap
{
    int *heap;
    int Size;
    int length;
public:
    Heap(int n);
    ~Heap();
    int Parent(int i);
    int Left(int i);
    int Right(int i);
    void MaxHeapify(int i);
    void buildHeap();
    void takeInput();
    void printHeap();
    void Insert(int x);
    void IncreaseKey(int i,int newKey);
    void DecreaseKey(int i,int newKey);
    int FindMax();
    int ExtractMax();
};

Heap::Heap(int n)
{
    heap = new int[n];
    Size = n;
    length = 0;
}

void Heap::takeInput()
{
    cout << "Enter " << Size << " numbers :"<< endl;
    for(int i=0;i<Size;i++)
    {
        cin >> heap[i];
    }
}

int Heap::Parent(int i)
{
    return (i-1)/2;
}

int Heap::Left(int i)
{
    return (2*i) +1;
}

int Heap::Right(int i)
{
    return (2*i)+2;
}

void Heap::MaxHeapify(int i)
{
    int l = Left(i);
    int r = Right(i);
    int largest;
    if (l<length&&heap[l]>heap[i])
       largest = l;
    else
        largest = i;
    if(r<length&&heap[r]>heap[largest])
        largest = r;
    if(largest!=i)
    {
        swap(heap[i],heap[largest]);
        MaxHeapify(largest);
    }
}

void Heap::buildHeap()
{
    int len = (length-1)/2;
    for(int i=len;i>=0;i--)
    {
        MaxHeapify(i);
    }
}

void Heap::IncreaseKey(int i,int newKey)
{
   // if(newKey < heap[i])
        //cout << "New key is smaller than old key!";
   // else
    {
        heap[i] = newKey;
        while(i>0 && heap[Parent(i)] < heap[i])
        {
            swap(heap[i],heap[Parent(i)]);
            i = Parent(i);
        }
    }
}

void Heap::DecreaseKey(int i,int newKey)
{
    heap[i] = newKey;
    MaxHeapify(i);
}

void Heap::Insert(int x)
{
    length += 1;
    heap[length-1] = INT_MIN;
    IncreaseKey(length-1,x);
}

int Heap::FindMax()
{
    return heap[0];
}

int Heap::ExtractMax()
{
    int maxi;
    if(length<1){
        cout << "Heap Underflow!";
        return INT_MIN;
    }
    else
    {
        maxi = heap[0];
        heap[0] = heap[length-1];
        length = length - 1;
        MaxHeapify(0);
        return maxi;
    }
}

void Heap::printHeap()
{
    for(int i=0;i<length;i++)
    {
        cout << heap[i] << " " << endl;
    }
}

Heap::~Heap()
{
    delete [] heap;
}

//******* End of Heap class **********


int main()
{
    int n,ch;
    int idx,nKey;
    cout << "Enter the size of the priority queue : ";
    cin >> n;
    Heap pq(n);
    while(1)
    {
        cout << "Priority queue operations : " << endl;
        cout <<"1. Insert an element\n2. Find the maximum element\n3. Extract the maximum element\n";
        cout <<"4. Increase the key of a certain index\n5. Decrease the key of a certain index\n";
        cout <<"6. Print the priority queue\n7. Exit\n\n";

        cout << "Enter your choice : ";
        cin >> ch;

        switch(ch)
        {
        case 1:
            int elem;
            cout << "Enter the element to enter : ";
            cin >> elem;
            pq.Insert(elem);
            cout << elem << " inserted\n";
            cout << endl;
            break;
        case 2:
            cout << "The maximum element is " << pq.FindMax() << endl;
            cout << endl;
            break;
        case 3:
            cout << pq.ExtractMax() << " extracted!" << endl;
            cout << endl;
            break;
        case 4:

            cout << "Enter the index : ";
            cin >> idx;
            cout << "Enter the new value : ";
            cin >> nKey;
            pq.IncreaseKey(idx,nKey);
            cout << endl;
            break;
        case 5:
            //int idx,nKey;
            cout << "Enter the index : ";
            cin >> idx;
            cout << "Enter the new value : ";
            cin >> nKey;
            pq.DecreaseKey(idx,nKey);
            cout << endl;
            break;
        case 6:
            cout << "The priority queue : ";
            pq.printHeap();
            cout << endl;
            cout << endl;
            break;
        case 7:
            exit(1);
            break;
        }
    }
    return 0;
}
