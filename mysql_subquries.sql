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


-- // pending work
-- *** also application of join operation
CREATE VIEW T1  AS (
SELECT mov_title , mov_year, mov_dt_rel FROM movie
WHERE mov_id IN (
SELECT mov_id FROM rating 
WHERE rev_id IN (
    SELECT rev_id FROM reviewer
     WHERE rev_name IS NULL
 ))
);

CREATE VIEW  T2 AS (
SELECT act_fname, act_lname FROM actor
WHERE act_id IN (
        SELECT act_id FROM movie_cast
        WHERE mov_id IN (
            SELECT mov_id FROM rating 
            WHERE rev_id IN (
                SELECT rev_id FROM reviewer 
                WHERE rev_name IS NULL)))
);

CREATE VIEW T3 AS (
SELECT dir_fname , dir_lname FROM director 
WHERE dir_id IN (
      SELECT dir_id FROM movie_direction 
      WHERE mov_id IN (
           SELECT mov_id FROM rating 
           WHERE rev_id IN (
            SELECT rev_id FROM reviewer
            WHERE rev_name IS NULL)))
);


SELECT * FROM T1,T2,T3;


-- ********************************* Qurey-5***************************************


SELECT mov_title FROM movie
WHERE mov_id IN (
    SELECT mov_id FROM movie_direction
    WHERE dir_id IN (
        SELECT dir_id FROM director
        WHERE dir_fname = 'Woody' AND dir_lname = 'Allen'
    )
);

-- ***************************Qurey-6 ********************************************
-- Verified || my solution match the artical solution
SELECT DISTINCT mov_year FROM movie
WHERE mov_id IN (
SELECT mov_id FROM rating 
WHERE rev_stars >= 3)
ORDER BY mov_year ASC;

-- ************************qurey-7************************************************
-- Verified || my solution match the artical solution

SELECT DISTINCT mov_title FROM movie
WHERE mov_id IN (
    SELECT mov_id FROM movie 
    WHERE mov_id NOT IN (
    SELECT mov_id FROM rating 
));

-- ************************ qurey-8 *********************************************

SELECT DISTINCT rev_name FROM reviewer 
WHERE rev_id IN (
    SELECT rev_id FROM rating 
    WHERE rev_stars IS NULL
);

-- *************************** qurey-9 ****************************************













