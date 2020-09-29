# Compte rendu

Dans lstar.c, j'ai ajouté ce qui suit dans struct posix_header pour toujours prendre des blocs de 512 quand je fais un read avec la structure :
```c
char bourrage[12];
```

Avant toute chose, lancer le makefile :
```bash
make
```

Pour tester lstar en sachant que le fichier test contient 20 octets:
```bash
tar -H ustar -c test | ./lstar
```

Test permettant de vérifier que lstar regarde bien tous les fichiers fournis par la commande :
```bash
tar -H ustar -c lstar.c Makefile README.md test | ./lstar
```

#   Décodage du format `tar`

Ce répertoire correspond aux exercices de la section
[Décodage du format `tar`](https://www.fil.univ-lille1.fr/~hym/e/pds/tp/tdfs1-cmd.html#tar).
À la fin de votre travail, il devra donc contenir les fichiers
suivants :

-   `lstar.c`,
-   `Makefile`,
-   éventuellement quelques (petits !) fichiers de test ; il est
    encore mieux si vous arrivez à ajouter les règles nécessaires à la
    génération de ces fichiers de test dans votre `Makefile` ou dans
    un script `tests.sh`.

Vous éditerez ce fichier pour qu’il contienne un **compte-rendu du
travail effectué**. Il devra notamment contenir une explication de ce
que vous avez effectué comme tests.

Par ailleurs, vous ferez attention à **ignorer** (ne pas ajouter au
dépôt) les fichiers compilés (`.o`, exécutable, etc.). Ajoutez tous
vos exécutables au fichier `.gitignore` pour éviter les mauvaises
manipulations.
