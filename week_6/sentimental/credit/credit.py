from cs50 import get_int

ccn = get_int("Number: ")
ccn1 = ccn
ccn3 = ccn
fsum = 0
product = 0
while (ccn > 0):
    fsum += ccn % 10
    ccn = ccn // 10
    product = (ccn % 10) * 2
    if (product > 9):
        fsum = product % 10 + fsum
        product = product // 10
        fsum = product + fsum
    else:
        fsum = product + fsum
    ccn = ccn // 10

l = len(str(ccn1))

while (ccn3 > 65):
    ccn3 = ccn3 // 10

    # Figure out type of card using its length and also its starting numbers. Check if it's real by seeing if it satisfies the checksum
if ((l == 15 and fsum % 10 == 0) and (ccn3 == 34 or ccn3 == 37)):
    print("AMEX")
elif ((l == 16 and fsum % 10 == 0) and (ccn3 == 51 or ccn3 == 52 or ccn3 == 53 or ccn3 == 54 or ccn3 == 55)):
    print("MASTERCARD")
elif (((l == 13 or l == 16) and fsum % 10 == 0) and (ccn3 // 10 == 4)):
    print("VISA")
else:
    print("INVALID")