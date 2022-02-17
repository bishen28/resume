-- ********************************************Subqueries-1******************************************* 
-- 1. From the following tables, write a SQL query to find the actors who played a role in the movie 'Annie Hall'. Return all the fields of 
-- actor table.

SELECT * FROM actor
WHERE act_id IN (
    SELECT act_id FROM movie_cast
    WHERE role =  ANY (
           SELECT role FROM movie_cast
           WHERE mov_id IN (
              SELECT mov_id FROM movie
              WHERE mov_title = 'Annie Hall')));


-- ******************************************** Subquries-2 ********************************************-- 
-- MEthod - 1
-- [ what is difference between method 1 and method2


SELECT dir_fname, dir_lname FROM director
WHERE dir_id IN (
        SELECT dir_id FROM movie_direction 
        WHERE mov_id IN (
              SELECT mov_id FROM movie_cast
              WHERE role = ANY (
                 SELECT role FROM movie_cast
                 WHERE mov_id IN (
                    SELECT mov_id FROM movie
                    WHERE mov_title = 'Eyes Wide Shut'))));

-- Method - 2

SELECT dir_fname, dir_lname FROM director
WHERE dir_id IN (
        SELECT dir_id FROM movie_direction 
        WHERE mov_id IN (
              SELECT mov_id FROM movie
              WHERE mov_title = 'Eyes Wide Shut'));



-- ************************************** Subquries-3 *********************************************************

SELECT mov_title,mov_year,mov_time, mov_dt_rel, mov_rel_country
FROM movie
WHERE mov_rel_country != 'UK';

-- *********************************** Subqueries - 4 **********************************************************









