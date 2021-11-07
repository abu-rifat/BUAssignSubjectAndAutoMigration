# BUAssignSubjectAndAutoMigration
Assign Subject and Auto Migration based on GST result BU

## File Formats:
### Subject_Selection.in
1. First line will contain 2 variables n and m. Where n is the total number of students and m is the total number of available subjects.
2. Next line will contain m strings representing the m subjects accordingly
3. Next line will contain m integers representing the total seats on that subjects accordingly
4. The i-th line of the next n line will contain an integer k<sub>i</sub> representing the marit position of i-th student, a value 0 or 1 representing auto migration on or off(0 is for auto migration off) of the i-th student, a integer value j<sub>i</sub> representing the total number of subject choices of the i-th student and j<sub>i</sub> strings representing the subject choices respecting the order.

#### Example
```
10 7
A B C D E F G
2 2 1 2 1 1 1
1 1 7 D B A C E F G
2 1 7 C B E D F G A
3 1 7 A B C D E F G
4 1 7 G F E D C B A
5 1 7 G C B A D E F
6 1 7 A G B F C E D
7 1 7 G F E A B C D
8 1 7 A B G C D E F
9 1 7 A G B C D E F
10 1 7 G D E C B F A
```

### migration.in
1. First line will contain an integer n representing the number of students who didn't get admitted to the selected subject.
2. The next line will contain n integers representing the marit position of the n students who didn't get admitted to the selected subject.
3. The next line will contain an integer m representing the number of students who want to off the auto migration.
4. The next line will contain m integers repregenting the marit position of the m students who want to off the auto migration.
#### Example
```
1
4
0
```

### dataFile.io
1. Top of the file will contain the full data of the file **subjectChoice.in** and then a blank line.
2. The next line will contain n strings where i-th of them represents the assigned subject of the i-th student respecting the order of the marit position and a blank line.
3. The i-th line of the next m lines (m is the number of subjects) will contain a number k<sub>i</sub> representing the total number of seats and k<sub>i</sub> integers representing the marit positions of the selected student of the i-th subject in assending order and a blank line.
4. The i-th line of the next m lines will contain a number l<sub>i</sub> representing the total number of the students in the queue of the subject to get auto migrated. And l<sub>i</sub> integers representing the marit positions of the students accordingly.
#### Example
```
10 7
A B C D E F G
2 2 1 2 1 1 1
1 1 7 D B A C E F G
2 1 7 C B E D F G A
3 1 7 A B C D E F G
4 1 7 G F E D C B A
5 1 7 G C B A D E F
6 1 7 A G B F C E D
7 1 7 G F E A B C D
8 1 7 A B G C D E F
9 1 7 A G B C D E F
10 1 7 G D E C B F A

D C A G B A F B D E

3 6
5 8
2
1 9
10
7
4

2 8 9
1 9
2 5 9
1 10
0
0
4 5 7 9 10
```

### stuGetSub.out
1. First line will contain an integer n representing the total number of students.
2. The i-th line of the next n lines will contain 1 integer and 1 string k<sub>i</sub> and l<sub>i</sub> representing the marit position of i-th student and the assigned subject, then an integer p<sub>i</sub> representing the total number of subjects where the student is in the queue to get auto migrated.(If auto migration is off for this student, this integer will be 0). Then p<sub>i</sub> strings accordingly representing the subjects.
#### Example
```
10
1 D 0
2 C 0
3 A 0
4 G 0
5 B 2 G C
6 A 0
7 F 1 G
8 B 1 A
9 D 4 A G B C
10 E 2 D G
```

### sub.out
1. First line will contain an integer m representing the total number of the subjects.
2. The i-th line of the next m lines will contain an integer p<sub>i</sub> as the total number of seats in the subject. Then p<sub>i</sub> integers representing the marit positions of the students who got assigned to the subject. Then an integer q<sub>i</sub> representing the number of the students wh are on the queue of the subject to get auto migrated to the subject. Then q<sub>i</sub> integers representing the marit positions of the students who ate in the auto migration queue of the subject.
#### Example
```
7
2 3 6 2 8 9
2 5 8 1 9
1 2 2 5 9
2 1 9 1 10
1 10 0
1 7 0
1 4 4 5 7 9 10
```

## How to run this Project?
### To make the first run (Assign subject for the first time):
1. Open terminal or power-shell.
2. run ```g++ Subject_Selection.cpp```
3. For linux: run ```./a.out```, for Windows: run ```./a.exe```
4. The result is now stored in <b>'dataFile.io'</b>.

### To make migration:
#### Must do the first run to get correct results.
1. Open terminal or power-shell.
2. run ```g++ Make_Migration.cpp```
3. For linux: run ```./a.out```, for Windows: run ```./a.exe```
4. The result is now stored in <b>'dataFile.io'</b>.

### Get Student based Output:
#### Must do the first run or migration to get correct results.
1. Open terminal or power-shell.
2. run ```g++ stuGetSub.cpp```
3. For linux: run ```./a.out```, for Windows: run ```./a.exe```
4. The result is now stored in <b>'stuGetSub.out'</b>.

### Get Subject based Output:
#### Must do the first run or migration to get correct results.
1. Open terminal or power-shell.
2. run ```g++ sub.cpp```
3. For linux: run ```./a.out```, for Windows: run ```./a.exe```
4. The result is now stored in <b>'sub.out'</b>.
