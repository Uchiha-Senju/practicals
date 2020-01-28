 -- Top 20 Largest Countries by Area
SELECT Code, Name, Continent, SurfaceArea FROM country ORDER BY -SurfaceArea LIMIT 20;
 -- Top 20 Largest Countries by Population
SELECT Code, Name, Continent, Population FROM country ORDER BY -Population LIMIT 20;
 -- Top 20 Longest Lived Countries
SELECT Code, Name, Continent, LifeExpectancy FROM country ORDER BY -LifeExpectancy LIMIT 20;
 -- Top 20 Richest Countries
SELECT Code, Name, Continent, GDP FROM country ORDER BY -GDP LIMIT 20;
 -- Top 20 Country with the greatest wealth per person
SELECT Code, Name, Continent, (1000000 * GDP / Population) AS 'GDP Per Capita (in $)' FROM country ORDER BY -(GDP/Population) LIMIT 20;
 -- All countries where population desnity is greater than 50 persons per km^2
SELECT Code, Name, (Population / SurfaceArea) AS PopDensity from country WHERE Population / SurfaceArea >= 50.0;
 -- All European countries which gained independence in the 19th century or later
SELECT Code, Name, Continent, Population, IndepYear 'Year of Independence' FROM country WHERE Continent='Europe' AND IndepYear >= 1800;
 -- All Countries where life expectancy is less than 65 years
SELECT Code, Name, Continent, LifeExpectancy, GDP AS 'GDP (in $1,000,000)' FROM country WHERE LifeExpectancy <= 65.0;
 -- All Asian countries and their development status by World Bank Standards
SELECT 
  Code, Name, Continent, 
  (1000000 * GDP / Population) AS 'GDP Per Capita (in $)', 
  ( CASE
    WHEN (1000000 * GDP / Population) > 4035 
      THEN 'Developed' 
    WHEN (1000000 * GDP / Population) > 1025 
      THEN 'Developing' 
    ELSE 'Undeveloped'
  END) AS 'Development Status'
FROM country 
  WHERE Continent='Asia'
  ORDER BY -(1000000 * GDP / Population);