/*****************************************************************************
*                    
*  Author:           Allison Ricketts
*  Email:            taterrickets@gmail.cpm
*  Label:            P02
*  Title:            Vector Class: Overload Operations
*  Course:           2143 OOP
*  Semester:         Fall 2021
* 
*  Description:
*       This program uses the power of vector manipulation and
        and overloaded operations to add, subtract, and ect. to vectors.
* 
*  Usage:
*        Use this program by giving the main function         
          instructions on combining two vectors into one.
* 
*  Files: main.cpp
*****************************************************************************/
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
//The main chunk of code is copied from the solution code of P01.
// Node for our linked list
class Node {
    public:
    Node(int d, Node* n = nullptr, Node* p = nullptr) {  // cunstructor to make adding values easy
        data = d;
        next = n;
        prev = p;
    }
    int data;  // data value (could be a lot more values)
    Node* prev;
    Node* next;  // we always need a "link" in a linked list
};

/**
 * MyVector
 * 
 * Description:
 *      This class holds the functions and abilities to traverse, add, and remove from a linked list.
 * 
 * Public Methods:
 *                    MyVector 
 *                    MyVector(int* A, int size)
 *                    MyVector(string FileName)
          void        pushFront(int val)                       
          void        pushFront(MyVector v2) 
          void        pushRear(int val)                        
          void        pushRear(MyVector v2)     
          bool        pushAt(int loc, int val) 
          int         popFront()
          int         popRear()
          int         popAt(int loc)
          bool        find(int val)
          int         operator[](int loc)
          MyVector    operator+(MyVector that)
          MyVector    operator-(MyVector that)
          MyVector    operator*(MyVector that)
          MyVector    operator/(MyVector that)
          MyVector    operator==(MyVector that)
          MyVector    operator=(MyVector initial)
          void        print()
 * 
 * Private Methods:
 *        node* head
          node* tail
          int size
 * 
 */
class MyVector {
private:
    Node* head;  //First value in list
    Node* tail;  //Last value in list

public:
    int size;
    
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
    MyVector() {
        head = NULL;  //Starting head and tail as empty nodes
        tail = NULL;
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
    MyVector(int *A, int arrSize) {
        head = nullptr;  // NULL = zeros
                      // and zeros imply empty
        tail = nullptr;
        for (int i = arrSize-1; i > -1; i--){
        head = new Node(A[i], head);

        if (head->next == nullptr){
            tail = head;
        }
        else{
            head->next->prev = head;
        }
        size++;
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
    MyVector(string filename) {
        ifstream fin; fin.open(filename);
        head = tail = nullptr;
        int temp;

        int i = 0;
        while(!fin.eof()) {
            fin >> temp;
            head = new Node(temp, head);
            if (head->next == nullptr){
                tail = head;
            }
            else {
                head->next->prev = head;
            }
            size++;
            i++;
        }
    }

    MyVector(const MyVector &V1) {
        head = tail = nullptr;
        for (int i = 0; i < V1.size; i++){
            head = new Node(V1.head->data, head);
            if (head->next == nullptr){
                tail = head;
            }
            else {
                head->next->prev = head;
            }
            size++;
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
        head = new Node(val, head);

        if (head->next == nullptr){
            tail = head;
        }
        else{
            head->next->prev = head;
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
    void pushFront(MyVector V2) {
        for (int i = 0; i < V2.size; i++){
            head = new Node(V2.head->data, head);
            if (head->next == nullptr){
                tail = head;
            }
            else {
                head->next->prev = head;
            }
            size++;
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
        tail = new Node(val, nullptr, tail);

        if (tail->prev == nullptr){
            head = tail;
        }
        else{
            tail->prev->next = tail;
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
    void pushRear(MyVector V2) {
        for (int i = 0; i < V2.size; i++){
            Node* travel = V2.head;      //using a travel Node to iterate through the V2 vector   
            while(travel){              //while travel != nullptr
            tail = new Node(travel->data, nullptr, tail);  //create a new Node at the end of the list
            if (tail->prev == nullptr){                    //checks to see if this is at the front of the list        
                head = tail;
            }
            else {                      //connects the end of the array to this new Node making it the tail
                tail->prev->next = tail;
            }
            travel = travel->next;      //Iterates to the next Node in the list
            size++;                     //Increases the size of the List thats being added to 
        }
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
     *      
     */
    void pushAt(int loc, int val) {
        Node* travel = head; 
        int currentLoc = 0;   
        while(currentLoc != loc){
        if(currentLoc != loc) {
            travel = travel->next;
            currentLoc++;
        }
        else {
            travel->data = val;
            return;
        }
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
        if(!empty()){
            int popped = head->data;
            Node* killMe = head;
            head = head->next;
            delete killMe;
            size--;
            return popped;
        }
        return -1;
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
        if(!empty()){
            int popped = tail->data;
            Node* killMe = tail;
            tail = tail->prev;
            delete killMe;
            size--;
            return popped;
        }
        return -1;
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
     *      0 and temp
     */
    int popAt(int loc) {
        Node* travel = head;
        int currentLoc;
        while(currentLoc != loc){
        if(currentLoc != loc) {
            travel = travel->next;
            currentLoc++;
        }
        else {
            int temp = travel->data;
            travel->prev->next = travel->next;
            delete travel;
            return temp;
        }
        }
        return 0;
    }

    bool empty(){
        return head == nullptr;
    }

    ~MyVector() {
        Node* travel = head;
        while(travel != nullptr){
            Node* tempNode = travel;
            travel = travel->next;
            delete tempNode;
        }
        head = nullptr;
    }

    /**
     * Public : operator[](int loc)
     * 
     * Description:
     *      Turns MyVector into an array
     * 
     * Params:
     *      int loc
     * 
     * Returns:
     *      The value in the node
     */
    int operator[](int loc){
      Node* temp = this->head;      //temp is equal to the head value at this
      for(int i = 0; i < loc; i++){
        temp = temp->next;          //go throught the list to find specific node
      }
      return temp->data;            //return specific node
    }

      /**
     * Public : operator+(MyVector& that)
     * 
     * Description:
     *      Adds two vectors together
     * 
     * Params:
     *      MyVector& that
     * 
     * Returns:
     *      A vector that holds the sums of the two original          vectors
     */
      MyVector operator+(MyVector& that) {
      MyVector total;        //need a new vector to hold both manipulated vectors
      Node* temp = this->head; //temp is the value at the head of this
      Node* temp2 = that.head; //temp2 is the value of head
      int smallest;            //The smallest array
      int largest;             //The larger array

      //Loop that will add both vectors
      for(int i = 0; i < smallest; i++){
        total.pushRear(temp->data + temp2->data); //tells operator to add data held in temp to data held in temp2
        temp = temp->next;    
        temp2 = temp2->next; 
      }

      //Decides which vector the new values will be added to
      if(!largest) {
        for(int i = smallest; i < that.size; i++) {
          total.pushRear(that[i]);
          
        }
      }
      else {
        for(int i = smallest; i < this->size; i++) {
          total.pushRear(temp->data);
          if(!temp->next)
            temp = temp->next;
        }
      }

      return total; //returns the new vector
    }    


   /**
     * Public : operator-(MyVector& that)
     * 
     * Description:
     *      Subtracts two vectors 
     * 
     * Params:
     *      MyVector& that
     * 
     * Returns:
     *      A vector that holds the values of the two                 subtracted  original vectors
     */
    MyVector operator-(MyVector& that) {
      MyVector total;        
      Node* temp = this->head;
      Node* temp2 = that.head;
      int smallest;    
      int largest;

      //Loop subtracts both vectors
      //Same code from the addition but with subtracting
      for(int i = 0; i < smallest; i++) {
        total.pushRear(temp->data - temp2->data);
        temp = temp->next;
        temp2 = temp2->next;
      }

      if(!largest) {
        for(int i = smallest; i < that.size; i++) {
          total.pushRear(that[i]);
        }
      }
     
      else {
        for(int i = smallest; i < this->size; i++) {
          total.pushRear(temp->data);
          if(temp->next != nullptr)
            temp = temp->next;
        }
      }

      return total;
    }    


     /**
     * Public : operator*(MyVector& that)
     * 
     * Description:
     *      Multiplies two vectors together
     * 
     * Params:
     *      MyVector& that
     * 
     * Returns:
     *      A vector that holds the products of the two               original vectors
     */
    MyVector operator*(MyVector& that) {
      MyVector total;        
      Node* temp = this->head;
      Node* temp2 = that.head;
      int smallest; 
      int largest;

      //Loop that multiplys both vectors
      //Same code from the addition but with muliplication
      for(int i = 0; i < smallest; i++) {
        total.pushRear(temp->data * temp2->data);
        temp = temp->next;
        temp2 = temp2->next;
      }

      if(!largest) {
        for(int i = smallest; i < that.size; i++) {
          total.pushRear(that[i]);
        }
      }
      else {
        for(int i = smallest; i < this->size; i++) {
          
          total.pushRear(temp->data);
          if(temp->next != nullptr)
            temp = temp->next;
        }
      }

      return total;
    } 


    /**
     * Public : operator/(MyVector& that)
     * 
     * Description:
     *      Divides two vectors together
     * 
     * Params:
     *      MyVector& that
     * 
     * Returns:
     *      A vector that holds the values of the two divided         original vectors
     */
    MyVector operator/(MyVector& that) {
      MyVector total;    
      Node* temp = this->head;
      Node* temp2 = that.head;
      int smallest; 
      int largest;

     //Loop that divides both vectors
      //Same code from the addition but with division
      for(int i = 0; i < smallest; i++) {
        total.pushRear(temp->data / temp2->data);
        temp = temp->next;
        temp2 = temp2->next;
      }

      if(!largest) {
        for(int i = smallest; i < that.size; i++) {
          total.pushRear(that[i]);
        }
      }
      else {
        for(int i = smallest; i < this->size; i++) {
          
          total.pushRear(temp->data);
          if(temp->next != nullptr)
            temp = temp->next;
        }
      }

      return total;
    } 

     /**
     * Public : operator==(MyVector& that)
     * 
     * Description:
     *      Simply compares vectors to see if they are equal
     * 
     * Params:
     *      MyVector& that
     * 
     * Returns:
     *      True or False
     */
    bool operator==(MyVector& that) {

      Node* temp = this->head;
      Node* temp2 = that.head;

      //Simply compares two vectors to see if they are equal
      if(this->size != that.size) {
        return false;  //If vectors are not equal its obviouly false
      }
      else {
        while(temp) {
          if(temp->data != temp2->data) {
            return false;  //Also isn't true if values are not equal
          }
          temp = temp->next;
          temp2 = temp2->next;
        }
      }
      return true; //otherwise vectors are equal
    }


   /**
     * Public : operator=(MyVector& that)
     * 
     * Description:
     *      Assigns one vector equal to another
     * 
     * Params:
     *      MyVector& that
     * 
     * Returns:
     *      Vector with new assigned values
     */
    MyVector operator=(const MyVector& initial) {
      
      //It's easier to create new values in a list with an empty list.
      Node* temp = head; 
      Node* temp2; 
      while(!temp) {
        temp2 = temp;   
        temp = temp->next;  //temp traves down each value
        delete temp2;       //then delets said value till head and tail are empty
      }
      head = NULL;
      tail = NULL;
      Node* temp3 = initial.head;
      for (int i = 0; i < initial.size; i++) {
        pushRear(temp3->data);
        temp3 = temp3->next;
      }
      return *this;
    }

    /**
     * Public : print()
     * 
     * Description:
     *      Prints the vector
     * 
     * Params:
     *      ofstream outfile
     * 
     * Returns:
     *      None
     */
    void print(ofstream outfile){
      Node* temp = head;
      while (temp) {
			cout << temp->data << ", ";
			temp = temp->next;
		}
		cout << temp->data << endl;

    temp = head;
    while (temp) {
			outfile << temp->data << ", ";
			temp = temp->next;
		}
		outfile << temp->data << endl;
    }
};

int main() {
int a1[] = { 1, 2, 3, 4, 5 };
int a2[] = { 10, 20, 30 };

MyVector V1(a1,5);
MyVector V2(a2,3);

ofstream outfile;
outfile.open("output.txt");

cout << V1[2] << endl;
// writes out 3

// V1[4] = 9;
// // V1 now = [1,2,3,4,9]

 //cout << V1 << endl;
// // writes out [1,2,3,4,9] to console.

 //outfile << V1 << endl;
// // writes out [1,2,3,4,9] to your output file.

// MyVector V3 = V1 + V2;
 //cout << V3 << endl;
// // writes out [11,22,33,4,9] to console.

// V3 = V1 - V2;
 //cout << V3 << endl;
// // writes out [-9,-18,-27,4,9] to console.

 //V3 = V2 - V1;
 //cout << V3 << endl;
// // writes out [9,18,27,4,9] to console.

 //V3 = V2 * V1;
 //cout << V3 << endl;
// // writes out [10,40,90,4,9] to console.

 //V3 = V1 * V2;
// cout << V3 << endl;
// // writes out [10,40,90,4,9] to console.

 //V3 = V1 / V2;
 //cout << V3 << endl;
// // writes out [0,0,0,4,9] to console.

// V3 = V2 / V1;
 //cout << V3 << endl;
// // writes out [10,10,10,4,9] to console.

 //cout << (V2 == V1) << endl;
// // writes 0 to console (false) .

 //MyVector V4 = V1;
 //cout << (V4 == V1) << endl;
// // writes 1 to console (true)
}