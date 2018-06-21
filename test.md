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
<br>
