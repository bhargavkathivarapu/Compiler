
Enter No.of productions:6
Enter no.of states:
12
Enter no.of terminals:
6
Enter no.of non-terminals:
3
Enter no.of terminals in i/p string:5
Enter the i/p string:
id
+
id
*
id


 parsing

id+id*id$	shift s5
+id*id$	reduce r6
+id*id$	reduce r4
+id*id$	reduce r2
+id*id$	shift s6
id*id$	shift s5
*id$	reduce r6
*id$	reduce r4
*id$	shift s7
id$	shift s5
$	reduce r6
$	reduce r3
$	reduce r1
string accepted
