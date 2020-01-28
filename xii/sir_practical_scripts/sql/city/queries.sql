 -- Top 20 most populated cities
SELECT * FROM city
 ORDER BY
   -Population
 LIMIT 20;
 -- Top 20 least populated cities
SELECT * FROM city
 ORDER BY
   Population
 LIMIT 20;
 -- Top 20 cities with the greatest fraction of their countries population
SELECT 
  ct.*, (100 * ct.Population / cy.Population) AS '% Population of Country' 
FROM city ct, country cy
 WHERE
   ct.Country = cy.Name 
 ORDER BY
   -(ct.Population / cy.Population)
 LIMIT 20;
 -- Top 20 cities with the least fraction of their countries population
SELECT 
  ct.*, (100 * ct.Population / cy.Population) AS '% Population of Country' 
FROM city ct, country cy
 WHERE
   ct.Country = cy.Name 
 ORDER BY
   (ct.Population / cy.Population)
 LIMIT 20;
 -- Top 20 cities in the most wealtiest countries where English is spoken
SELECT
  ct.ID, ct.Name, ct.Country, ct.Population,
  (cy.GDP * ct.Population / cy.Population) AS 'Approx. GDP of City  (in million $ USD)',
  cy.GDP, cl.Language
FROM city ct, country cy, countrylanguage cl
  WHERE
    ct.Country = cy.Name
    AND
    cy.Code = cl.CountryCode
    AND
    cl.Language = 'English'
  ORDER BY
    -(cy.GDP * ct.Population / cy.Population)
  LIMIT 20;
 -- Top 20 wealtiest African cities
SELECT
  ct.ID, ct.Name, ct.Country, ct.Population,
  (cy.GDP * ct.Population / cy.Population) AS 'Approx. GDP of City (in million $ USD)',
  cy.GDP
FROM city ct, country cy
  WHERE
    ct.Country = cy.Name
    AND
    cy.Continent = 'Africa'
  ORDER BY
    -(cy.GDP * ct.Population / cy.Population)
  LIMIT 20;
 -- All citites in countries where a European language is spoken
SELECT 
  ct.*, cy.Population, cy.Continent, cl.Language
FROM city ct, country cy, countrylanguage cl
 WHERE
   ct.Country = cy.Name 
   AND
   cy.Code = cl.CountryCode
   AND
   cl.Language IN (
     SELECT
       cl.Language
     FROM country cy, countrylanguage cl
     WHERE 
       cy.Code = cl.CountryCode
       AND
       cy.Continent = 'Europe'
   )
 ORDER BY
   -ct.Population;
 -- All countries where a Chinese language is spoken
SELECT 
  ct.*, cy.Population, cy.Continent, cl.Language
FROM city ct, country cy, countrylanguage cl
 WHERE
   ct.Country = cy.Name 
   AND
   cy.Code = cl.CountryCode
   AND
   cl.Language IN (
     SELECT
       cl.Language
     FROM country cy, countrylanguage cl
     WHERE 
       cy.Code = cl.CountryCode
       AND
       cy.Name = 'China'
   )
 ORDER BY
   -ct.Population;