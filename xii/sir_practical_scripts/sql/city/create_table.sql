CREATE TABLE city (
  ID int NOT NULL,
  Name char(35) NOT NULL DEFAULT'' ,
  Country char(52) NOT NULL DEFAULT'' ,
  Population int NOT NULL DEFAULT' 0',
  PRIMARY KEY (ID),
)

 -- Data refined from world.city by
 -- CREATE TABLE city AS (
 --   SELECT 
 --     ID, Name, 
 --     (SELECT Name FROM world.country WHERE Code = wc.CountryCode ) AS Country,
 --     Population 
 --   FROM world.city wc 
 --   WHERE 
 --     Population >= 1000000 
 --     AND 
 --     CountryCode IN (
 --       SELECT Code FROM world.country WHERE Population >= 10000000)
 -- );
 
INSERT INTO city VALUES(   1, 'Kabul'              , 'Afghanistan'                         ,  1780000);
INSERT INTO city VALUES(  35, 'Alger'              , 'Algeria'                             ,  2168000);
INSERT INTO city VALUES(  56, 'Luanda'             , 'Angola'                              ,  2022000);
INSERT INTO city VALUES(  69, 'Buenos Aires'       , 'Argentina'                           ,  2982146);
INSERT INTO city VALUES(  70, 'La Matanza'         , 'Argentina'                           ,  1266461);
INSERT INTO city VALUES(  71, 'CÃ³rdoba'           , 'Argentina'                           ,  1157507);
INSERT INTO city VALUES( 130, 'Sydney'             , 'Australia'                           ,  3276207);
INSERT INTO city VALUES( 131, 'Melbourne'          , 'Australia'                           ,  2865329);
INSERT INTO city VALUES( 132, 'Brisbane'           , 'Australia'                           ,  1291117);
INSERT INTO city VALUES( 133, 'Perth'              , 'Australia'                           ,  1096829);
INSERT INTO city VALUES( 150, 'Dhaka'              , 'Bangladesh'                          ,  3612850);
INSERT INTO city VALUES( 151, 'Chittagong'         , 'Bangladesh'                          ,  1392860);
INSERT INTO city VALUES(3520, 'Minsk'              , 'Belarus'                             ,  1674000);
INSERT INTO city VALUES( 206, 'SÃ£o Paulo'         , 'Brazil'                              ,  9968485);
INSERT INTO city VALUES( 207, 'Rio de Janeiro'     , 'Brazil'                              ,  5598953);
INSERT INTO city VALUES( 208, 'Salvador'           , 'Brazil'                              ,  2302832);
INSERT INTO city VALUES( 209, 'Belo Horizonte'     , 'Brazil'                              ,  2139125);
INSERT INTO city VALUES( 210, 'Fortaleza'          , 'Brazil'                              ,  2097757);
INSERT INTO city VALUES( 211, 'BrasÃ­lia'          , 'Brazil'                              ,  1969868);
INSERT INTO city VALUES( 212, 'Curitiba'           , 'Brazil'                              ,  1584232);
INSERT INTO city VALUES( 213, 'Recife'             , 'Brazil'                              ,  1378087);
INSERT INTO city VALUES( 214, 'Porto Alegre'       , 'Brazil'                              ,  1314032);
INSERT INTO city VALUES( 215, 'Manaus'             , 'Brazil'                              ,  1255049);
INSERT INTO city VALUES( 216, 'BelÃ©m'             , 'Brazil'                              ,  1186926);
INSERT INTO city VALUES( 217, 'Guarulhos'          , 'Brazil'                              ,  1095874);
INSERT INTO city VALUES( 218, 'GoiÃ¢nia'           , 'Brazil'                              ,  1056330);
INSERT INTO city VALUES(1803, 'Douala'             , 'Cameroon'                            ,  1448300);
INSERT INTO city VALUES(1804, 'YaoundÃ©'           , 'Cameroon'                            ,  1372800);
INSERT INTO city VALUES(1810, 'MontrÃ©al'          , 'Canada'                              ,  1016376);
INSERT INTO city VALUES(2812, 'Abidjan'            , 'CÃ´te dÂ’Ivoire'                     ,  2500000);
INSERT INTO city VALUES( 554, 'Santiago de Chile'  , 'Chile'                               ,  4703954);
INSERT INTO city VALUES(1890, 'Shanghai'           , 'China'                               ,  9696300);
INSERT INTO city VALUES(1891, 'Peking'             , 'China'                               ,  7472000);
INSERT INTO city VALUES(1892, 'Chongqing'          , 'China'                               ,  6351600);
INSERT INTO city VALUES(1893, 'Tianjin'            , 'China'                               ,  5286800);
INSERT INTO city VALUES(1894, 'Wuhan'              , 'China'                               ,  4344600);
INSERT INTO city VALUES(1895, 'Harbin'             , 'China'                               ,  4289800);
INSERT INTO city VALUES(1896, 'Shenyang'           , 'China'                               ,  4265200);
INSERT INTO city VALUES(1897, 'Kanton [Guangzhou]' , 'China'                               ,  4256300);
INSERT INTO city VALUES(1898, 'Chengdu'            , 'China'                               ,  3361500);
INSERT INTO city VALUES(1899, 'Nanking [Nanjing]'  , 'China'                               ,  2870300);
INSERT INTO city VALUES(1900, 'Changchun'          , 'China'                               ,  2812000);
INSERT INTO city VALUES(1901, 'XiÂ´an'             , 'China'                               ,  2761400);
INSERT INTO city VALUES(1902, 'Dalian'             , 'China'                               ,  2697000);
INSERT INTO city VALUES(1903, 'Qingdao'            , 'China'                               ,  2596000);
INSERT INTO city VALUES(1904, 'Jinan'              , 'China'                               ,  2278100);
INSERT INTO city VALUES(1905, 'Hangzhou'           , 'China'                               ,  2190500);
INSERT INTO city VALUES(1906, 'Zhengzhou'          , 'China'                               ,  2107200);
INSERT INTO city VALUES(1907, 'Shijiazhuang'       , 'China'                               ,  2041500);
INSERT INTO city VALUES(1908, 'Taiyuan'            , 'China'                               ,  1968400);
INSERT INTO city VALUES(1909, 'Kunming'            , 'China'                               ,  1829500);
INSERT INTO city VALUES(1910, 'Changsha'           , 'China'                               ,  1809800);
INSERT INTO city VALUES(1911, 'Nanchang'           , 'China'                               ,  1691600);
INSERT INTO city VALUES(1912, 'Fuzhou'             , 'China'                               ,  1593800);
INSERT INTO city VALUES(1913, 'Lanzhou'            , 'China'                               ,  1565800);
INSERT INTO city VALUES(1914, 'Guiyang'            , 'China'                               ,  1465200);
INSERT INTO city VALUES(1915, 'Ningbo'             , 'China'                               ,  1371200);
INSERT INTO city VALUES(1916, 'Hefei'              , 'China'                               ,  1369100);
INSERT INTO city VALUES(1917, 'UrumtÂši [ÃœrÃ¼mqi]', 'China'                               ,  1310100);
INSERT INTO city VALUES(1918, 'Anshan'             , 'China'                               ,  1200000);
INSERT INTO city VALUES(1919, 'Fushun'             , 'China'                               ,  1200000);
INSERT INTO city VALUES(1920, 'Nanning'            , 'China'                               ,  1161800);
INSERT INTO city VALUES(1921, 'Zibo'               , 'China'                               ,  1140000);
INSERT INTO city VALUES(1922, 'Qiqihar'            , 'China'                               ,  1070000);
INSERT INTO city VALUES(1923, 'Jilin'              , 'China'                               ,  1040000);
INSERT INTO city VALUES(1924, 'Tangshan'           , 'China'                               ,  1040000);
INSERT INTO city VALUES(2257, 'SantafÃ© de BogotÃ¡', 'Colombia'                            ,  6260862);
INSERT INTO city VALUES(2258, 'Cali'               , 'Colombia'                            ,  2077386);
INSERT INTO city VALUES(2259, 'MedellÃ­n'          , 'Colombia'                            ,  1861265);
INSERT INTO city VALUES(2260, 'Barranquilla'       , 'Colombia'                            ,  1223260);
INSERT INTO city VALUES(2298, 'Kinshasa'           , 'The Democratic Republic of the Congo', 5064000 );
INSERT INTO city VALUES(2413, 'La Habana'          , 'Cuba'                                ,  2256000);
INSERT INTO city VALUES(3339, 'Praha'              , 'Czech Republic'                      ,  1181126);
INSERT INTO city VALUES( 593, 'Guayaquil'          , 'Ecuador'                             ,  2070040);
INSERT INTO city VALUES( 594, 'Quito'              , 'Ecuador'                             ,  1573458);
INSERT INTO city VALUES( 608, 'Cairo'              , 'Egypt'                               ,  6789479);
INSERT INTO city VALUES( 609, 'Alexandria'         , 'Egypt'                               ,  3328196);
INSERT INTO city VALUES( 610, 'Giza'               , 'Egypt'                               ,  2221868);
INSERT INTO city VALUES( 756, 'Addis Abeba'        , 'Ethiopia'                            ,  2495000);
INSERT INTO city VALUES(2974, 'Paris'              , 'France'                              ,  2125246);
INSERT INTO city VALUES(3068, 'Berlin'             , 'Germany'                             ,  3386667);
INSERT INTO city VALUES(3069, 'Hamburg'            , 'Germany'                             ,  1704735);
INSERT INTO city VALUES(3070, 'Munich [MÃ¼nchen]'  , 'Germany'                             ,  1194560);
INSERT INTO city VALUES( 910, 'Accra'              , 'Ghana'                               ,  1070000);
INSERT INTO city VALUES(3483, 'Budapest'           , 'Hungary'                             ,  1811552);
INSERT INTO city VALUES(1024, 'Mumbai (Bombay)'    , 'India'                               , 10500000);
INSERT INTO city VALUES(1025, 'Delhi'              , 'India'                               ,  7206704);
INSERT INTO city VALUES(1026, 'Calcutta [Kolkata]' , 'India'                               ,  4399819);
INSERT INTO city VALUES(1027, 'Chennai (Madras)'   , 'India'                               ,  3841396);
INSERT INTO city VALUES(1028, 'Hyderabad'          , 'India'                               ,  2964638);
INSERT INTO city VALUES(1029, 'Ahmedabad'          , 'India'                               ,  2876710);
INSERT INTO city VALUES(1030, 'Bangalore'          , 'India'                               ,  2660088);
INSERT INTO city VALUES(1031, 'Kanpur'             , 'India'                               ,  1874409);
INSERT INTO city VALUES(1032, 'Nagpur'             , 'India'                               ,  1624752);
INSERT INTO city VALUES(1033, 'Lucknow'            , 'India'                               ,  1619115);
INSERT INTO city VALUES(1034, 'Pune'               , 'India'                               ,  1566651);
INSERT INTO city VALUES(1035, 'Surat'              , 'India'                               ,  1498817);
INSERT INTO city VALUES(1036, 'Jaipur'             , 'India'                               ,  1458483);
INSERT INTO city VALUES(1037, 'Indore'             , 'India'                               ,  1091674);
INSERT INTO city VALUES(1038, 'Bhopal'             , 'India'                               ,  1062771);
INSERT INTO city VALUES(1039, 'Ludhiana'           , 'India'                               ,  1042740);
INSERT INTO city VALUES(1040, 'Vadodara (Baroda)'  , 'India'                               ,  1031346);
INSERT INTO city VALUES(1041, 'Kalyan'             , 'India'                               ,  1014557);
INSERT INTO city VALUES( 939, 'Jakarta'            , 'Indonesia'                           ,  9604900);
INSERT INTO city VALUES( 940, 'Surabaya'           , 'Indonesia'                           ,  2663820);
INSERT INTO city VALUES( 941, 'Bandung'            , 'Indonesia'                           ,  2429000);
INSERT INTO city VALUES( 942, 'Medan'              , 'Indonesia'                           ,  1843919);
INSERT INTO city VALUES( 943, 'Palembang'          , 'Indonesia'                           ,  1222764);
INSERT INTO city VALUES( 944, 'Tangerang'          , 'Indonesia'                           ,  1198300);
INSERT INTO city VALUES( 945, 'Semarang'           , 'Indonesia'                           ,  1104405);
INSERT INTO city VALUES( 946, 'Ujung Pandang'      , 'Indonesia'                           ,  1060257);
INSERT INTO city VALUES(1380, 'Teheran'            , 'Iran'                                ,  6758845);
INSERT INTO city VALUES(1381, 'Mashhad'            , 'Iran'                                ,  1887405);
INSERT INTO city VALUES(1382, 'Esfahan'            , 'Iran'                                ,  1266072);
INSERT INTO city VALUES(1383, 'Tabriz'             , 'Iran'                                ,  1191043);
INSERT INTO city VALUES(1384, 'Shiraz'             , 'Iran'                                ,  1053025);
INSERT INTO city VALUES(1365, 'Baghdad'            , 'Iraq'                                ,  4336000);
INSERT INTO city VALUES(1464, 'Roma'               , 'Italy'                               ,  2643581);
INSERT INTO city VALUES(1465, 'Milano'             , 'Italy'                               ,  1300977);
INSERT INTO city VALUES(1466, 'Napoli'             , 'Italy'                               ,  1002619);
INSERT INTO city VALUES(1532, 'Tokyo'              , 'Japan'                               ,  7980230);
INSERT INTO city VALUES(1533, 'Jokohama [Yokohama]', 'Japan'                               ,  3339594);
INSERT INTO city VALUES(1534, 'Osaka'              , 'Japan'                               ,  2595674);
INSERT INTO city VALUES(1535, 'Nagoya'             , 'Japan'                               ,  2154376);
INSERT INTO city VALUES(1536, 'Sapporo'            , 'Japan'                               ,  1790886);
INSERT INTO city VALUES(1537, 'Kioto'              , 'Japan'                               ,  1461974);
INSERT INTO city VALUES(1538, 'Kobe'               , 'Japan'                               ,  1425139);
INSERT INTO city VALUES(1539, 'Fukuoka'            , 'Japan'                               ,  1308379);
INSERT INTO city VALUES(1540, 'Kawasaki'           , 'Japan'                               ,  1217359);
INSERT INTO city VALUES(1541, 'Hiroshima'          , 'Japan'                               ,  1119117);
INSERT INTO city VALUES(1542, 'Kitakyushu'         , 'Japan'                               ,  1016264);
INSERT INTO city VALUES(1860, 'Almaty'             , 'Kazakstan'                           ,  1129400);
INSERT INTO city VALUES(1881, 'Nairobi'            , 'Kenya'                               ,  2290000);
INSERT INTO city VALUES(2464, 'Kuala Lumpur'       , 'Malaysia'                            ,  1297526);
INSERT INTO city VALUES(2515, 'Ciudad de MÃ©xico'  , 'Mexico'                              ,  8591309);
INSERT INTO city VALUES(2516, 'Guadalajara'        , 'Mexico'                              ,  1647720);
INSERT INTO city VALUES(2517, 'Ecatepec de Morelos', 'Mexico'                              ,  1620303);
INSERT INTO city VALUES(2518, 'Puebla'             , 'Mexico'                              ,  1346176);
INSERT INTO city VALUES(2519, 'NezahualcÃ³yotl'    , 'Mexico'                              ,  1224924);
INSERT INTO city VALUES(2520, 'JuÃ¡rez'            , 'Mexico'                              ,  1217818);
INSERT INTO city VALUES(2521, 'Tijuana'            , 'Mexico'                              ,  1212232);
INSERT INTO city VALUES(2522, 'LeÃ³n'              , 'Mexico'                              ,  1133576);
INSERT INTO city VALUES(2523, 'Monterrey'          , 'Mexico'                              ,  1108499);
INSERT INTO city VALUES(2524, 'Zapopan'            , 'Mexico'                              ,  1002239);
INSERT INTO city VALUES(2485, 'Casablanca'         , 'Morocco'                             ,  2940623);
INSERT INTO city VALUES(2698, 'Maputo'             , 'Mozambique'                          ,  1018938);
INSERT INTO city VALUES(2710, 'Rangoon (Yangon)'   , 'Myanmar'                             ,  3361700);
INSERT INTO city VALUES(2741, 'Lagos'              , 'Nigeria'                             ,  1518000);
INSERT INTO city VALUES(2742, 'Ibadan'             , 'Nigeria'                             ,  1432000);
INSERT INTO city VALUES(2318, 'Pyongyang'          , 'North Korea'                         ,  2484000);
INSERT INTO city VALUES(2822, 'Karachi'            , 'Pakistan'                            ,  9269265);
INSERT INTO city VALUES(2823, 'Lahore'             , 'Pakistan'                            ,  5063499);
INSERT INTO city VALUES(2824, 'Faisalabad'         , 'Pakistan'                            ,  1977246);
INSERT INTO city VALUES(2825, 'Rawalpindi'         , 'Pakistan'                            ,  1406214);
INSERT INTO city VALUES(2826, 'Multan'             , 'Pakistan'                            ,  1182441);
INSERT INTO city VALUES(2827, 'Hyderabad'          , 'Pakistan'                            ,  1151274);
INSERT INTO city VALUES(2828, 'Gujranwala'         , 'Pakistan'                            ,  1124749);
INSERT INTO city VALUES(2890, 'Lima'               , 'Peru'                                ,  6464693);
INSERT INTO city VALUES( 765, 'Quezon'             , 'Philippines'                         ,  2173831);
INSERT INTO city VALUES( 766, 'Manila'             , 'Philippines'                         ,  1581082);
INSERT INTO city VALUES( 767, 'Kalookan'           , 'Philippines'                         ,  1177604);
INSERT INTO city VALUES( 768, 'Davao'              , 'Philippines'                         ,  1147116);
INSERT INTO city VALUES(2928, 'Warszawa'           , 'Poland'                              ,  1615369);
INSERT INTO city VALUES(3018, 'Bucuresti'          , 'Romania'                             ,  2016131);
INSERT INTO city VALUES(3580, 'Moscow'             , 'Russian Federation'                  ,  8389200);
INSERT INTO city VALUES(3581, 'St Petersburg'      , 'Russian Federation'                  ,  4694000);
INSERT INTO city VALUES(3582, 'Novosibirsk'        , 'Russian Federation'                  ,  1398800);
INSERT INTO city VALUES(3583, 'Nizni Novgorod'     , 'Russian Federation'                  ,  1357000);
INSERT INTO city VALUES(3584, 'Jekaterinburg'      , 'Russian Federation'                  ,  1266300);
INSERT INTO city VALUES(3585, 'Samara'             , 'Russian Federation'                  ,  1156100);
INSERT INTO city VALUES(3586, 'Omsk'               , 'Russian Federation'                  ,  1148900);
INSERT INTO city VALUES(3587, 'Kazan'              , 'Russian Federation'                  ,  1101000);
INSERT INTO city VALUES(3588, 'Ufa'                , 'Russian Federation'                  ,  1091200);
INSERT INTO city VALUES(3589, 'TÂšeljabinsk'       , 'Russian Federation'                  ,  1083200);
INSERT INTO city VALUES(3590, 'Rostov-na-Donu'     , 'Russian Federation'                  ,  1012700);
INSERT INTO city VALUES(3591, 'Perm'               , 'Russian Federation'                  ,  1009700);
INSERT INTO city VALUES(3173, 'Riyadh'             , 'Saudi Arabia'                        ,  3324000);
INSERT INTO city VALUES(3174, 'Jedda'              , 'Saudi Arabia'                        ,  2046300);
INSERT INTO city VALUES( 712, 'Cape Town'          , 'South Africa'                        ,  2352121);
INSERT INTO city VALUES(2331, 'Seoul'              , 'South Korea'                         ,  9981619);
INSERT INTO city VALUES(2332, 'Pusan'              , 'South Korea'                         ,  3804522);
INSERT INTO city VALUES(2333, 'Inchon'             , 'South Korea'                         ,  2559424);
INSERT INTO city VALUES(2334, 'Taegu'              , 'South Korea'                         ,  2548568);
INSERT INTO city VALUES(2335, 'Taejon'             , 'South Korea'                         ,  1425835);
INSERT INTO city VALUES(2336, 'Kwangju'            , 'South Korea'                         ,  1368341);
INSERT INTO city VALUES(2337, 'Ulsan'              , 'South Korea'                         ,  1084891);
INSERT INTO city VALUES( 653, 'Madrid'             , 'Spain'                               ,  2879052);
INSERT INTO city VALUES( 654, 'Barcelona'          , 'Spain'                               ,  1503451);
INSERT INTO city VALUES(3224, 'Omdurman'           , 'Sudan'                               ,  1271403);
INSERT INTO city VALUES(3250, 'Damascus'           , 'Syria'                               ,  1347000);
INSERT INTO city VALUES(3251, 'Aleppo'             , 'Syria'                               ,  1261983);
INSERT INTO city VALUES(3263, 'Taipei'             , 'Taiwan'                              ,  2641312);
INSERT INTO city VALUES(3264, 'Kaohsiung'          , 'Taiwan'                              ,  1475505);
INSERT INTO city VALUES(3305, 'Dar es Salaam'      , 'Tanzania'                            ,  1747000);
INSERT INTO city VALUES(3320, 'Bangkok'            , 'Thailand'                            ,  6320174);
INSERT INTO city VALUES(3357, 'Istanbul'           , 'Turkey'                              ,  8787958);
INSERT INTO city VALUES(3358, 'Ankara'             , 'Turkey'                              ,  3038159);
INSERT INTO city VALUES(3359, 'Izmir'              , 'Turkey'                              ,  2130359);
INSERT INTO city VALUES(3360, 'Adana'              , 'Turkey'                              ,  1131198);
INSERT INTO city VALUES(3361, 'Bursa'              , 'Turkey'                              ,  1095842);
INSERT INTO city VALUES(3426, 'Kyiv'               , 'Ukraine'                             ,  2624000);
INSERT INTO city VALUES(3427, 'Harkova [Harkiv]'   , 'Ukraine'                             ,  1500000);
INSERT INTO city VALUES(3428, 'Dnipropetrovsk'     , 'Ukraine'                             ,  1103000);
INSERT INTO city VALUES(3429, 'Donetsk'            , 'Ukraine'                             ,  1050000);
INSERT INTO city VALUES(3430, 'Odesa'              , 'Ukraine'                             ,  1011000);
INSERT INTO city VALUES( 456, 'London'             , 'United Kingdom'                      ,  7285000);
INSERT INTO city VALUES( 457, 'Birmingham'         , 'United Kingdom'                      ,  1013000);
INSERT INTO city VALUES(3793, 'New York'           , 'United States'                       ,  8008278);
INSERT INTO city VALUES(3794, 'Los Angeles'        , 'United States'                       ,  3694820);
INSERT INTO city VALUES(3795, 'Chicago'            , 'United States'                       ,  2896016);
INSERT INTO city VALUES(3796, 'Houston'            , 'United States'                       ,  1953631);
INSERT INTO city VALUES(3797, 'Philadelphia'       , 'United States'                       ,  1517550);
INSERT INTO city VALUES(3798, 'Phoenix'            , 'United States'                       ,  1321045);
INSERT INTO city VALUES(3799, 'San Diego'          , 'United States'                       ,  1223400);
INSERT INTO city VALUES(3800, 'Dallas'             , 'United States'                       ,  1188580);
INSERT INTO city VALUES(3801, 'San Antonio'        , 'United States'                       ,  1144646);
INSERT INTO city VALUES(3503, 'Toskent'            , 'Uzbekistan'                          ,  2117500);
INSERT INTO city VALUES(3539, 'Caracas'            , 'Venezuela'                           ,  1975294);
INSERT INTO city VALUES(3540, 'MaracaÃ­bo'         , 'Venezuela'                           ,  1304776);
INSERT INTO city VALUES(3769, 'Ho Chi Minh City'   , 'Vietnam'                             ,  3980000);
INSERT INTO city VALUES(3770, 'Hanoi'              , 'Vietnam'                             ,  1410000);
INSERT INTO city VALUES(1792, 'Beograd'            , 'Yugoslavia'                          ,  1204000);
INSERT INTO city VALUES(4068, 'Harare'             , 'Zimbabwe'                            ,  1410000);