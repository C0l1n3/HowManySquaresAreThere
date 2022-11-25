# HOW MANY SQUARES ARE THERE?

## 1/ introduction
From a single file, the program is able to
- process each line and get point datas all the while avoiding to add duplicates
- find errors in the input file (ex: unwanted characters)
- find all squares that can be drawn with these points
- print out to the terminal those points

Since comparing points 4 by 4 would take too much resources, I decided to compare points 2 by 2 and project the three squares that would result from those two first points and check if they exist in the file.
##### For the sake of the exercise, we consider the points to be within the int range
##### This project was part of a recruitement process.

## 2/ how to install
Installation uses a makefile.
In the terminal type in
```bash
make
```
It will create a program named "SquareFinder".

## 3/ how to use
Type in the terminal 
```bash
./SquareFinder file
```
Where _file_ is the input file where your points are located in this format :

```
2 -5
+6 8
15 -2
526 -52
2 69
-36 -896
(...)
```
## 4/ example

```bash
> ./SquareFinder file
> File Ok
> number of squares found : 3
> SQUARE 1 : A[-667, -717], B[-661, 943], C[993, -723], D[999, 937]
> SQUARE 2 : A[882, 358], B[528, 684], C[556, 4], D[202, 330]
> SQUARE 3 : A[-549, -785], B[-559, -886], C[-650, -775], D[-660, -876]

```

For a file containing 5000 points, the program will roughly take 4 minutes to calculate. 

