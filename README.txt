Troy Ricks: cssc1101
Sydney Blackburn: cssc1112

Class: CS570, Professor Leonard, Summer 2017
Due: June 5, 2017
Project: Assignment #1, Process Manager
File: README

** cssc1112 edoras account will be available for testing **

File Manifest:
	page.c
	page.h
	pages.txt (editable)
	Makefile
	README

Compile Instructions:
	To compile our program, just enter the command "make" which will run
        our Makefile bash script, creating an executable named "a2".
        Otherwise enter "gcc page.c" to compile it manually with an
        "a.out" as your executable.

Operating Instructions:
	To operate our program, use the Makefile provided and run the created
        "a2" executable. The program will use the "pages.txt" file provided. 
	The program will then prompt the user to input the number of frames
	the program will have to work with.

Novel/Significant Design Decisions:
	We decided it best to separate our work, each working on a separate 
	Page Replacement Algorithms (Troy on Clock and Sydney on Second 
	Chance) then combine to finish the Optimal.

Extra Features/Algorithms/Functions:
	No extra features added. Does what was required via the prompt.

All Known Deficiencies Or Bugs:
	No known deficiencies or bugs.

Lessons Learned:
	Better understanding of Page Replacement Algorithms and C were
	achieved through the creation of this program.

Page Analysis:
	For our page analysis, we edited "page.txt" twice to contain two different data sets. For each 
	of those sets, we ran our program with two different frame sizes (3 and 4) to determine the 
	optimal Page Replacement Algorithm between Second Chance, Clock and OPT. The determining 
	factor for this test was the order in which the numbers in the "pages.txt" file were arranged.
	This led to inconclusive data concerning which PRA was best. Different frame and page sizes
	(along with page input) led to different PRA's being superior for the set.
	
	Controls: "pages.txt" (both size of file and input data),
	Variables: Frame size (user input)
	Outcomes: Inconclusive results due to different PRA's being superior for different sets
	Input Characterizations: Pages: partitioned memory into small equal fixed-sized blocks
				 Frames: blocks in memory for the processes to be executed
	
Data:
	
	Pages: 2 3 2 1 5 2 4 5 3 2 5 2	
	Enter number of frames: 3
	Number of Second Chance faults: 6
	Number of Clock faults: 8
	Number of Optimal faults: 6

	Enter number of frames: 4
	Number of Second Chance faults: 6
	Number of Clock faults: 6
	Number of Optimal faults: 6

	Pages: 1 4 2 3 5 3 5 2 4 1 4 2 4 3 1 2 4 2 3 4 2 3 4 2
	Enter number of frames: 3
	Number of Second Chance faults: 13
	Number of Clock faults: 10
	Number of Optimal faults: 14

	Enter number of frames: 4
	Number of Second Chance faults: 9
	Number of Clock faults: 9
	Number of Optimal faults: 8