SELECT name FROM people JOIN stars ON person_id = people.id JOIN movies ON movies.id = movie_id AND title = "Toy Story";