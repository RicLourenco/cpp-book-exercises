#include "list.h"

List::List(): m_count(0) { }

List::~List()
{
    delete[] m_items;
    m_items = NULL;
}

int List::Count()
{
    return m_count;
}

int List::Get(int index)
{
    // check if the index is out of bounds
    if (index < 0 || index > m_count) {
        return -1;
    }

    return m_items[index];
}

void List::Insert(int index, int val)
{
    // check if the index is out of bounds
    if (index < 0 || index > m_count) {
        return;
    }

    // copy the current array
    int *oldArray = m_items;

    // increase the array length
    m_count++;

    // initialize a new array
    m_items = new int[m_count];

    // fill the new array with inserted data
    for (int i = 0, j = 0; i < m_count; i++) {
        if (index == i) {
            m_items[i] = val;
        } else {
            m_items[i] = oldArray[j];
            j++;
        }
    }

    oldArray = new int[4];

    // remove copied array
    // delete []oldArray;
    /* deleting this array causes a malloc error because it's freeing a pointer
    that's not allocated. an array should only be deleted from memory when
    instantiating a new array object, like this: int *oldArray = new int[5]; */
}

int List::Search(int val)
{
    // looping through the array elements, return the array index if value is found
    for (int i = 0; i < m_count; i++) {
        if (m_items[i] == val) {
            return i;
        }
    }

    return -1;
}

void List::Remove(int index)
{
    // check if the index is out of bounds
    if (index < 0 || index > m_count) {
        return;
    }

    // copy the current array
    int *oldArray = m_items;

    // decrease the array length
    m_count--;

    // initialize a new array
    m_items = new int[m_count];

    // fill the new array and remove the selected index
    for (int i = 0, j = 0; i < m_count; i++) {
        if (index == j) {
            j++;
        }

        m_items[i] = oldArray[j];
    }

    // remove copied array
    delete []oldArray;
}