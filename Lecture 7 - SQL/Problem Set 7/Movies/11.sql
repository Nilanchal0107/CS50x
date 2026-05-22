-- 11. Titles of the five highest rated movies (in order) that Chadwick Boseman starred in, starting with the highest rated
SELECT movies.title
FROM movies
JOIN stars ON stars.movie_id = movies.id
JOIN people ON people.id = stars.person_id
JOIN ratings ON ratings.movie_id = movies.id
WHERE people.name = 'Chadwick Boseman'
ORDER BY ratings.rating DESC
LIMIT 5;
