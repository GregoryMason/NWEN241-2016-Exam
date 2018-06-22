## Question 1. C General Questions [20 Marks]
<details style="color:brown">
  <summary style="color:black">
  <b>(a) [4 Marks]</b> Explain the four steps of compilation for C programs.
  </summary>
  
---
1. **Pre-processing** <br> Removes comments, joins continued lines (lines ending in `\`) and interprets pre-processor commands (lines starting with `#`).
2. **Compilation** <br> Translates pre-processed code into assembly instructions.
3. **Assembly** <br> Translates assembly instructions into machine code/object code.
4. **Linking** <br> Arranges the object code, and adds missing code, to produce an executable program.

---

</details>
<br>
<details style="color:brown">
  <summary style="color:black">
  <b>(b) [6 Marks]</b> Explain how the Stack, Heap and Data Segment sections are used in program memory and how those sections relate to compile-time or run-time memory allocation.
  </summary>
  
---
* **Stack** <br>Used at run time to track the program as it's running. Each time a function is called a 'stack frame' gets added to the stack which contains all the automatic/temporary variables and other information relating to that instance of the function being called. Stack frames must at minimum contain a return address denoting where the program should return to once the frame is fulfilled.
* **Heap** <br>Used for dynamic memory allocation in run-time. Memory in the Heap is managed through the use of <span style="font-family:monospace">malloc</span>, <span style="font-family:monospace">realloc</span>, <span style="font-family:monospace">calloc</span>, and <span style="font-family:monospace">free</span>.
* **Data Segment** <br>Stores the values for all global variables and static variables. Split into 2 segments: "initialized" for variables that are declared with specific starting values, and "uninitialized" for variables that don't have specified starting values.

---

</details>
<br>
<details style="color:brown">
  <summary style="color:black">
  <b>(c) [6 Marks]</b> Explain the difference between Java Class objects and C Structure variables.
  </summary>
  
---
C Structures are only a collection of different data types, whilst Java Class objects can also have associated methods, can have various restrictions for variable and method access (eg "private", "protected"), and can utilise inheritance.<br>
Java also creates class objects as references, whilst C creates Structures as values. (You would use pointers to structs in C to create the same effect of references.)

---

</details>
<br>
<details style="color:brown">
  <summary style="color:black">
  <b>(d) [4 Marks]</b> Discuss pass-by-value and pass-by-reference in C and Java.
  </summary>
  
---
Java manipulates objects by reference, where all object variables are references. However for method arguments they're passed by value, or more specifically it passes the value of the reference, not the reference itself or the object/value it's pointing to. This means it creates a new, independent, reference to the same object/values as what's passed in.<br><br>
C is strictly pass-by-value. If you with to pass a reference into a function then you would pass a pointer, and dereference that pointer to get the value it's pointing to.<br>
*Note: That pointer is still passed into to the function by value (the location it's pointing at).*

---

</details>
<br><br>

---
## Question 2. Arrays, Pointers and File Handling [20 Marks]
<details style="color:brown">
  <summary style="color:black">
  <b>(a) [2 Marks]</b> Write a <span style="font-family:monospace">scanf</span> statement that takes all characters except the new-line character.
  </summary>
  
---
```c
scanf("%[^\n]", str); //reads it into str
```

---

</details>
<br>
<b>(b) [4 Marks]</b> Give a declaration for the variable <span style="font-family:monospace">p</span> in each of the following cases.
<details style="color:brown">
  <summary style="color:black">
  <span style="font-family:monospace">p</span> is a pointer to an element of a string.
  </summary>
  
---
```c
char *p;
```

---

</details>
<details style="color:brown">
  <summary style="color:black">
  <span style="font-family:monospace">p</span> is an array of <span style="font-family:monospace">n</span> pointers to <span style="font-family:monospace">char</span>.
  </summary>
  
---
```c
char *p[n];
```

---

</details>
<details style="color:brown">
  <summary style="color:black">
  <span style="font-family:monospace">p</span> is a function that takes no arguments and returns a pointer to <span style="font-family:monospace">int</span>.
  </summary>
  
---
```c
int *p();
```

---

</details>
<details style="color:brown">
  <summary style="color:black">
  <span style="font-family:monospace">p</span> is a pointer to a function that takes two arguments: a pointer to <span style="font-family:monospace">int</span> and a pointer to a pointer to <span style="font-family:monospace">int</span> and returns a pointer to an array of <span style="font-family:monospace">n</span> pointers to <span style="font-family:monospace">char</span>.
  </summary>
  
---
```c
char **p(int* a, int** b);
```

---

</details>
<br>
<details style="color:brown">
  <summary style="color:black">
  <b>(c) [8 Marks]</b> Consider the following code:<br>
  <span style="font-family:monospace">
    char *a[] = {"AAA", "BBB", "CCC"};<br>
    // <b>for you to complete - n</b> is the number of elements in <b>a</b><br>
    int n = ...;<br>
    // <b>for you to complete -</b> declare <b>ptr</b><br>
    ...<br>
    ptr = &a;<br>
    printStr(ptr,n);<br>
  </span>
  Define the <span style="font-family:monospace">int</span> variable <span style="font-family:monospace">n</span>, declare variable <span style="font-family:monospace">ptr</span>, and implement function <span style="font-family:monospace">printStr</span> so that <span style="font-family:monospace">printStr(ptr,n)</span> prints out the three strings in the following format:<br>
  <span style="font-family:monospace">AAA<br>BBB<br>CCC</span>
  </summary>
  
---
```c
void printStr(char **ptr, int n) {
  for (int i = 0; i < n; ++i) {
    printf("%s\n", *ptr);
    ptr++;
  }
}

int n = sizeof(a)/sizeof(a[0]);
char **ptr;
```

---

</details>
<br>
<details style="color:brown">
  <summary style="color:black">
  <b>(d) [6 Marks]</b> Write a command-line-arguments based program. The program will be called with two file names as it's command line arguments. The program should read the characters from the first file, delete any character which is an odd number (1, 3, 5, 7, 9), and then write it to the second file. You <b>must use pointer notation</b> to implement this program.
  </summary>
  
---
```c
#include <stdio.h>

int main(int argc, char *argv[]) {
	if (argc != 3) return 1;

	FILE *f1 = fopen(*(argv+1), "r");
	if (f1 == NULL) return 1;

	FILE *f2 = fopen(*(argv+2), "w");
	if (f2 == NULL) return 1;

	while (1) {
		char c = getc(f1);
		if (feof(f1)) break;
		if (c<'9'+1 && c>'0' && (c-'0')%2 == 1) continue;
		putc(c, f2);
	}

	fclose(f1);
	fclose(f2);
    return 0;
}
```

---

</details>
<br><br>
  
---
## Question 3. Bitwise Operators and Data Structures [20 Marks]
<details style="color:brown">
  <summary style="color:black">
  <b>(a) [10 Marks]</b> In the following, we have defined a structure type named <span style="font-family:monospace">charNode</span>:<br>
  <span style="font-family:monospace;line-height:0">
    #define node_size sizeof(charNode)<br>
    typedef struct charNode charNode;<br>
    typedef charNode *ptr_charNode;<br><br>
    struct charNode {<br>
    &nbsp;&nbsp;char data;<br>
    &nbsp;&nbsp;ptr_charNode next;<br>
    };<br><br>
  </span>
  Write a function with prototype <span style="font-family:monospace">ptr_charNode charList(char *)</span>, which creates a <span style="font-family:monospace">charNode</span> for each character in a string and links the nodes in sequence, and returns a pointer to the first node of the resulting list.
  </summary>
  
---
```c
ptr_charNode charList(char *str) {
	if (str[0] == '\0') return NULL;

	ptr_charNode head = malloc(node_size);

	ptr_charNode tail = head;
	tail->data = str[0];

	int i = 1;
	while (str[i] != '\0') {
		tail->next = malloc(node_size);
		tail = tail->next;
		tail->data = str[i];
		i++;
	}
	tail->next = NULL;

	return head;
}
```

---

</details>
<br>
<details style="color:brown">
  <summary style="color:black">
  <b>(b) [10 Marks]</b> See the program below.<br>
  <span style="font-family:monospace;line-height:0">
    int main(void)<br>
    {<br>
    &nbsp;&nbsp;int age[] = {8, 2, 6, ..., 12, 15, 11};<br>
    &nbsp;&nbsp;...<br>
    &nbsp;&nbsp;int *ageInt = calloc(m, sizeof(int));<br>
    &nbsp;&nbsp;...<br>
    &nbsp;&nbsp;return 0;<br>
    }<br><br>
  </span>
  In the box below, complete this program. Assume that the ages in the array <span style="font-family:monospace">age</span> are between 0 - 15. Pack all the ages into the memory space allocated to <b style="font-family:monospace">ageInt</b>. You need to minimise the memory space required for packing, that is, you need to minimise the value of <b style="font-family:monospace">m</b>. The ages need to be packed in order from high-order bits to low-order bits in the memory space. Assume that you are working on a 32-bit machine where the <b style="font-family:monospace">sizeof(int)</b> is <b>4 bytes</b>.
  </summary>
  
---
```c
int main(void) {
	int age[] = {8, 2, 6, ..., 12, 15, 11};
	int numAges = sizeof(age)/sizeof(int);
	int m = numAges/8 + (numAges%8? 1:0);

	int* ageInt = calloc(m, sizeof(int));

	for (int i = 0, count = 0; i < m; ++i) {
		for (int j = 0; j < 8 && count++ < numAges; ++j) {
			ageInt[i] += (age[(i*8)+j] & 0xFF) << (28-(j*4));
		}
	}
	return 0;
}
```

---
</details><br>
<b>Note:</b> "we didn't talk about packing so I can't give you this kind of 
question" - Alvin
<br><br>
  
---
## Question 4. Python Fundamentals  [20 Marks]
<div></div>
<b>a) [5 Marks]</b> Some of the following strings are legal Python identifiers and some are not. For each one state if the name is legal and if not, explain why:
<details style="color:brown">
  <summary style="color:black">
  <span style="font-family:monospace">i) total_time</span>
  </summary>
  
---
Legal

---

</details>
<details style="color:brown">
  <summary style="color:black">
  <span style="font-family:monospace">ii) pass</span>
  </summary>
  
---
Not legal; `pass` is a reserved keyword

---

</details>
<details style="color:brown">
  <summary style="color:black">
  <span style="font-family:monospace">iii) 2nd_day</span>
  </summary>
  
---
Not legal; identifiers cannot start with a number

---

</details>
<details style="color:brown">
  <summary style="color:black">
  <span style="font-family:monospace">iv) numberOfVisits</span>
  </summary>
  
---
Legal

---

</details>
<details style="color:brown">
  <summary style="color:black">
  <span style="font-family:monospace">v) user-count</span>
  </summary>
  
---
Not legal; identifiers cannot contain `-` as it is an operator

---

</details>
<br>
<b>b) [5 Marks]</b> Consider the following python code:<br>
<span style="font-family:monospace;line-height:0">
  #!/usr/bin/env python3<br><br>
  firstList = [5, 15, 2, 22]<br>
  firstList.sort()<br>
  firstList.append(20)<br>
  secondList = firstList[2:]<br>
</span><br>
What would the output be from the following python commands?<br>
<details style="color:brown">
  <summary style="color:black">
  <span style="font-family:monospace">i) print(firstList)</span>
  </summary>
  
---
<span style="font-family:monospace">[2, 5, 15, 22, 20]</span>

---

</details>
<details style="color:brown">
  <summary style="color:black">
  <span style="font-family:monospace">ii) print(len(secondList))</span>
  </summary>
  
---
<span style="font-family:monospace">3</span>

---

</details>
<details style="color:brown">
  <summary style="color:black">
  <span style="font-family:monospace">iii) print(firstList == secondList)</span>
  </summary>
  
---
<span style="font-family:monospace">False</span>

---

</details>
<details style="color:brown">
  <summary style="color:black">
  <span style="font-family:monospace">iv) print(firstList[-1])</span>
  </summary>
  
---
<span style="font-family:monospace">20</span>

---

</details>
<details style="color:brown">
  <summary style="color:black">
  <span style="font-family:monospace">v) print(firstList + secondList)</span>
  </summary>
  
---
<span style="font-family:monospace">[2, 5, 15, 22, 20, 15, 22, 20]</span>

---

</details>
<br>
<b>c) [10 Marks]</b> For each of the following Python keywords, briefly explain what it does and write a short piece of code to illustrate its use.
<details style="color:brown">
  <summary style="color:black">
  <span style="font-family:monospace">i) elif</span>
  </summary>
  
---
"elif" is short for "else if". It is used at the end of an if statement to provide other conditional blocks which be executed if (and only if) previous conditions are not true. Zero or more `elif` parts can be used, optionally followed by an `else`.
```python
x = int(input("Enter a number: "))
if x < 0:
  print("x is less than 0")
elif x == 0:
  print("x is 0")
else:
  print("x is greater than 0")
```

---

</details>
<details style="color:brown">
  <summary style="color:black">
  <span style="font-family:monospace">ii) with</span>
  </summary>
  
---
Binds the return value of the method of the object to the specified target(s) of `as` (if any). It also calls the `__exit__` method on the object at the termination of the loop, and passes in the conditions for termination (I.E. an exception that was raised).
```python
with open('file.txt', 'r') as file:
  print(file.read()) #prints out the contents of file.txt
```

---

</details>
<br><br>
  
---
## Question 5. Writing and Reading Python Programs [20 Marks]
<details style="color:brown">
  <summary style="color:black">
  <b>a) [10 Marks]</b> Write a python program that reads two strings as parameters on the command line and prints out the longer of the two. If they are the same length, print both. For example, it might be called by:<br>
  <span style="font-family:monospace;line-height:4">
    $python3 longeststring.py first second<br>
  </span>
  Your program should check the parameters and issue appropriate error messages and return values.
  </summary>
  
---
```python
import sys

def main():
	if (len(sys.argv) != 3):
		print("Incorrect number of arguments")
		return
	if (len(sys.argv[1]) >= len(sys.argv[2])):
		print(sys.argv[1])
	if (len(sys.argv[1]) <= len(sys.argv[2])):
		print(sys.argv[2])

if __name__ == "__main__":
	main()
```

---

</details>
<br>
<b>b) [10 Marks]</b> Consider the following python program which retrieves earthquake data from the geonet website for various periods of time. You are to add 10 suitable comments (one comment for each of the marking boxes) to the following code explaining the functionality.<br><br>
<b style="line-height:2.5">Additional information</b><br>
Data returned from the <span style="font-family:monospace">fp.read()</span> statement in the code is a sequence of bytes that are encoded in the UTF-8 character set. The returned data is a well-formed series of Comma Separated Values (CSV). Each line in the CSV refers to a detected earthquake. The 9<sup>th</sup> value of each line is the magnitude of the earthquake.<br><br>
<span style="font-family:monospace;line-height:0">
  #!/usr/bin/env python3<br><br>
  import sys, os<br>
  import datetime<br>
  import urllib.request<br><br>
  months = ['January', 'February', 'March', 'April', 'May', 'June', 'July', 'August', 'September', 'October', 'November', 'December']<br><br>
  urlbase = "http://wfs.geonet.org.nz/geonet/ows?output=csv&"<br>
</span><br>

---
<details style="color:brown">
  <summary style="color:black">
    <span style="font-family:monospace"># (1)</span>
  </summary>
  <span style="font-family:monospace">&nbsp;&nbsp;# Get the current year</span>
</details>
<span style="font-family:monospace">&nbsp;&nbsp;thisyear = datetime.datetime.now().year</span>

---
<span style="font-family:monospace">
  earthquakes = {}<br>
  for month in months:
</span><br><br>

---
<details style="color:brown">
  <summary style="color:black">
    <span style="font-family:monospace">&nbsp;&nbsp;# (2)</span>
  </summary>
  <span style="font-family:monospace">
  &nbsp;&nbsp;&nbsp;&nbsp;# Set start date to first day of month<br>
  &nbsp;&nbsp;&nbsp;&nbsp;# Set end date to 30 days after start date
  </span>
</details>
<span style="font-family:monospace">
  &nbsp;&nbsp;&nbsp;&nbsp;start_date = datetime.datetime.strptime('%s-%s' % (thisyear, month), '%Y-%B')<br>
  &nbsp;&nbsp;&nbsp;&nbsp;end_date = start_date + datetime.datetime.timedelta(days=30)
</span>
<br>

---
---
<details style="color:brown">
  <summary style="color:black">
    <span style="font-family:monospace">&nbsp;&nbsp;# (3)</span>
  </summary>
  <span style="font-family:monospace">&nbsp;&nbsp;&nbsp;&nbsp;# Construct URL from base and start/end dates for month</span>
</details>
<span style="font-family:monospace">
  &nbsp;&nbsp;&nbsp;&nbsp;url = urlbase + 'from=' + start_date.strftime("'%Y-%m-%d'") + '&to=' + end_date.strftime("'%Y-%m-%d'")
</span>
<br>

---
---
<details style="color:brown">
  <summary style="color:black">
    <span style="font-family:monospace">&nbsp;&nbsp;# (4)</span>
  </summary>
  <span style="font-family:monospace">&nbsp;&nbsp;&nbsp;&nbsp;# Get the CSV file from the constructed URL and read it in</span>
</details>
<span style="font-family:monospace">
  &nbsp;&nbsp;&nbsp;&nbsp;try:<br>
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;fp = urllib.request.urlopen(url)<br>
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;mybytes = fp.read()<br>
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;fp.close()<br>
  &nbsp;&nbsp;&nbsp;&nbsp;except:<br>
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;break<br>
</span>
<br>

---
<span style="font-family:monospace">
  end_date = start_date + datetime.timedelta(days=30)
</span><br><br>

---
<details style="color:brown">
  <summary style="color:black">
    <span style="font-family:monospace">&nbsp;&nbsp;# (5)</span>
  </summary>
  <span style="font-family:monospace">&nbsp;&nbsp;&nbsp;&nbsp;# Decode UTF-8 bytes from CSV file and convert to a string</span>
</details>
<span style="font-family:monospace">&nbsp;&nbsp;&nbsp;&nbsp;mycsv = str(mybytes.decode('utf-8'))</span>

---
<span style="font-family:monospace">
  &nbsp;&nbsp;&nbsp;&nbsp;events = []
</span><br><br>

---
<details style="color:brown">
  <summary style="color:black">
    <span style="font-family:monospace">&nbsp;&nbsp;# (6)</span>
  </summary>
  <span style="font-family:monospace">&nbsp;&nbsp;&nbsp;&nbsp;# Split the CSV into lines</span>
</details>
<span style="font-family:monospace">
  &nbsp;&nbsp;&nbsp;&nbsp;lines = mycsv.split('\n')<br>
  &nbsp;&nbsp;&nbsp;&nbsp;for line in lines:
</span>

---
<span style="font-family:monospace">
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;try:
</span><br><br>

---
<details style="color:brown">
  <summary style="color:black">
    <span style="font-family:monospace">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# (7)</span>
  </summary>
  <span style="font-family:monospace">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# Split each line by "," and add the magnitude to events</span>
</details>
<span style="font-family:monospace">
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;values = line.split(',')<br>
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;magnitude = float(values[8])<br>
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;events.append(magnitude)
</span>

---
<span style="font-family:monospace">
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;except:<br>
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;pass
</span><br><br>

---
<details style="color:brown">
  <summary style="color:black">
    <span style="font-family:monospace">&nbsp;&nbsp;# (8)</span>
  </summary>
  <span style="font-family:monospace">&nbsp;&nbsp;&nbsp;&nbsp;# Sort list of events, decending</span>
</details>
<span style="font-family:monospace">
  &nbsp;&nbsp;&nbsp;&nbsp;sorted_events = sorted(events, reverse=True)
</span>

---
---
<details style="color:brown">
  <summary style="color:black">
    <span style="font-family:monospace">&nbsp;&nbsp;# (9)</span>
  </summary>
  <span style="font-family:monospace">&nbsp;&nbsp;&nbsp;&nbsp;# Collate results and add them to earthquakes</span>
</details>
<span style="font-family:monospace">
  &nbsp;&nbsp;&nbsp;&nbsp;try:<br>
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;results = {month: {'max' : sorted_events[0], 'avg' : sum(sorted_events)/len(sorted_events)}}<br>
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;earthquakes.update(results)<br>
  &nbsp;&nbsp;&nbsp;&nbsp;except:<br>
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;break
</span>

---
---
<details style="color:brown">
  <summary style="color:black">
    <span style="font-family:monospace"># (10)</span>
  </summary>
  <span style="font-family:monospace">&nbsp;&nbsp;# Print each month with the results collected for it</span>
</details>
<span style="font-family:monospace">
  &nbsp;&nbsp;for month, results in earthquakes.items():<br>
  &nbsp;&nbsp;&nbsp;&nbsp;print(month + " " + repr(results))
</span>

---
