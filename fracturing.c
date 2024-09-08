//********************************************************
// fracturing.c
// Author: Kevin Castro-Escobar
// Date: 9/8/24
// Class: COP 3223, Professor Parra
// Purpose: This program is to develop an understanding for "fracturing"
// logic within a program, dividing it into multiple, easier to understand, parts.
// Input: User inputs two points for each of the following functions:
// distance, perimeter, area, width, height
//
// Output: (to the command line) The resultant perimeter, area, width, and height, of a
// square encompassed by the two points, and the distance between the two points. Each for the respective
// points given for the operation
// //********************************************************

#include <stdio.h>
#include <math.h>

#define PI 3.14159

// Structure to make manipulation of user points easier
typedef struct {
    double x1; // X coordinate of point 1.
    double y1; // Y coordinate of point 1.
    double x2; // X coordinate of point 2.
    double y2; // Y coordinate of point 2.
} UserPoints;

//********************************************************
// double pointsWidth (UserPoints points)
//
// Purpose:         To re-use logic for getting the width of the square
//                  between two points.
// Input:           A UserPoints structure representing the user's input points.
// Output:          A double is returned representing the width of the 
//                  square encompassed by the points.
//********************************************************
double pointsWidth(UserPoints points) { 
    return fabs(points.x2 - points.x1); 
}

//********************************************************
// double pointsHeight (UserPoints points)
//
// Purpose:         To re-use logic for getting the height of the square
//                  between two points.
// Input:           A UserPoints structure representing the user's input points.
// Output:          A double is returned representing the height of the 
//                  square encompassed by the points.
//********************************************************
double pointsHeight(UserPoints points) { 
    return fabs(points.y2 - points.y1); 
}


//********************************************************
// double askForUserInput ()
//
// Purpose:         To halt a program and wait for user input of a float.
// Output:          Returns a double representing the user's input.
//********************************************************
double askForUserInput() {
    double output;
    scanf(" %lf", &output);
    return output;
}


//********************************************************
// UserPoints askForUserPoints ()
//
// Purpose:         To halt a program and wait for user input of two distinc points, represented
//                  with 4 doubles for each of the two points' two coordinates.
// Output:          Returns a UserPoints structure representing the user's input.
//********************************************************
UserPoints askForUserPoints() {
    UserPoints output;
    
    printf("Enter point #1 x: ");
    output.x1 = askForUserInput();
    printf("Enter point #1 y: ");
    output.y1 = askForUserInput();
    
    printf("Enter point #2 x: ");
    output.x2 = askForUserInput();
    printf("Enter point #2 y: ");
    output.y2 = askForUserInput();
    return output;
}

//********************************************************
// void repeatUserInput ()
//
// Purpose:         To display the user points given to it to the console.
// Input:           Takes in a UserPoints structure to display the points of.
//********************************************************
void repeatUserInput(UserPoints points) {
    printf("Point #1 entered: x1 = %lf; y1 = %lf\n", points.x1, points.y1);
    printf("Point #2 entered: x2 = %lf; y2 = %lf\n", points.x2, points.y2);
}

//********************************************************
// double calculateDistance ()
//
// Purpose:         To display the distance between two points to the console, re-using prior logic
//                  and taking in user input for where the two points are.
// Input:           Asks the user to input two points, coordinate by coordinate.
// Output:          Returns a double which is the distance between the two points the user inputs,
//                  along with repeating those inputted points before hand.
//********************************************************
double calculateDistance() {
    UserPoints points = askForUserPoints();
    repeatUserInput(points);
    
    double x = points.x1 - points.x2;
    double y = points.y1 - points.y2;
    double distance = sqrt(x*x + y*y);
    
    printf("The distance between the two points is %lf.\n", distance);
    
    return distance;
}

//********************************************************
// void calculateWidth ()
//
// Purpose:         To display the width of the square between two points to the console, 
//                  re-using prior logic and taking in user input for where the two points are.
// Input:           Asks the user to input two points, coordinate by coordinate.
// Output:          Returns a double from one to 5 representing how hard it was to code this. 
//                  In this case 2.0.
//********************************************************
void calculateWidth() {
    UserPoints points = askForUserPoints();
    repeatUserInput(points);
    
    printf("The width of the city encompassed by your request is %lf.\n", pointsWidth(points));
}

//********************************************************
// void calculateHeight ()
//
// Purpose:         To display the height of the square between two points to the console, 
//                  re-using prior logic and taking in user input for where the two points are.
// Input:           Asks the user to input two points, coordinate by coordinate.
// Output:          Returns a double from one to 5 representing how hard it was to code this. 
//                  In this case 2.0.
//********************************************************
void calculateHeight() {
    UserPoints points = askForUserPoints();
    repeatUserInput(points);
    
    printf("The height of the city encompassed by your request is %lf.\n", pointsHeight(points));
}

//********************************************************
// void calculatePerimeter ()
//
// Purpose:         To display the perimeter of the square between two points to the console, 
//                  re-using prior logic and taking in user input for where the two points are.
// Input:           Asks the user to input two points, coordinate by coordinate.
// Output:          Returns a double from one to 5 representing how hard it was to code this. 
//                  In this case 1.0.
//********************************************************
void calculatePerimeter() {
    UserPoints points = askForUserPoints();
    repeatUserInput(points);
    
    double perimeter = 2 * (pointsWidth(points) + pointsHeight(points));
    printf("The perimeter of the city encompassed by your request is %lf.\n", perimeter);
}

//********************************************************
// void calculateArea ()
//
// Purpose:         To display the area of the square between two points to the console, 
//                  re-using prior logic and taking in user input for where the two points are.
// Input:           Asks the user to input two points, coordinate by coordinate.
// Output:          Returns a double from one to 5 representing how hard it was to code this. 
//                  In this case 1.0.
//********************************************************
double calculateArea() {
    UserPoints points = askForUserPoints();
    repeatUserInput(points);
    
    double area = pointsWidth(points) * pointsHeight(points);
    printf("The area of the city encompassed by your request is %lf.\n", area);
}

//********************************************************
// int main (int argc, char **argv)
//
// Purpose:         To call the calculateDistance(), calculatePerimeter()< calculateArea(),
//                  calculateWidth(), and calculateHeight() functions in order.
//********************************************************
int main(int argc, char **argv) {
    calculateDistance();
    calculatePerimeter();
    calculateArea();
    calculateWidth();
    calculateHeight();
    
    return 0;
}
