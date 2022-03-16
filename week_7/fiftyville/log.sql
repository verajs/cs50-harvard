-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Crime scene report
SELECT description
FROM crime_scene_reports
WHERE month = 7 and day = 28
AND street = "Humphrey Street";
-- You'll want to check the interviews from the three witnesses, robbery took place at 10:15 am in the bakery and see where they coincide.
-- The same day, littering took place at 16:36, with no known witnesses.

-- According to Emma, the bakery owner; the thief came whispering into a phone for half an hour, but they never bought anything.
-- You might want to check the credit card purchases that day.
SELECT transcript
FROM interviews
WHERE month = 7 and day = 28
AND name = "Emma";

-- As the thief left the bakery, he called somebody else (maybe?). The thief planned to take the EARLIEST flight out of fiftyville the next day, he asked the person to purchase the ticket the day of the robbery.
SELECT transcript
FROM interviews
WHERE month = 7 and day = 28
AND name = "Raymond";

-- The thief went to the ATM on Leggett Street in the morning (before 10 am) and the thief was withdrawing money
SELECT transcript
FROM interviews
WHERE month = 7 and day = 28
AND name = "Eugene";

-- Check who withdrew money that morning
SELECT *
FROM atm_transactions
WHERE year = "2021"
AND month = "7"
AND day = "28"
AND atm_location = "Leggett Street"

-- List of people who withdrew from the ATM on Leggett Street that same day.
-- Luca, Kenny, Taylor(not), Bruce, Brooke, Kaelyn(not), Iman, Benista, Diana(not)
SELECT name
FROM people, bank_accounts
WHERE person_id = id
AND account_number = -- Any of the people who withdrew money that morning

-- Check the people who went out of Fiftyville the very next day
SELECT *
FROM flights
WHERE year = 2021
AND month = 7
AND day = 29

-- In the morning there were two flights, number 36 and 43, let's check the passagers inside them to see if one of them matches our ATM list
SELECT *
FROM flights
WHERE flight_id = 36

-- Kenny, Luca, Taylor and Bruce were in flight 36 hmmm
SELECT name
FROM people
WHERE passport_number IN (SELECT passport_number FROM passengers WHERE flight_id = 36);

-- Our list of suspects boils down to: Kenny, Luca, Taylor and Bruce, they went to New York City, so the thief for sure escaped there.
SELECT city
FROM airports
WHERE id = 4

-- Let's check who called that day
SELECT *
FROM phone_calls
WHERE year = 2021
AND month = 7
AND day = 28
AND caller = (367) 555-5533

-- Bruce, one of our suspects had a phone call that very same day that lasted for about what Emma said the thief was on the phone, he called a guy named Robin
SELECT name
FROM people
WHERE phone_number IN (SELECT receiver FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration = 75);

-- Let's check the bakery security logs
SELECT *
FROM bakery_security_logs
WHERE year = 2021
AND month = 7
AND day = 28
AND hour BETWEEN 8 and 11

-- Check the drivers_id in the bakery's security logs
SELECT name
FROM people
WHERE license_plate = "94KL13X"

-- We now know Bruce left the bakery 3 minutes after the reported bakery theft hour, he left Fiftyville on the first flight of the day and went to New York City
-- He was calling a guy named Robin, he withdrew money from the same reported ATM sighting, so he maybe was his accomplice.
-- At first I got mistaken thinking it was a guy named Carl because I thought the call lasted for an hour and a half instead of half an hour
-- The sql queries are no the exact same I used, but I think you can see most of them in the past edits I've done to the file since I edited them a lot and only left the last ones I used.