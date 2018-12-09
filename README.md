# PA7_S2_K_Shvedov
Attendance Tracker

This project was made for the purpose of learning C++ and understanding how
lists could be used in everyday use.

The program can do six things:
1. Import course list
2. Load master list
3. Store master list
4. Mark absences
5. Edit absences
6. Generate report

1. This action will import information about students into a list from a CSV file
2. This action will import information about students into a list with all the
   information about there absences
3. This action will store information about students and their absences from
   a list into a text file
4. This action will go through all the students and let the instructor mark off
   Any students that are absent, which in turn will store this information into
   the list node of the student into there stack of absences.
5. This action will allow the instructor to search for a student using their name
   or ID. If a student is found, any of there absences can be removed.
6. This action will allow the instructor to choose if they want to print a report with
   all students and their latest absence or just a list of students that have been
   absent for X or more times and all their absence dates.
   
If I would have done this project again, I would consider splitting up functions more
into more appropriate smaller functions that would allow for easier readability and easier
testing.
