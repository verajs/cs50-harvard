while True:
    # Store height between 0 and 8 in variable
    try:
        h = int(input("Height: "))
    except ValueError:
        print("That's not an integer!")
    else:
        if h > 0 and h <= 8:
            break
# Master loop
for i in range(h):
    # Print spaces dynamically
    for s in range(h - i - 1):
        print(" ", end="")
    # Print blocks
    for j in range(i + 1):
        print("#", end="")
    # Add space between both pyramids
    print("  ", end="")
    # Print second row of blocks
    for p in range(i + 1):
        print("#", end="")
    # Print a space after every row
    print()