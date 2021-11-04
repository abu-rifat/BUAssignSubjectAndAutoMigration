# BUAssignSubjectAndAutoMigration
Assign Subject and Auto Migration based on GST result BU

## Input Formats:
### subjectChoice.in
1. First line will contain 2 variables n and m. Where n is the total number of students and m is the total number of available subjects.
2. Next line will contain m strings representing the m subjects accordingly
3. Next line will contain m integers representing the total seats on that subjects accordingly
4. The i-th line of the next n line will contain a value 0 or 1 representing auto migration on or off(0 is for auto migration off) of the i-th student, a integer value j<sub>i</sub> representing the total number of subject choices of the i-th student and j<sub>i</sub> strings representing the subject choices respecting the order.

#### Example
```
10 7
A B C D E F G
2 2 1 2 1 1 1
1 7 D B A C E F G
1 7 C B E D F G A
1 7 A B C D E F G
1 7 G F E D C B A
1 7 G C B A D E F
1 7 A G B F C E D
1 7 G F E A B C D
1 7 A B G C D E F
1 7 A G B C D E F
1 7 G D E C B F A
```