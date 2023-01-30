from random import randint

def gen_stack(n, start = 1, end = 20):
    l = []
    while len(l) < n :
        r = randint (start, end)
        if r not in l :
            l.append(r)
    return l

def show_stacks(l1 = [], l2 = [], l3 = []):
    l = []
    diff1 = abs(len(l1) - len(l3))
    diff2 = abs(len(l2) - len(l3))
    L1 = list(l1)
    L2 = list(l2)
    c1 = ['' for i in range(diff1)]
    c2 = ['' for i in range(diff2)]
    L1 = list(c1 + l1)
    L2 = list(c2 + l2)
    for k,j in zip(L1 + ['A'],L2 + ['B']):
            print(k, end = '') ; print('     ', end ='') ; print(j)

def swap(l):
    if len(l) > 1 :
        temp = l[0]
        l[0] = l[1]
        l[1] = temp
    return l

def push(l1, l2):
    l2 = list(l2)
    if len(l1) > 0 :
        push = l1[0]
        del l1[0]
        l2 = list([push] + l2)
    return l1, l2

def rotate(l):
    if len(l) > 0 :
        top = l[0]
        del l[0]
        l += [top]
    return l

def reverserotate(l):
    if len(l) > 0 :
        bottom = l[len(l) - 1]
        del l[len(l) - 1]
        l = [bottom] + l
    return l

def cancel(instruction, A, B):
    if instruction == 'sa' :
        return swap(A), B
    elif instruction == 'sb' :
        return A, swap(B)
    elif instruction == 'ss' :
        return swap(A), swap(B)
    elif instruction == 'ra' :
        return reverserotate(A), B
    elif instruction == 'rb' :
        return A, reverserotate(B)
    elif instruction == 'rr' :
        return reverserotate(A), reverserotate(B)
    elif instruction == 'pa' :
        return push(A, B)
    elif instruction == 'pb' :
        return push(B, A)
    elif instruction == 'rra' :
        return rotate(A), B
    elif instruction == 'rrb' :
        return A, rotate(B)
    elif instruction == 'rrr' :
        return rotate(A), rotate(B)

specimen = [152, 251, 474, 392, 253, 132, 500, 139, 344, 420, 26, 331, 398, 146, 16, 399, 221, 374, 437, 179, 233, 355, 267, 458, 190, 372, 346, 169, 482, 339]

s15 = [13, 8, 4, 0, 2, 14, 10, 5, 3, 9, 7, 6, 11, 1, 12]

s10 = [9, 4, 8, 5, 1, 3, 2, 7, 6, 0]
#37

def manual(A=specimen):
    S = list(A)
    S.sort()
    B = []
    c = 0
    l = []
    show_stacks(A,B,S)
    while(True):
        instruction = input("Saisir l'instruction : ")
        if instruction == 'sa' :
            swap(A)
        elif instruction == 'sb' :
            swap(B)
        elif instruction == 'ss' :
            swap(A) ; swap(B)
        elif instruction == 'ra' :
            rotate(A)
        elif instruction == 'rb' :
            rotate(B)
        elif instruction == 'rr' :
            rotate(A) ; rotate(B)
        elif instruction == 'pa' :
            A = push(B, A)[1]
        elif instruction == 'pb' :
            B = push(A, B)[1]
        elif instruction == 'rra' :
            A = reverserotate(A)
        elif instruction == 'rrb' :
            B = reverserotate(B)
        elif instruction == 'rrr' :
            A = reverserotate(A) ; B = reverserotate(B)
        elif instruction == 'stop' :
            break
        elif instruction == 'cancel' :
            if c > 0 :
                c -= 2
                A,B = cancel(old, A, B)
                del l[len(l) - 1]
            else :
                print("Nothing to cancel")
                continue
        else :
            print("Invalid instruction !")
            if c >= 0 :
                c -= 1
        c += 1
        #print(A)
        #print(B)
        #print(S)
        show_stacks(A,B,S)
        l.append(instruction)
        if c > 0 :
            old = l[len(l) - 1]
    show_stacks(A,B,S)
    alpha = list(A)
    A.sort()
    if (alpha == A) :
        print("Stack sorted !")
    print(c)
    print(l)
    
        
a = gen_stack(7)
b = gen_stack(1)
s = list(a)
s.sort()


            
"""
def show_stacks2(l1, l2):
    diff = abs(len(l1) - len(l2))
    c = -1
    if len(l1) > len(l2) :
        for k in range(len(l1)) :
            c += 1
            if c >= diff :
                print(l1[k], end='')
                print(' ', end = '')
                print(l2[c - diff])
            else :
                print(l1[k])
    elif len(l1) == len(l2) :
        for k,j in zip(l1,l2):
            print(k, j)
    else :
        for k in range(len(l2)) :
            c += 1
            print(l2[k])
            if c >= diff :
                print(' ')
                print(l1[c - diff])
"""
