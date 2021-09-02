/*****************************************************************************
*
*  Author:           Allison Ricketts
*  Code by:          Terry Griffin
*  Title:            A04 Basic Program Organization
*  Course:           2143 OOP
*  Semester:         Fall 2021
*
*  Description:
*        This program is a circular queue.
*
*  Usage:
*        Enter in values that you would like to add to a list (Queue)
*
*****************************************************************************/

#include <iostream>

using namespace std;

/**
 * CircularArrayQue
 *
 * Description:
 *      This class contains all the functions and variables needed to preforming a proper circular arry.
 *
 * Public Methods:
 * 
 *              CircularArrayQue ()
 *              CircularArrayQue(int size)
 *      void    Push(int item)
 *      int     Pop()
 *
 * Private Methods:
 * 
 *      int* Container;
 *      int     Front;
 *      int     Rear;
 *      int     QueSize; 
 *      int     CurrentSize;
 *      void    init(int size = 0)
 *      bool    Full()
 *
 * Usage:
 *
 *      - examples of how
 *      - to use your class
 *
 */

class CircularArrayQue {
private:
    int* Container;                           //Pointer that points to an array
    int Front;                                //Variable at the front of the queue
    int Rear;                                 //Variable at the end of the queue
    int QueSize;                              //The number of variables on the queue
    int CurrentSize;                          //Current size of the array

    /**
     * Private: init
     *
     * Description:
     *      Intilizing the values and sizes, starting at 0.
     *
     * Params:
     *      int size = 0
     *
     * Returns:
     *      Returns Nothing
     */

    void init(int size = 0) {
        Front = Rear = CurrentSize = 0;      //Initilizing variables to equal 0
        QueSize = size;                      //Initilizing size
    }

    /**
     * Private: Full
     *
     * Description:
     *      When the array points to Null then this function ends the program.
     *
     * Params:
     *      No Parameters
     *
     * Returns:
     *      Returns CurrentSize == QueSize
     */

    bool Full() {
        return CurrentSize == QueSize;
    }

public:

    /**
     * Public: CircularArrayQue
     *
     * Description:
     *      Intilizing Container and setting Container to the value of 10.
     *
     * Params:
     *      No Parameters
     *
     * Returns:
     *      Returns Nothing
     */

    CircularArrayQue() {
        Container = new int[10];       //Setting the starting size of the array
        init(10);
    }

    /**
     * Public: CircularArrayQue
     *
     * Description:
     *      Intilizing Container to be the value of size.
     *
     * Params:
     *      int size
     *
     * Returns:
     *      Returns Nothing
     */

    CircularArrayQue(int size) {
        Container = new int[size];  //Setting pointer to point to a new address
        init(size);
    }

    /**
     * Public : Push
     *
     * Description:
     *      This function takes a piece of data and adds it to the rear of the queue.
     *
     * Params:
     *      int item
     *
     * Returns:
     *      Returns Nothing
     */

    void Push(int item) {
        if (!Full()) {
            Container[Rear] = item;
            Rear = (Rear + 1) % QueSize;
            CurrentSize++;
        }
        else {
            cout << "FULL!!!!" << endl;
        }
    }

    /**
     * Public : Pop
     *
     * Description:
     *      This function removes the value at the front of the list as Queues
            work in a FOLO pattern.
     *
     * Params:
     *      No Parameters
     *
     * Returns:
     *      temp
     */

    int Pop() {
        int temp = Container[Front];
        Front = (Front + 1) % QueSize;   //This line is what makes the array circular
        CurrentSize--;
        return temp;
    }
    friend ostream& operator<<(ostream& os, const CircularArrayQue& other);
};

/**
     * Public : ostream
     *      
     * Description:
     *      This will print our Array
     *
     * Params:
     *      ostream& os
            const CircularArrayQue& other
     *
     * Returns:
     *      Returns the Array
     */

ostream& operator<<(ostream& os, const CircularArrayQue& other) {

    for (int i = other.Front; i < other.CurrentSize; i = (i + 1) % other.QueSize) {
        os << other.Container[i] << " ";       //This is equivalent to a cout statement
    }
    os << endl;
    return os;
}

/**
 * Main Driver
 *
 * For this program, the main driver was used to test the CircularArrayQue class
 *
 */
int main() {
    CircularArrayQue C1(5);

    // C1.Push(34);
    // C1.Push(38);
    // C1.Push(44);
    // C1.Push(22);
    // C1.Push(99);
    // C1.Push(100);

    C1.Push(1);
    C1.Push(2);
    C1.Push(3);
    // C1.Push(6);
    // C1.Push(7);
    cout << C1 << endl;

    // C1.Push(1);
    // C1.Push(2);
    // C1.Push(3);

    cout << C1 << endl;
}
