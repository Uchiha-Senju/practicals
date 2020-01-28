CREATE TABLE countrylanguage (
  CountryCode char(3) NOT NULL DEFAULT'' ,
  Language char(30) NOT NULL DEFAULT'' ,
  IsOfficial enum('T','F') NOT NULL DEFAULT' F',
  Percentage decimal(4,1) NOT NULL DEFAULT' 0.0',
  PRIMARY KEY (CountryCode,Language)
);

 -- Data Refined from world.countrylanguage by
 -- CREATE TABLE countrylanguage AS (
 --   SELECT * FROM world.countrylanguage
 --      WHERE CountryCode IN (
 --        SELECT Code FROM world.country WHERE Population >= 10000000
 --      ) AND (IsOfficial = 'T' OR Percentage >= 10.0)
 --  );
 
INSERT INTO countrylanguage VALUES('AFG', 'Dari'               , 'T',  32.1);
INSERT INTO countrylanguage VALUES('AFG', 'Pashto'             , 'T',  52.4);
INSERT INTO countrylanguage VALUES('AGO', 'Kongo'              , 'F',  13.2);
INSERT INTO countrylanguage VALUES('AGO', 'Mbundu'             , 'F',  21.6);
INSERT INTO countrylanguage VALUES('AGO', 'Ovimbundu'          , 'F',  37.2);
INSERT INTO countrylanguage VALUES('ARG', 'Spanish'            , 'T',  96.8);
INSERT INTO countrylanguage VALUES('AUS', 'English'            , 'T',  81.2);
INSERT INTO countrylanguage VALUES('BEL', 'Dutch'              , 'T',  59.2);
INSERT INTO countrylanguage VALUES('BEL', 'French'             , 'T',  32.6);
INSERT INTO countrylanguage VALUES('BEL', 'German'             , 'T',   1.0);
INSERT INTO countrylanguage VALUES('BFA', 'Mossi'              , 'F',  50.2);
INSERT INTO countrylanguage VALUES('BGD', 'Bengali'            , 'T',  97.7);
INSERT INTO countrylanguage VALUES('BLR', 'Belorussian'        , 'T',  65.6);
INSERT INTO countrylanguage VALUES('BLR', 'Russian'            , 'T',  32.0);
INSERT INTO countrylanguage VALUES('BRA', 'Portuguese'         , 'T',  97.5);
INSERT INTO countrylanguage VALUES('CAN', 'English'            , 'T',  60.4);
INSERT INTO countrylanguage VALUES('CAN', 'French'             , 'T',  23.4);
INSERT INTO countrylanguage VALUES('CHL', 'Spanish'            , 'T',  89.7);
INSERT INTO countrylanguage VALUES('CHN', 'Chinese'            , 'T',  92.0);
INSERT INTO countrylanguage VALUES('CIV', 'Akan'               , 'F',  30.0);
INSERT INTO countrylanguage VALUES('CIV', 'Gur'                , 'F',  11.7);
INSERT INTO countrylanguage VALUES('CIV', 'Kru'                , 'F',  10.5);
INSERT INTO countrylanguage VALUES('CIV', 'Malinke'            , 'F',  11.4);
INSERT INTO countrylanguage VALUES('CMR', 'Bamileke-bamum'     , 'F',  18.6);
INSERT INTO countrylanguage VALUES('CMR', 'Duala'              , 'F',  10.9);
INSERT INTO countrylanguage VALUES('CMR', 'Fang'               , 'F',  19.7);
INSERT INTO countrylanguage VALUES('COD', 'Kongo'              , 'F',  16.0);
INSERT INTO countrylanguage VALUES('COD', 'Luba'               , 'F',  18.0);
INSERT INTO countrylanguage VALUES('COD', 'Mongo'              , 'F',  13.5);
INSERT INTO countrylanguage VALUES('COD', 'Rwanda'             , 'F',  10.3);
INSERT INTO countrylanguage VALUES('COL', 'Spanish'            , 'T',  99.0);
INSERT INTO countrylanguage VALUES('CUB', 'Spanish'            , 'T', 100.0);
INSERT INTO countrylanguage VALUES('CZE', 'Czech'              , 'T',  81.2);
INSERT INTO countrylanguage VALUES('CZE', 'Moravian'           , 'F',  12.9);
INSERT INTO countrylanguage VALUES('DEU', 'German'             , 'T',  91.3);
INSERT INTO countrylanguage VALUES('DZA', 'Arabic'             , 'T',  86.0);
INSERT INTO countrylanguage VALUES('DZA', 'Berberi'            , 'F',  14.0);
INSERT INTO countrylanguage VALUES('ECU', 'Spanish'            , 'T',  93.0);
INSERT INTO countrylanguage VALUES('EGY', 'Arabic'             , 'T',  98.8);
INSERT INTO countrylanguage VALUES('ESP', 'Catalan'            , 'F',  16.9);
INSERT INTO countrylanguage VALUES('ESP', 'Spanish'            , 'T',  74.4);
INSERT INTO countrylanguage VALUES('ETH', 'Amhara'             , 'F',  30.0);
INSERT INTO countrylanguage VALUES('ETH', 'Oromo'              , 'F',  31.0);
INSERT INTO countrylanguage VALUES('FRA', 'French'             , 'T',  93.6);
INSERT INTO countrylanguage VALUES('GBR', 'English'            , 'T',  97.3);
INSERT INTO countrylanguage VALUES('GHA', 'Akan'               , 'F',  52.4);
INSERT INTO countrylanguage VALUES('GHA', 'Ewe'                , 'F',  11.9);
INSERT INTO countrylanguage VALUES('GHA', 'Mossi'              , 'F',  15.8);
INSERT INTO countrylanguage VALUES('GRC', 'Greek'              , 'T',  98.5);
INSERT INTO countrylanguage VALUES('GTM', 'QuichÃ©'            , 'F',  10.1);
INSERT INTO countrylanguage VALUES('GTM', 'Spanish'            , 'T',  64.7);
INSERT INTO countrylanguage VALUES('HUN', 'Hungarian'          , 'T',  98.5);
INSERT INTO countrylanguage VALUES('IDN', 'Javanese'           , 'F',  39.4);
INSERT INTO countrylanguage VALUES('IDN', 'Malay'              , 'T',  12.1);
INSERT INTO countrylanguage VALUES('IDN', 'Sunda'              , 'F',  15.8);
INSERT INTO countrylanguage VALUES('IND', 'Hindi'              , 'T',  39.9);
INSERT INTO countrylanguage VALUES('IRN', 'Azerbaijani'        , 'F',  16.8);
INSERT INTO countrylanguage VALUES('IRN', 'Persian'            , 'T',  45.7);
INSERT INTO countrylanguage VALUES('IRQ', 'Arabic'             , 'T',  77.2);
INSERT INTO countrylanguage VALUES('IRQ', 'Kurdish'            , 'F',  19.0);
INSERT INTO countrylanguage VALUES('ITA', 'Italian'            , 'T',  94.1);
INSERT INTO countrylanguage VALUES('JPN', 'Japanese'           , 'T',  99.1);
INSERT INTO countrylanguage VALUES('KAZ', 'Kazakh'             , 'T',  46.0);
INSERT INTO countrylanguage VALUES('KAZ', 'Russian'            , 'F',  34.7);
INSERT INTO countrylanguage VALUES('KEN', 'Kalenjin'           , 'F',  10.8);
INSERT INTO countrylanguage VALUES('KEN', 'Kamba'              , 'F',  11.2);
INSERT INTO countrylanguage VALUES('KEN', 'Kikuyu'             , 'F',  20.9);
INSERT INTO countrylanguage VALUES('KEN', 'Luhya'              , 'F',  13.8);
INSERT INTO countrylanguage VALUES('KEN', 'Luo'                , 'F',  12.8);
INSERT INTO countrylanguage VALUES('KHM', 'Khmer'              , 'T',  88.6);
INSERT INTO countrylanguage VALUES('KOR', 'Korean'             , 'T',  99.9);
INSERT INTO countrylanguage VALUES('LKA', 'Mixed Languages'    , 'F',  19.6);
INSERT INTO countrylanguage VALUES('LKA', 'Singali'            , 'T',  60.3);
INSERT INTO countrylanguage VALUES('LKA', 'Tamil'              , 'T',  19.6);
INSERT INTO countrylanguage VALUES('MAR', 'Arabic'             , 'T',  65.0);
INSERT INTO countrylanguage VALUES('MAR', 'Berberi'            , 'F',  33.0);
INSERT INTO countrylanguage VALUES('MDG', 'French'             , 'T',   0.0);
INSERT INTO countrylanguage VALUES('MDG', 'Malagasy'           , 'T',  98.9);
INSERT INTO countrylanguage VALUES('MEX', 'Spanish'            , 'T',  92.1);
INSERT INTO countrylanguage VALUES('MLI', 'Bambara'            , 'F',  31.8);
INSERT INTO countrylanguage VALUES('MLI', 'Ful'                , 'F',  13.9);
INSERT INTO countrylanguage VALUES('MLI', 'Senufo and Minianka', 'F',  12.0);
INSERT INTO countrylanguage VALUES('MMR', 'Burmese'            , 'T',  69.0);
INSERT INTO countrylanguage VALUES('MOZ', 'Makua'              , 'F',  27.8);
INSERT INTO countrylanguage VALUES('MOZ', 'Tsonga'             , 'F',  12.4);
INSERT INTO countrylanguage VALUES('MWI', 'Chichewa'           , 'T',  58.3);
INSERT INTO countrylanguage VALUES('MWI', 'Lomwe'              , 'F',  18.4);
INSERT INTO countrylanguage VALUES('MWI', 'Yao'                , 'F',  13.2);
INSERT INTO countrylanguage VALUES('MYS', 'Malay'              , 'T',  58.4);
INSERT INTO countrylanguage VALUES('NER', 'Hausa'              , 'F',  53.1);
INSERT INTO countrylanguage VALUES('NER', 'Songhai-zerma'      , 'F',  21.2);
INSERT INTO countrylanguage VALUES('NER', 'Tamashek'           , 'F',  10.4);
INSERT INTO countrylanguage VALUES('NGA', 'Ful'                , 'F',  11.3);
INSERT INTO countrylanguage VALUES('NGA', 'Hausa'              , 'F',  21.1);
INSERT INTO countrylanguage VALUES('NGA', 'Ibo'                , 'F',  18.1);
INSERT INTO countrylanguage VALUES('NGA', 'Joruba'             , 'F',  21.4);
INSERT INTO countrylanguage VALUES('NLD', 'Dutch'              , 'T',  95.6);
INSERT INTO countrylanguage VALUES('NPL', 'Maithili'           , 'F',  11.9);
INSERT INTO countrylanguage VALUES('NPL', 'Nepali'             , 'T',  50.4);
INSERT INTO countrylanguage VALUES('PAK', 'Pashto'             , 'F',  13.1);
INSERT INTO countrylanguage VALUES('PAK', 'Punjabi'            , 'F',  48.2);
INSERT INTO countrylanguage VALUES('PAK', 'Sindhi'             , 'F',  11.8);
INSERT INTO countrylanguage VALUES('PAK', 'Urdu'               , 'T',   7.6);
INSERT INTO countrylanguage VALUES('PER', 'AimarÃ¡'            , 'T',   2.3);
INSERT INTO countrylanguage VALUES('PER', 'KetÂšua'            , 'T',  16.4);
INSERT INTO countrylanguage VALUES('PER', 'Spanish'            , 'T',  79.8);
INSERT INTO countrylanguage VALUES('PHL', 'Cebuano'            , 'F',  23.3);
INSERT INTO countrylanguage VALUES('PHL', 'Pilipino'           , 'T',  29.3);
INSERT INTO countrylanguage VALUES('POL', 'Polish'             , 'T',  97.6);
INSERT INTO countrylanguage VALUES('PRK', 'Korean'             , 'T',  99.9);
INSERT INTO countrylanguage VALUES('ROM', 'Romani'             , 'T',   0.7);
INSERT INTO countrylanguage VALUES('ROM', 'Romanian'           , 'T',  90.7);
INSERT INTO countrylanguage VALUES('RUS', 'Russian'            , 'T',  86.6);
INSERT INTO countrylanguage VALUES('SAU', 'Arabic'             , 'T',  95.0);
INSERT INTO countrylanguage VALUES('SDN', 'Arabic'             , 'T',  49.4);
INSERT INTO countrylanguage VALUES('SDN', 'Dinka'              , 'F',  11.5);
INSERT INTO countrylanguage VALUES('SOM', 'Arabic'             , 'T',   0.0);
INSERT INTO countrylanguage VALUES('SOM', 'Somali'             , 'T',  98.3);
INSERT INTO countrylanguage VALUES('SYR', 'Arabic'             , 'T',  90.0);
INSERT INTO countrylanguage VALUES('THA', 'Chinese'            , 'F',  12.1);
INSERT INTO countrylanguage VALUES('THA', 'Lao'                , 'F',  26.9);
INSERT INTO countrylanguage VALUES('THA', 'Thai'               , 'T',  52.6);
INSERT INTO countrylanguage VALUES('TUR', 'Kurdish'            , 'F',  10.6);
INSERT INTO countrylanguage VALUES('TUR', 'Turkish'            , 'T',  87.6);
INSERT INTO countrylanguage VALUES('TWN', 'Hakka'              , 'F',  11.0);
INSERT INTO countrylanguage VALUES('TWN', 'Mandarin Chinese'   , 'T',  20.1);
INSERT INTO countrylanguage VALUES('TWN', 'Min'                , 'F',  66.7);
INSERT INTO countrylanguage VALUES('TZA', 'Nyamwesi'           , 'F',  21.1);
INSERT INTO countrylanguage VALUES('TZA', 'Swahili'            , 'T',   8.8);
INSERT INTO countrylanguage VALUES('UGA', 'Ganda'              , 'F',  18.1);
INSERT INTO countrylanguage VALUES('UGA', 'Nkole'              , 'F',  10.7);
INSERT INTO countrylanguage VALUES('UKR', 'Russian'            , 'F',  32.9);
INSERT INTO countrylanguage VALUES('UKR', 'Ukrainian'          , 'T',  64.7);
INSERT INTO countrylanguage VALUES('USA', 'English'            , 'T',  86.2);
INSERT INTO countrylanguage VALUES('UZB', 'Russian'            , 'F',  10.9);
INSERT INTO countrylanguage VALUES('UZB', 'Uzbek'              , 'T',  72.6);
INSERT INTO countrylanguage VALUES('VEN', 'Spanish'            , 'T',  96.9);
INSERT INTO countrylanguage VALUES('VNM', 'Vietnamese'         , 'T',  86.8);
INSERT INTO countrylanguage VALUES('YEM', 'Arabic'             , 'T',  99.6);
INSERT INTO countrylanguage VALUES('YUG', 'Albaniana'          , 'F',  16.5);
INSERT INTO countrylanguage VALUES('YUG', 'Serbo-Croatian'     , 'T',  75.2);
INSERT INTO countrylanguage VALUES('ZAF', 'Afrikaans'          , 'T',  14.3);
INSERT INTO countrylanguage VALUES('ZAF', 'English'            , 'T',   8.5);
INSERT INTO countrylanguage VALUES('ZAF', 'Xhosa'              , 'T',  17.7);
INSERT INTO countrylanguage VALUES('ZAF', 'Zulu'               , 'T',  22.7);
INSERT INTO countrylanguage VALUES('ZWE', 'English'            , 'T',   2.2);
INSERT INTO countrylanguage VALUES('ZWE', 'Ndebele'            , 'F',  16.2);
INSERT INTO countrylanguage VALUES('ZWE', 'Shona'              , 'F',  72.1);