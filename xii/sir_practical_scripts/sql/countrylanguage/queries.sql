 -- The most spoken language in each country
SELECT cl.* FROM countrylanguage cl
WHERE 
  Percentage = (
    SELECT 
      MAX(Percentage) 
    FROM countrylanguage 
    WHERE
      CountryCode = cl.CountryCode
  );
 -- The least spoken language in each country, except in countries with only one language in the database
SELECT cl.* FROM countrylanguage cl
WHERE 
  Percentage = (
    SELECT 
      MIN(Percentage) 
    FROM countrylanguage 
    WHERE
      CountryCode = cl.CountryCode
  )
  AND
  (SELECT 
    COUNT(*)
  FROM countrylanguage 
    WHERE 
      CountryCode = cl.CountryCode) != 1
  );
 -- All unofficial languages spoken more frequently than any official language in their country
SELECT * FROM countrylanguage cl
WHERE 
  IsOfficial = 'F'
  AND
  Percentage >= (
    SELECT 
      MAX(Percentage) 
    FROM countrylanguage 
    WHERE
      CountryCode = cl.CountryCode
      AND
      IsOfficial = 'T'
  );
 -- All official languages spoken less frequently than any unofficial language in their country
SELECT * FROM countrylanguage cl
WHERE 
  IsOfficial = 'T'
  AND
  Percentage <= (
    SELECT 
      MIN(Percentage) 
    FROM countrylanguage 
    WHERE
      CountryCode = cl.CountryCode
      AND
      IsOfficial = 'F'
  );
 -- The most spoken official and unofficial in all countries
SELECT * FROM countrylanguage cl
WHERE 
  Language IN (
    SELECT 
      Language 
    FROM countrylanguage cl_sub
    WHERE
      CountryCode = cl.CountryCode
      AND
      Percentage = (
        SELECT 
          MAX(Percentage)
        FROM countrylanguage
        WHERE 
          CountryCode = cl_sub.CountryCode
          AND
          IsOfficial = cl_sub.IsOfficial
      )
  )
  ORDER BY
      CountryCode;
 -- JOIN WITH TABLE `country`
 -- All Spoken Language order by no. of speakers
SELECT 
  cl.CountryCode, c.Name AS Country, cl.Language, 
  cl.IsOfficial, (cl.Percentage * c.Population) AS 'No. of speakers',
  cl.Percentage
FROM country c, countrylanguage cl
  WHERE 
    c.Code = cl.CountryCode
  ORDER BY 
    -(Percentage * Population);