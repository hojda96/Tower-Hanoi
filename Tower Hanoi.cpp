/*
***********************************************************************
    Create a program to solve the Tower of Hanoi problem recursively.
***********************************************************************

Created iterative solution first, becouse what's more fun than solving the issue in two different ways.


P.S. But really, I just saw a meme and decided to go all in.
*/ 


#include <iostream>
#include <stack>

using namespace std;

void solveHanoi(stack<int> &first, stack<int>& second, stack<int>& third );
void recursiveHanoi(int disckCounter, stack<int>& source, stack<int>& auxiliary, stack<int>& destination);
void printHanoi(stack<int>  first, stack<int>  second, stack<int> third);
void printHanoi(stack<int>  tower);



int main()
{

    stack<int> firstTower({9,8,7,6,5,4,3,2,1 });
    stack<int> secondTower;
    stack<int> thirdTower;

    solveHanoi(firstTower, secondTower, thirdTower);
    printHanoi(firstTower, secondTower, thirdTower);
    // reversing to prior state ,for even numbers of elements the result is on third tower
    if(secondTower.empty()){ 
        firstTower = thirdTower;
        thirdTower = secondTower;
    }
    else
    {
        firstTower = secondTower;
        secondTower = thirdTower;
    }
    

    cout << "\nRecursive approach:\n";
    recursiveHanoi(firstTower.size(), firstTower, secondTower, thirdTower);
    printHanoi(firstTower, secondTower, thirdTower);
  
}

void solveHanoi(stack<int>& first, stack<int>& second, stack<int>& third)
{
    size_t stackSize = first.size();

    while (second.size() != stackSize && third.size() != stackSize)
    {
        //Move one disk from peg A to peg B or vice versa, whichever move is legal.
        if (second.empty() || !first.empty() && first.top() < second.top()) {
            second.push(first.top());
            first.pop();
        }else
        {
            first.push(second.top());
            second.pop();
        }


        if (second.size() == stackSize || third.size() == stackSize) break; //if alredy completed
        //Move one disk from peg A to peg C or vice versa, whichever move is legal.
        else if  (third.empty() || !first.empty() && first.top() < third.top()) {
            third.push(first.top());
            first.pop();
        }else
        {
            first.push(third.top());
            third.pop();
        }
        
        
        if (second.size() == stackSize || third.size() == stackSize) break;//if alredy completed
        //Move one disk from peg B to peg C or vice versa, whichever move is legal.
        else if (second.empty() || !third.empty() && third.top() < second.top()) {
            second.push(third.top());
            third.pop();
        }else
        {
            third.push(second.top());
            second.pop();
        }

    }

}

void recursiveHanoi(int disckCounter, stack<int>& source, stack<int>& auxiliary, stack<int>& destination )
{

    if (disckCounter > 0) {

    recursiveHanoi(disckCounter-1 , source, destination, auxiliary); //move n-1 from source to auxiliary
    destination.push(source.top());//move the remaining element
    source.pop();
    recursiveHanoi(disckCounter-1,  auxiliary,source, destination); //move n-1 from auxiliary to destionation
    }
   
    
}
void printHanoi(stack<int>  tower) {// reversing the tower to print from bottom up
    stack<int> aux; 
    while (!tower.empty())
    {
        aux.push(tower.top());
        tower.pop();
    }
    while (!aux.empty())
    {
        cout << aux.top()<<'\t';
        aux.pop();
    }

}
void printHanoi(stack<int> first, stack<int> second, stack<int> third)
{
    
    cout << "First Tower: \t";
    printHanoi(first);

    cout << "\nSecond Tower: \t";
    printHanoi(second);

    cout << "\nThird Tower: \t";
    printHanoi(third);
    
    cout << endl;
}