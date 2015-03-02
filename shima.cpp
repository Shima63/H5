/*
 * H5 Program
 * To Understand How to Declare and Manipulate a Collections of Objects Using an Array, Enumerators, and Structures.
 * By Shima Azizzadeh-Roodpish
 * 25 Feb 2015
 * No Copyright
 * Github account: https://github.com/Shima63/H5.git
 */
 
// External Libraries

#include <cstdlib> 
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ctype.h>
#include <locale>
using namespace std;

// Global Variables

string inputfilename, outputfilename = "shima.out", logfilename = "shima.log", message;

// ********************************************************************************************************************

// Function Prototype

void open_input ( ifstream & );
void open_file ( string, ofstream & );
void print_file ( string, ofstream & );
void check_date ( string, ofstream & );
void check_time ( string, ofstream & );
void check_time_zone ( string, ofstream & );
void check_magnitude_type ( string, ofstream & );
void check_magnitude_size ( float, ofstream & );
string uppercase ( string );

// ********************************************************************************************************************

// Main Program.
// Return Zero on Success, Non-Zero in case of Failure.

int main () {

    // Defining Variables' Type
    
    string Event_ID, date, time, time_zone, earthquake_name, earthquake_name_continue, magnitude_type;
    double longitude, latitude, depth;
    float magnitude_size;
    //int num_stations = 300;
    
    // Prompt User for Input File Name.

    ifstream inputfile;
    open_input ( inputfile );
    
    // Preparing log file
    
    ofstream logfile;
    open_file ( logfilename, logfile );
    
    // Reading and Checking Header
        
    inputfile >> Event_ID;
    inputfile >> date;   
    check_date ( date, logfile );
    inputfile >> time;
    check_time ( time, logfile );
    inputfile >> time_zone;
    check_time_zone ( time_zone, logfile );
    inputfile >> earthquake_name;
    getline(inputfile, earthquake_name_continue);
    earthquake_name.append ( earthquake_name_continue ); 
    
    // Epicenter Location
    
    inputfile >> longitude;
    inputfile >> latitude; 
    inputfile >> depth;
    
    // Magnitude Information
    
    inputfile >> magnitude_type;
    check_magnitude_type ( magnitude_type, logfile );
    inputfile >> magnitude_size;
    check_magnitude_size ( magnitude_size, logfile );

    

    // Preparing output file
    
    ofstream outputfile;
    open_file ( outputfilename, outputfile );

    return 0;
}

// ********************************************************************************************************************

// Functions

// "open_input" Function Will Ask the Name of the Input File and Will Check Its Validity. 

void open_input ( ifstream & ifs ) {

    // Prompt User for Input File Name.

    cout << "Enter input file name: ";
    cin >> inputfilename;
 
    ifs.open(inputfilename.c_str());

    // Check to Make Sure the File Is Opened Properly

    if ( !ifs.is_open() ) {
    	message = "Input file does not exist!";
    	
        // Making log file When There Is Error

	    ofstream logfile;
	    open_file ( logfilename, logfile );
	    print_file ( message, logfile );
        exit (EXIT_FAILURE);
    }   
    return;
} 

// "open_file" Function Will Make a New File.
    
void open_file ( string filename, ofstream & ofs ) {
    ofs.open(filename.c_str());
    if ( !ofs.is_open() ) {
        message = "File does not exist!";
            
        // Making log file When There Is Error

	    ofstream logfile;
	    open_file ( logfilename, logfile );
	    print_file ( message, logfile );
        exit (EXIT_FAILURE);
    }   
    return;
} 

// This "print_file" function Prints Messages on Files and Terminal. Message Is of String Type.

void print_file ( string message, ofstream & ofs ) {
    ofs << message << flush;
    cout << message << flush;
    return;
}

// This "check_date" function checks the validity of date entry.

void check_date ( string date, ofstream & logfile ) {
    message = "Date format is not right.";
    if ( date.length() != 10 ) {
        print_file ( message, logfile );
        exit (EXIT_FAILURE);
    }
    else {
        if ( ( ( date[2] != "-"[0] ) && ( date[2] != "/"[0] ) ) || ( ( date[5] != "-"[0] ) && ( date[5] != "/"[0] ) ) ) {
            print_file ( message, logfile );
            exit (EXIT_FAILURE);
        }
        else {
            if ( ( !isdigit ( date[0] ) ) || ( !isdigit ( date[1] ) ) || ( !isdigit ( date[3] ) ) || ( !isdigit ( date[4] ) ) ) {
                print_file ( message, logfile );
                exit (EXIT_FAILURE);
            }  
            if ( ( !isdigit ( date[6] ) ) || ( !isdigit ( date[7] ) ) || ( !isdigit ( date[8] ) ) || ( !isdigit ( date[9] ) ) ) {
                print_file ( message, logfile );
                exit (EXIT_FAILURE);
            }
        }
    }
    return;
}    

// This "check_time" function checks the validity of time entry.

void check_time ( string time, ofstream & logfile ) {
    message = "Time format is not right.";
    if ( time.length() != 12 ) {
        print_file ( message, logfile );
        exit (EXIT_FAILURE);
    }
    else {
        if ( ( time[2] != ":"[0] ) || ( time[5] != ":"[0] ) || ( time[8] != "."[0] ) ) {
            print_file ( message, logfile );
            exit (EXIT_FAILURE);
        }
        else {
        if ( ( !isdigit ( time[0] ) ) || ( !isdigit ( time[1] ) ) || ( !isdigit ( time[3] ) ) || ( !isdigit ( time[4] ) ) ) {
            print_file ( message, logfile );
            exit (EXIT_FAILURE);
        }  
        if ( ( !isdigit ( time[6] ) ) || ( !isdigit ( time[7] ) ) || ( !isdigit ( time[9] ) ) || ( !isdigit ( time[10] ) ) || ( !isdigit ( time[11] ) ) ) {
            print_file ( message, logfile );
            exit (EXIT_FAILURE);
        }
        }
    }
    return;
}    

// This "check_time_zone" function checks the validity of time zone entry.

void check_time_zone ( string time_zone, ofstream & logfile ) {
    message = "Time_zone format is not right.";
    if ( time_zone.length() != 3 ) {
        print_file ( message, logfile );
        exit (EXIT_FAILURE);
    }
    return;
}    

// This "check_magnitude_type" function checks the validity of magnitude type considering it case insensitive.

void check_magnitude_type ( string magnitude_type, ofstream & logfile ) {
    message = "magnitude_type is not right.";
    string mt = uppercase ( magnitude_type );
    if ( ( mt != uppercase ( "ml" ) ) && ( mt != uppercase ( "ms" ) ) && ( mt != uppercase ( "mb" ) ) && ( mt != uppercase ( "mw" ) ) ) {
        print_file ( message, logfile );
        exit (EXIT_FAILURE);
    }
    return;
}

// This "check_magnitude_size" function checks the validity of magnitude size as a positive real number (>0).

void check_magnitude_size ( float magnitude_size, ofstream & logfile ) {
    message = "magnitude_size is not right.";
    if ( magnitude_size <= 0 ) {
        print_file ( message, logfile );
        exit (EXIT_FAILURE);
    }
    return;
}

// This "string uppercase" function changes all the lettera of the input string to upper case.

string uppercase ( string s ) {
    string result = s;
    for (int i=0; i < (int)s.size(); i++)
        result[i] = toupper(s[i]);
    return result;
}

    