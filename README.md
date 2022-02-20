# INF224

Final project of INF224 (Paradigmes de programmation, théorie et pratique).

C++ part: https://perso.telecom-paristech.fr/elc/cpp/TP-C++.html
Java swing part: https://perso.telecom-paristech.fr/elc/swing/TP-Swing.html

Compiler c++:
    make
Complier java:
    cd JavaSwing
    make

Etape 2: 
    Base est la classe de base. Les classes Photo, Video et Film héritent de cette classe.

Etape 4:
    On déclare une méthodes virtuelles pures (virtual void show() const = 0;). Donc la classe Base ne peux plus instancer.

Etape 5: #define TEST_POLYMORPHISM
    La propriété caractéristique est polymorphisme.
    En c++, on crée une tableau de pointeur de classe de base, et on ajoute des objets de sous-classe dans le tableau.
    Les éléments dans le tableau sont un pointeur vers l'objet Base. En java, il existe que des pointeurs.

Etape 6: #define TEST_FILM
    Pour　assurer l'encapsulation, quand on modifier les durées, une copie de la liste donnée est stockée. Et on retourne une pointeur constant dans la méthode getDurations.

Etape 7: #define TEST_DEEPCOPY
    Le destructeur de la class Film doit être modifé car on crée une liste avec new pour sauvegarder les durées. Dans le destructeur, il faut delete[] durations.
    Comme l'existance de cette liste, il faut redéfinir la constructeur de copie et opérand = pour réaliser une copie profonde.

Etape 8: #define TEST_GROUP; #define TEST_SMART_PTR
    La class Group hérite de la classe list.
    Un objet Group contient des pointeur des objets car on veux utiliser le polymorphisme.

Etape 9: #define TEST_GROUP; #define TEST_SMART_PTR
    On utilise smart pointer pour Film, Video et Photo.

Etape 10: #define TEST_TABLE; #define DISABLE_CONSTRUCTOR
    On interdit de créer un object multimédia dehors cette classe par définir les constructeurs de ces classe privés. Pour que la classe Table puisse y accéder, on la définit dans les classe de multimédia une classe amie.

    On ajoute une méthode pour supprimer une objet multimédia ou un groupe. 

Etape 11: #define TEST_TABLE; #define DISABLE_CONSTRUCTOR; #define TEST_SERVER
    On définit une classe RequestProcessor pour traiter les requêtes. Les instructions suivant sont définies:
        findMedia name : chercher un objet Multimédia avec son nom et donner ses informations
        findGroup name : chercher un group avec son nom et donner ses informations
        play name : jouer un objet Multimédia
        deleteGroup name : supprimer un group
        deleteMedia name : supprimer un objet multimédia
    On définit des maps contenants des pointeurs de méthodes.

JavaSwing:
    Il existe trois bouttons, un tool bar, un menu dans la fenêtre. On peut taper une instruction dans le textArea et l'envoyer à la serveur en appuyant sur ENTER.
    Le premier boutton ajoute un mot play dans le textAre et le deuxième ajoute findMedia.


