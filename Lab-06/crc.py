def xor(a, b):

    result = []

    for i in range(1, len(b)):
        if a[i] == b[i]:
            result.append('0')
        else:
            result.append('1')

    return ''.join(result)


def mod2div(dividend, divisor):
    pick = len(divisor)

    tmp = dividend[0: pick]

    while pick < len(dividend):

        if tmp[0] == '1':

            tmp = xor(divisor, tmp) + dividend[pick]

        else:
            tmp = xor('0' * pick, tmp) + dividend[pick]

        pick += 1

    if tmp[0] == '1':
        tmp = xor(divisor, tmp)
    else:
        tmp = xor('0' * pick, tmp)

    checkword = tmp
    return checkword


def encodeData(data, key):
    l_key = len(key)

    appended_data = data + '0' * (l_key - 1)
    remainder = mod2div(appended_data, key)
    print("modified data: "+str(appended_data))

    codeword = data + remainder
    return codeword


def decodeData(code, key):
    remainder = mod2div(code, key)
    return remainder


data = "1011101"
print("Dataword: "+str(data))

key = "10001000000100001"
print("Generating Polynomial: "+key)
codeword = encodeData(data, key)
print("Transmitted Codeword: "+str(codeword))
code = input("Enter Transmitted Codeword: ")
recieved_data = int(decodeData(code, key))
if recieved_data == 0:
    print("NO ERROR! SUCCESSFUL TRANSMISSION, Received Frame is Correct")
else:
    print("ERROR HAS OCCURRED.")
