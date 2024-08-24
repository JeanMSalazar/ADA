#include <iostream>
using namespace std;

//Designing a vector using Object Oriented Programming
template <typename Type> class CVector
{
private:
  Type*m_pVect; // Pointer to the buffer
  int m_nCount; // Control how many elements are actually used
  int m_nMax; // Control the number of allocated elements
  int m_nDelta; // To control the growing
  void Init(int delta); // Init our private variables, etc
  void Resize(); // Resize the vector when occurs an overflow
public:
  CVector(int delta = 10); // Constructor
  void Insert(Type elem); // Insert a new element
  void Print();
// ...
};

template <typename Type>
CVector<Type>::CVector(int delta) : m_nCount(0), m_nMax(delta), m_nDelta(delta)
{
  m_pVect = new Type[m_nMax];
}

template <typename Type> void CVector<Type>::Resize()
{
 const int delta = 10; // Used to increase the vector size
  //gpVect = realloc(gpVect, sizeof(int) * (gnMax + delta));
// You can also use the following code:
 int *pTemp, i;
 pTemp = new int[m_nMax + delta]; // Alloc a new vector
 for(i = 0 ; i < m_nMax ; i++) // Transfer the elements
 pTemp[i] = m_pVect[i]; // we can also use the function memcpy
 delete [ ] m_pVect; // delete the old vector
 m_pVect = pTemp; // Update the pointer
 m_nMax += delta; // The Max has to be increased by delta
}

template <typename Type> void CVector<Type>::Insert(Type elem)
{
  if( m_nCount == m_nMax ) // Verify the overflow
    Resize(); // Resize the vector before inserting elem
  m_pVect[m_nCount++] = elem; // Insert the element at the end
}

template <typename Type> void CVector<Type>::Print()
{
  for(int i = 0; i < m_nCount;i++){
    cout<<m_pVect[i]<< " ";
  }
}

int main()
{
  CVector<int> vec;
  for(int i=0; i<10; i++)
    vec.Insert(i);
  vec.Print();
  return 0;
}