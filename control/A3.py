import sys

A = input()
B = input()

if len(B) < len(A):
    B += B[-1] * (len(A) - len(B))

for line in sys.stdin:
    new_line = []
    for c in line:
        for i in range(len(A) - 1, -1, -1):
            if A[i] == c:
                new_line.append(B[i])
                break
        else:
            new_line.append(c)
    sys.stdout.write(''.join(new_line))
