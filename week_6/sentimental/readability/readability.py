from cs50 import get_string

# Define dictionary inside a list
abc = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
       'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']

cba = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
       'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']

sen = ['.', '!', '?']

# Get input from user
text = get_string("Text: ")

# Initializing variables
words = 1
letters = 0
sentences = 0

# Counting words
for i in range(0, len(text)):
    if text[i] == " ":
        words += 1

# Counting letters
for c in text:
    if c in abc:
        letters += 1

# Counting sentences
for s in text:
    if s in sen:
        sentences += 1

# Counting letters in caps
for m in text:
    if m in cba:
        letters += 1

# Using the algorithm
laverage = (letters / words) * 100
saverage = (sentences / words) * 100
index = 0.0588 * laverage - 0.296 * saverage - 15.8

# Printing grade level according to the algorithm
if index >= 16:
    print("Grade 16+")
elif index < 1:
    print("Before Grade 1")
else:
    print(f"Grade {round(index)}")

