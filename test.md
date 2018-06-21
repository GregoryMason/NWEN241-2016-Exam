## Question 1. C General Questions [20 Marks]
<details style="color:brown">
  <summary style="color:black">
  <b>(a) [4 Marks]</b> Explain the four steps of compilation for C programs.
  </summary>
  
---
---

</details>
<br>
<details style="color:brown">
  <summary style="color:black">
  <b>(b) [6 Marks]</b> Explain how the Stack, Heap and Data Segment sections are used in program memory and how those sections relate to compile-time or run-time memory allocation.
  </summary>
  
---
---

</details>
<br>
<details style="color:brown">
  <summary style="color:black">
  <b>(c) [6 Marks]</b> Explain the difference between Java Class objects and C Structure variables.
  </summary>
  
---
---

</details>
<br>
<details style="color:brown">
  <summary style="color:black">
  <b>(d) [4 Marks]</b> Discuss pass-by-value and pass-by-reference in C and Java.
  </summary>
  
---
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
---

</details>
<br>
<b>(b) [4 Marks]</b> Give a declaration for the variable <span style="font-family:monospace">p</span> in each of the following cases.
<details style="color:brown">
  <summary style="color:black">
  <span style="font-family:monospace">p</span> is a pointer to an element of a string.
  </summary>
  
---
---

</details>
<details style="color:brown">
  <summary style="color:black">
  <span style="font-family:monospace">p</span> is an array of <span style="font-family:monospace">n</span> pointers to <span style="font-family:monospace">char</span>.
  </summary>
  
---
---

</details>
<details style="color:brown">
  <summary style="color:black">
  <span style="font-family:monospace">p</span> is a function that takes no arguments and returns a pointer to <span style="font-family:monospace">int</span>.
  </summary>
  
---
---

</details>
<details style="color:brown">
  <summary style="color:black">
  <span style="font-family:monospace">p</span> is a pointer to a function that takes two arguments: a pointer to <span style="font-family:monospace">int</span> and a pointer to a pointer to <span style="font-family:monospace">int</span> and returns a pointer to an array of <span style="font-family:monospace">n</span> pointers to <span style="font-family:monospace">char</span>.
  </summary>
  
---
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
---

</details>
<br>
<details style="color:brown">
  <summary style="color:black">
  <b>(d) [6 Marks]</b> Write a command-line-arguments based program. The program will be called with two file names as it's command line arguments. The program should read the characters from the first file, delete any character which is an odd number (1, 3, 5, 7, 9), and then write it to the second file. You <b>must use pointer notation</b> to implement this program.
  </summary>
  
---
---

</details>
<br><br>
  
---
Question 3. Bitwise Operators and Data Structures [20 Marks]
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
---

</details>
<br>
