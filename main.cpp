/*************************************************************************
* Erica Buchanan                                           Triangle Test *
* 30/04/2021                                                             *
*                                                                        *
* I attest that all work below has been performed by me, Erica Buchanan, *
* without the use of notes, texts, internet resources (other than the    *
* approved C++ reference website, and the vector/apmatrix cheatsheet)    *
* or discussion with another person.I will not share the content of      *
* this evaluation with anyone until permitted.                           *
*                                                                        *
* This program will read in data about different triangles from a        *
* text file and output the side lengths from the triangle with           *
* the smallest area.                                                     *
*************************************************************************/

#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;

// Prototypes
bool read_file(const char *fname, int numberTriangles, vector<int> &sides, float &smallestArea, vector<int> &smallestSides);
float find_area(ifstream &inputFile, vector<int> &sides);

int main(){
    // Declare and initialize variables
    char fileName[10] = "input.txt";
    int numTriangles = 0;
    vector<int> triangleSides(3);
    float smallestArea = 0;
    char answer = ' ';
    vector<int> smallestSides(3);

    // Call function to read the file and return -1 if it fails to open
    if (!read_file(fileName, numTriangles, triangleSides, smallestArea, smallestSides)){
        cout << "Error opening file." << endl;
        return -1;
    }else{
        // Ask user if they want to know the area of the smallest triangle
        cout << "Would you like to know what the area is? (y/n) ";
        cin >> answer;
        // Print answer if they do and end program if not
        if (answer == 'y'){
            cout << "The smallest area is " << smallestArea << "." << endl;
        }else{
            cout << "Okay, have a nice day! " << endl;
        }
    }
    return 0;
}

/* This function opens the file and returns false if it fails to open. If it opens, it reads the number of triangles
and then calls another function to find the smallest area. fname is the name of the input file, sides is the vector that holds
the triangle's side lengths, and smallestArea and smallestSides hold the area and dimensions for the smallest triangle.*/
bool read_file(const char *fname, int numberTriangles, vector<int> &sides, float &smallestArea, vector<int> &smallestSides){
    int area = 0;
    // Open file
    ifstream inFile(fname);
    // Return false if it isn't open
    if (!inFile.is_open()){
        return false;
    // Read file if open
    }else{
        // Read in the number of triangles
        inFile >> numberTriangles;
        // Get the area of each of the triangles by calling another function
        for (int i = 1; i <= numberTriangles; i++){
            area = find_area(inFile, sides);
            // Initialize the smallest triangle's area and dimensions to the first triangle's values
            if (i == 1){
                smallestArea = area;
                for (int j = 0; j < 3; j++){
                    smallestSides[j] = sides[j];
                }
            }
            // Compare other areas to the first triangle's area and update the smallest triangle accordingly
            if (area < smallestArea){
                smallestArea = area;
                for (int j = 0; j < 3; j++){
                    smallestSides[j] = sides[j];
                }
            }
        }
        // Print the dimensions of the smallest triangle
        cout << "The triangle with the smallest area has side lengths of " << smallestSides[0] << ", " << smallestSides[1] << " and " << smallestSides[2] << "." << endl;
        // Close file
        inFile.close();
        return true;
    }
}

/* This function reads in the side lengths of a triangle, calculates and returns its area. It uses the same input
file as the function it is in (read_file) and loads the side lengths into the sides vector. */
float find_area(ifstream &inputFile, vector<int> &sides){
    float p = 0;
    float area = 0;
    // Read in the three side lengths
    for (int i = 0; i < 3; i++){
        inputFile >> sides[i];
    }
    // Calculate the area
    p = (sides[0]+sides[1]+sides[2])/2.0;
    area = sqrt(p*(p-sides[0])*(p-sides[1])*(p-sides[2]));
    // Return the value of the area
    return area;
}





