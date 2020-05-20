#t y []  {}
from itertools import combinations

#"n" is the bit length of "x" and "u" vector
n=4

#define the input multiset "X"
X=['0000','0001','0010','0011','0100','0101','0110','0111','1000','1001','1010','1011','1100','1101','1110','1111',
'0000','0000','0000','0001','0010','0011','0100','0101','0110','0111']  
#X=['0000','0011','0011','0011','0101','0110','1000','1011','1101','1110']
#this fuction calculates the value xi^ui
def xi_ui(xi,ui):
    if xi=='0' and ui=='0':
        return 1
    elif xi=='1' and ui=='0':
        return 1
    elif xi=='1' and ui=='1':
        return 1
    elif xi=='0' and ui=='1':
        return 0


#this function is when all bits of X are selected 
#the first example table in division property paper
def pi_u_all(x,u):
    r=1
    for i in range(n):
        r=r*xi_ui(x[i],u[i])
    return r

selected_bits_in_x = 4

indexes=[i for i in range(n)]
comb=combinations(indexes,selected_bits_in_x)

#the following function is used when p, (p<n) number of bits are used of x vector of the Multiset
def pi_u_sel_bits(x,u,sel_bits):
    r=1
    for i in sel_bits:
        r=r*xi_ui(x[i],u[i])
    return r

for selected_bits in comb:
    print "selected combination is",
    print selected_bits
    for u_dec in range(2**n):
        sum=0
        u_bin='{0:04b}'.format(u_dec)
        print '%d :  '%u_bin.count('1'),
        for x in X:
            val=pi_u_sel_bits(x,u_bin,selected_bits)
            sum=sum+val
            print val,
        print '---> %d \n'%(sum),
