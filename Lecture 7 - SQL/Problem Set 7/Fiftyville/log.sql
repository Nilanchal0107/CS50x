-- CS50x Fiftyville Mystery Investigation Log
-- Theft of the CS50 Duck took place on July 28, 2025 on Humphrey Street

-- =========================================================
-- Step 1: Read the crime scene report
-- =========================================================
SELECT description
FROM crime_scene_reports
WHERE year = 2025
AND month = 7
AND day = 28
AND street = 'Humphrey Street';
-- Result: Theft at 10:15am at the Humphrey Street bakery.
-- Three witnesses were interviewed, each transcript mentions the bakery.

-- =========================================================
-- Step 2: Read witness interviews from July 28
-- =========================================================
SELECT name, transcript
FROM interviews
WHERE year = 2025
AND month = 7
AND day = 28;
-- Key witnesses:
-- Ruth:    Thief left bakery parking lot within 10 minutes of theft → check bakery_security_logs
-- Eugene:  Thief withdrew money from ATM on Leggett Street → check atm_transactions
-- Raymond: Thief made a phone call under 1 minute, planned earliest flight out on July 29 → check phone_calls + flights

-- =========================================================
-- Step 3: Ruth's clue — cars that exited bakery 10:15–10:25am
-- =========================================================
SELECT license_plate
FROM bakery_security_logs
WHERE year = 2025 AND month = 7 AND day = 28
AND hour = 10 AND minute BETWEEN 15 AND 25
AND activity = 'exit';
-- 8 license plates returned

-- =========================================================
-- Step 4: Eugene's clue — ATM withdrawals on Leggett Street
-- =========================================================
SELECT account_number
FROM atm_transactions
WHERE year = 2025 AND month = 7 AND day = 28
AND atm_location = 'Leggett Street'
AND transaction_type = 'withdraw';
-- 8 account numbers returned

-- =========================================================
-- Step 5: Raymond's clue — phone calls under 1 minute on July 28
-- =========================================================
SELECT caller, receiver
FROM phone_calls
WHERE year = 2025 AND month = 7 AND day = 28
AND duration < 60;
-- 9 calls returned

-- =========================================================
-- Step 6: Cross-reference all three clues to narrow suspects
-- =========================================================
SELECT name, phone_number, license_plate
FROM people
WHERE license_plate IN (
    SELECT license_plate
    FROM bakery_security_logs
    WHERE year = 2025 AND month = 7 AND day = 28
    AND hour = 10 AND minute BETWEEN 15 AND 25
    AND activity = 'exit'
)
AND id IN (
    SELECT person_id
    FROM bank_accounts
    WHERE account_number IN (
        SELECT account_number
        FROM atm_transactions
        WHERE year = 2025 AND month = 7 AND day = 28
        AND atm_location = 'Leggett Street'
        AND transaction_type = 'withdraw'
    )
)
AND phone_number IN (
    SELECT caller
    FROM phone_calls
    WHERE year = 2025 AND month = 7 AND day = 28
    AND duration < 60
);
-- Two suspects: Diana and Bruce

-- =========================================================
-- Step 7: Check who boarded the earliest flight out of Fiftyville on July 29
-- =========================================================
SELECT name
FROM people
WHERE passport_number IN (
    SELECT passport_number
    FROM passengers
    WHERE flight_id = (
        SELECT id
        FROM flights
        WHERE year = 2025 AND month = 7 AND day = 29
        AND origin_airport_id = (
            SELECT id FROM airports WHERE city = 'Fiftyville'
        )
        ORDER BY hour, minute
        LIMIT 1
    )
)
AND name IN ('Diana', 'Bruce');
-- Result: Bruce → Bruce is the THIEF

-- =========================================================
-- Step 8: Find the destination city of the earliest flight
-- =========================================================
SELECT city
FROM airports
WHERE id = (
    SELECT destination_airport_id
    FROM flights
    WHERE year = 2025 AND month = 7 AND day = 29
    AND origin_airport_id = (
        SELECT id FROM airports WHERE city = 'Fiftyville'
    )
    ORDER BY hour, minute
    LIMIT 1
);
-- Result: New York City

-- =========================================================
-- Step 9: Find the accomplice (receiver of Bruce's phone call)
-- =========================================================
SELECT name
FROM people
WHERE phone_number = (
    SELECT receiver
    FROM phone_calls
    WHERE year = 2025 AND month = 7 AND day = 28
    AND duration < 60
    AND caller = '(367) 555-5533'
);
-- Result: Robin → Robin is the ACCOMPLICE

-- =========================================================
-- SOLUTION
-- Thief:       Bruce
-- Escaped to:  New York City
-- Accomplice:  Robin
-- =========================================================
