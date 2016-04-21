Enter No.of productions:3
Enter no.of states:
10
Enter no.of terminals:
3
Enter no.of non-terminals:
3
Enter no.of terminals in i/p string:
4
Enter the i/p string:
c
c
d
d

 parsing

ccdd$	shift s3
cdd$	shift s3
dd$	shift s4
d$	reduce r3
d$	reduce r2
d$	reduce r2
d$	shift s7
$	reduce r3
$	reduce r1
string accepted
