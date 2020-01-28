CREATE TABLE country (
  Code char(3) NOT NULL DEFAULT' ',
  Name char(52) NOT NULL DEFAULT' ',
  Continent enum('Asia','Europe','North America','Africa','Oceania','Antarctica','South America') NOT NULL DEFAULT 'Asia',
  SurfaceArea decimal(10,2) NOT NULL DEFAULT' 0.00',
  IndepYear smallint DEFAULT NULL,
  Population int NOT NULL DEFAULT' 0',
  LifeExpectancy decimal(3,1) DEFAULT NULL,
  GDP decimal(10,2) DEFAULT NULL, -- in $ million USD
  PRIMARY KEY (Code)
);

 -- Data refined from world.country by
 -- CREATE TABLE country AS (
 --   SELECT 
 --     Code, Name, Continent, SurfaceArea, IndepYear, Population, LifeExpectancy, GNP, Capital 
 --   FROM world.country 
 --   WHERE Population >= 10000000
 -- );

INSERT INTO country VALUES('AFG', 'Afghanistan'                          ,'Asia'          ,  652090.00 , 1919 ,  22720000 , 45.9 ,   5976.00 );
INSERT INTO country VALUES('AGO', 'Angola'                               ,'Africa'        , 1246700.00 , 1975 ,  12878000 , 38.3 ,   6648.00 );
INSERT INTO country VALUES('ARG', 'Argentina'                            ,'South America' , 2780400.00 , 1816 ,  37032000 , 75.1 , 340238.00 );
INSERT INTO country VALUES('AUS', 'Australia'                            ,'Oceania'       , 7741220.00 , 1901 ,  18886000 , 79.8 , 351182.00 );
INSERT INTO country VALUES('BEL', 'Belgium'                              ,'Europe'        ,   30518.00 , 1830 ,  10239000 , 77.8 , 249704.00 );
INSERT INTO country VALUES('BFA', 'Burkina Faso'                         ,'Africa'        ,  274000.00 , 1960 ,  11937000 , 46.7 ,   2425.00 );
INSERT INTO country VALUES('BGD', 'Bangladesh'                           ,'Asia'          ,  143998.00 , 1971 , 129155000 , 60.2 ,  32852.00 );
INSERT INTO country VALUES('BLR', 'Belarus'                              ,'Europe'        ,  207600.00 , 1991 ,  10236000 , 68.0 ,  13714.00 );
INSERT INTO country VALUES('BRA', 'Brazil'                               ,'South America' , 8547403.00 , 1822 , 170115000 , 62.9 , 776739.00 );
INSERT INTO country VALUES('CAN', 'Canada'                               ,'North America' , 9970610.00 , 1867 ,  31147000 , 79.4 , 598862.00 );
INSERT INTO country VALUES('CHL', 'Chile'                                ,'South America' ,  756626.00 , 1810 ,  15211000 , 75.7 ,  72949.00 );
INSERT INTO country VALUES('CHN', 'China'                                ,'Asia'          , 9572900.00 , 1523 ,1277558000 , 71.4 , 982268.00 );
INSERT INTO country VALUES('CIV', 'CÃ´te dÂ’Ivoire'                      ,'Africa'        ,  322463.00 , 1960 ,  14786000 , 45.2 ,  11345.00 );
INSERT INTO country VALUES('CMR', 'Cameroon'                             ,'Africa'        ,  475442.00 , 1960 ,  15085000 , 54.8 ,   9174.00 );
INSERT INTO country VALUES('COD', 'The Democratic Republic of the Congo' ,'Africa'        , 2344858.00 , 1960 ,  51654000 , 48.8 ,   6964.00 );
INSERT INTO country VALUES('COL', 'Colombia'                             ,'South America' , 1138914.00 , 1810 ,  42321000 , 70.3 , 102896.00 );
INSERT INTO country VALUES('CUB', 'Cuba'                                 ,'North America' ,  110861.00 , 1902 ,  11201000 , 76.2 ,  17843.00 );
INSERT INTO country VALUES('CZE', 'Czech Republic'                       ,'Europe'        ,   78866.00 , 1993 ,  10278100 , 74.5 ,  55017.00 );
INSERT INTO country VALUES('DEU', 'Germany'                              ,'Europe'        ,  357022.00 , 1955 ,  82164700 , 77.4 ,2133367.00 );
INSERT INTO country VALUES('DZA', 'Algeria'                              ,'Africa'        , 2381741.00 , 1962 ,  31471000 , 69.7 ,  49982.00 );
INSERT INTO country VALUES('ECU', 'Ecuador'                              ,'South America' ,  283561.00 , 1822 ,  12646000 , 71.1 ,  19770.00 );
INSERT INTO country VALUES('EGY', 'Egypt'                                ,'Africa'        , 1001449.00 , 1922 ,  68470000 , 63.3 ,  82710.00 );
INSERT INTO country VALUES('ESP', 'Spain'                                ,'Europe'        ,  505992.00 , 1492 ,  39441700 , 78.8 , 553233.00 );
INSERT INTO country VALUES('ETH', 'Ethiopia'                             ,'Africa'        , 1104300.00 , 1000 ,  62565000 , 45.2 ,   6353.00 );
INSERT INTO country VALUES('FRA', 'France'                               ,'Europe'        ,  551500.00 ,  843 ,  59225700 , 78.8 ,1424285.00 );
INSERT INTO country VALUES('GBR', 'United Kingdom'                       ,'Europe'        ,  242900.00 , 1066 ,  59623400 , 77.7 ,1378330.00 );
INSERT INTO country VALUES('GHA', 'Ghana'                                ,'Africa'        ,  238533.00 , 1957 ,  20212000 , 57.4 ,   7137.00 );
INSERT INTO country VALUES('GRC', 'Greece'                               ,'Europe'        ,  131626.00 , 1830 ,  10545700 , 78.4 , 120724.00 );
INSERT INTO country VALUES('GTM', 'Guatemala'                            ,'North America' ,  108889.00 , 1821 ,  11385000 , 66.2 ,  19008.00 );
INSERT INTO country VALUES('HUN', 'Hungary'                              ,'Europe'        ,   93030.00 , 1918 ,  10043200 , 71.4 ,  48267.00 );
INSERT INTO country VALUES('IDN', 'Indonesia'                            ,'Asia'          , 1904569.00 , 1945 , 212107000 , 68.0 ,  84982.00 );
INSERT INTO country VALUES('IND', 'India'                                ,'Asia'          , 3287263.00 , 1947 ,1013662000 , 62.5 , 447114.00 );
INSERT INTO country VALUES('IRN', 'Iran'                                 ,'Asia'          , 1648195.00 , 1906 ,  67702000 , 69.7 , 195746.00 );
INSERT INTO country VALUES('IRQ', 'Iraq'                                 ,'Asia'          ,  438317.00 , 1932 ,  23115000 , 66.5 ,  11500.00 );
INSERT INTO country VALUES('ITA', 'Italy'                                ,'Europe'        ,  301316.00 , 1861 ,  57680000 , 79.0 ,1161755.00 );
INSERT INTO country VALUES('JPN', 'Japan'                                ,'Asia'          ,  377829.00 , -660 , 126714000 , 80.7 ,3787042.00 );
INSERT INTO country VALUES('KAZ', 'Kazakstan'                            ,'Asia'          , 2724900.00 , 1991 ,  16223000 , 63.2 ,  24375.00 );
INSERT INTO country VALUES('KEN', 'Kenya'                                ,'Africa'        ,  580367.00 , 1963 ,  30080000 , 48.0 ,   9217.00 );
INSERT INTO country VALUES('KHM', 'Cambodia'                             ,'Asia'          ,  181035.00 , 1953 ,  11168000 , 56.5 ,   5121.00 );
INSERT INTO country VALUES('KOR', 'South Korea'                          ,'Asia'          ,   99434.00 , 1948 ,  46844000 , 74.4 , 320749.00 );
INSERT INTO country VALUES('LKA', 'Sri Lanka'                            ,'Asia'          ,   65610.00 , 1948 ,  18827000 , 71.8 ,  15706.00 );
INSERT INTO country VALUES('MAR', 'Morocco'                              ,'Africa'        ,  446550.00 , 1956 ,  28351000 , 69.1 ,  36124.00 );
INSERT INTO country VALUES('MDG', 'Madagascar'                           ,'Africa'        ,  587041.00 , 1960 ,  15942000 , 55.0 ,   3750.00 );
INSERT INTO country VALUES('MEX', 'Mexico'                               ,'North America' , 1958201.00 , 1810 ,  98881000 , 71.5 , 414972.00 );
INSERT INTO country VALUES('MLI', 'Mali'                                 ,'Africa'        , 1240192.00 , 1960 ,  11234000 , 46.7 ,   2642.00 );
INSERT INTO country VALUES('MMR', 'Myanmar'                              ,'Asia'          ,  676578.00 , 1948 ,  45611000 , 54.9 , 180375.00 );
INSERT INTO country VALUES('MOZ', 'Mozambique'                           ,'Africa'        ,  801590.00 , 1975 ,  19680000 , 37.5 ,   2891.00 );
INSERT INTO country VALUES('MWI', 'Malawi'                               ,'Africa'        ,  118484.00 , 1964 ,  10925000 , 37.6 ,   1687.00 );
INSERT INTO country VALUES('MYS', 'Malaysia'                             ,'Asia'          ,  329758.00 , 1957 ,  22244000 , 70.8 ,  69213.00 );
INSERT INTO country VALUES('NER', 'Niger'                                ,'Africa'        , 1267000.00 , 1960 ,  10730000 , 41.3 ,   1706.00 );
INSERT INTO country VALUES('NGA', 'Nigeria'                              ,'Africa'        ,  923768.00 , 1960 , 111506000 , 51.6 ,  65707.00 );
INSERT INTO country VALUES('NLD', 'Netherlands'                          ,'Europe'        ,   41526.00 , 1581 ,  15864000 , 78.3 , 371362.00 );
INSERT INTO country VALUES('NPL', 'Nepal'                                ,'Asia'          ,  147181.00 , 1769 ,  23930000 , 57.8 ,   4768.00 );
INSERT INTO country VALUES('PAK', 'Pakistan'                             ,'Asia'          ,  796095.00 , 1947 , 156483000 , 61.1 ,  61289.00 );
INSERT INTO country VALUES('PER', 'Peru'                                 ,'South America' , 1285216.00 , 1821 ,  25662000 , 70.0 ,  64140.00 );
INSERT INTO country VALUES('PHL', 'Philippines'                          ,'Asia'          ,  300000.00 , 1946 ,  75967000 , 67.5 ,  65107.00 );
INSERT INTO country VALUES('POL', 'Poland'                               ,'Europe'        ,  323250.00 , 1918 ,  38653600 , 73.2 , 151697.00 );
INSERT INTO country VALUES('PRK', 'North Korea'                          ,'Asia'          ,  120538.00 , 1948 ,  24039000 , 70.7 ,   5332.00 );
INSERT INTO country VALUES('ROM', 'Romania'                              ,'Europe'        ,  238391.00 , 1878 ,  22455500 , 69.9 ,  38158.00 );
INSERT INTO country VALUES('RUS', 'Russian Federation'                   ,'Europe'        ,17075400.00 , 1991 , 146934000 , 67.2 , 276608.00 );
INSERT INTO country VALUES('SAU', 'Saudi Arabia'                         ,'Asia'          , 2149690.00 , 1932 ,  21607000 , 67.8 , 137635.00 );
INSERT INTO country VALUES('SDN', 'Sudan'                                ,'Africa'        , 2505813.00 , 1956 ,  29490000 , 56.6 ,  10162.00 );
INSERT INTO country VALUES('SOM', 'Somalia'                              ,'Africa'        ,  637657.00 , 1960 ,  10097000 , 46.2 ,    935.00 );
INSERT INTO country VALUES('SYR', 'Syria'                                ,'Asia'          ,  185180.00 , 1941 ,  16125000 , 68.5 ,  65984.00 );
INSERT INTO country VALUES('THA', 'Thailand'                             ,'Asia'          ,  513115.00 , 1350 ,  61399000 , 68.6 , 116416.00 );
INSERT INTO country VALUES('TUR', 'Turkey'                               ,'Asia'          ,  774815.00 , 1923 ,  66591000 , 71.0 , 210721.00 );
INSERT INTO country VALUES('TWN', 'Taiwan'                               ,'Asia'          ,   36188.00 , 1945 ,  22256000 , 76.4 , 256254.00 );
INSERT INTO country VALUES('TZA', 'Tanzania'                             ,'Africa'        ,  883749.00 , 1961 ,  33517000 , 52.3 ,   8005.00 );
INSERT INTO country VALUES('UGA', 'Uganda'                               ,'Africa'        ,  241038.00 , 1962 ,  21778000 , 42.9 ,   6313.00 );
INSERT INTO country VALUES('UKR', 'Ukraine'                              ,'Europe'        ,  603700.00 , 1991 ,  50456000 , 66.0 ,  42168.00 );
INSERT INTO country VALUES('USA', 'United States'                        ,'North America' , 9363520.00 , 1776 , 278357000 , 77.1 ,8510700.00 );
INSERT INTO country VALUES('UZB', 'Uzbekistan'                           ,'Asia'          ,  447400.00 , 1991 ,  24318000 , 63.7 ,  14194.00 );
INSERT INTO country VALUES('VEN', 'Venezuela'                            ,'South America' ,  912050.00 , 1811 ,  24170000 , 73.1 ,  95023.00 );
INSERT INTO country VALUES('VNM', 'Vietnam'                              ,'Asia'          ,  331689.00 , 1945 ,  79832000 , 69.3 ,  21929.00 );
INSERT INTO country VALUES('YEM', 'Yemen'                                ,'Asia'          ,  527968.00 , 1918 ,  18112000 , 59.8 ,   6041.00 );
INSERT INTO country VALUES('YUG', 'Yugoslavia'                           ,'Europe'        ,  102173.00 , 1918 ,  10640000 , 72.4 ,  17000.00 );
INSERT INTO country VALUES('ZAF', 'South Africa'                         ,'Africa'        , 1221037.00 , 1910 ,  40377000 , 51.1 , 116729.00 );
INSERT INTO country VALUES('ZWE', 'Zimbabwe'                             ,'Africa'        ,  390757.00 , 1980 ,  11669000 , 37.8 ,   5951.00 );