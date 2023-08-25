# Multiple Student Course Grading Program with File IO
 
## Directions
Write a complete program to help your professor(s) calculate the course grade of their students. In your program: 

[x] - You MUST have arrays that store the data read from the file and close the file as soon as possible (you may use strings for the student name and file names). 

Create your project on the desktop. Open the input and output files through IDE ONLY. Meet with a team member with a windows system to view the executable file if you need to view my sample file. Please start early and adhere to all requirements on this exam and NOT the SAMPLE executable file.

- Each faculty member has their grading policy (number of items that get graded and points for each item). See and use the attached two grading scheme files, “syllabus.txt” and “syllabus 2.txt”.
- You may assume that each item is one “token” (no spaces, see “syllabus 2.txt”)
- You may assume that the total points end up to 100 (no need for you to validate that).
- The student answer input file has in the first line the name of the student and in the next lines the grade that he/she got in the corresponding part
- You may assume that each student file has at least as many grades as the items to be graded (you do not need to validate that). If there are more grades in - the student file you may assume that they belong to extra credit and you can ignore them.
- You may use my input files and modify them for your various testing needs. Note that the input file names may contain spaces.
- The data files will have each grade in a separate line.

## Requirements

### Read Syllabus File
[x] - Ask the user where the point allocation data for each item is stored,
[x] - Read that file name, 
  ([x] - remember to have the file names hardwired in the code as constants)
[x] - Open that file and
[x] - Make sure it exists.
[x] - If it doesn’t, output an error message and keep on asking for the correct filename till it is provided
[x] - If it does, read the data from that file and Close that file.

### Read Student Information
[x] - Ask the user how many students are in that course. Validate your input. Keep on asking for valid input till it is provided. Make sure the Number of student files doesn't exceed 3.
[x] - (your code automatically generates the file names, you do not have to ask the user for that filename), where i is an iterator (goes from 1 to the total number of students in the class. BIG HINT: You will need to use the to_string function, defined in the string library. That function takes an integer as an argument and returns it as a string. For example, to_string(15) returns “15”.
[x] - Attempt to open a file named Student #i.txt 
[x] - Makes sure it exists.
[x] - If it doesn’t, output an error message and goes to the next student (a student may not have taken the exam)
[x] - If it does, read the data from that file into the answer key array and

### Write Student File
[x] - Finally, your program will use each of the student's full name to create a corresponding file (make sure you append “.txt” after the name of the student before you create the output file)
[x] - And output in that file the information in a similar way as my sample program does (nice table)
  [x] - The name of the student
  [x] - The list of items in the course, the item's weight, the grade the student got for that item, and the points the student earned as a result.
  [x] - The course grade for that student
  [x] - And whether or not the student has passed or not the exam (the passing grade is 70%)

### Structure
[] - A function that loads the answer key – this function should take the file name that contains the point allocation as an argument as well as any other arguments you find necessary.
[] - A function that “grades” the student – that function will also output the information described above to the file with the student’s name as filename (can do the open as well).
[x] - You can use any function or member function with the condition that you explain how it works and why you used it.
[x] - Any other function(s) that you find useful
[x] - Your program should compile with NO errors and NO warnings.
