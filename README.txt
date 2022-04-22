#Projekt realistycznej wody wykonywany przy użyciu biblioteki OpenGL

#Technologie

C++/OpenGL

#Biblioteki

glfw - biblioteka która pozwala na wyświetlanie okna oraz obsługę Inputów gracza.
glad - biblioteka inicjalizująca OpenGL
glm - biblioteka matetamtyczna np:.(Transformacje macierzy, Rotacje macierzy, sklaowanie macierzy, wektory, operacje na wektorach)

OpenGL - biblioteka graficzna pozwalająca tworzyć tak zwane shadery (program który obsługuję wieszchołki w przestrzeni i pixele na ekranie)

#Aktualny stan

Najnowsza wersja na branchu Refactor.

Aktualnie aplikacja obsługuje inputy gracza zarówno myszkę jak i klawiaturę. Dzięki rozłożeniu wszystkich metod z bibliotek na klasy wygodnie i szybko można tworzyć własne cube lub jeżeli chcemy zmienić nasze preferencje możemy stworzyć Pyramidy. nakładanie tekstur odbywa się w pliku txt w folderze texture dzięki czemu wciskając R na klawiaturze możemy przeładować cały shader i zmienić teksturę w locie (Aktualnie na czas refaktoru pewne elementy mogą nie działać). Aplikacja posiada również zakodowany ruch kamery dzięki czemu możemy doświadczyć prawdziewego 3d.

Dodane:
-Możliwość stworzenia kuli narazie tylko i wyłącznie siatki.
-Możliwość stworzenia shadera z odbiciem skyboxa.
-Możliwość stworzenia skyboxa 6 przykładowych tekstur.
-Diffuse oraz Specular Light.
-Możliwość stworzenia realistycznej wody na powieszchni przy pomocy pewnych określonych reguł
TIP:

Change In Visual Studio Solution Platforms x86
