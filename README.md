# README #

This repository contains my own solution for semestral work of FLP. There are three solutions in different languages. One in C++ 2011, second in Lisp and last in Prolog.

## Problem description ##

### Noise ###
The capital city of Fitlands, Fitopolis, is in trouble. People riot because the main highway goes straight through the city and the loudness annoys those living close to it. The loudness or intensity level of sound is usually measured in decibels and sound having intensity level 130 decibels or higher is considered painful. The intensity level of normal conversation is 60 - 65 decibels and that of heavy traffic is 70 - 80 decibels. Consider the following city map where the edges refer to streets and the nodes refer to crossings:

The integer on each edge is the average intensity level of sound (in decibels) in the corresponding street. To get from crossing A to crossing G you may follow the following path: A-C-F-G. In that case you must be capable of tolerating sound intensity as high as 140 decibels. For the paths A-B-E-G, A-B-D-G and A-C-F-D-G you must tolerate respectively 90, 120 and 80 decibels of sound intensity. There are other paths, too. However, it is clear that A-C-F-D-G is the most comfortable path since it does not demand you to tolerate more than 80 decibels.

In this problem, given a city map you are required to determine the minimum sound intensity level you must be able to tolerate in order to get from a given crossing to another.

### Input ###
The input may contain multiple test cases.

The first line of each test case contains three integers C(≤ 100), S(≤ 1000) and Q(≤ 10000) where C indicates the number of crossings (crossings are numbered using distinct integers ranging from 1 to C), S represents the number of streets and Q is the number of queries. Each of the next S lines contains three integers: c1, c2 and d indicating that the average sound intensity level on the street connecting the crossings c1 and c2 (c1 ≠ c2) is d decibels. Each of the next Q lines contains two integers c1 and c2 (c1 ≠ c2) asking for the minimum sound intensity level you must be able to tolerate in order to get from crossing c1 to crossing c2. The input will terminate with three zeros form C, S and Q.

### Output ###
For each test case in the input first output the test case number (starting from 1) as shown in the sample output. Then for each query in the input print a line giving the minimum sound intensity level (in decibels) you must be able to tolerate in order to get from the first to the second crossing in the query. If there exists no path between them just print the line “no path”. Print a blank line between two consecutive test cases.

Copyright (c) 2015, Rostislav Novák. All rights reserved.