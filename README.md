# Przetwarzanie obrazów cyfrowych

## Zliczanie przechodniów

### Mateusz Tracki

Niniejszy projekt wykonany zosta³ w jêzyku C++ przy pomocy biblioteki OpenCV. Ma on na 
celu zliczanie przechodniów przechodz¹cych przez tzw. "pu³apkê".  Osobno zliczane s¹ 
osoby która przechodz¹ j¹ od prawej strony, jak i z lewej. 



Detekcja ludzi zosta³a zrealizowana za pomoc¹ metody nazywanej histogramem 
zorientowanych gradientów. Metoda ta jest bardzo skuteczna, lecz w du¿ym stopniu 
obci¹¿a komputer. 