#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

//student object
struct Student
{
   string studentName;
   double gradeAverage;
   char grade;
};


// begin main (sorry I know it's long. i realize now I couldve broken it up.)
int main()
{

//get user input for desired file
string classFile;
cout << "Enter file of desired class: ";
cin >> classFile;

//read in file and declare stringstream
ifstream infile(classFile);

//error message if there is no such file
if(!infile)
   {
    cout << "that file is not real. deal with it.";
   }

// run everything otherwise (again sorry. This could be broken up)
else
{
   
    //declare variables
    int x = 0;  
    double average = 0;
    string name;
    string buffer;
    int students;
    int grade1, grade2, grade3, grade4;
    stringstream str;










    // read in the first line and store in buffer
    getline(infile, buffer);

    // change into an integer for number of students
    str << buffer;
    str >> students;
    Student info[students];


    //declare the arrays to be used
    string aName[students];
    double aAvg[students];
    int gradeID[students];


    while (x < (students) ) // line is less than twice number of students (one line for name, one for grades)
    {

        //read in the name, store in array, go to next line
        getline(infile, name);



        stringstream obj; //declare new stringstream

        //read  in line and store in buffer
        getline(infile, buffer); 

        //declare and store values in respective grades
        int grade1, grade2, grade3, grade4;
        obj << buffer;
        obj >> grade1>> grade2 >> grade3 >> grade4; 
        average = (grade1 + grade2 + grade3 + grade4)/4.0;

        //store into average array
        aAvg[x] = average;
        gradeID[x] = x; 



        info[x] = Student{name, average, '0'};
        x ++ ;
    }

    infile.close(); //close file


    //label what portion of the students will recieve each grade
    int gradeA = students * 0.9;
    int gradeB = students * 0.7;
    int gradeC = students * 0.3;
    int gradeD = students * 0.1;

    //array.. mostly because I got confused and didn't want to overwrite another array.
    double sortedAvg[students];

    // set each index of the array to the average of the corresponding student
    for(int i = 0; i < students; i++)
    {
        sortedAvg[i] = info[i].gradeAverage;
        gradeID[i] = i;
    }

    //assign the gradeIDs (index) and sort sortedAverage
    for(int i = 0; i < students; i++)
    {
        for(int j = i + 1; j < students; j++)
        {
        if(sortedAvg[i] > sortedAvg[j])
        {
            int bufferA = sortedAvg[i];
             sortedAvg[i] = sortedAvg[j];
            sortedAvg[j] = bufferA;
           
            int bufferK = gradeID[i];
            gradeID[i] = gradeID[j];
            gradeID[j] = bufferK;
            }
        }
    }
   

   //assign the grades to the students
    for(int i = 0; i < students; i++)
    {
        if(i < gradeD)
        {
        info[gradeID[i]].grade = 'F';
        }
        else if(i >= gradeD && i < gradeC)
        {
        info[gradeID[i]].grade = 'D';
        }
        else if(i >= gradeC && i < gradeB)
        {
        info[gradeID[i]].grade = 'C';
        }
        else if(i >= gradeB && i < gradeA)
        {
        info[gradeID[i]].grade = 'B';
        }
        else if(i >= gradeA && i < students)
        {
        info[gradeID[i]].grade = 'A';
        }
    }

    //print out the results
    for(int i = 0; i < students; i++)
    {
    cout << info[i].studentName << " - " << info[i].grade << endl;
    }


} // end else
    return 0;
}// end main



