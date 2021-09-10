/*****************************************************************************
*                    
*  Author:           Allison Ricketts
*  Email:            taterrickets@gmail.cpm
*  Label:            P01
*  Title:            Vector Class
*  Course:           2143 OOP
*  Semester:         Fall 2021
* 
*  Description:
*       This program manipulates a classed linked list using
        using vectors. We can add and remove any valuse from the list using this clasS, and traverse the list at the same time.
* 
*  Usage:
*        Use this program by giving the main function         
          instructions on what values to add, remove, or traverse within this list.
* 
*  Files: main.cpp
*****************************************************************************/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/**
 * MyVector
 * 
 * Description:
 *      This class holds the functions and abilities to               traverse, add, and remove from a linked list.
 * 
 * Public Methods:
 *                    MyVector 
 *                    MyVector(int* A, int size)
 *                    MyVector(string FileName)
          void        pushFront(int val)                       void        pushFront(MyVector v2) 
          void        pushRear(int val)                        void        pushRear(MyVector v2)     
          bool        pushAt(int loc, int val) 
          int         popFront()
          int         popRear()
          int         popAt(int loc)
          bool        find(int val)
          void        print()
 * 
 * Private Methods:
 *        node* head
          node* tail
          int size
 * 
 * Usage: 
 * 
 *        
 *      
 */
class MyVector {
private:
	struct node {           //Setting up the nodes for our linked list
    node* prev;           //The node pointing to the value before our current node
		node* next;           //The node pointing to the node after our current node
		int data;
		node(int val) {       
			data = val;
			next = NULL;
		}
	};

	node* head;            //The node at the front of our linked list
	node* tail;            //The node at the end of our linked list
	int size;

public:
/**
     * Public : MyVector
     * 
     * Description:
     *      This the default constructor. Just sets initial values.
     * 
     * Params:
     *       None
     * 
     * Returns:
     *       None
     */
	MyVector() {                    //Our first constructor to initialize head, tail, and size
		head = tail = NULL;
		size = 0;
	}

/**
     * Public : MyVextor(int * A, int size)
     * 
     * Description:
     *      Makes MyVector into an array.
     * 
     * Params:
     *      int* A
            int size
     * 
     * Returns:
     *      None
     */
	MyVector(int* A, int size) {
		head = tail = NULL;                       //Setting head and tail to equal literally nothinf

		for (int i = 0; i < size; i++) {          //Setting up the array for our vector
			pushRear(A[i]);
		}
	}

/**
     * Public : MyVector(string FileName)
     * 
     * Description:
     *      Reads data off of a vile and inputs it into MyVector
     * 
     * Params:
     *      string FileNmae
     * 
     * Returns:
     *      None
     */
	MyVector(string FileName) {
		head = tail = NULL;
    size = 0;

		ifstream fin;
		fin.open(FileName);                              //Asks to open a specific file then adds values to vector

		int temp;
		while (!fin.eof()) {
			fin >> temp;
			pushRear(temp);
		}
	}

/**
     * Public : pushFront(int val)
     * 
     * Description:
     *      Adds values to the front of the vector.
     * 
     * Params:
     *      int val
     * 
     * Returns:
     *      None
     */
	void pushFront(int val) {
		node* temp = new node(val);

		if (head == NULL) {             //If head is nothing then we want to replace with temp
			head = temp;                  //Pushing value to front and now making head(nothing)
      tail = head;                  //Equal to tail. Making the last node value NULL.
			size++;
		}
		else {
			temp->next = head;            //taking value of head and pushing to next and making new value head.
			head = temp;
      size++;
			}
  }

  /**
     * Public : pushFront(MyVector v2)
     * 
     * Description:
     *      Adds a vector to the front of the vector.
     * 
     * Params:
     *      MyVector v2
     * 
     * Returns:
     *      None
     */
	void pushFront(MyVector v2) {
		node* temp = v2.tail;
		while (temp) {
			pushFront(temp->data);
			temp = temp->next;
		}
	}

/**
     * Public : pushRear(int val)
     * 
     * Description:
     *      Adds value to the back of the vector.
     * 
     * Params:
     *      int val
     * 
     * Returns:
     *      None
     */
	void pushRear(int val) {
    node* temp = new node(val);               
		if (!head) {
			head = new node(val);                   //Set head as the new value, but set tail(end of vector) to equal head
      tail = head;                            //This adds new value to the tail of vector
		}
		else {
			tail->next = temp;                      
      tail = temp;

		}
	}

/**
     * Public : pushRear(MyVector v2)
     * 
     * Description:
     *      Adds vector to the back of the vector.
     * 
     * Params:
     *      int val
     * 
     * Returns:
     *      None
     */

	void pushRear(MyVector v2) {
		node* temp = v2.head;
		while(temp){
      pushRear(temp->data);
      temp = temp->next;
    }
	}

/**
     * Public : pushAt(int loc, int val)
     * 
     * Description:
     *      Adds a value to a specific location.
     * 
     * Params:
     *      int loc
            int val
     * 
     * Returns:
     *      True or False
     */

	bool pushAt(int loc, int val) {
		if (loc < 0 || loc > size) {          //If you are looking for a loction that does not exist false will be returned.
			return false;
		}
		else{
		if (loc == 0) {                       //If you are looking for spot 0 it will add the value to head
			pushFront(val);
		}
     else if (loc == size){               //If you are looking for the last node it will add value to tail
		pushRear(val);
    } else {
      node* temp = head;
      for (int i = 0; i < loc; i++){      
        temp = temp->next;
        }
      node* temp2 = new node(val);         //Sets new value to a temp node that is set between next and prev
      temp2->next = temp->prev;
      size++;
    }
    return true;
		}
	}
  
/**
     * Public : popFront()
     * 
     * Description:
     *      Removes a value fron the front of the vector
     * 
     * Params:
     *      None
     * 
     * Returns:
     *      val
     */
	int popFront() {
    int val = head->data;

		node* temp = head;
		head = head->next;            //Take the head and make it equal to the next value getting rid of previous head
    head->prev = NULL;
    delete temp;
		return val;
	}

/**
     * Public : popRear()
     * 
     * Description:
     *      Removes value from back of the vector
     * 
     * Params:
     *      None
     * 
     * Returns:
     *      val
     */

	int popRear() {
    int val = tail->data;
		node* temp = tail;
		tail = tail->prev;          //Tale is moved to the value before it getting rid of the previous tail.
    tail->next = NULL;
    delete temp;
		return val;
	}

/**
     * Public : popAt(int loc)
     * 
     * Description:
     *      Removes a value from a specific location in the vector
     * 
     * Params:
     *      int loc
     * 
     * Returns:
     *      0 and temp->data
     */
	int popAt(int loc) {
    int val;
    node* prev = NULL;
    if (loc < 0) {                            //A node less than 0 does not exist
			return 0;
		}
		else{
		if (loc == 0) {                           //If the location equals zero than they pop the value of head
			val = popFront();
    }
     else if (loc == size-1){                 //If they pop the size-1 then they would hace to pop the rear value
       val = popRear();
    } else {
      node* temp = head;
      for (int i = 0; i < loc; i++){
        temp = temp->next;
        }
      node* next = temp->next;                 //If popping a spicific location than they would have to remove node between prev and next.
      prev->next = next;
      return temp->data;
    }
		}
	return 0;
  }
	
  /**
     * Public : find(int val)
     * 
     * Description:
     *      Finds where a value is located in the vector.
     * 
     * Params:
     *      int val
     * 
     * Returns:
     *      True and False
     */
	bool find(int val) {
		node* temp = head;
		while (temp != NULL) {
			if(val == temp->data) {             //As long as the value is not NULL a val can be returned.
				return true;
			}
			temp = temp->next;
		}
		return false;
	}

/**
     * Public : print()
     * 
     * Description:
     *      Prints the vector
     * 
     * Params:
     *      None
     * 
     * Returns:
     *      None
     */
void print() {
		node* temp = head;
		while (temp) {
			cout << temp->data << ", ";
			temp = temp->next;
		}
		cout << endl;
	}
	
	};


int main() {
  int x = 0;

	MyVector v1;
	v1.pushFront(18);
	v1.pushFront(20);
	v1.pushFront(25);
	v1.pushRear(18);
	v1.pushRear(20);
	v1.pushRear(25);
	v1.print();
	// [25, 20, 18, 18, 20, 25]

	int A[] = { 11,25,33,47,51 };
	MyVector v2(A, 5);
	v2.print();
	// [11, 25, 33, 47, 51]

	v2.pushFront(9);
	v2.pushRear(63);
	v2.print();
	// [9, 11, 25, 27, 33, 47, 51, 63]

	v1.pushRear(v2);
	v1.print();
	// [25, 20, 18, 18, 20, 25, 9, 11, 25, 27, 33, 47, 51, 63]

	x = v1.popFront();
	x = v1.popFront();
	x = v1.popFront();
	v1.print();
	// [18, 20, 25, 9, 11, 25, 27, 33, 47, 51, 63]
	cout << x << endl;
	// 18

	//x = v1.popRear();
	//x = v1.popRear();
	//x = v1.popRear();
	//v1.print();
	// [18, 20, 25, 9, 11, 25, 27, 33]
	//cout << x << endl;
	// 47

	//x = v2.popAt(3);
	//v2.print();
	// [9, 11, 25, 33, 47, 51, 63]
	//cout << x << endl;
	// 27

	x = v2.find(51);
	cout << x << endl;
	// 5

	x = v2.find(99);
	cout << x << endl;
	// -1

	MyVector v3(v1);
	v3.print();
	// [18, 20, 25, 9, 11, 25, 27, 33]

	v3.pushFront(v2);
	v3.print();
	//[9, 11, 25, 33, 47, 51, 63, 18, 20, 25, 9, 11, 25, 27, 33]

	//MyVector v4("input.dat");
	//v4.pushRear(v3);
	//v4.print();
}