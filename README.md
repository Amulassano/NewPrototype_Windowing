# Windowing Function
Function based on SECRET Multi-Buffer behaviour, in which the buffer is an Hash table.
## Hash Table
### Structure
It's a dynamic table based on a given dimension that can be selected by the programmer and it's a constant that never changes.<br>
Inside the table every row is a dynamic vector in which there is a key, that is a window [ openign, closure ), and the content; the content is a dynamic vector that owns a tuble in which there is the element and his timestamp.
### How does it work?
Every row of the table is accessible via an indicator computed by scope function, in which thanks to the timestamp we can know 
the exactly position of the first window that owns the timestamp given:<br><br>
        `l = (int)ceil((double)(ts-c)/(double)slide);`<br><br> where: <ul> <li> l: position in the table</li> <li> ts: timestamp</li> <li> c: very first closure computed </li> <li> slide: slide of the window </li>
        </ul><br>
The windows are put in the table in a sequetial way: the very first row will have the first avaiable window and so on.<br>
The maximum number of windows that can coexist at the same moment is given by the dimension of the table.<br>
When a window is put in the last row of the table, the next one will be put as first of the table contiguously; we have two indicators that help us: 
<ul><li>M: it indicates the position of the first row in tha table with an active window</li>
<li>N: it indicates the position of the next row in the table where to put in the window </li></ul><br>
Both of the values will start form zero once reached the maximum size of the table.
