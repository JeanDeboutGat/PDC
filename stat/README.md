# Réponses

## ex7
L'appel système utilisé : fstatat

Type en C utilisé : struct stat { ... }

Bloc -> nombres de blocs de 512 bytes utilisés par le fichier

Bloc d'E/S -> taille en bytes d'un ensemble de 8 blocs qui s'ajoute à chaque dépassement du seuil des 8 blocs précédants.

## ex8
Le seuil est de 4096 caractères, au dela le nombre de blocs double (passe de 8 à 16).
Au dela de 8192 (4096 * 2), les blocs passent de 16 à 24 etc ...
Lorsque le seuil est dépassé, un nouveau tableau de 4096 bytes est utilisé pour stocker la suite du fichier.

## ex10
Liens ->

Le fichier de base et la copie n'ont pas le meme nombre de liens.
La fichier de base a 2 liens, la copie un seul. Le lien physique a les
meme caractéristiques que le fichier de base. Le lien symbolique a aussi un seul lien mais
aucun blocs et une taille différente du fichier de base.

i-noeuds ->

Le numéro Inoeud est identique pour le fichier de base et le lien physique.
Il est est différend pour la copie, pareil pour le lien symbolique.

Après suppression du fichier test, on peut retrouver le texte avec la copie,
le lien physique mais pas le lien symbolique. Au passage le lien physique semble avoir perdu
un lien si on le regarde avec la commande stat.

# Compte rendu
Après avoir lu les man pages, j'ai testé la commande stat avec un fichier test :
```bash
  Fichier : test
   Taille : 15        	Blocs : 8          Blocs d'E/S : 4096   fichier
Périphérique : 801h/2049d	Inœud : 1057587     Liens : 2
Accès : (0777/-rwxrwxrwx)  UID : ( 1000/     moi)   GID : ( 1000/     moi)
Accès : 2020-09-13 21:45:59.584479555 +0200
Modif. : 2020-09-13 21:45:54.816479659 +0200
Changt : 2020-09-14 00:04:36.820298566 +0200
  Créé : -
```
Avec la man page de stat on tombe vite sur fstatat qui est l'appel système à utiliser pour récupérer les infos à afficher via
la struct stat. A partir de la j'ai formatté l'affichage avec la structure et des printf.
J'ai du beacoups chercher pour trouver comment afficher proprement les dates avant de voir la réponse à une question sur le sujet.
Pour l'exercice 13 on retrouve les structures à utiliser dans les 2 man pages. Il ne restait plus qu'à les afficher par la suite.

#   Afficher les métadonnées d’un i-nœud

Ce répertoire correspond aux exercices de la section
[Afficher les métadonnées d’un i-nœud](https://www.fil.univ-lille1.fr/~hym/e/pds/tp/tdfs1-cmd.html#stat).
À la fin de votre travail, il devra donc contenir les fichiers
suivants :

-   `stat.c`,
-   `Makefile`,
-   éventuellement quelques (petits !) fichiers de test (cependant
    évitez de mettre des liens physiques).

Vous éditerez ce fichier pour qu’il contienne un **compte-rendu du
travail effectué**. Il devra notamment contenir une trace de ce que
vous avez fait comme tests ; par exemple vous pourrez dire « j’ai
lancé la commande suivante :

```bash
ln a b
```

et j’ai obtenu... ».

Ce compte-rendu indiquera aussi vos réponses pour les questions qui
vous demandent autre chose que du code.

Par ailleurs, vous ferez attention à **ignorer** (ne pas ajouter au
dépôt) les fichiers compilés (`.o`, exécutable, etc.). Ajoutez tous
vos exécutables au fichier `.gitignore` pour éviter les mauvaises
manipulations.
