/*
 * H4 Program, Fibonacci Sequence
 * To Demonstrate That You Have Secured Access to the Computer Resources necessary to be Successful in the Course,
 * And How to Design and Use Functions
 * By Shima Azizzadeh-Roodpish
 * 24 Feb 2015
 * No Copyright
 * Github account: https://github.com/Shima63/H4.git
 */
 
// External Libraries

#include <cstdlib> 
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

// Global Variables

string inputfilename = "shima.in", outputfilename = "shima.out", errorfilename = "shima.err", message;

// Function Prototype

void open_input ( string, ifstream & );
void open_file ( string, ofstream & );
void print_file ( string, ofstream & );
void print_file ( long double, ofstream & );

// Main Program.
// Return Zero on Success, Non-Zero in case of Failure.

int main () {

    // Defining Variables' Type

    int num_of_rows = 0, m = 0, n = 0;
    double i = 0, j = 1;
    
    // Preparing output file
    
    ofstream outputfile;
    open_file ( outputfilename, outputfile );
    
    // First Checking Messages.
    
    message = "I was able to compile this code using the HPC at the University of Memphis."
              "When I compiled it there, it did not produce any warning message."
              "The HPC uses a GNU C++ compiler that can be considered a good up-to-date standard."
              "I also version-controlled this code using git, and used a remote repository hosted by github." 
              "If I can do this, so can you!!!";
	print_file ( message, outputfile );
	print_file ( "\n\n", outputfile );
	message = "I am so cool, that I was also able to write a code that produces the first M numbers of the Fibonacci sequence."
	          "Here they are:";
	print_file ( message, outputfile );
	print_file ( "\n\n", outputfile );

    // Open the Input File. 
    
    ifstream inputfile;
	open_input ( inputfilename, inputfile );
	
    //  Check the Validity of Input
    
    inputfile >> num_of_rows;
    if ( num_of_rows < 1 ) {
        message = "Input for number of rows is not valid. It should be equal or more than one.";
        ofstream errorfile;
        
        // Making error file When There Is Error

        open_file ( errorfilename, errorfile );
	    print_file ( message, errorfile );
        return 2;
    }      

    // Producing Fibonacci Series. In Math It Starts from 1, But in Modern Usage It Starts from 0. We Choose 0 as a Starting Point.

    for ( n = 1; n <= num_of_rows; n++ ) {
        m = 0;
        while ( m < 10 ) { //Producing Two Fibonacci Numbers in Each Step
            print_file ( i, outputfile );
            print_file ( j, outputfile );
            i = i + j;
            j = j + i;
            m = m + 2;
        }
        print_file ( "\n", outputfile );
    }
    
    inputfile.close ();
    outputfile.close ();
    
    return 0;
}


// Functions

// "open_input" Function Will Read the Input File and Will Check Its Validity. It Returns One If the File Is Not Valid.
    
void open_input ( string inputfilename, ifstream & ifs ) {
    ifs.open(inputfilename.c_str());

    // Check to Make Sure the File Is Opened Properly

    if ( !ifs.is_open() ) {
    	message = "Input file does not exist!";
    	
        // Making error file When There Is Error

	    ofstream errorfile;
	    open_file ( errorfilename, errorfile );
	    print_file ( message, errorfile );
        exit (EXIT_FAILURE);
    }   
    return;
} 

// "open_file" Function Will Make a New File.
    
void open_file ( string filename, ofstream & ofs ) {
    ofs.open(filename.c_str());
    if ( !ofs.is_open() ) {
        if ( filename == "foo/shima.err" ) {
            message = "error file does not exist!";
            cout << message << flush;
            exit (EXIT_FAILURE);
        } 
        else {
            message = "File does not exist!";
            
            // Making error file When There Is Error

	        ofstream errorfile;
	        open_file ( errorfilename, errorfile );
	        print_file ( message, errorfile );
            exit (EXIT_FAILURE);
        }
    }   
    return;
} 

// This "print_file" function Prints Messages on Files and Terminal. Message Is of String Type.

void print_file ( string message, ofstream & ofs ) {
    ofs << message << flush;
    cout << message << flush;
    return;
}

// This "print_file" function Prints Outputs for This Program. Output Is Double Type.

void print_file ( long double number, ofstream & ofs ) {
    ofs << setw (20) << left << number; // Less than 20 Digits Assumed for Numbers
    cout << setw (20) << left << number;
    return;
}

 