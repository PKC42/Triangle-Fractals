/**********************************************************************
 *  Recursive Graphics (Triangle Fractal)                       
 **********************************************************************/

Pratush Kc



/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
 In this program, a recursive function was called to draw a Triangle Fractal
 where a series of triangles are drawn at the vertex of vertex of the previous 
 triangles for a depth of recursion recieved as an integer from the command line. 
 The other command line argument is L which is the length of a side of the equilateral 
 triangle. This length is divided in half per each level in terms of depth of recursion. 
 The Triangle Fractal will be drawn in a window using sfml. I was able to accomplish this
 using sfml libraries along with a Triangle class which stores the information and color
 of each triangle. Each time a function is called, a new triangle object is created as
 a local object in a fTree() function. This allows for the triangle specifications
 to be easily contained. Additionally, a message on the screen containing the recursion
 depth was printed which allows for the user to better understand the relationship 
 between recursion depth and triangle appearance. Additionally, cpplint.py was used
 to ensure that the code follows a particular style. 


 /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/
 In this project, a Triangle class was made which stored the starting coordinate (x, y).
 Depth of recursion (N) side length (L) along with a convex shape object (triangle). This 
 was drawn to a window using draw inherited from sf::drawable. To draw each triangle, each 
 new triangle was based on the location of a particular vertex of the previous triangle 
 (at the previous depth). This would continue until all triangles at each depth were drawn. 



/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.
 **********************************************************************/
 The fTree() function is the function that works recursively. It has a return
 type of void and takes X, Y, L, N, color and window as parameters. The function uses
 X, Y, L, N and color to initialize a Triangle object. If the recursive depth is greater 
 than 0, the function will call on itself at each of the triangles' three vertices to draw
 the next stages. Depending on the depth, the function will call on itself repeatedly until
 for one corner, all the triangles are draw. The function repeats this with the other two 
 corners until the triangle fractal has been draw. The function can be seen below: 

 void fTree(double x, double y, double L, int N,
    sf::RenderWindow* window, sf::Color color) {
    // create triangle object
    Triangle triangle(x, y, L, color);
    window->draw(triangle);
    double height = ((sqrt(3)/2) * L);

    if (N > 0) {
        fTree(x - (L / 2), y - height, L / 2, N - 1, window, sf::Color::Red);
        fTree(x + (L / 2) + (L / 4), y - height + ((sqrt(3)/2) * L / 2),
        L / 2, N - 1, window, sf::Color::Green);
        fTree(x - (L / 4), y + ((sqrt(3)/2) * L / 2),
        L / 2, N -1, window, sf::Color::Blue);
    }
}
    Note: The parameters for each of the calls inside the function are different
    as they show the starting point at each respective vertex which are at different
    coordinates in the SFML window. 

    It should also be noted that the SFML window will always be 3.5 times bigger than original
    length entered via command line. The purpos of this is to allow for the window to be properly 
    scalable and the triangle fractal to be viewable if it is especially small or especially large. 
    If the triangle fractal is particularly small, the window can be expaned and the triangle fractal
    can be seen in a larger format. 

 /**********************************************************************
 *  Briefly explain what you learned in the assignment.
 **********************************************************************/
 In this project, I learned that recursion can be useful when needing to 
 repeat actions without using too many loops. Additionally, I learned about
 proper code styling (according to Google standards).



/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
 I have recieved help from the sfml official documentation pages along with
 comments from Dr.Daly and fellow students on Dr.Daly's discord server. 


/**********************************************************************
 *  Describe any serious problems you encountered.  
 *  If you didn't complete any part of any assignment, 
 *  the things that you didn't do, or didn't get working.                  
 **********************************************************************/
I had issues with cpplint having issues with the draw function in the Triangle
class. This was resolved by using the following as mentioned on Dr. Daly's 
discord server: --filter=-runtime/references. This filters out the issue. 


/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
 For extra credit, I color coded each of the triangles forming from the 
 first triangle (black) as red, green and blue respectively. This helps 
 better identify parts of the triangle. Additionally, the depth of recursion
 was printed into the sfml window using Impact font (for extra credit). This 
 was to help the user identify depth of recursion without counting the stages. 

 To run the program, type: ./TFractal (enter length) (enter recursive depth)
 To check with cpplint, type: cpplint.py --filter=-runtime/references *.cpp *.h

 The program should pass the cpplint test.

 example command: ./TFractal 150 4

 A screenshot of this triangle fractal can be seen in the file. 

 Note: The impact.ttf file was taken from: https://www.wfonts.com/
 The cpplint.py file was taken from : https://github.com/cpplint/cpplint

 Note: type make to create objects