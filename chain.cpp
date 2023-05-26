#include "chain.h"
#include "chain_given.cpp"
#include <cmath>
#include <iostream>

// PA1 functions

/**
 * Destroys the current Chain. This function should ensure that
 * memory does not leak on destruction of a chain.
 */
Chain::~Chain()
{
    clear();

}

/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
void Chain::insertBack(const Block &ndata)
{
    Node* newNode = new Node(ndata);
    Node* temp = head_;

    while (temp->next != head_) {
        temp = temp->next;
    }
    
    temp->next = newNode;
    newNode->next = head_;

    length_ ++;
}


/**
 * Swaps the two nodes at the indexes "node1" and "node2".
 * The indexes of the nodes are 1 based.
 * assumes i and j are valid (in {1,length_} inclusive)
 * 
 */
void Chain::swap(int i, int j)
{
    Node *prevI = NULL;
    Node *currI = head_;
    int x = 0;
    while (x < i - 1) {
        prevI = currI;
        currI = currI->next;
        x++;
    }
 
    Node *prevJ = NULL;
    Node *currJ = head_;
    int y = 0;
    while (y < j - 1) {
        prevJ = currJ;
        currJ = currJ->next;
        y++;
    }
 
    Node* temp = currJ->next;
    currJ->next = currI->next;
    currI->next = temp;

    currI = currI->next;
    currJ = currJ->next;

    temp = currI->next;
    currI->next = currJ->next;
    currJ->next = temp;
}

/**
 * Reverses the chain
 */
void Chain::reverse()
{
    Node* curr = head_;
    Node *prev = NULL;
    Node *next = NULL;
 
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head_ = prev;
}

/*
* Modifies the current chain by "rotating" every k nodes by one position.
* In every k node sub-chain, remove the first node, and place it in the last 
* position of the sub-chain. If the last sub-chain has length less than k,
* then don't change it at all. 
* Some examples with the chain a b c d e:
*   k = 1: a b c d e
*   k = 2: b a d c e
*   k = 3: b c a d e
*   k = 4: b c d a e
*/
void Chain::rotate(int k)
{

        /* for (int i = 0; i <= length_; i++){

            if (length_-i < k) {
                return;
            }
            swap(i, i+1);
    }  */

    int time = k;
    for(int i = 1; i <= length_; i++){
        if (time > 1) {
            swap(i, i+1);
            time--;
        } else {
            time = k;
            if (length_-i < k) {
            return;
            }
        }
    }
}


    /*  for(int i = 1; i <= length_; i++) {
        if (length_ > k+i){
            for (int j = 0; j<k; j++) {
                swap(i, i +1);
         }
    } else {
        return;
    }
} 
} */



/**
 * Destroys ALL dynamically allocated memory associated with the
 * current Chain class.
 */
void Chain::clear()
{
    Node* temp = head_;
    Node* toDelete = head_;

    while (temp->next != head_) {
        temp = temp->next;
        delete toDelete;
        toDelete = temp;
    }
    delete temp;

    head_ = NULL;

    length_ = 0;
    height_ = 0;
    width_ = 0; 
}

/* makes the current object into a copy of the parameter:
 * All member variables should have the same value as
 * those of other, but the memory should be completely
 * independent. This function is used in both the copy
 * constructor and the assignment operator for Chains.
 */
void Chain::copy(Chain const &other)
{
    head_ = NULL;
    length_ = 0;
    width_ = other.width_;
    height_ = other.height_;

    head_ = new Node();
    head_->next = head_;
    Node* curr = other.head_->next;

    while (curr != other.head_){
        insertBack (curr->data);
        curr = curr->next;
    }
}
