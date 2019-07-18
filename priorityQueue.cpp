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
    if (l<Size&&heap[l]>heap[i])
       largest = l;
    else
        largest = i;
    if(r<Size&&heap[r]>heap[largest])
        largest = r;
    if(largest!=i)
    {
        swap(heap[i],heap[largest]);
        MaxHeapify(largest);
    }
}

void Heap::buildHeap()
{
    int len = (Size-1)/2;
    for(int i=len;i>=0;i--)
    {
        MaxHeapify(i);
    }
}

void Heap::printHeap()
{
    for(int i=0;i<Size;i++)
    {
        cout << heap[i] << endl;
    }
}

Heap::~Heap()
{
    delete [] heap;
}

//******* End of Heap class **********

//******* Start of a Priority Queue class *******
class pQueue
{
    Heap *heap;
public:
    pQueue(int n);
    ~pQueue();
    void Insert(int x);
    int FindMax();
    int ExtractMax();
    void IncreaseKey(int i,int newKey);
    void DecreaseKey(int i,int newKey);
    void Print();
};

pQueue::pQueue(int n)
{
    heap = new Heap(5);
}

void pQueue::Insert(int x)
{

}

int main()
{
    Heap h(5);
  //  h(5);
    h.takeInput();
    h.buildHeap();
    h.printHeap();
    return 0;
}
