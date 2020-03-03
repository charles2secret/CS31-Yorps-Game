//
//  main.cpp
//  project4
//
//  Created by Fate End on 5/7/19.
//  Copyright © 2019 Charles Zhou. All rights reserved.
//

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

int countMatches(const string a[], int n, string target)
{
    int Matches = 0;
    if (n < 0) //check if the n is negative, if so, return -1
        return -1;
    else
    {
        for (int t = 0; t<n ;t++)//repeatedly check each element in the given array a
        {
            if (a[t] == target)//if there is an element matches the target string, add one to Matches
            {
                Matches ++;
            }
        }
    }
    return Matches;//return the number of Matches
}

int detectMatch(const string a[], int n, string target)
{
    int number = 0;
    int maxNumber = 0;
    if(n<0)
        return -1; //check if the n is negative, if so, return -1
    else
    {
        for (int t=0;t<n; t++) //repeatedly check each element in the given array a
        {
            if (a[t] == target)//if there is an element mtaches the target string, break out the for loop
            {
                maxNumber ++;
                number = t;
                break;
            }
        }
    }
    if (maxNumber == 0)//if there is no match, return -1
        return -1;
    else
        return number;//return the position
}

bool detectSequence(const string a[], int n, string target, int& begin, int& end)
{
    int firstNumber = 0;
    if (n <0)
    {
        return false;//check if the n is negative, if so, return -1
        
    }
    else
    {
        for(int t=0;t<n;t++)//repeatedly, check each element in the given array a
        {
            if (a[t] == target)//if there is an element matches the target string
            {
                firstNumber ++;
                begin = t;//set begin to that position
                end = begin;//set end to begin position as well
                for(int s = t+1;s<n;s++)//repeatedly, check all elements follow the first match
                {
                    if(a[s] == target)//if there is another match, add one to end position
                    {
                        end++;
                    }
                    else//break if not
                        break;
                }
                break;
            }
        }
    }
    if (firstNumber == 0)
        return false; //if there is no match, return false;
    else
        return true;
}

int detectMin(const string a[], int n)
{
    int t=0;
    int numberMin = 0;
    if (n<0)
        return -1;//check if the n is negative, if so, return -1
    else if (n == 0)//check if n is 0, if so, return 0
        return -1;
    else
    {
        for (t=0;t<n-1;t++)//repeatedly, check each element in the array a
        {
            int s=0;
            if (a[t] <= a[t+1])//if the following number is bigger or equals to the previous one, let the variable equals to t
            {
                numberMin = t;
                for (s = t+1;s<n;s++)//repeatedly, check the rest elements except the first two, find if they are all in nondecreasing order, if not, break
                {
                    if (a[t] <= a[s])
                    {
                        numberMin += 0;
                    }
                    else
                        break;
                }
            }
            if(s==n)//if s runs to the end, break
                break;
        }
    }
    if (t==n-1)//if t runs to the end, return the last element
        return n-1;
    else
        return numberMin;//return the variable
}

int moveToBack(string a[], int n, int pos)
{
    if (n<0||pos<0 ||pos>=n)
        return -1;//check if the n is negative, if so, return -1
    string End = a[pos];
    
    for (int t = pos; t < n-1; t++)//repeatedly, check all the elements following pos
    {
        a[t]=a[t+1];//move every elements following pos to the front one
    }
        a[n-1] = End;//let the last element equals to the element at the pos
    
    return pos;
}

int moveToFront(string a[], int n, int pos)
{
    if (n<0||pos<0)//check if the n is negative, if so, return -1
        return -1;
    else if(pos>=n)
        return -1;
    string Front = a[pos];
    for(int t = pos; t > 0;t--)//repeatedly, check all the elements before pos
    {
        a[t] =a[t-1];//move every elements before pos to the back one
    }
        a[0] = Front;//let the first element equals to the element at the pos

    return pos;
}

int detectDifference(const string a1[], int n1, const string a2[], int n2)
{
    int DifferentNumber = 0;
    if(n1<0 || n2<0)
        return -1;
    else
    {
        if (n1>=n2)//compare the size of n1 and n2
        {
            for (int t = 0; t<n2; t++)//repeatedly, check all elements in array a2
            {
                if (a1[t] == a2[t])//if a1 and a2 are the same in the corresponding position, add one to the vaiable
                {
                    DifferentNumber++;
                    
                }
                else
                    break;
            }
        }
        else
        {
            for (int t=0; t<n1; t++)//repeatedly, check all elements in array a1
            {
                
                if(a1[t] == a2[t])//if a1 and a2 are the same in the corresponding position, add one to the vaiable
                    DifferentNumber++;
                else
                    break;
            }
        }
    }
    
    return DifferentNumber;//return the variable at last
}

int deleteDups(string a[], int n)
{
    int DuplicateNumber=1;
    if(n<0)
        return -1;
    else if(n == 1)//if n is one, return 1
        return 1;
    else
    {
        for (int t=0; t<n-1; t++)//repeatedly, check all elements except teh last one in array a
        {
            if(a[t] ==a[t+1])//if the following one is equals to the front one, do nothing
                DuplicateNumber += 0;
            else
            {
                a[DuplicateNumber] = a[t+1];//else, move the first different one to the front
                DuplicateNumber++;
             }
                
        }
    }
    return DuplicateNumber;//return the variable
}

bool contains(const string a1[], int n1, const string a2[], int n2)
{
    int s = 0;
    int StartPoint = 0;
    int CheckContains = 0;
    if (n1<0 ||n2<0)
        return false;
    else if (n1 < n2)
        return false;//return false if n1, n2 is negative or n2 bigger than n1
    else if(n2==0)
        return true;
    else
    {
        for (int t = 0; t < n2; t++)//repeatedly, check each element in a2
        {
            
           
            for(s = StartPoint; s < n1; s++)//repeatedly, check each element in a1
            {
                
                if (a2[t] == a1[s])//if there is a match, break out the loop
                {
                    CheckContains ++;
                    StartPoint = s;
                    break;
                }
                else
                    CheckContains = 0;
                
            }
            
                
        }
        if(CheckContains == 0)//if there is no match, return false
            return false;
        
    }
    return true;
}

int meld(const string a1[], int n1, const string a2[], int n2, string result[], int max)
{
    int StartPoint1 =0;
    int StartPoint2 =0;
    int Sum = 0;
    int All = n1+n2;
    if (n1<0 || n2<0 ||max <0)
        return -1;
    else if (n1+n2>max)
        return -1;//if n1,n2 or max is negative, return -1
    else
    {
        for (int t = 0; t<n1-1;t++)//repeatedly, check if array a1 is in nondecreasing order
        {
            if (a1[t]>a1[t+1])
            {
                return -1;
            }
        }
        
        for (int t = 0; t<n2-1;t++)//repeatedly, check if array a2 is in nondecreading order
        {
            if (a2[t]>a2[t+1])
            {
                return -1;
            }
        }
        
        for (int t = StartPoint2;t<n1;t++)// repeatedly, check all the elements in a1 starting at StartPoint2
        {
            for(int s =StartPoint1;s<n2;s++)// repeatedly, check all the elements in a2 starting at StartPoint1
            {
                if(a1[t]<=a2[s])//if the following one is bigger or equal to the previous one, add the position of a1 to result
                {
                    result[Sum]=a1[t];
                    Sum++;
                    break;
                }
                else//else, add the position of a2 to result
                {
                    result[Sum]=a2[s];
                    Sum++;
                    StartPoint1++;
                    
                }
                if(StartPoint1 == n2)//check if the StartPoint1 equals to n2, if so, break
                {
                    StartPoint2=t;
                    break;
                }
            }
        }
        if(StartPoint1<n2)
            StartPoint2 = n1;
        if(StartPoint2<n1)// check the remaining item of n1, if there is still something left, add to the result
        {
            for(int t=StartPoint2;t<n1;t++)
            {
                result[Sum]=a1[t];
                Sum++;
            }
        }
        if(StartPoint1<n2)// check the remaining item of n2, if there is still something left, add to the result
        {
            for(int t =StartPoint1;t<n2;t++)
            {
                result[Sum]=a2[t];
                Sum++;
                
            }
        }
        
    }

    
    return All;
}

int split(string a[], int n, string splitter)
{
    int position1 = 0;
    int position2 = 0;
    string temp;
    if (n<0)
        return -1;
    else
    {
        for(int t = 0; t<n;t++)//repeatedly, check every item in the array a
        {
            if(position1+position2 == n)
                break;//the positions add together equals to n, break
            if (a[t]<splitter)//if the position is less than splitter, move the position to the designated position
            {
                temp = a[t];
                a[t] = a[position1];
                a[position1] = temp;
                position1++;
            }
            else//else, move from the back to front(the designated position as well)
            {
                temp = a[t];
                a[t] = a[n-1-position2];
                a[n-1-position2]=temp;
                position2++;
                t--;
            }
        }
    }
   
    if(position1==n)//if there is no such position, return n;
        return n;
    else if(position2 == n)
        return 0;
    else
        return position1;
}
int main()
{


    string d[9] = {
        "thor", "romanoff", "danvers", "danvers", "stark", "stark", "stark", "danvers", "danvers"
    };
    assert(countMatches(d, 9, "danvers") == 4);//check the normal case
    assert(countMatches(d,8,"danvers") == 3);//check the case where n is smaller than the array size
    
    string p[6] = { "danvers", "thor", "stark", "banner", "romanoff","romanoff" };
    assert(detectMatch(p, 5, "banner") == 3);//check the normal case
    assert(detectMatch(p,0,"thor")==-1);//check the zero case
    assert(detectMatch(p,-1,"thor")==-1);//if n is smaller than 0, return -1
    assert(detectMatch(p,6,"romanoff") == 4);
    //check if the function return the smallest position number of such a matching string.
    assert(detectMatch(p,6,"a")==-1);//check when the array has no such string
    assert(detectMatch(p,2,"stark")==-1);//check when there is no match
    
    
    int b;
    int e;
    assert(detectSequence(d, 9, "danvers", b, e) == true && b == 2 && e == 3);
    //if there is more than one sequence, return the earliest
    assert(detectSequence(d, 9, "stark", b, e) == true && b == 4 && e == 6);
    //if there is more than one sequence, return the earliest
    assert(detectSequence(d, 9, "romanoff", b, e) == true && b == 1 && e == 1);
    //if there is only one match, return begin and end as euqal numbers
    assert(detectSequence(d,9,"a",b,e)==false && b==1 && e ==1 );
    b = -999;
    e = -999;
    assert(detectSequence(d, 9, "rogers", b, e) == false && b ==-999 && e == -999);
    //check if there is no match, do not change the value of b and e
    assert(detectSequence(d, -2, "rogers", b, e) == false && b ==-999 && e == -999);
    //check the negative array size
    
    
    string h[7] = { "romanoff", "thor", "rogers", "banner", "", "danvers", "rogers" };
    string g[4] = { "romanoff", "thor", "banner", "danvers" };
    string g1[5] = { "apple","romanoff", "thor", "banner", "danvers" };
    string g2[6] = { "apple","romanoff", "thor", "banner", "danvers","haha" };
    string h1[5] = { "romanoff", "thor", "banner", "danvers","apple"};
    string h2[5] = { "apple","romanoff", "thor", "bear", "danvers"};
    
    assert(detectMin(g, 4) == 2);//check if the function can return the smallest element
    assert(detectMin(h,0)==-1);//check if the n=0, return -1
    assert(detectMin(h,7)==4);//check if the function can handle empty strings
    assert(detectMin(g1,5)==0);//check when the smallest is at the beginning of the array
    assert(detectMin(h1,5)==4);//check when the smallest is at the end of the array
    
    
    assert(detectDifference(h, 4, g, 4) == 2);//check the normal case
    assert(detectDifference(h,7,g1,5)==0);//there is a difference at the beginning of the two arrays
    assert(detectDifference(h,0,g,4)==0);//check if it can handle n = 0 case
    assert(detectDifference(g1,5,g2,6)==5);//check when one array runs out, return the array size
    assert(detectDifference(g2,5,h2,5)==3);//check if it can detect the first difference
    
    
    string f[5] = { "danvers", "danvers", "danvers", "thor", "thor" };
    
    assert(moveToBack(g, 4, 1) == 1 && g[1] == "banner" && g[3] == "thor");
    //check if the changed string is correct
    assert(moveToBack(f,5,0) == 0 && f[1] =="danvers" && f[2] == "thor");
    //check if the changed string is correct
    assert(moveToBack(f,5,-1) == -1);
    //check when n is negative
    string f1[4] = { "danvers", "banner", "thor", "rogers" };
    assert(moveToFront(f1, 4, 2) == 2 && f1[0] == "thor" && f1[2] == "banner");
    //check if the changed string is correct
    string f3[5] = { "danvers", "danvers", "danvers", "thor", "thor" };
    assert(moveToFront(f3,5,4)==4 && f3[0]=="thor");
    
    string f2[5] = { "danvers", "danvers", "danvers", "thor", "thor" };
    assert(deleteDups(f2, 5) == 2 && f2[1] == "thor");//check if it can handle multiple duplicate strings
    string a[9] = {
        "thor", "romanoff", "danvers", "danvers", "stark", "stark", "stark", "danvers", "danvers"
    };
    assert(deleteDups(a, 9) == 5 && a[4] == "danvers");//check if it can handle multiple duplicate strings
    
    
    string big[10] = { "danvers", "thor", "stark", "banner", "romanoff", "stark" };
    string little1[10] = { "thor", "banner", "romanoff" };
    assert(contains(big, 6, little1, 3)==true);
    string little2[10] = { "stark", "thor" };
    assert(contains(big, 6, little2, 2)==false);
    string little3[10] = { "thor", "stark", "stark" };
    assert(contains(big, 6, little3, 3)==true);
    string little4[10] = { "thor", "thor", "stark" };
    assert(contains(big, 6, little4, 3)==true);
    assert(contains(big, 6, little4, 0)==true);
    
    string x[4] = { "rhodes", "rhodes", "tchalla", "thor" };
    string y[4] = { "banner", "danvers", "rhodes", "rogers" };
    string z[10];
    assert(meld(x, 4, y, 4, z, 10) == 8&& z[5] == "rogers");
    
    assert(split(h, 7, "rogers") == 3);
    
    string m[6] = { "rhodes", "banner", "stark", "danvers", "thor", "rogers" };
    assert (split(m, 6, "romanoff")==4);  //  returns 4eded" << endl;
        
  
    
}
