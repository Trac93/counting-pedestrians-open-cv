# Przetwarzanie obrazów cyfrowych
## Zliczanie przechodniów
### Mateusz Tracki
Niniejszy projekt wykonany został w języku C++ przy pomocy biblioteki OpenCV. Ma on na celu zliczanie przechodniów przechodzących przez tzw. "pułapkę".  Osobno zliczane są osoby która przechodzą ją od prawej strony, jak i z lewej. 

Detekcja ludzi została zrealizowana za pomocą metody nazywanej histogramem zorientowanych gradientów. Metoda ta jest bardzo skuteczna, lecz w dużym stopniu obciąża komputer. 

Zliczanie odbywa się na podstawie przykładowego filmiku, który został dołączony do repozytorium. 