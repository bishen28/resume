CREATE TABLE actor (
   act_id INT,
   act_fname VARCHAR(20),
   act_lname VARCHAR(20),
   act_gender VARCHAR(1),
   PRIMARY KEY (act_id)
);

CREATE TABLE genres (
   gen_id INT,
   gen_title VARCHAR(20),
   PRIMARY KEY (gen_id)
);

CREATE TABLE director (
   dir_id INT,
   dir_fname VARCHAR(20),
   dir_lname VARCHAR(20),
   PRIMARY KEY (dir_id)
);

CREATE TABLE movie (
  mov_id INT,	
  mov_title VARCHAR(50),
  mov_year INT,
  mov_time 	INT,
  mov_lang 	VARCHAR(20),
  mov_dt_rel DATE,	
  mov_rel_country VARCHAR(5),
  PRIMARY KEY (mov_id)
);


CREATE TABLE movie_genres (
  mov_id INT,
  gen_id INT,
  PRIMARY KEY (mov_id)
);

CREATE TABLE movie_direction (
  dir_id INT,
  mov_id INT,
  PRIMARY KEY (dir_id,mov_id)
);

CREATE TABLE reviewer (
  rev_id INT,
  rev_name VARCHAR(50),
  PRIMARY KEY (rev_id)
);

CREATE TABLE rating (
  mov_id INT,
  rev_id INT,
  rev_stars DECIMAL(4,2),
  num_o_ratings INT,
  PRIMARY KEY (mov_id,rev_id)
);

CREATE TABLE movie_cast (
  act_id INT,
  mov_id INT,
  role VARCHAR(50),
  PRIMARY KEY (act_id,mov_id)
);
