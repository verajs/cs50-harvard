SELECT title, rating FROM ratings JOIN movies ON ratings.movie_id = movies.id AND movies.year = 2010 ORDER BY rating DESC, title ASC;