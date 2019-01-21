real_output = open("./real_output.txt", 'r')
output = open("./output.txt", 'r')

for i in range(6):
    real_val = int(real_output.readline())
    val = int(output.readline())

    if real_val == val:
        print("CORRECT")

    else:
        print("WRONG - Real: %d, Test: %d" % (real_val,val))

