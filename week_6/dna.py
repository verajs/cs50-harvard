import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit("Usage python dna.py data.csv sequence.txt")

    STRs = []
    profiles = []
    # TODO: Read database file into a variable
    filename = sys.argv[1]
    with open(filename) as file:
        reader = csv.DictReader(file)
        # Populate list of STRs, by using 1: you get the second to last fieldname in the csv file
        STRs = reader.fieldnames[1:]
        # Add person to profiles
        for row in reader:
            profiles.append(row)

    # TODO: Read DNA sequence file into a variable

    # Initialize a dictionary that uses STRS
    strcount = dict.fromkeys(STRs, 0)
    namefile = sys.argv[2]
    with open(namefile) as file1:
        sequence = file1.readline()

    # TODO: Find longest match of each STR in DNA sequence
    for STR in STRs:
        strcount[STR] = longest_match(sequence, STR)

    # TODO: Check database for matching profiles
    for profile in profiles:
        matches = 0
        for STR in STRs:
            if int(profile[STR]) == strcount[STR]:
                matches += 1
            elif int(profile[STR]) != strcount[STR]:
                continue

            if matches == len(STRs):
                print(profile['name'])
                return

    print("No match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
