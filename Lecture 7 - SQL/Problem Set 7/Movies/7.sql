-- 7. All movies and ratings from 2010, in decreasing order by rating (alphabetical for those with same rating)
SELECT movies.title , ratings.rating
FROM movies
JOIN ratings ON ratings.movie_id = movies.id
WHERE movies.year = 2010
ORDER BY ratings.rating DESC, movies.title ASC;

